/*******************************************************************
 *  A simple sketch for forwarding data and responses from       
 *  the harwdware serial conneciton of an ESP8266 to the
 *  a software one and vice versa
 *                         
 *  I'm using this to communicate with a bluetooth module (HC-06)
 *                                                                 
 *  Written by Brian Lough - https://www.youtube.com/channel/UCezJOfu7OtqGzd5xrP3q6WA                                        
 *******************************************************************/

#include <SoftwareSerial.h>

#define RX_PIN D2 // connect to TXD of module
#define TX_PIN D1 // connect to RXD of module (logic level 3.3v!)


SoftwareSerial swSer(RX_PIN, TX_PIN, false, 128);

void setup() {
  Serial.begin(115200);
  swSer.begin(115200);
}

void loop() {
  while (swSer.available() > 0) {
    Serial.write(swSer.read());
  }
  while (Serial.available() > 0) {
    swSer.write(Serial.read()); //Start HID Report
  }
}

