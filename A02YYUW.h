#ifndef A02YYUW_H
#define A02YYUW_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class A02YYUW {
  public:
    A02YYUW(int pinRX, int pinTX);
    void begin(int baudRate = 9600);
    int getDistance();
  
  private:
    int _pinRX;
    int _pinTX;
    SoftwareSerial* _mySerial;
    unsigned char _data_buffer[4];
    unsigned char _CS;
    int _distance;
};

#endif
