#include "application.h"
#include "utils.h"
#include <iostream>
#include <limits> 
#include <iomanip>

Application::Application() : running(true)  //for creating senor objects
{

    sensors.emplace_back("Temperature", "\u00B0C", 10.0f, 35.0f);
    sensors.emplace_back("Humidity", "%", 30.0f, 80.0f);
}

void Application::run()
{
    while (running)
    {
        showMenu();

        int choice;
        std::cin >> choice;

        // input validation
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        // clear leftover newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        clearWindow();
        switch (choice)
        {
        case 1:
            handleReadMeasurements();
            break;
        case 2:
            handleShowStatistics();
            break;
        case 3:
            handleShowAll();
            break;
        case 4:
            handleSaveToFile();
            break;
        case 5:
            handleLoadFromFile();
            break;
        case 6:
            std::cout << "Exiting program.\n";
            running = false;
            break;
        default:
            std::cout << "Invalid option. Try again.\n";
            break;
        }
    }
}

void Application::showMenu()
{
    std::cout << "\n=====  SENSOR MENU  =====\n";
    std::cout << "[1] Read new measurements\n";
    std::cout << "[2] Show statistics\n";
    std::cout << "[3] Show all measurements\n";
    std::cout << "[4] Save measurements to file\n";
    std::cout << "[5] Load measurements from file\n";
    std::cout << "[6] Exit\n";
    std::cout << "Select option: ";
}

void Application::handleReadMeasurements()
{
    std::cout << "\nReading new measurements...\n";

    for (const auto& sensor : sensors)
    {
        Measurement m;
        m.sensorName = sensor.getName();
        m.unit = sensor.getUnit();
        m.value = sensor.read();
        m.timestamp = utils::getCurrentTimestamp();

        storage.addMeasurement(m);

        std::cout << sensor.getName() << ": "
            << std::fixed << std::setprecision(2) << m.value << " " << m.unit << "\n";
    }

    std::cout << "Measurements added successfully.\n";
}

void Application::handleShowStatistics()
{
    std::cout << "\n--- STATISTICS PER SENSOR ---\n";
    for (const auto& sensor : sensors)
    {
        storage.printSensorStatistics(sensor.getName());
    }
}

void Application::handleShowAll()
{
    std::cout << "\n--- ALL MEASUREMENTS ---\n";
    std::cout << std::left << std::setw(20) << "Timestamp"
        << std::setw(15) << "Sensor"
        << std::right << std::setw(10) << "Value"
        << std::setw(8) << "Unit" << std::endl;
    std::cout << std::setfill('-') << std::setw(53) << "-" << std::setfill(' ') << std::endl;
    storage.printAll();
}

void Application::handleSaveToFile()
{
    std::string filename;
    std::cout << "Enter filename to save (e.g. data.txt): ";
    std::getline(std::cin, filename);

    storage.saveToFile(filename);
    std::cout << "Data saved to " << filename << "\n";
}

void Application::handleLoadFromFile()
{
    std::string filename;
    std::cout << "Enter filename to load: ";
    std::getline(std::cin, filename);

    storage.loadFromFile(filename);
    std::cout << "Data loaded from " << filename << "\n";
}
void Application::clearWindow() {
    std::cout << "\x1B[2J \x1B[H";
}
