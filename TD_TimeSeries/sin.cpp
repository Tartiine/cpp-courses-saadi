#include "headers/sin.h"
#include <cmath>

using namespace std;

vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    vector<double> series(size);

    for (int i = 0; i < size; ++i) {
        series[i] = amplitude * sin(frequency * i + phase);
    }

    return series;
}
