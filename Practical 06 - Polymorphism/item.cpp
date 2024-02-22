#include "item.h"
#include <cmath>
#include <sstream>

int getLenght(int bN){
    int result = 0;
    while (bN > 0)
    {
        bN/=2;
        result++;
    }
    return result;
}

void readIn(bool* &barcode, int bN, int size){
    int index = 0;
    while (bN > 0) {
        barcode[size-++index] = bN % 2;
        bN /= 2;
    }
}

int barcodeToInt(bool* barcode, int bl){
    int result = 0;
    int powerOfTwo = 1;

    for (int i = bl - 1; i >= 0; i--){
        if (barcode[i])
            result += powerOfTwo;
        powerOfTwo *= 2;
    }
    
    return result;
}


item::item(std::string n, int bN) {
    name = n;
    barcodeLength = getLenght(bN);
    barcode = new bool[barcodeLength];
    readIn(barcode,bN,barcodeLength);
}

item::~item() {
    if (barcode != NULL){
        delete[] barcode;
        barcode = NULL;
    }
}

std::string item::getName(){
    return name;
}

std::string item::getBarcode(){
    std::stringstream ss;
    ss << '[';
    for (int i = 0; i < barcodeLength; i++){
        if (barcode[i]) ss << '|';
        else ss << ' ';
    }
    ss << ']' << "(" << barcodeToInt(barcode, barcodeLength) << ")";
    return ss.str();
}