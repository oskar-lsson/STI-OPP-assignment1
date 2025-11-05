#pragma once 
#include <string>
#include <vector>
namespace utils
{
    std::string getCurrentTimestamp();

    // Statistic calculations
    float calculateAverage(const std::vector<float>& values);
    float calculateMin(const std::vector<float>& values);
    float calculateMax(const std::vector<float>& values);
    float calculateStdDev(const std::vector<float>& values);
}

