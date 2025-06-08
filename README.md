# Air-Pollution-Monitoring-System

# Air Pollution Monitoring System using ESP32 and IoT 🌍💨

## 📋 Project Overview

The **Air Pollution Monitoring System** is a real-time, portable, and low-cost solution designed to monitor and report environmental air quality. It uses an ESP32 microcontroller integrated with various gas sensors and the Blynk IoT platform to collect, display, and transmit pollutant data such as CO, CO₂, smoke, temperature, and humidity. The system is designed to raise awareness, help reduce health risks, and support smart city infrastructure by providing accurate, mobile air quality data.

---

## 🧠 Motivation

Air pollution is a growing global issue, especially in urban areas. Traditional monitoring stations are expensive and stationary, limiting access to real-time, localized pollution data. Our project leverages IoT to deliver an affordable and mobile alternative, empowering individuals and authorities to make informed decisions.

---

## 🎯 Objectives

- Detect key air pollutants (CO, CO₂, smoke, NH₃) and environmental parameters (temperature and humidity).
- Display real-time sensor data on an LCD and a mobile dashboard.
- Transmit data to the cloud for remote access and historical analysis.
- Provide alerts when pollution levels exceed safe thresholds.

---

## 🧰 Technologies & Tools Used

### 🖥️ Hardware
- **ESP32** – Microcontroller with built-in Wi-Fi
- **MQ135 Sensor** – Detects CO₂, NH₃, Benzene, etc.
- **MQ2 Sensor** – Detects smoke and LPG
- **MQ7 Sensor** – Detects Carbon Monoxide
- **DHT11 Sensor** – Measures temperature and humidity
- **16x2 LCD (I2C)** – For local real-time display
- **Power Source** – USB or Battery Pack

### 💻 Software
- **Arduino IDE** – Firmware development
- **Blynk IoT Platform** – Cloud integration and mobile app
- **Firebase (optional)** – For data logging and visualization
- **MIT App Inventor (optional)** – For custom app development

---

## 📦 Features

- 📲 **Mobile Dashboard** – View live readings on Android/iOS via Blynk
- 📊 **Local Display** – LCD shows gas concentrations, temperature, and humidity
- 📡 **Cloud Sync** – Real-time wireless data transmission
- 🚨 **Threshold Alerts** – Instant warnings when pollutant levels are dangerous
- 🔋 **Portable** – Can run on power banks for field use
- 🌐 **Smart City Ready** – Scalable for broader deployment


