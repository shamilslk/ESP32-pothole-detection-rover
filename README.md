ESP32 Pothole Detection Rover

An autonomous rover built using ESP32, ultrasonic sensing, and servo-based scanning to detect potholes on roads and avoid them.
This project demonstrates how embedded systems and robotics can be used for smart road monitoring and hazard detection.

---

📌 Features

- Ultrasonic sensor based pothole detection
- Servo motor scanning for obstacle measurement
- Autonomous rover movement
- Differential motor control using motor driver
- Real-time distance measurement
- Automatic direction adjustment when pothole detected
- Designed for smart city / road monitoring applications

---

🧠 Working Principle

1. The ultrasonic sensor continuously measures the distance between the rover and the ground/obstacle.
2. The servo motor rotates the sensor to scan the surroundings.
3. The ESP32 processes the distance values.
4. If a pothole or sudden depth change is detected:
   - The rover stops
   - Scans left and right
   - Chooses a safer direction
5. Motors are controlled using a motor driver module.

---

🧰 Hardware Components

- ESP32 Development Board
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- Motor Driver (L298N / L293D)
- DC Motors with wheels
- Robot chassis
- Li-ion battery pack
- Jumper wires

---

⚙️ Pin Configuration

Component| ESP32 Pin
Motor ENA| 5
Motor IN1| 8
Motor IN2| 7
Motor ENB| 11
Motor IN3| 4
Motor IN4| 3
Servo Motor| 6
Ultrasonic TRIG| 9
Ultrasonic ECHO| 2

---

💻 Software Requirements

- Arduino IDE
- ESP32 Board Package
- Servo Library

---

🚀 How to Run

1. Clone the repository

git clone https://github.com/shamilslk/esp32-pothole-detection.git

2. Open the project in Arduino IDE

3. Install required libraries

- Servo.h

4. Select the correct ESP32 board and COM port

5. Upload the code to the ESP32

---

📷 Project Demo

Add images or videos of your rover here.

Example:

/images/rover.jpg
/images/working.gif

---

🔮 Future Improvements

- GPS tagging of pothole locations
- IoT cloud reporting
- Camera-based pothole detection using OpenCV
- Mobile app monitoring dashboard

---

👨‍💻 Author

Shamil K
B.Tech Electronics and Communication Engineering
NSS College of Engineering, Palakkad

---

⭐ Contribution

Feel free to fork this repository and improve the project.
Pull requests are welcome.

---
