#ifndef SIN_WAVE_GENERATOR_H
#define SIN_WAVE_GENERATOR_H

#include "tsgen.h"
#include <vector>

using namespace std;

class SinWaveGenerator : public TimeSeriesGenerator {
public:
    SinWaveGenerator() : amplitude(1.0), frequency(1.0), phase(0.0) {}
    vector<double> generateTimeSeries(int size) override;

private:
    double amplitude; 
    double frequency; 
    double phase;    
};

#endif 
