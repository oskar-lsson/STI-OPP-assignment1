#include "storage.h"
#include "iostream"

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
	
	std::vector<Measurement> result;   // empty list to save all measurement of selected sensor

	for (const auto& m : measurements)
	{
		if (m.sensorName == sensorName)
		{
			result.push_back(m);
		}
	}
	return result;
}

int Storage::count(const std::string& sensorName) const {

}
float Storage::average(const std::string& sensorName) const {
}
float Storage::minimum(const std::string& sensorName) const {

}
float Storage::maximum(const std::string& sensorName) const {

}
float Storage::stdDeviation(const std::string& sensorName) const {

}
