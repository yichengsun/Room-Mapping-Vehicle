# Room Mapping Vehicle
![Picture](https://raw.githubusercontent.com/yichengsun/Room-Mapping-Vehicle/master/CAD%20Files/car.png) 

*On left, the autonomous vehicle. On right, room visualization with obstacles marked in red, car in blue, and unexplored regions in black.*

## Table of Contents

* [Team Members](#team-members)
* [Introduction](#introduction)
* [Speed Control](#steering-control)
* [Steering Control](#navigation-control)
* [Ultrasonic Visualization](#ultrasonic-visualization)

## Team Members
* "Yicheng Sun" <yichengs@princeton.edu>
* "Edgar Wang" <edgarw@princeton.edu>

## Introduction
This work was done as part of ELE302, a Princeton electrical engineering class on designing complex electronic systems. As part of the final project, we constructed an RC-sized car that uses ultrasound to map out a room. The data collected was then analyzed in Python and visualized using Processing. The car can also had autonomous speed and steering control systems with the extended capabilities of being able to be driven by a laptop via bluetooth.

## Speed Control
>The purpose of this project is to deconstruct an RC car and replace the built-in radio receiver with an autonomous speed controller. We implemented a proportional-integral-derivative feedback controller using a PSOC microprocessor to drive the car at a constant 3 m/s on uphills, downhills, and across flat surfaces... The critical components involved in are the power regulator board, sensor interface board, speed control board, and PSOC PID control code.

Pictures and full details can be found in **[report #1](https://github.com/yichengsun/Room-Mapping-Vehicle/raw/master/Report%20%231%20Speed%20control.pdf)**.

## Steering Control
>The purpose of this project is to create a system to allow the car to follow a closed track autonomously. The car must travel at a 3 ft/s speed or faster, make turns of 3 foot radius, and complete the track twice. In order to do this we installed a VGA camera for line detection and implemented PD control to center the car on the line as it moves forward. This is broken into three parts, the camera and sync separator, hardware comparator and data reading with PSOC, and PD control code.

Pictures and full details can be found in **[report #2](https://github.com/yichengsun/Room-Mapping-Vehicle/raw/master/Report%20%232%20Steering%20control.pdf)**.

## Ultrasonic Visualization
>We built a car that constructs a two dimensional floor map as it travels across the room via commands sent through bluetooth.
>
>Hardware wise, this was done with the following additions:
>* Ultrasonic sensor to detect obstacles
>* Rotary encoders for differential odometry
>* Arduino for control and calculations
>* Bluetooth module for remote control and data sending
>* H-bridge for backwards driving.

>In software, we wrote code for the following: 
>* Position tracking with error correction
>* Obstacle detection with error correction
>* Laptop controlled remote navigation control
>* Data processing with python
>* Visualization with Processing


Pictures and full details can be found in **[report #3](https://github.com/yichengsun/Room-Mapping-Vehicle/raw/master/Report%20%233%20Room%20Mapping.pdf)**.
