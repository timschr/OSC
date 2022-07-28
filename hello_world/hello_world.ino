#include <ArduinoOSCWiFi.h>

// Wifi
char ssid[] = "bat cave";
char pwd[] = "yat@Berlin53";

// OSC
char host[] = "192.168.178.21";
int publish_port = 5005; // neighbors door

int period = 5000; // 5000ms = 5s
long timer = 0;

void setup() {
    // Serial connection
    Serial.begin(115200);  
    while (!Serial);    // wait for the serial port to open

    // WiFi connection
    WiFi.begin(ssid, pwd);
}

void loop() {
    // is called to subscribe + publish osc
    OscWiFi.update(); 
   
    // every other period (5s) send test message
    while(millis() - timer >= period){
        // Update Timer
        timer = millis();

        // Define String to send
        String send_string = "Hello World";
        
        // publish test message via OSC
        OscWiFi.send(host, publish_port, "/chat", send_string);
        // print test message
        Serial.println(send_string);
    }
}
