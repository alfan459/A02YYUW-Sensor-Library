#include "A02YYUW.h"

A02YYUW::A02YYUW(int pinRX, int pinTX) {
  _pinRX = pinRX;
  _pinTX = pinTX;
  _mySerial = new SoftwareSerial(_pinRX, _pinTX);
}

void A02YYUW::begin(int baudRate) {
  _mySerial->begin(baudRate);
}

int A02YYUW::getDistance() {
  if (_mySerial->available() > 0) {
    delay(4);
    if (_mySerial->read() == 0xff) {
      _data_buffer[0] = 0xff;
      for (int i = 1; i < 4; i++) {
        _data_buffer[i] = _mySerial->read();
      }
      _CS = _data_buffer[0] + _data_buffer[1] + _data_buffer[2];
      if (_data_buffer[3] == _CS) {
        _distance = (_data_buffer[1] << 8) + _data_buffer[2];
        return _distance / 10;
      }
    }
  }
  return -1; // Return -1 if no valid data
}
