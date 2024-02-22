#ifndef DISTANCE_FUNCTION_H
#define DISTANCE_FUNCTION_H

#include <cmath>

#include "DataPoint.h"

class DistanceFunction{
    public:
        static float ManhattanDistance(DataPoint* dpA, DataPoint* dpB);
        static float EuclideanDistance(DataPoint* dpA, DataPoint* dpB);
        static float ChebyshevDistance(DataPoint* dpA, DataPoint* dpB);
};


#endif /*DISTANCE_FUNCTION_H*/