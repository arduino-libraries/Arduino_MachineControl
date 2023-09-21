/*
  This file is part of the MachineControl library.
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
  if(!_tca.testConnection()) {
    return false;
  }
  //Initialize all pins to the default mode
  initPins();

  return true;
}

bool ArduinoIOExpanderClass::begin(uint8_t address)
{
  setAddress(address);
  if(!_tca.testConnection()) {
    return false;
  }
  //Initialize all pins to the default mode
  initPins();

  return true;
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

void ArduinoIOExpanderClass::setAddress(uint8_t address) {
  _tca.setAddress(address);
}

bool ArduinoIOExpanderClass::set(int pin, PinStatus status)
{ 
  if (pin < IO_READ_CH_PIN_00) {
    if (status > HIGH)
        return false;

    _tca.writePin(pin, status == HIGH ? TCA6424A_HIGH : TCA6424A_LOW);
    return true;
  }
  return false; 
}

int ArduinoIOExpanderClass::read(int pin)
{
  if(_tca.getAddress() == IO_ADD) {
    if (pin > TCA6424A_P13 && pin <= TCA6424A_P27) {
      return _tca.readPin(pin) == true ? 1 : 0;
    }
  } else if(_tca.getAddress() == DIN_ADD) {
    if ((pin >=   TCA6424A_P00)  && (pin <=   TCA6424A_P10) && (pin !=TCA6424A_P03)) {
        return _tca.readPin(pin) == true ? 1 : 0;
    }
  }
  return -1;
}

void ArduinoIOExpanderClass::writeAll(uint32_t banks) {
  _tca.writeAll(banks & 0xFF, (banks  >> 8) & 0xFF, 0x00);
}

uint32_t ArduinoIOExpanderClass::readAll()
{
  uint8_t banks[3];
  _tca.readAll(banks);
  return *(uint32_t*)banks;
}


void ArduinoIOExpanderClass::toggle(){
  writeAll(~(readAll()));
}

void ArduinoIOExpanderClass::initPins()
{

    if (_tca.getAddress() == IO_ADD) {
      PinStatus status = SWITCH_OFF;
      set(IO_WRITE_CH_PIN_00, status);
      set(IO_WRITE_CH_PIN_01, status);
      set(IO_WRITE_CH_PIN_02, status);
      set(IO_WRITE_CH_PIN_03, status);
      set(IO_WRITE_CH_PIN_04, status);
      set(IO_WRITE_CH_PIN_05, status);
      set(IO_WRITE_CH_PIN_06, status);
      set(IO_WRITE_CH_PIN_07, status);
      set(IO_WRITE_CH_PIN_08, status);
      set(IO_WRITE_CH_PIN_09, status);
      set(IO_WRITE_CH_PIN_10, status);
      set(IO_WRITE_CH_PIN_11, status);
      
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

      writeAll(SWITCH_OFF_ALL);
    } else {
      pinMode(DIN_READ_CH_PIN_00, INPUT);
      pinMode(DIN_READ_CH_PIN_01, INPUT);
      pinMode(DIN_READ_CH_PIN_02, INPUT);
      pinMode(DIN_READ_CH_PIN_03, INPUT);
      pinMode(DIN_READ_CH_PIN_04, INPUT);
      pinMode(DIN_READ_CH_PIN_05, INPUT);
      pinMode(DIN_READ_CH_PIN_06, INPUT);
      pinMode(DIN_READ_CH_PIN_07, INPUT);
    }
}

ArduinoIOExpanderClass Expander;
