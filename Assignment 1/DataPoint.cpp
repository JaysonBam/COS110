#include "DataPoint.h"

void Formatline(std::string& line) {
    while (line.find_first_of(" ()") != std::string::npos) {
        line.erase(line.find_first_of(" ()"), 1);
    }
    if (line.length()!=0)
        line = line + ',';
}

int countNumbers(std::string line){
    int result;
    result = 0;
    while (line.find(',')!=std::string::npos){
        result++;
        line.erase(1,line.find(',')+1);
    }
    return result;
}

DataPoint::DataPoint(std::string line) {
    Formatline(line);
    numberOfAttributes = countNumbers(line);
    attributes = new float[numberOfAttributes];
    std::string numStr;
    float num;
    int i;
    for (i = 0; i < numberOfAttributes; i++){
        numStr = line.substr(0, line.find(','));
        line.erase(0, line.find(',') + 1);
        std::istringstream iss(numStr);
        iss >> num;
        attributes[i] = num;
    }
}

DataPoint::DataPoint(DataPoint *other) {
    if (other == NULL)
        this->numberOfAttributes=0;
    else
        this->numberOfAttributes = other->numberOfAttributes;

    this->attributes = new float[this->numberOfAttributes];
    for (int i = 0; i < this->numberOfAttributes; i++) 
        this->attributes[i] = other->attributes[i];
    
}

DataPoint::DataPoint(float *attributes, int numberOfAttributes) {
    if (numberOfAttributes<0 || attributes==NULL)
        this->numberOfAttributes=0;
    else
        this->numberOfAttributes = numberOfAttributes;

    this->attributes = new float[this->numberOfAttributes];
    for (int i = 0; i < this->numberOfAttributes; i++)
        this->attributes[i] = attributes[i]; 
}

DataPoint::~DataPoint() {
    if (attributes != NULL)
        delete[] attributes;        
    attributes = NULL;
}

DataPoint* DataPoint::clone() {
    return new DataPoint(attributes,numberOfAttributes);
}

float* DataPoint::getAttributes() {
    return attributes;
}

int DataPoint::getNumberOfAttributes() {
    return  numberOfAttributes;
}
