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

#include "RS485.h"

RS485Class::RS485Class(HardwareSerial& hwSerial, PinName txPin, PinName dePin, PinName rePin) :
  _serial(&hwSerial),
  _txPin(txPin),
  _dePin(dePin),
  _rePin(rePin),
  _transmisionBegun(false)
{
}

void RS485Class::begin(unsigned long baudrate)
{
  begin(baudrate, SERIAL_8N1);
}

void RS485Class::begin(unsigned long baudrate, uint16_t config)
{
  _baudrate = baudrate;
  _config = config;

  if (_dePin != NC) {
    pinMode(_dePin, OUTPUT);
    digitalWrite(_dePin, LOW);
  }

  if (_rePin != NC) {
    pinMode(_rePin, OUTPUT);
    digitalWrite(_rePin, HIGH);
  }

  _transmisionBegun = false;

  _serial->begin(baudrate, config);
}

void RS485Class::end()
{
  _serial->end();

  if (_rePin != NC) {
    digitalWrite(_rePin, LOW);
    pinMode(_dePin, INPUT);
  }

  if (_dePin != NC) {
    digitalWrite(_dePin, LOW);
    pinMode(_rePin, INPUT);
  }
}

int RS485Class::available()
{
  return _serial->available();
}

int RS485Class::peek()
{
  return _serial->peek();
}

int RS485Class::read(void)
{
  return _serial->read();
}

size_t RS485Class::readBytes(char *buf, size_t length)
{
  return _serial->readBytes(buf, length);
}
void RS485Class::flush()
{
  return _serial->flush();
}

size_t RS485Class::write(uint8_t b)
{
  if (!_transmisionBegun) {
    setWriteError();
    return 0;
  }

  return _serial->write(b);
}

RS485Class::operator bool()
{
  return true;
}

void RS485Class::beginTransmission()
{
  if (_dePin > -1) {
    digitalWrite(_dePin, HIGH);
    delayMicroseconds(50);
  }

  _transmisionBegun = true;
}

void RS485Class::endTransmission()
{
  _serial->flush();

  if (_dePin != NC) {
    delayMicroseconds(50);
    digitalWrite(_dePin, LOW);
  }

  _transmisionBegun = false;
}

void RS485Class::receive()
{
  if (_rePin != NC) {
    digitalWrite(_rePin, LOW);
  }
}

void RS485Class::noReceive()
{
  if (_rePin != NC) {
    digitalWrite(_rePin, HIGH);
  }
}

void RS485Class::sendBreak(unsigned int duration)
{
  _serial->flush();
  _serial->end();
  if (_txPin != NC) {
    pinMode(_txPin, OUTPUT);
    digitalWrite(_txPin, LOW);
  }
  delay(duration);
  _serial->begin(_baudrate, _config);
}

void RS485Class::sendBreakMicroseconds(unsigned int duration)
{
  _serial->flush();
  _serial->end();
  if (_txPin != NC) {
    pinMode(_txPin, OUTPUT);
    digitalWrite(_txPin, LOW);
  }
  delayMicroseconds(duration);
  _serial->begin(_baudrate, _config);
}

void RS485Class::setPins(PinName txPin, PinName dePin, PinName rePin)
{
  _txPin = txPin;
  _dePin = dePin;
  _rePin = rePin;
}
