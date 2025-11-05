#pragma once
#include <string>

class Sensor
{
private:
    std::string name;
    std::string unit;
    double minValue;
    double maxValue;

public:
    Sensor(const std::string& name, const std::string& unit, double minValue, double maxValue);

    std::string getName() const;
    std::string getUnit() const;
    double read() const;
};

