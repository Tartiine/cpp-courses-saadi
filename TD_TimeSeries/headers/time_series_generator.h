#ifndef TIME_SERIES_GENERATOR_H
#define TIME_SERIES_GENERATOR_H

#include <vector>

class TimeSeriesGenerator {
    public:
        TimeSeriesGenerator();
        TimeSeriesGenerator(int);
        std::vector<double> generateTimeSeries(int);
        void printTimeSeries(const std::vector<double>&);

    private:
        int seed;
};

#endif 
