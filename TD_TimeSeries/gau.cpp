#include "headers/gau.h"

#include <random>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


using namespace std;


vector<double> GaussianGenerator::generateTimeSeries(int size) {
    vector<double> series;
    series.reserve(size);

    mt19937 rng(getSeed());
    uniform_real_distribution<double> dist(0.0, 1.0);

    for (int i = 0; i < size; ++i) {
        //Two uniform random values
        double u1 = dist(rng);
        double u2 = dist(rng);

        //Box-Muller transform
        double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        //Convert the standard normal value to the specified Gaussian distribution
        double value = mean + z0 * standardDeviation;

        series.push_back(value);
    }

    return series;
}
