#include "storage.h"
#include <iostream>
#include "utils.h"

void Storage::addMeasurement(const Measurement& m) {
	measurements.push_back(m);
}

void Storage::printAll() const {

	if (measurements.empty())
	{
		std::cerr << "PRINT FAILED: No values" << std::endl;
	}
	else
	{
		
		for (auto& m : measurements)
		{
			std::cout << m.sensorName << ", " << m.timestamp << ", " << m.value << " " << m.unit << std::endl;
		}
	}
}
std::vector<Measurement> Storage::getSensor(const std::string& sensorName) const {
	
	std::vector<Measurement> selectedSensor;   // empty list to save all measurement of selected sensor

	for (const auto& m : measurements)
	{
		if (m.sensorName == sensorName)
		{
			selectedSensor.push_back(m);
		}
	}
	return selectedSensor;
}
std::vector<float> Storage::getSensorValues(const std::string& sensorName) const {

	std::vector<float> sensorValues;   // empty list to save all measurement of selected sensor

	for (const auto& m : measurements)
	{
		if (m.sensorName == sensorName)
		{
			sensorValues.push_back(m.value);
		}
	}
	return sensorValues;
}

int Storage::count(const std::string& sensorName) const {
	auto val = getSensorValues(sensorName);
	return val.size();
}
float Storage::average(const std::string& sensorName) const {
	auto val = getSensorValues(sensorName);
	return utils::calculateAverage(val);
}
float Storage::minimum(const std::string& sensorName) const {
	auto val = getSensorValues(sensorName);
	return utils::calculateMin(val);

}
float Storage::maximum(const std::string& sensorName) const {
	auto val = getSensorValues(sensorName);
	return utils::calculateMax(val);
}
float Storage::stdDeviation(const std::string& sensorName) const {
	auto val = getSensorValues(sensorName);
	return utils::calculateStdDev(val);
}
void Storage::printSensorStatistics(const std::string& sensorName) {
	
	std::cout << "--- " << sensorName << " ---\n";

	for (const auto& m : getSensor(sensorName))
	{
		std::cout << m.timestamp << " : " << m.value << " " << m.unit << std::endl;
	}

	std::cout << "\nCount: " << count(sensorName);
	std::cout << "\nAverage: " << average(sensorName);
	std::cout << "\nMinimum value: " << minimum(sensorName);
	std::cout << "\nMaximum value: " << maximum(sensorName);
	std::cout << "\nStandard Deviation: " << stdDeviation(sensorName);
	std::cout << "\n\n";
}
