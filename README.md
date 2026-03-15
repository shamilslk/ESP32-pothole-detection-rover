# ESP32 Pothole Detection Rover

An autonomous rover built using **ESP32, ultrasonic sensing, and servo-based scanning** to detect potholes and avoid unsafe road surfaces.  
This project demonstrates how **embedded systems, sensors, and robotics** can be used for **smart road monitoring applications**.

---

## 📌 Project Overview

Road potholes are a major cause of vehicle damage and accidents.  
This project builds a **small autonomous rover** capable of detecting potholes using an **ultrasonic sensor** and navigating safely using a **servo scanning mechanism**.

The ESP32 processes distance data and controls the motors to **avoid potholes automatically**.

---

## ✨ Features

- Ultrasonic sensor based depth detection
- Servo motor scanning for obstacle/pothole measurement
- Autonomous rover movement
- Differential motor control
- Real-time distance measurement
- Automatic direction adjustment when pothole detected
- Expandable for IoT road monitoring

---

## 🧠 Working Principle

1. The **ultrasonic sensor** continuously measures distance from the ground.
2. The **servo motor rotates the sensor** to scan left and right.
3. The **ESP32 analyzes the measured distance values**.
4. If a pothole or sudden depth change is detected:
   - The rover stops
   - The sensor scans left and right
   - The rover chooses a safer path
5. The **motor driver controls the DC motors** to move the rover.

---

## 🧰 Hardware Components

- ESP32 Development Board
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- Motor Driver (L298N / L293D)
- DC Motors
- Robot chassis
- Li-ion battery pack
- Jumper wires

---

## ⚙️ Pin Configuration

| Component | Pin |
|-----------|-----|
| Motor ENA | 5 |
| Motor IN1 | 8 |
| Motor IN2 | 7 |
| Motor ENB | 11 |
| Motor IN3 | 4 |
| Motor IN4 | 3 |
| Servo Motor | 6 |
| Ultrasonic TRIG | 9 |
| Ultrasonic ECHO | 2 |

---

## 💻 Software Requirements

- Arduino IDE
- ESP32 Board Package
- Servo Library

---

## 🚀 Installation

Clone the repository:

```bash
git clone https://github.com/shamilslk/esp32-pothole-detection.git
