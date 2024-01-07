#ifndef KNN_H
#define KNN_H

#include "tsdata.h"
#include <string>
#include <vector>

using namespace std;

class KNN {
    public:
        KNN(int k, string similarityMeasure);
        double evaluate(const TimeSeriesDataset& trainData, 
                        const TimeSeriesDataset& testData, 
                        const vector<int>& groundTruth);

    private:
        int k;
        string similarityMeasure;

};

#endif
