#include "warehouse.h"
#include "crate.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

warehouse::warehouse(){
    numCrates = 0;
    crates = new crate*[numCrates];
}

warehouse::warehouse(int numCrates){
    this->numCrates = numCrates;
    crates = new crate*[numCrates];
    for (int i = 0; i < numCrates; i++)
        crates[i] = new crate;

}

warehouse::warehouse(int numCrates, crate** crates){
    this->numCrates = numCrates;
    this->crates = new crate*[numCrates];
    for (int i = 0; i < numCrates; i++)
        this->crates[i] = new crate(*crates[i]);
}

warehouse::warehouse(const warehouse& w){
    this->numCrates = w.numCrates;
    this->crates = new crate*[numCrates];
    for (int i = 0; i < numCrates; i++)
        this->crates[i] = new crate(*w.crates[i]);
}

warehouse::~warehouse(){
    if (crates!=NULL)
    {
        for (int i = 0; i < numCrates; i++)
            if (crates[i]!=NULL){
                delete crates[i];
                crates[i] = NULL;
            }
        delete[] crates;
        crates = NULL;
    }

}

int warehouse::getNumCrates(){
    return numCrates;
}

crate** warehouse::getCrates(){
    return crates;
}

float warehouse::getValue(){
    float result = 0;
    for (int i = 0; i < numCrates; i++)
        result += crates[i]->getValue();
    return result;
}

std::ostream& operator<<(std::ostream& os, warehouse& w){
    std::string s = "";
    for (int i = 0; i < 80; i++)
        s+="-";
    os<<s<<std::endl;
    for (int i = 0; i < w.numCrates; i++)
        os<<*w.crates[i];
    os<<s<<std::endl;
    os << std::left << std::setw(50) << "Warehouse";
    os << std::left << std::setw(10) << w.numCrates;
    os << std::left << std::setw(10) << " ";
    os << std::left << std::setw(2)  << "R ";
    os << std::left << std::setw(8)  << std::fixed << std::setprecision(2) << w.getValue() << std::endl;

    os<<s<<std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, warehouse& w){
    std::string line;
    int size;
    is >> size;
    std::getline(is,line); // Go to the next line.

    for (int i = 0; i < size; i++) {
        crate temp;
        is >> temp;
        w += temp;
    }
    return is;
}

  
warehouse& warehouse::operator+=(crate& c){
    //case 1
    for (int i = 0; i < numCrates; i++)
        if (*crates[i]==c) 
        {
            *crates[i]+=c.getAmount();
            return *this;
        }
    //case 2
    for (int i = 0; i < numCrates; i++)
        if (crates[i]->getName()=="empty") 
        {
            crates[i]->setName(c.getName());
            crates[i]->setAmount(c.getAmount());
            crates[i]->setPrice(c.getPrice());
            return *this;
        }
    //case 3
    crate** temp = new crate*[numCrates+1];
    for (int i= 0; i<numCrates;i++)
        temp[i] = new crate(*crates[i]);
    temp[numCrates] = new crate(c);

    for (int i = 0; i < numCrates; i++)
        delete crates[i];
    delete[] crates;

    numCrates++;
    crates = temp;
    return *this; 
}

warehouse& warehouse::operator-=(crate& c){
    for (int i = 0; i < numCrates; i++)
        if (*crates[i]==c){
            *crates[i]-=c.getAmount();
            return *this;;
        }
    return *this;
}

