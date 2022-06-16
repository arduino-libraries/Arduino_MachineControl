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

#pragma once

#include <Arduino.h>
#include "TCA6424A.h"

#define IO_ADD       TCA6424A_ADDRESS_ADDR_LOW // address pin low (GND)
#define DIN_ADD      TCA6424A_ADDRESS_ADDR_HIGH // address pin high (VCC)

#define SWITCH_ON HIGH
#define SWITCH_OFF LOW

#define SWITCH_ON_ALL 0x0000FFFF
#define SWITCH_OFF_ALL 0x00000000

enum {
    ON_VALUE_PIN_00 =      0x01,
    ON_VALUE_PIN_01 =      0x02,
    ON_VALUE_PIN_02 =      0x04,
    ON_VALUE_PIN_03 =      0x08,
    ON_VALUE_PIN_04 =      0x80,
    ON_VALUE_PIN_05 =      0x40,
    ON_VALUE_PIN_06 =      0x20,
    ON_VALUE_PIN_07 =      0x10,
    ON_VALUE_PIN_08 =      0x100,
    ON_VALUE_PIN_09 =      0x200,
    ON_VALUE_PIN_10 =      0x400,
    ON_VALUE_PIN_11 =      0x800,
};

enum {
    IO_WRITE_CH_PIN_00 =      TCA6424A_P00,
    IO_WRITE_CH_PIN_01 =      TCA6424A_P01,
    IO_WRITE_CH_PIN_02 =      TCA6424A_P02,
    IO_WRITE_CH_PIN_03 =      TCA6424A_P03,
    IO_WRITE_CH_PIN_04 =      TCA6424A_P07,
    IO_WRITE_CH_PIN_05 =      TCA6424A_P06,
    IO_WRITE_CH_PIN_06 =      TCA6424A_P05,
    IO_WRITE_CH_PIN_07 =      TCA6424A_P04,
    IO_WRITE_CH_PIN_08 =      TCA6424A_P10,
    IO_WRITE_CH_PIN_09 =      TCA6424A_P11,
    IO_WRITE_CH_PIN_10 =      TCA6424A_P12,
    IO_WRITE_CH_PIN_11 =      TCA6424A_P13,

    IO_READ_CH_PIN_00 =       TCA6424A_P27,
    IO_READ_CH_PIN_01 =       TCA6424A_P26,
    IO_READ_CH_PIN_02 =       TCA6424A_P25,
    IO_READ_CH_PIN_03 =       TCA6424A_P24,
    IO_READ_CH_PIN_04 =       TCA6424A_P23,
    IO_READ_CH_PIN_05 =       TCA6424A_P22,
    IO_READ_CH_PIN_06 =       TCA6424A_P21,
    IO_READ_CH_PIN_07 =       TCA6424A_P20,
    IO_READ_CH_PIN_08 =       TCA6424A_P17,
    IO_READ_CH_PIN_09 =       TCA6424A_P16,
    IO_READ_CH_PIN_10 =       TCA6424A_P15,
    IO_READ_CH_PIN_11 =       TCA6424A_P14
};

enum {
    DIN_READ_CH_PIN_00 =      TCA6424A_P10,
    DIN_READ_CH_PIN_01 =      TCA6424A_P05,
    DIN_READ_CH_PIN_02 =      TCA6424A_P04,
    DIN_READ_CH_PIN_03 =      TCA6424A_P02,
    DIN_READ_CH_PIN_04 =      TCA6424A_P01,
    DIN_READ_CH_PIN_05 =      TCA6424A_P00,
    DIN_READ_CH_PIN_06 =      TCA6424A_P07,
    DIN_READ_CH_PIN_07 =      TCA6424A_P06,
};

class ArduinoIOExpanderClass {

public:
    ArduinoIOExpanderClass() = default;
    ~ArduinoIOExpanderClass() = default;

    bool begin();
    bool begin(uint8_t address);

    operator bool();
    void setAddress(uint8_t address);
    bool set(int pin, PinStatus status);
    bool set(int pin, int status) { return set( pin, (PinStatus)status); };
    void writeAll(uint32_t banks);
    int read(int pin);
    uint32_t readAll();
    void toggle();
    bool pinMode(int pin, PinMode direction);

private:
    void initPins();
private:
    TCA6424A _tca {};
};

extern ArduinoIOExpanderClass Expander;
