#include <fstream>
#include <iostream>

#include "warehouse.h"
#include "crate.h"

using namespace std;

void crateCreate(){
    crate c1;
    cout<<"Default crate:  \t"<<c1;
    crate c2("apples",20,5);
    cout<<"Parameter crate:\t"<<c2;
    crate c3(c2);
    cout<<"Copy crate:     \t"<<c3;
    crate c4("banana|15|9");
    cout<<"String crate:    \t"<<c4;
}

void crateOperation(){
    crate c1;
    c1.setName("apples");
    c1.setAmount(20);
    c1.setPrice(5);

    cout<<"Name:  "<<c1.getName()<<endl;
    cout<<"Amount:"<<c1.getAmount()<<endl;
    cout<<"Price: "<<c1.getPrice()<<endl;
    cout<<"Value: "<<c1.getValue()<<endl;

    cout<<c1;
    //>> tested in main
    crate c2;
    c2 | "banana|15|9";

    ++c2;
    c2++;
    c2+=4;
    c2-=4;
    c2-=100;

    cout<<(c1==c2)<<(c1<=c2)<<(c1>=c2)<<(c1<c2)<<(c1>c2)<<endl;

}

void warehouseCreate(){
    warehouse w1;
    cout<<"Default wearhouse\n"<<w1;
    
    warehouse w2(5);
    cout<<"5 int warehouse\n"<<w2;

    warehouse w3(w2.getNumCrates(),w2.getCrates());
    cout<<"Copy 1\n"<<w3;

    warehouse w4(w3);
    cout<<"Copy 2\n"<<w4;
}

void warehouseOperations(){
    fstream file("test.txt");
    warehouse w(5);
    file >> w;
    file >> w;
    file.close();
    cout << w.getValue()<<endl;
    cout << w;
    crate c("green apple|4|7.99");
    crate e("empty|0|0");
    w+=c;
    cout << w;
    w-=c;
    cout << w;
    w|=-1;
    cout << w;
    w|=0;
    cout << w;
    w|=1;
    cout << w;
    cout<<w[-1];
    cout<<w[3];
    w();
    cout << w;
    w+=c;
    w+=e;
    cout << w;
    w(c);
    cout << w;
}

int main() {
    cout<<"__________________________________________________________________________________________________________________\n";
    crateCreate();
    cout<<"__________________________________________________________________________________________________________________\n";
    crateOperation();
    cout<<"__________________________________________________________________________________________________________________\n";
    warehouseCreate();
    cout<<"__________________________________________________________________________________________________________________\n";
    warehouseOperations();
    cout<<"__________________________________________________________________________________________________________________\n";
    fstream file("input.txt");
    warehouse* w = new warehouse(5);
    file >> *w;
    file >> *w;
    cout << *w;
    file.close();
    delete w;
    return 0;
    cout<<"_________________________________________________________\n";
}
