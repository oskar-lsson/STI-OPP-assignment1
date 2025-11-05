#include <iostream>
#include "sensor.h"
#include "measurement.h"
#include "storage.h"

int main()
{
	Sensor temp("Temperture", "Celsius", 0, 40);
	Sensor hum("Humidity", "%", 0, 100);
	Storage storage;

	Measurement measurements;
	for (size_t i = 0; i < 10; i++)
	{
		measurements.sensorName = temp.getName();
		measurements.unit = temp.getUnit();
		measurements.value = temp.read();
		measurements.timestamp = "2022 test";
		storage.addMeasurement(measurements);
	}
	storage.printAll();
	
}


