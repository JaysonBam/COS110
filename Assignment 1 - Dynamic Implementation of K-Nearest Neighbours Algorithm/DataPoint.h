#ifndef DATA_POINT_H
#define DATA_POINT_H

#include <string>
#include <iostream>
#include <sstream>

class DataPoint
{
private:
    float *attributes;
    int numberOfAttributes;

public:
    DataPoint(std::string line);
    DataPoint(DataPoint *other);
    DataPoint(float *attributes, int numberOfAttributes);
    ~DataPoint();
    DataPoint *clone();
    float *getAttributes();
    int getNumberOfAttributes();
    void printOut()
    {
        std::cout << "[";
        for (int i = 0; i < numberOfAttributes - 1; i++)
        {
            std::cout << attributes[i] << ",";
        }
        if (numberOfAttributes > 0)
        {
            std::cout << attributes[numberOfAttributes - 1];
        }
        std::cout << "]" << std::endl;
    };
};

#endif /*DATA_POINT_H*/