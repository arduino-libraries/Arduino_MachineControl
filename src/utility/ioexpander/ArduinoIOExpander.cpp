/*
  This file is part of the AutomationCarrier library.
  Copyright (C) 2020  Arduino AG (http://www.arduino.cc/)
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

#include "ArduinoIOExpander.h"

bool ArduinoIOExpanderClass::begin()
{
  Wire.begin();
  _tca.initialize();
  return _tca.testConnection();
}

ArduinoIOExpanderClass::operator bool()
{
  return _tca.testConnection();
}

bool ArduinoIOExpanderClass::pinMode(int pin, PinMode direction)
{
  if (direction > OUTPUT)
    return false;

  _tca.setPinDirection(pin, direction == INPUT ? TCA6424A_INPUT : TCA6424A_OUTPUT);
  return true;
}

bool ArduinoIOExpanderClass::digitalWrite(int pin, PinStatus status)
{ 
  if (pin < IO_READ_CH_PIN_00) {
    if (status > HIGH)
        return false;

    _tca.writePin(pin, status == HIGH ? TCA6424A_HIGH : TCA6424A_LOW);
    return true;
  }
  return false; 
}

int ArduinoIOExpanderClass::digitalRead(int pin)
{
  if (pin > IO_READ_CH_PIN_11) {
    return _tca.readPin(pin) == true ? 1 : 0;
  }
  return -1;
}

void ArduinoIOExpanderClass::initPins()
{
    pinMode(IO_WRITE_CH_PIN_00, OUTPUT);
    pinMode(IO_WRITE_CH_PIN_01, OUTPUT);
    pinMode(IO_WRITE_CH_PIN_02, OUTPUT);
    pinMode(IO_WRITE_CH_PIN_03, OUTPUT);
    pinMode(IO_WRITE_CH_PIN_04, OUTPUT);
    pinMode(IO_WRITE_CH_PIN_05, OUTPUT);
    pinMode(IO_WRITE_CH_PIN_06, OUTPUT);
    pinMode(IO_WRITE_CH_PIN_07, OUTPUT);
    pinMode(IO_WRITE_CH_PIN_08, OUTPUT);
    pinMode(IO_WRITE_CH_PIN_09, OUTPUT);
    pinMode(IO_WRITE_CH_PIN_10, OUTPUT);
    pinMode(IO_WRITE_CH_PIN_11, OUTPUT);
    pinMode(IO_READ_CH_PIN_00, INPUT);
    pinMode(IO_READ_CH_PIN_01, INPUT);
    pinMode(IO_READ_CH_PIN_02, INPUT);
    pinMode(IO_READ_CH_PIN_03, INPUT);
    pinMode(IO_READ_CH_PIN_04, INPUT);
    pinMode(IO_READ_CH_PIN_05, INPUT);
    pinMode(IO_READ_CH_PIN_06, INPUT);
    pinMode(IO_READ_CH_PIN_07, INPUT);
    pinMode(IO_READ_CH_PIN_08, INPUT);
    pinMode(IO_READ_CH_PIN_09, INPUT);
    pinMode(IO_READ_CH_PIN_10, INPUT);
    pinMode(IO_READ_CH_PIN_11, INPUT);
}

ArduinoIOExpanderClass Expander {};