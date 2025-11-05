#pragma once
#include <string>

class Sensor
{
private:
    std::string name;
    std::string unit;
    float minValue;
    float maxValue;

public:
    Sensor(const std::string& name, const std::string& unit, float minValue, float maxValue);

    std::string getName() const;
    std::string getUnit() const;
    float read() const;
};

