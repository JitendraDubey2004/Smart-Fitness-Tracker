# 🏃‍♀️ Wearable Fitness Tracking System

A compact, low-power, microcontroller-based wearable device designed to monitor and record a user's fitness activities. This system is built for real-time health tracking, making it ideal for personal wellness, fitness routines, and data-driven health insights.

## 🔍 Overview

The device collects and processes live physiological and motion data such as:
- 👣 Steps Taken
- 🛣️ Distance Traveled
- ❤️ Heart Rate
- 🔥 Calories Burned

All data is measured using onboard sensors and microcontroller peripherals, and can be stored or transmitted for analysis via a mobile or web interface.

## 🧠 Key Features

- Real-time step counting using accelerometer data
- Heart rate monitoring via pulse sensor
- Calorie estimation based on user activity
- Distance tracking using step-length calibration
- Compact, power-efficient design suitable for wearable enclosures

## 🛠️ Hardware Components

- **Microcontroller**: (e.g., ATmega328P / ESP32 / STM32 / custom MCU)
- **Accelerometer**: MPU6050 / ADXL345 (for step counting and motion detection)
- **Heart Rate Sensor**: Pulse Sensor / MAX30100 / MAX30102
- **Display**: OLED or LCD (optional)
- **Power**: Li-Po battery with charging module (TP4056)
- **Communication (optional)**: Bluetooth (HC-05 / BLE) for wireless sync

## 💻 Software & Tools

- **Embedded C / Arduino / MicroPython** (based on MCU used)
- **Arduino IDE / PlatformIO / STM32CubeIDE**
- **Data Processing**: Step detection algorithm, heart rate calculation logic
- **Optional**: Mobile app integration via Bluetooth for live data view

## 🔧 How It Works

1. **Step Counter**: Uses accelerometer data to detect foot motion patterns.
2. **Heart Rate Monitor**: Uses an optical sensor to track pulses via light absorption.
3. **Calorie Estimator**: Calculates calories using MET values, heart rate, and activity.
4. **Distance Tracker**: Multiplies step count with user-calibrated step length.
5. **Data Output**: Displayed on screen or sent over Bluetooth for mobile sync.

## 📦 Folder Structure

Wearable-Fitness-Tracker/
├── firmware/ # Embedded code for MCU
│ └── main.ino / main.c
├── hardware/ # Circuit diagrams, schematics
├── docs/ # Project documentation, flowcharts
└── README.md

## 📈 Applications

- Personal fitness and health tracking
- Elderly activity monitoring
- Remote health sensing in wearable form
- Integration with fitness mobile/web apps

