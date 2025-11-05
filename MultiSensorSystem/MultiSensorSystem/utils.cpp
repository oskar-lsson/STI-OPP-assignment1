#include "utils.h"
#include <chrono>   
#include <ctime>    
#include <cmath>    
#include <numeric> 

namespace utils {
    std::string getCurrentTimestamp() {
        return "2025-11-05 16:00";
    }

    // Statistic calculations
    float calculateAverage(const std::vector<float>& values)
    {
        double sum = std::accumulate(values.begin(), values.end(), 0.0);
        return values.empty() ? 0.0 : sum / values.size();
    }
    float calculateMin(const std::vector<float>& values)
    {
        return *std::min_element(values.begin(), values.end());
    }
    float calculateMax(const std::vector<float>& values)
    {
        return *std::max_element(values.begin(), values.end());
    }
    float calculateStdDev(const std::vector<float>& values) 
    {
        if (values.empty()) return 0.0;

        double mean = calculateAverage(values);
        double var = 0.0;
        for (double v : values)
        {
            var += std::pow(v - mean, 2);
        }
        return std::sqrt(var / values.size());
    }
}