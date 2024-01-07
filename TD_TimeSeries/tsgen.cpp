#include "headers/tsgen.h"
#include <iostream>
#include <vector>
#include <random>
using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}


TimeSeriesGenerator::TimeSeriesGenerator(int s) : seed(s) {}

vector<double> TimeSeriesGenerator::generateTimeSeries(int size) {
    vector<double> series(size);
    mt19937 rng(seed);
    uniform_real_distribution<double> dist(0.0, 1.0);

    for (int i = 0; i < size; ++i) {
        series[i] = dist(rng);
    }

    return series;
}

void TimeSeriesGenerator::printTimeSeries(const vector<double>& series) {
    for (double value : series) {
        cout << value << " ";
    }
    cout << endl;
}