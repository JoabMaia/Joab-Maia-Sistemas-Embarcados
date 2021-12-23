#include <Arduino.h>

int pLed = 13;
int pKey = 2; 
int state = 0; 

int tHigh = 2000;
int tLow = 1000; 

void setup() {
  pinMode(pLed, OUTPUT);
  pinMode(pKey, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pKey), func_blink, FALLING);                              
}                                                              

void loop(){
  digitalWrite(pLed, HIGH); 
  delay(tHigh); 
  digitalWrite(pLed, LOW); 
  delay(tLow); 
}

void func_blink() { 
  state = !state; 
    
  if (state == 1) {
    tHigh = 2000; 
    tLow = 1000; 
  } else {
    tHigh = 5000; 
    tLow = 25000; 
  }
}