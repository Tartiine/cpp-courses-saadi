#include "headers/tsdata.h"
#include <cmath>
#include <numeric>

using namespace std;

TimeSeriesDataset::TimeSeriesDataset(bool zNormalize, bool isTrain)
    : znormalize(zNormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label) {
    vector<double> normalizedSeries;

    if (znormalize) {
        double mean = accumulate(series.begin(), series.end(), 0.0) / series.size();
        double sqSum = inner_product(series.begin(), series.end(), series.begin(), 0.0);
        double stdDev = sqrt(sqSum / series.size() - mean * mean);

        normalizedSeries.reserve(series.size());
        for (const auto& value : series) {
            normalizedSeries.push_back((value - mean) / stdDev);
        }
    } else {
        normalizedSeries = series;
    }

    data.insert(data.end(), normalizedSeries.begin(), normalizedSeries.end());
    labels.push_back(label);
    maxLength = max(maxLength, static_cast<int>(normalizedSeries.size()));
    ++numberOfSamples;
}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series) {
    vector<double> normalizedSeries;

    if (znormalize) {
        double mean = accumulate(series.begin(), series.end(), 0.0) / series.size();
        double sqSum = inner_product(series.begin(), series.end(), series.begin(), 0.0);
        double stdDev = sqrt(sqSum / series.size() - mean * mean);

        normalizedSeries.reserve(series.size());
        for (const auto& value : series) {
            normalizedSeries.push_back((value - mean) / stdDev);
        }
    } else {
        normalizedSeries = series;
    }

    data.insert(data.end(), normalizedSeries.begin(), normalizedSeries.end());
    maxLength = max(maxLength, static_cast<int>(normalizedSeries.size()));
    ++numberOfSamples;
}