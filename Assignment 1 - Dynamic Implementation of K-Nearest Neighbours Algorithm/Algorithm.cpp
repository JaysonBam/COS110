#include "Algorithm.h"

int GetLineSize(std::string line){
    int result;
    result = 0;
    int i;
    int size;
    size = line.length();
    for (i = 0; i < size; i++){
        if (line[i]=='(') 
            result++;
    }
    return result;
}

int GetFileSize(std::string textfile){
    int result;
    result = 0;
    std:: fstream myFile(textfile.c_str ());
    std::string line;
    while (std::getline(myFile ,line))
        result += GetLineSize(line);
    myFile.close();
    return result;
}

float GetDistance(DataPoint* dpA, DataPoint* dpB,int distanceMetric){
    switch (distanceMetric)
    {
    case 0:return DistanceFunction::ManhattanDistance(dpA,dpB);
           break;

    case 1:return DistanceFunction::EuclideanDistance(dpA,dpB);
           break;

    case 2:return DistanceFunction::ChebyshevDistance(dpA,dpB);
           break;
    default: return INFINITY;
             break;
    }
}

Algorithm::Algorithm(std::string textfile) {
    numberOfDataPoints = GetFileSize(textfile);
    k = -1;
    centroids = NULL;

    std::fstream myFile(textfile.c_str());
    std::string line;
    int dp_counter;
    dp_counter = 0;
    dataPoints = new DataPoint*[numberOfDataPoints];
    while (std::getline(myFile ,line))
    {
        if (line.length()!=0){
            while (line.find('(') != std::string::npos){
                dataPoints[dp_counter] = new DataPoint(line.substr(0,line.find(')')+1));
                dp_counter++;
                line.erase(0,line.find(')')+1);
            }
        }
    }
    myFile.close();
}

Algorithm::Algorithm(DataPoint** dps, int numberOfDataPoints) {
    int i;
    k = -1;
    centroids = NULL;

    if (dps == NULL) {
        this->numberOfDataPoints = 0;
    } else {
        if (numberOfDataPoints < 0) {
            this->numberOfDataPoints = 0;
        } else {
            this->numberOfDataPoints = numberOfDataPoints;
        }
    }

    dataPoints = new DataPoint*[this->numberOfDataPoints];
    for (i = 0; i < this->numberOfDataPoints; i++) {
        if (dps[i] != NULL) {
            dataPoints[i] = new DataPoint(dps[i]);
        } else {
            dataPoints[i] = NULL;
        }
    }
}


Algorithm::Algorithm(Algorithm* other) {
    k = -1;
    centroids = NULL;

    if (other == NULL) {
        numberOfDataPoints = 0;
    } else {
        numberOfDataPoints = other->numberOfDataPoints;
    }

    dataPoints = new DataPoint*[numberOfDataPoints];
    for (int i = 0; i < numberOfDataPoints; i++) {
        dataPoints[i] = other->dataPoints[i]->clone();
    }
}


Algorithm::~Algorithm() {
    for (int i = 0; i < numberOfDataPoints;i++)
       if (dataPoints[i] != NULL)
          delete dataPoints[i];

    if (dataPoints!=NULL)
        delete[] dataPoints;
    dataPoints = NULL;

    for (int i = 0; i < k;i++)
       if (centroids[i] != NULL)
          delete centroids[i];

    if (centroids!=NULL)
        delete[] centroids;
    centroids = NULL; 
}

int Algorithm::getNumDataPoints() const {
    return numberOfDataPoints;
}

DataPoint** Algorithm::getDataPoints() const {
    return dataPoints;
}

DataPoint** Algorithm::getCentroids() const {
    return centroids;
}

DataPoint** Algorithm::setCentroids(float** rawCentroidPositions, int k, int numAttributes) {
    DataPoint** oldCentroid;
    if (rawCentroidPositions == NULL) {
        oldCentroid = NULL;
        return oldCentroid;
    } else {
        if (k < 0) {
            oldCentroid = NULL;
            return oldCentroid;
        } else {
            if (centroids == NULL) {
                oldCentroid = NULL;
            } else {
                if (this->k < 0) {
                    oldCentroid = NULL;
                } else {
                    oldCentroid = new DataPoint*[this->k];
                    for (int i = 0; i < this->k; i++) {
                        oldCentroid[i] = new DataPoint(centroids[i]);
                    }
                }
            }
        }

        if (centroids != NULL) {
            for (int i = 0; i < this->k; i++) {
                delete centroids[i];
            }
            delete[] centroids;
        }

        this->k = k;
        centroids = new DataPoint*[k];
        for (int i = 0; i < k; i++) {
            centroids[i] = new DataPoint(rawCentroidPositions[i], numAttributes);
        }
    }

    return oldCentroid;
}


