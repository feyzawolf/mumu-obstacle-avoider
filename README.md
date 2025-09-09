# mumu-obstacle-avoider
Arduino-based autonomous obstacle-avoiding vehicle with ultrasonic sensors.
This repository contains the Arduino code and supporting materials for **Mumu**, an autonomous robot vehicle designed to detect and avoid obstacles using an ultrasonic sensor.  

The project was developed as part of the *Autonomous Systems 2024* course at Tilburg University.  

## Project Overview

- **Goal**: Build a simple autonomous vehicle that navigates its environment without human control.  
- **Approach**:  
  - Ultrasonic sensor detects objects within ~30 cm.  
  - Arduino Uno microcontroller processes sensor data.  
  - DC motors adjust direction to avoid obstacles.  
- **Inspiration**: Based on Braitenberg’s “fearful” vehicle concept, where the robot moves away from detected stimuli. 

---

## Arduino Code

The main program is provided in mumu.ino .  
It controls the ultrasonic sensor and motors, enabling obstacle detection and avoidance.  

---

## Circuit Schematic

The vehicle’s wiring setup is shown in Circuit.png .  

---

## Hardware Used

- Arduino Uno microcontroller  
- Ultrasonic sensor (HC-SR04)  
- DC motors (x2) + motor controller (L293D)  
- Car chassis + wheels + caster wheel  
- Breadboard and jumper wires  
- Battery pack (4x AA batteries)  

---

## How It Works

1. Ultrasonic sensor sends pulses and measures distance to obstacles.  
2. If an obstacle is closer than 30 cm → Mumu turns to avoid it.  
3. If the path is clear → Mumu drives forward.  
4. Loop continues, allowing the robot to autonomously navigate.  

