#ifndef TIME_SERIES_DATASET_H
#define TIME_SERIES_DATASET_H

#include <vector>
#include <stdexcept>

using namespace std;

class TimeSeriesDataset {
    public:
        TimeSeriesDataset(bool zNormalize = false, bool isTrain = false);
        void addTimeSeries(const vector<double>& series, int label);
        void addTimeSeries(const vector<double>& series);
        int getNumberOfSamples() const {
            return numberOfSamples;
        }
        int getMaxLength() const {
            return maxLength;
        }
        vector<double> getData(int i) const {
            if (i >= numberOfSamples) {
                throw out_of_range("Index out of range");
            }
            vector<double>::const_iterator start = data.begin() + i * maxLength;
            vector<double>::const_iterator end = start + maxLength;
            return vector<double>(start, end);
        }

        int getLabel(int i) const {
            if (i >= labels.size()) {
                throw out_of_range("Index out of range");
            }
            return labels[i];
        }

    private:
        bool znormalize;           
        bool isTrain;              
        vector<double> data;  
        vector<int> labels;   
        int maxLength;             
        int numberOfSamples;       
};

#endif 
