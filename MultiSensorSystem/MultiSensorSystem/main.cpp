#include <iostream>
#include "sensor.h"
#include "measurement.h"

int main()
{
	Sensor temp("Temperture", "Celsius", 0, 40);
	Sensor hum("Humidity", "%", 0, 100);

	Measurement mTemp;
	Measurement mHum;

	mTemp.sensorName = temp.getName();
	mTemp.unit = temp.getUnit();
	mTemp.value = temp.read();
	mTemp.timestamp = "2022 test";

	mTemp.print();

	
}


