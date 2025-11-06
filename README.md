# 🧠 Assignment 1 – Multi-Sensor System for Data Collection and Analysis

## 📋 Overview
This project is a C++ application that models a simple **IoT-like system** with multiple sensors.  
The program can **simulate measurements**, **store data**, **perform statistical analysis**, and **handle file input/output**.  
Users interact with the program through a **menu-based terminal interface**.

This project serves as the foundation for *Assignment 2*, where inheritance and polymorphism will be introduced.

---

## 🎯 Purpose
The goal of this assignment is to practice:
- Building a **multi-class C++ system** with clear separation of responsibility  
- Modeling a **sensor-based system** that collects data  
- Handling **structured data**, performing **analysis**, and **saving results**  
- Using **C++ features** such as classes, vectors, file handling, and menus  
- Writing clean, structured, and well-organized code  

---

## 🧩 Program Features
The program can:
1. Manage **multiple sensors** of different types  
2. Simulate **measurement values** within defined intervals  
3. Store each measurement in a **structured format**  
4. Perform **statistical analysis** per sensor  
5. **Read from and write to files** (CSV or text)  
6. Provide a **menu-driven terminal interface**  

---
## 🕒 Timestamps
Each measurement automatically gets a **timestamp** using the current system time (`std::chrono`).  
The timestamp is stored in the `Measurement` struct and displayed when data is printed or saved to a file.

Example format:
```
2025-11-06 20:13:45 | TempSensor 1 | 22.4 °C
```

---

## 🧱 Project Structure
```
project/
├── main.cpp
├── sensor.h / sensor.cpp
├── measurement.h / measurement.cpp
├── storage.h / storage.cpp
├── utils.h / utils.cpp
├── application.h / application.cpp   
└── README.md
```

---

## ⚙️ Classes and Structures

### **Sensor**
- Attributes:
  - `std::string name`
  - `std::string unit`
  - `float minValue`, `float maxValue`
- Method:
  - `double read()` — returns a random value within the specified range

Example:  
`TempSensor 1` with unit `"°C"` and range `[-10, 35]`

---

### **Measurement (struct)**
- `std::string sensorName`
- `std::string unit`
- `double value`
- `std::string timestamp`

Represents one individual sensor reading.

---

### **Storage**
- Contains: `std::vector<Measurement> measurements`
- Methods:
  - `addMeasurement(const Measurement&)`
  - `printAll()`
  - `calculateStatistics(sensorName)` — computes count, mean, min, max, and standard deviation
  - `saveToFile(filename)`
  - `loadFromFile(filename)`

---

## 📊 Data Analysis
For each sensor, the system can calculate:
- Number of measurements  
- Average value  
- Minimum and maximum values  
- Standard deviation  

Formatted output is displayed using `std::setprecision`.

---

## 💾 File Format
Example CSV or text format:
```
2025-10-28 09:15, Temperature, 22.5, °C
2025-10-28 09:30, Humidity, 48.0, %
```

File handling uses:
- `std::ofstream` — save data to file  
- `std::ifstream` — load data from file  

Invalid or malformed lines are skipped safely.

---

## 🧭 Menu Interface
User menu options:

| Option | Description |
|---------|-------------|
| 1 | Read new measurements from all sensors |
| 2 | Show statistics per sensor |
| 3 | Display all stored measurements |
| 4 | Save all data to file |
| 5 | Load measurements from file |
| 6 | Exit the program |

Invalid input is handled gracefully.

---

## 🧮 Example Run
```
=== Sensor System ===
1. Read new measurements
2. Show statistics
3. View all measurements
4. Save to file
5. Load from file
6. Exit
Choice: 1

Reading sensor data...
Temperature: 22.4 °C
Humidity: 45.8 %
```

---

## 🧰 Technical Requirements
- Language: **C++17** or later  
- Compiler: Visual Studio, g++, or clang++  
- Uses:
  - `std::vector`
  - `std::string`
  - `<iostream>`, `<fstream>`, `<iomanip>`
  - `<ctime>` (for timestamps)
  - `<random>` (for simulated values)

---
