#include "a7105.h"
#include <stdint.h>
#include <Arduino.h>
#include <SPI.h>
#include "config.h"


void loop() {
  Serial.begin(115200);
  A7105_Setup(); //A7105_Reset();
  int startTime, waitTime, hubsanWait,finishTime;
  Serial.println("Preinit");
  initialize();

  startTime = micros();
  while (1) {
    if (Serial.available()>4) {
      if (Serial.read()!=97) {
        throttle = rudder =aileron = elevator = 0;
        Serial.println("Setting everything to 0");
      } else {
      throttle=Serial.read();
      rudder=Serial.read();
      aileron=Serial.read();
      elevator=Serial.read();
      Serial.println("Setting values:");
      }
    }
    
//      if (state!=0 && state!=1 & state!=128){ 
//Serial.print("State: ");
//Serial.println(state);}
    hubsanWait = hubsan_cb();
//    finishTime=micros();
//    waitTime = hubsanWait - (micros() - startTime);
//    Serial.print("hubsanWait: " ); Serial.println(hubsanWait);
//    Serial.print("waitTime: " ); Serial.println(waitTime);
//    Serial.println(hubsanWait);
    delayMicroseconds(hubsanWait);
    startTime = micros();
  }
}

