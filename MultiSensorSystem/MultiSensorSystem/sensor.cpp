#include "sensor.h"
#include <random> 

Sensor::Sensor(const std::string& name, const std::string& unit, float minValue, float maxValue)
    : name(name), unit(unit), minValue(minValue), maxValue(maxValue){}

std::string Sensor::getName() const {
    return name;
}
std::string Sensor::getUnit() const {
    return unit;
}

float Sensor::read() const {
    std::random_device randomVal;
    std::mt19937 gen(randomVal());
    std::uniform_real_distribution<> dist(minValue, maxValue);

    return dist(gen);
}