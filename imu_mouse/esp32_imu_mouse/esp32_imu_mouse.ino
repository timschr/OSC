#include <ArduinoOSCWiFi.h>
#include <BMI160Gen.h>
#include<Wire.h>

float gx, gy, gz;
long timer = 0;

char ssid[] = "bat cave";
char pwd[] = "yat@Berlin53";
char host[] = "192.168.178.21";
int publish_port = 5005;

void setup() {
    // Serial connection
    Serial.begin(9600);  
    while (!Serial);    // wait for the serial port to open
    // BEgin I2C
    Wire.begin(21,22);  
    // WiFi connection
    WiFi.begin(ssid, pwd);

    // initialize IMU
    Serial.println("Initializing IMU device...");
    //BMI160.begin(BMI160GenClass::SPI_MODE, /* SS pin# = */10);
    BMI160.begin(BMI160GenClass::I2C_MODE);
    uint8_t dev_id = BMI160.getDeviceID();
    Serial.print("DEVICE ID: ");
    Serial.println(dev_id, HEX);
  
     // Set the accelerometer range to 250 degrees/second
    BMI160.setGyroRange(250);
    Serial.println("Initializing IMU device...done.");
  
    // set up OSC publish function
    OscWiFi.publish(host, publish_port, "/imu", gx, gy, gz)
        ->setFrameRate(20); // set transmission rate per second
}

void loop() {
    // should be called to subscribe + publish osc
    OscWiFi.update(); 

    if (millis() - timer > 50){
      // raw gyro values
      int gxRaw, gyRaw, gzRaw;  
       
      // read raw gyro measurements from device
      
      BMI160.readGyro(gxRaw, gyRaw, gzRaw);
      // convert the raw gyro data to degrees/second
      gx = convertRawGyro(gxRaw);
      gy = convertRawGyro(gyRaw);
      gz = convertRawGyro(gzRaw);
      timer = millis();
    }
    
}

float convertRawGyro(int gRaw) {
  // since we are using 250 degrees/seconds range
  // -250 maps to a raw value of -32768
  // +250 maps to a raw value of 32767

  float g = (gRaw * 250.0) / 32768.0;

  return g;
}
