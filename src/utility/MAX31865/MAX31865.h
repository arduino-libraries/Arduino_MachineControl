/*
  This file is part of the MachineControl library.
  Copyright (c) 2021 Arduino SA.

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

#ifndef MAX31865_H
#define MAX31865_H

#include <Arduino.h>
#include <mbed.h>
#include <SPI.h>


#define MAX31856_CONFIG_REG 0x00
#define MAX31856_RTD_MSB_REG 0x01
#define MAX31856_FAULT_STATUS_REG 0x07

//config bias mask
#define MAX31856_CONFIG_BIAS_MASK 0x7F
#define MAX31856_CONFIG_BIAS_ON 0x80

//config conversion mode mask
#define MAX31856_CONFIG_CONV_MODE_MASK 0xBF
#define MAX31856_CONFIG_CONV_MODE_AUTO 0x40

//config one shot mask
#define MAX31856_CONFIG_ONE_SHOT_MASK 0xDF
#define MAX31856_CONFIG_ONE_SHOT 0x20

//config wire mask
#define MAX31856_CONFIG_WIRE_MASK 0xEF
#define MAX31856_CONFIG_3_WIRE 0x10

//config wire fault detection cycle mask
#define MAX31856_CONFIG_FAULT_DECT_CYCLE_MASK 0xF3
#define MAX31856_CONFIG_CLEAR_FAULT_CYCLE 0xD3

//config fault status mask
#define MAX31856_CONFIG_FAULT_STATUS_MASK 0xFD
#define MAX31856_CONFIG_CLEAR_FAULT 0x02

// config 50 60 filter frequency mask
#define MAX31856_CONFIG_60_50_HZ_FILTER_MASK 0xFE

// fault mask
#define MAX31865_FAULT_HIGH_THRESH 0x80
#define MAX31865_FAULT_LOW_THRESH 0x40
#define MAX31865_FAULT_LOW_REFIN 0x20
#define MAX31865_FAULT_HIGH_REFIN 0x10
#define MAX31865_FAULT_LOW_RTDIN 0x08
#define MAX31865_FAULT_OVER_UNDER_VOLTAGE 0x04

#define RTD_A 3.9083e-3
#define RTD_B -5.775e-7

#define TWO_WIRE 0
#define THREE_WIRE 1


class MAX31865Class {
public:
  MAX31865Class(PinName cs = PA_6);

  bool begin(int wires);
  void end();

  float readTemperature(float RTDnominal, float refResistor);
  uint8_t readFault(void);
  void clearFault(void);
  uint32_t readRTD();
  bool getHighThresholdFault(uint8_t fault);
  bool getLowThresholdFault(uint8_t fault);
  bool getLowREFINFault(uint8_t fault);
  bool getHighREFINFault(uint8_t fault);
  bool getLowRTDINFault(uint8_t fault);
  bool getVoltageFault(uint8_t fault);



private:
  uint8_t readByte(uint8_t addr);
  uint16_t readBytes(uint8_t addr);
  void writeByte(uint8_t addr, uint8_t data);

  PinName _cs;
  SPIClass& _spi;
};


#endif