GroupInfo* Algorithm::formGroup(int distanceMetric) {
    GroupInfo* result;
    result = new GroupInfo;
    result->sizes = new int[k];
    for (int i = 0; i < k; i++) result->sizes[i] = 0;

    //Get sizes
    for (int d = 0; d < numberOfDataPoints; d++) {
        float closest;
        closest = INFINITY;
        int closestCen;
        closestCen = 0;
        
        for (int c = 0; c < k; c++) {
            float dist = GetDistance(dataPoints[d], centroids[c], distanceMetric);
            if (dist < closest) {
                closest = dist;
                closestCen = c;
            }
        }
        result->sizes[closestCen]++;
    }

    //Populate groups
    result->groups = new DataPoint**[k];
    for (int i = 0; i < k; i++) {
        result->groups[i] = new DataPoint*[result->sizes[i]];
    }

    int* counter;
    counter = new int[k];
    for (int i = 0; i < k; i++) counter[i] = 0;

    for (int d = 0; d < numberOfDataPoints; d++) {
        float closest;
        closest = INFINITY;
        int closestCen;
        closestCen = 0;

        for (int c = 0; c < k; c++) {
            float dist = GetDistance(dataPoints[d], centroids[c], distanceMetric);
            if (dist < closest) {
                closest = dist;
                closestCen = c;
            }
        }
        result->groups[closestCen][counter[closestCen]++] = dataPoints[d];
    }

    delete[] counter;
    return result; 
}

DataPoint* Algorithm::averagePositionOfGroup(DataPoint** group, int size) const {
    DataPoint* result = NULL;
    
    if (group != NULL) {
        if (size > 0) {
            int numAttributes = group[0]->getNumberOfAttributes();

            float* avg = new float[numAttributes];
            for (int i = 0; i < numAttributes; i++) {
                avg[i] = 0;
            }

            for (int i = 0; i < size; i++) {
                if (group[i] != NULL) {
                    for (int a = 0; a < numAttributes; a++) {
                        avg[a] += group[i]->getAttributes()[a];
                    }
                }
            }

            for (int a = 0; a < numAttributes; a++) {
                avg[a] /= size;
            }

            result = new DataPoint(avg, numAttributes);
            delete[] avg;
        }
    }
    
    return result;
}


DataPoint** Algorithm::singleRun(int distanceMetric) {
    DataPoint** result = NULL;

    if (centroids != NULL) {
        if (k >= 0) {
            GroupInfo* g = this->formGroup(distanceMetric);

            // Getting Averages DataPoints
            DataPoint** avgDataPoints = new DataPoint*[k];
            for (int i = 0; i < k; i++) {
                avgDataPoints[i] = averagePositionOfGroup(g->groups[i], g->sizes[i]);
            }

            // Turning Average DataPoint to average "floats"
            float** avgCentroids = new float*[k];
            for (int c = 0; c < k; c++) {
                int numAttributes = centroids[c]->getNumberOfAttributes();
                avgCentroids[c] = new float[numAttributes];
                if (avgDataPoints[c] == NULL) {
                    for (int a = 0; a < numAttributes; a++) {
                        avgCentroids[c][a] = centroids[c]->getAttributes()[a];
                    }
                } else {
                    for (int a = 0; a < numAttributes; a++) {
                        avgCentroids[c][a] = avgDataPoints[c]->getAttributes()[a];
                    }
                }
            }

            // Set centroids
            DataPoint** oldCentroids = this->setCentroids(avgCentroids, this->k, centroids[0]->getNumberOfAttributes());
            if (oldCentroids != NULL) {
                for (int i = 0; i < k; i++) {
                    if (oldCentroids[i] != NULL) {
                        delete oldCentroids[i];
                    }
                }
                delete[] oldCentroids;
            }

            // Clean up memory
            for (int i = 0; i < k; i++) {
                if (avgDataPoints[i] != NULL) {
                    delete avgDataPoints[i];
                    avgDataPoints[i] = NULL;
                }
                if (avgCentroids[i] != NULL) {
                    delete[] avgCentroids[i];
                    avgCentroids[i] = NULL;
                }
            }
            delete[] avgDataPoints;
            delete[] avgCentroids;

            for (int i = 0; i < k; i++) {
                if (g->groups[i] != NULL) {
                    delete[] g->groups[i];
                    g->groups[i] = NULL;
                }
            }
            delete[] g->groups;
            delete[] g->sizes;
            delete g;

            result = centroids;
        }
    }

    return result;
}

DataPoint*** Algorithm::fullRun(int distanceMetric, int numberOfIterations) {
    DataPoint*** result = NULL;

    if (centroids != NULL) {
        if (k >= 0 && numberOfIterations >= 0) {
            result = new DataPoint**[numberOfIterations];
            for (int i = 0; i < numberOfIterations; i++) {
                result[i] = new DataPoint*[k];
                singleRun(distanceMetric);
                for (int j = 0; j < k; j++) {
                    result[i][j] = centroids[j]->clone();
                }
            }
        }
    }

    return result;
}