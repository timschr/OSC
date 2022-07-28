#include <ArduinoOSCWiFi.h>

// Wifi
char ssid[] = "bat cave";
char pwd[] = "yat@Berlin53";

// OSC
char host[] = "192.168.178.21";
int publish_port = 5005; // neighbors door

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

   //Check if there is new input from Serial
   if (Serial.available()) { 
    
      // read Serial message to String
      String send_string = Serial.readString();
      
      // publish read message via OSC
      OscWiFi.send(host, publish_port, "/chat", send_string);
      Serial.println(send_string);
   } 
}
