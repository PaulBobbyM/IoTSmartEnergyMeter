# AC Energy Meter using ESP32 and PZEM004T v3.0

## Description
An IoT-based AC energy meter using ESP32 and PZEM004T v3.0 to measure voltage, current, power, energy, frequency, and power factor. Data is transmitted via Wi-Fi to the Blynk platform for real-time monitoring and analysis of electrical parameters.

---

## Overview
This project implements a Wi-Fi-enabled AC energy monitoring system using an ESP32 microcontroller and a PZEM004T v3.0 energy sensor. The system measures key electrical parameters, including voltage, current, power, energy consumption, frequency, and power factor, and sends them to the Blynk IoT platform for visualisation.  
It serves as a practical demonstration of IoT-based power measurement for smart homes, industrial, and academic applications.

---

## Hardware Requirements

| Component | Description |
|------------|-------------|
| ESP32 Dev Board | Wi-Fi-enabled microcontroller for IoT communication |
| PZEM004T v3.0 | Energy meter module for AC measurements |
| AC Load or Source | Input for measurement testing |
| Connecting Wires | For interfacing ESP32 and PZEM module |
| Power Supply | 5V via USB or adapter |

---

## Circuit Connections

| PZEM004T v3.0 Pin | ESP32 Pin |
|--------------------|-----------|
| RX | GPIO 16 |
| TX | GPIO 17 |
| VCC | 5V |
| GND | GND |

**Note:** The PZEM004T measures live AC voltage and current. Ensure electrical safety and proper isolation during testing.

---

## Software Requirements

- Arduino IDE  
- ESP32 Board Package  
- Required Libraries:  
  - WiFi.h  
  - BlynkSimpleEsp32.h  
  - PZEM004Tv30.h  

---

## Working Principle
The ESP32 communicates with the PZEM004T v3.0 energy meter via UART. The module provides real-time readings of AC electrical parameters, which are then validated and transmitted over Wi-Fi to the Blynk IoT cloud. The data can be monitored through the Blynk dashboard on a web interface or mobile app.



