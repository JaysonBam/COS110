#include "DistanceFunction.h"

float DistanceFunction::ManhattanDistance(DataPoint* dpA, DataPoint* dpB) {
    //is Valid
    bool valid;
    valid = true;
    if (dpB == NULL) 
        valid = false;
    if (dpA == NULL) 
        valid = false;
    if (valid)
        if (dpA->getNumberOfAttributes() != dpB->getNumberOfAttributes()) 
            valid = false;
    //
    if (!valid) 
        return INFINITY;
    float result;
    result = 0;
    int i;
    for ( i = 0; i < dpA->getNumberOfAttributes(); i++) 
         result += std::abs(dpA->getAttributes()[i] - dpB->getAttributes()[i]);
    return result;
}

float DistanceFunction::EuclideanDistance(DataPoint* dpA, DataPoint* dpB) {
    //is Valid
    bool valid;
    valid = true;
    if (dpB == NULL) 
        valid = false;
    if (dpA == NULL) 
        valid = false;
    if (valid)
        if (dpA->getNumberOfAttributes() != dpB->getNumberOfAttributes()) 
            valid = false;
    //
    if (!valid) 
        return INFINITY;
    float result;
    result = 0;
    int i;
     for ( i = 0; i < dpA->getNumberOfAttributes(); i++)
         result += pow(dpA->getAttributes()[i] - dpB->getAttributes()[i],2);
    return pow(result,0.5); 
}

float DistanceFunction::ChebyshevDistance(DataPoint* dpA, DataPoint* dpB) {
    //is Valid
    bool valid;
    valid = true;
    if (dpB == NULL) 
        valid = false;
    if (dpA == NULL) 
        valid = false;
    if (valid)
        if (dpA->getNumberOfAttributes() != dpB->getNumberOfAttributes()) 
            valid = false;
    //
    if (!valid)  
        return INFINITY;
    float result;
    result = 0;
    int i;
     for ( i = 0; i < dpA->getNumberOfAttributes(); i++) {
         float temp = std::abs(dpA->getAttributes()[i] - dpB->getAttributes()[i]);
         if (temp>result) 
            result = temp;
     }
     return result; 
}