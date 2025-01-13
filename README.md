# A02YYUW Library

A simple arduino library to interface with the **A02YYUW ultrasonic sensor ** via UART communication.

## Features
- Easy to use interface for the A02YYUW Sensor 
- Provides distance measurements in centimeters
- Compatible with all Arduino-compatible boards

## Installation
1. Download the library from the [Github Repository](https://github.com/alfan459/A02YYUW-Sensor-Library)
2. Extract the contents into your Arduino librarier folder
3. Restart the Arduino IDE 

## Usage
``` Arduino 
#include <A02YYUW.h>

A02YYUW sensor (10,11);

void setup(){
    Serial.begin(9600);
    sensor.begin();
    Serial.println("A02YYUW Test");
    Serial.println("Please wait...");
    delay(1000);
}

void loop(){
    int distance = sensor.getDistance();

    if(distance !=-1){
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" cm");
    }
    else{
        Serial.println("No valid data.");
    }
    delay(500);
}

```
