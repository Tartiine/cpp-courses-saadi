#ifndef STEP_GENERATOR_H
#define STEP_GENERATOR_H

#include "tsgen.h"
#include <vector>
#include <random>

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator() {}
    vector<double> generateTimeSeries(int size) override;
};

#endif
