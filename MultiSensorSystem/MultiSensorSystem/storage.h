#pragma once
#include <vector>
#include <string>
#include "measurement.h"

class Storage
{
private:
    std::vector<Measurement> measurements;

public:
    void addMeasurement(const Measurement& m);
    void printAll() const;

    std::vector<Measurement> getSensor(const std::string& sensorName) const;        //used for sorting the vector to one sensor, later used for showing statistics

    int countFor(const std::string& sensorName) const;
    double averageFor(const std::string& sensorName) const;
    double minFor(const std::string& sensorName) const;
    double maxFor(const std::string& sensorName) const;
    double stdDevFor(const std::string& sensorName) const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

