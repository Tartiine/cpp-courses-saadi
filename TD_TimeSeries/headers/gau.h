#ifndef GAUSSIAN_GENERATOR_H
#define GAUSSIAN_GENERATOR_H

#include "tsgen.h"

using namespace std;

class GaussianGenerator : public TimeSeriesGenerator {
public:
    GaussianGenerator() : mean(0.0), standardDeviation(1.0) {}
    vector<double> generateTimeSeries(int size) override;

private:
    double mean;             
    double standardDeviation; 
};

#endif 
