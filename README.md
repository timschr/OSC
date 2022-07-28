# OSC
<<<<<<< HEAD
Dieses Repository ist im Rahmen des Seminars Hot Topics in Communication Systems an der TU Berlin entstanden. Ziel ist es, zu untersuchen, wie Open Sound Control (OSC) auf unterschiedlicher Hardware mit möglichst geringen Barrieren implementiert werden kann. Zu diesem Zweck wurden mehrere Use Cases entwickelt, die einen guten Einstieg in das Thema OSC bieten. Details zur Implementierung sind im [Wiki](https://github.com/timschr/OSC/wiki) zu finden.

## Use Case 1: Hello World
Der [ESP32](https://www.espressif.com/en/products/modules/esp32) sendet ein "Hello World" an einen Computer mit OSC.

## Use Case 2: Chat
Die serielle Konsole des [ESP32](https://www.espressif.com/en/products/modules/esp32) kann verwendet werden, um eine Nachricht einzugeben und sie an einen Computer zu senden.

## Use Case (zusätzlich): IMU-Maus
Sensordaten werden über den [ESP32](https://www.espressif.com/en/products/modules/esp32) so übertragen, dass er wie eine Computermaus funktioniert. Zu diesem Zweck wird eine [Interial Measurement Unit](https://de.wikipedia.org/wiki/Inertiale_Messeinheit) an den ESP32 angeschlossen. Mit OSC werden die Sensordaten an einen OSC-Server auf dem PC gesendet, der gesteuert werden soll. 

![](assets/imu_mouse.gif)
=======
This repository is developed during the seminar Hot Topics in Communication Systems at the TU Berlin. The goal is to investigate how Open Sound Control (OSC) can be implemented on different hardware with as few barriers as possible. Initially OSC was designed for realtime music performances, it will be investigated which limits and possibilities OSC has outside the music domain. 
>>>>>>> 15193cec4e3aa85a23ce436280c5b6f9f8d326c4
