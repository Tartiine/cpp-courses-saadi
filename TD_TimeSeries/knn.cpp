#include "headers/knn.h"
#include <vector>
#include <cmath>  
#include <stdexcept>
#include <algorithm>
#include <unordered_map>

using namespace std;

double euclideanDistance(const vector<double>& x, const vector<double>& y) {
    if (x.size() != y.size()) {
        throw invalid_argument("Time series must be of the same length");
    }

    double sumSq = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        sumSq += pow(x[i] - y[i], 2);
    }

    return sqrt(sumSq);
}


double dynamicTimeWarping(const vector<double>& x, const vector<double>& y) {
    size_t Lx = x.size();
    size_t Ly = y.size();

    vector<vector<double>> D(Lx + 1, vector<double>(Ly + 1, numeric_limits<double>::infinity()));

    D[0][0] = 0;

    for (size_t i = 1; i <= Lx; ++i) {
        for (size_t j = 1; j <= Ly; ++j) {
            double d = pow(x[i - 1] - y[j - 1], 2);
            D[i][j] = d + min({D[i][j-1],   
                                       D[i][j-1],    
                                       D[i-1][j-1]}); 
        }
    }

    return sqrt(D[Lx][Ly]);
}



KNN::KNN(int k, string similarityMeasure)
    : k(k), similarityMeasure(move(similarityMeasure)) {}

double KNN::evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& groundTruth) {
    int correctPredictions = 0;
    double accuracy = 0.0;
    
    for (size_t i = 0; i < testData.getNumberOfSamples(); ++i) {
        vector<pair<double, int>> distances;

        for (size_t j = 0; j < trainData.getNumberOfSamples(); ++j) {
            double distance;
            if (similarityMeasure == "euclidean_distance") {
                distance = euclideanDistance(testData.getData(i), trainData.getData(j));
            } else if (similarityMeasure == "dtw") {
                distance = dynamicTimeWarping(testData.getData(i), trainData.getData(j));
            } else {
                throw invalid_argument("Invalid term for similarity");
            }
            distances.emplace_back(distance, trainData.getLabel(j));
        }

        sort(distances.begin(), distances.end());

        unordered_map<int, int> labelCounts;
        for (int neighbor = 0; neighbor < k && neighbor < distances.size(); ++neighbor) {
            labelCounts[distances[neighbor].second]++;
        }

        int predictedLabel = max_element(labelCounts.begin(), labelCounts.end(),
                                         [](const pair<int, int>& a, const pair<int, int>& b) {
                                             return a.second < b.second; })->first;

        if (predictedLabel == groundTruth[i]) {
            ++correctPredictions;
        }
    }

    accuracy = static_cast<double>(correctPredictions) / testData.getNumberOfSamples();

    return accuracy;
}

