# OSC
This repository is developed during the seminar Hot Topics in Communication Systems at the TU Berlin. The goal is to investigate how Open Sound Control (OSC) can be implemented on different hardware with as few barriers as possible. For this purpose, several use cases were developed that offer a good introduction to the topic of OSC. Implementation details can be found in the [Wiki](https://github.com/timschr/OSC/wiki).

## Use Case 1: Hello World
The [ESP32](https://www.espressif.com/en/products/modules/esp32) transmits a "Hello World" to a computer with OSC.

## Use Case 2: Chat
The serial console of the [ESP32](https://www.espressif.com/en/products/modules/esp32) can be used to input a message and send it to a computer.

## Use Case (Additional): IMU Mouse
Sensor data are transmitted via the [ESP32](https://www.espressif.com/en/products/modules/esp32) in such a way that it functions as a computer mouse. For this purpose an [Interial Measurement Unit](https://de.wikipedia.org/wiki/Inertiale_Messeinheit) is connected to the ESP32. With OSC the sensor data are sent to an OSC server on the PC, which is to be controlled. 

![](assets/imu_mouse.gif)
