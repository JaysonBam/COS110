#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>

#include "DataPoint.h"
#include "DistanceFunction.h"
#include "Algorithm.h"

void printCentroid(DataPoint* centroid, int index) {
    if (centroid != NULL) {
        std::cout << "Centroid " << index << ": ";
        centroid->printOut();
    } else {
        std::cout << "Centroid " << index << ": NULL" << std::endl;
    }
}

void printGroup(GroupInfo* groups, int k) {
    for (int i = 0; i < k; i++) {
        std::cout << "Group " << i << " (" << groups->sizes[i] << " data points):" << std::endl;
        for (int j = 0; j < groups->sizes[i]; j++) {
            std::cout << "Data Point " << j << ": ";
            groups->groups[i][j]->printOut();
        }
        std::cout << std::endl;
    }
}

void studentMain()
{
    Algorithm *a1 = new Algorithm("textfile_55555.txt");
    float **centroids = new float *[3]; // Update to 3 centroids
    centroids[0] = new float[3];
    centroids[0][0] = 0.5f;
    centroids[0][1] = 4.5f;
    centroids[0][2] = 0;
    centroids[1] = new float[3];
    centroids[1][0] = 5;
    centroids[1][1] = 0.4f;
    centroids[1][2] = 1.5f;
    centroids[2] = new float[3]; // Third centroid
    centroids[2][0] = 2.0f;
    centroids[2][1] = 3.0f;
    centroids[2][2] = 1.0f;
    std::cout<<"main:"<<__LINE__<<std::endl;
    a1->setCentroids(centroids, 3, 3); // Update to 3 centroids
    std::cout<<"main:"<<__LINE__<<std::endl;
    DataPoint ***results = a1->fullRun(1, 20);
    std::cout<<"main:"<<__LINE__<<std::endl;
    if (results == NULL)
    {
        std::cout<<"main:"<<__LINE__<<std::endl;
        std::cout << "results == NULL" << std::endl;
    }
    else
    {
        std::cout<<"main:"<<__LINE__<<std::endl;
        for (int i = 0; i < 20; i++)
        {
            std::cout << "Generation: " << i << std::endl;
            if (results[i] == NULL)
            {
                std::cout << "results[" << i << "] == NULL" << std::endl;
            }
            else
            {
                for(int j=0; j < 3; j++){ // Update to 3 centroids
                    std::cout << "Centroid: " << j << std::endl;
                    if(results[i][j] == NULL){
                        std::cout << "results[" << i << "][" << j << "] == NULL" << std::endl;
                    } else {
                        results[i][j]->printOut();
                        delete results[i][j];
                        results[i][j] = NULL;
                    }
                }
                delete[] results[i];
                results[i] = NULL;
            }
        }
        delete[] results;
        results = NULL;
    }
    for(int i=0; i < 3; i++){ // Update to 3 centroids
        delete[] centroids[i];
        centroids[i] = NULL;
    }
    delete[] centroids;
    centroids = NULL;
    delete a1;
    a1 = NULL;
}

int main(int argc, char const *argv[])
{
    studentMain();
}
