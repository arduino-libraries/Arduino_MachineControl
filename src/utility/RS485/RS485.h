/*
  This file is part of the ArduinoRS485 library.
  Copyright (c) 2020 Arduino SA.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _RS485_MACHINECONTROL_H_INCLUDED
#define _RS485_MACHINECONTROL_H_INCLUDED

#include "Arduino.h"
#include "mbed.h"

class RS485Class : public HardwareSerial {
  public:
    RS485Class(HardwareSerial& hwSerial, PinName txPin = NC, PinName dePin = NC, PinName rePin = NC);

    virtual void begin(unsigned long baudrate);
    virtual void begin(unsigned long baudrate, uint16_t config);
    virtual void end();
    virtual int available();
    virtual int peek();
    virtual int read(void);
    virtual size_t readBytes(char *buf, size_t length);
    virtual size_t readBytes(uint8_t *buf, size_t length) { return readBytes((char *)buf, length); };
    virtual void flush();
    virtual size_t write(uint8_t b);
    using Print::write; // pull in write(str) and write(buf, size) from Print
    virtual operator bool();

    void beginTransmission();
    void endTransmission();
    void receive();
    void noReceive();

    void sendBreak(unsigned int duration);
    void sendBreakMicroseconds(unsigned int duration);

    void setPins(PinName txPin, PinName dePin, PinName rePin);

    mbed::DigitalOut half_duplex = mbed::DigitalOut(PA_9);
    mbed::DigitalOut sel_485 = mbed::DigitalOut(PA_10);
    mbed::DigitalOut slew_n = mbed::DigitalOut(PG_14);
    mbed::DigitalOut fd_tx_term = mbed::DigitalOut(PI_15);
    mbed::DigitalOut term = mbed::DigitalOut(PI_14);
    mbed::DigitalOut enable = mbed::DigitalOut(PG_9);

  private:
    HardwareSerial* _serial;
    PinName _txPin;
    PinName _dePin = NC;
    PinName _rePin = NC;


    bool _transmisionBegun;
    unsigned long _baudrate;
    uint16_t _config;
};

#endif
