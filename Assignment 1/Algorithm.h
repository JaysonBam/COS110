#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <fstream>

#include "DataPoint.h"
#include "DistanceFunction.h"

struct GroupInfo{
    DataPoint*** groups;
    int* sizes;
};

class Algorithm{
    private:
        DataPoint** dataPoints;
        DataPoint** centroids;
        int numberOfDataPoints;
        int k;

    public:
        Algorithm(std::string textfile);
        Algorithm(DataPoint** dps, int numberOfDataPoints);
        Algorithm(Algorithm* other);
        ~Algorithm();
        DataPoint** setCentroids(float** rawCentroidPositions, int k, int numAttributes);
        DataPoint** getCentroids() const;
        DataPoint** singleRun(int distanceMetric);
        DataPoint*** fullRun(int distanceMetric, int numberOfIterations);
        GroupInfo* formGroup(int distanceMetric);
        DataPoint* averagePositionOfGroup(DataPoint** group, int size) const;
        int getNumDataPoints() const;
        DataPoint** getDataPoints() const;

        void printOut(){
            for(int i=0; i < numberOfDataPoints; i++){
                if(dataPoints[i] != NULL){
                    dataPoints[i]->printOut();
                }
            }
        }

};

#endif /*ALGORITHM_H*/