warehouse warehouse::operator|(int method){
    warehouse w(*this);
    if (method==0)
    {
        for (int i = 0; i < numCrates - 1; ++i) {
            for (int j = i + 1; j < numCrates; ++j) {
                if (*w.crates[j] <= *w.crates[i] )
                {
                    if (w.crates[j]->getName()==w.crates[i]->getName())
                    {
                        if (w.crates[j]->getValue()<w.crates[i]->getValue()){
                            crate* temp = w.crates[j];
                            w.crates[j] = w.crates[i];
                            w.crates[i] = temp;    
                        }
                        
                    }
                    else
                    {
                        crate* temp = w.crates[j];
                        w.crates[j] = w.crates[i];
                        w.crates[i] = temp;
                    }
                }

            }
        } 
    }
    if (method>0)
    {
        for (int i = 0; i < numCrates - 1; ++i) {
            for (int j = i + 1; j < numCrates; ++j) {
                if (*w.crates[j] < *w.crates[i] )
                {
                    if (w.crates[j]->getValue()==w.crates[i]->getValue())
                    {
                        if (w.crates[j]->getName()<w.crates[i]->getName()){
                            crate* temp = w.crates[j];
                            w.crates[j] = w.crates[i];
                            w.crates[i] = temp;    
                        }
                        
                    }
                    else
                    {
                        crate* temp = w.crates[j];
                        w.crates[j] = w.crates[i];
                        w.crates[i] = temp;
                    }
                }

            }
        } 
    }

    if (method<0)
    {
        for (int i = 0; i < numCrates - 1; ++i) {
            for (int j = i + 1; j < numCrates; ++j) {
                if (*w.crates[j] > *w.crates[i] )
                {
                    if (w.crates[j]->getName()==w.crates[i]->getName())
                    {
                        if (w.crates[j]->getValue()<w.crates[i]->getValue()){
                            crate* temp = w.crates[j];
                            w.crates[j] = w.crates[i];
                            w.crates[i] = temp;    
                        }
                        
                    }
                    else
                    {
                        crate* temp = w.crates[j];
                        w.crates[j] = w.crates[i];
                        w.crates[i] = temp;
                    }
                }

            }
        } 
    }
    return w;
}

warehouse& warehouse::operator|=(int method) {
    warehouse sortedWarehouse = *this | method;

    for (int i = 0; i < numCrates; i++) {
        delete crates[i];
    }
    delete[] crates;

    numCrates = sortedWarehouse.numCrates;
    crates = new crate*[numCrates];

    for (int i = 0; i < numCrates; i++) {
        crates[i] = new crate(*sortedWarehouse.crates[i]);
    }

    return *this;
}

crate& warehouse::operator[](int index){
    if (index<numCrates && index >=0)
        return *crates[index];
    else
    {
        crate* maxCrate = crates[0];
        for (int i = 1; i < numCrates; i++)
            if (*crates[i]>*maxCrate)
                if (crates[i]->getValue()==maxCrate->getValue())
                {
                    if (crates[i]->getName()<maxCrate->getName())
                    maxCrate = crates[i];
                }
                else
                    maxCrate = crates[i];
        return *maxCrate;
    }           
}

warehouse& warehouse::operator()(){
    int tempCounter = 0;
    crate** tempCrates;

    for (int i = 0; i<numCrates;i++)
        if (crates[i]->getName()!="empty")
            tempCounter++;
    
    tempCrates = new crate*[tempCounter];
    int j = 0;
    for (int i = 0; i<numCrates;i++)
        if (crates[i]->getName()!="empty")
            tempCrates[j++] = new crate(*crates[i]);

    for (int i = 0; i < numCrates; i++)
        delete crates[i];
    delete[] crates;

    numCrates = tempCounter;
    crates = tempCrates;
    return *this; 
}

warehouse& warehouse::operator()(crate& c){
    int tempCounter = 0;
    crate** tempCrates;

    for (int i = 0; i<numCrates;i++)
        if (crates[i]->getName()!="empty" && !(*crates[i] == c))
            tempCounter++;
    
    tempCrates = new crate*[tempCounter];
    int j = 0;
    for (int i = 0; i<numCrates;i++)
        if (crates[i]->getName()!="empty" && !(*crates[i] == c))
            tempCrates[j++] = new crate(*crates[i]);

    for (int i = 0; i < numCrates; i++)
        delete crates[i];
    delete[] crates;

    numCrates = tempCounter;
    crates = tempCrates;
    return *this; 
}
