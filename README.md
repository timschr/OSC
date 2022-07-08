# OSC
This repository is developed during the seminar Hot Topics in Communication Systems at the TU Berlin. The goal is to investigate how Open Sound Control (OSC) can be implemented on different hardware with as few barriers as possible. Furthermore, the limitations and possibilities of OSC will be investigated. 

## Uee Case 1: IMU Mouse
The possibilities made possible by OSC are shown in the first use case with a very tangible example. Sensor data are transmitted via an [ESP32](https://www.espressif.com/en/products/modules/esp32) in such a way that it functions as a computer mouse. For this purpose an Interial Measurement Unit is connected to the ESP32. With OSC the sensor data are sent to an OSC server on the PC, which is to be controlled. Implementation details can be found in the [Wiki](https://github.com/timschr/OSC/wiki).


![](assets/imu_mouse.gif)
