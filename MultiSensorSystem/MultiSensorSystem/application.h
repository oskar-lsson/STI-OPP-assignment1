#pragma once
#include <vector>
#include <string>
#include "sensor.h"
#include "storage.h"

class Application
{
private:
    Storage storage;
    std::vector<Sensor> sensors;
    bool running;

    void showMenu();
    void handleReadMeasurements();
    void handleShowStatistics();
    void handleShowAll();
    void handleSaveToFile();
    void handleLoadFromFile();
    void clearWindow();

public:
    Application();
    void run();
};
