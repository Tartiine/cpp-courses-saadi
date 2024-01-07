#include "headers/stp.h"

vector<double> StepGenerator::generateTimeSeries(int size) {
    vector<double> series(size, 0); // Initialize all elements to 0

    mt19937 rng(getSeed()); // Random number generator with seed
    uniform_int_distribution<int> distValue(0, 100); // For generating values between 0 and 100
    uniform_int_distribution<int> distChoice(0, 1); // For the 50-50 choice

    for (int i = 1; i < size; ++i) { // Start from the second element
        if (distChoice(rng) == 0) {
            // 50% chance of keeping the previous value
            series[i] = series[i - 1];
        } else {
            // 50% chance of getting a new random value
            series[i] = distValue(rng);
        }
    }

    return series;
}
