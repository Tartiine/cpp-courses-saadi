#ifndef TIME_SERIES_GENERATOR_H
#define TIME_SERIES_GENERATOR_H

#include <vector>

using namespace std;

class TimeSeriesGenerator {
    public:
        TimeSeriesGenerator();
        TimeSeriesGenerator(int);
        virtual vector<double> generateTimeSeries(int);
        void printTimeSeries(const vector<double>&);
        int getSeed() const { return seed; }
    private:
        int seed;
};

#endif 
