# Summary

 Members                                    | Descriptions
--------------------------------------------|------------------------------------------
`class` [`AnalogInClass`](#class-analoginclass) | Class for the Analog IN connector of the Portenta Machine Control.
`class` [`AnalogOutClass`](#class-analogoutclass) | Class for the Analog OUT connector of the Portenta Machine Control.
`class` [`CANCommClass`](#class-cancommclass) | Class for managing the CAN Bus communication protocol of the Portenta Machine Control.
`class` [`DigitalOutputsClass`](#class-digitaloutputsclass) | Class for the Digital Output connector of the Portenta Machine Control.
`class` [`EncoderClass`](#class-encoderclass) | Class for the encoder module of the Portenta Machine Control.
`class` [`ProgrammableDINClass`](#class-programmabledinclass) | Class for the Programmable Digital Input connector of the Portenta Machine Control.
`class` [`ProgrammableDIOClass`](#class-programmabledioclass) | Class for the Programmable Digital IO connector of the Portenta Machine Control.
`class` [`RS485CommClass`](#class-rs485commclass) | Class for managing the RS485 and RS232 communication protocols of the Portenta Machine Control.
`class` [`RTDTempProbeClass`](#class-rtdtempprobeclass) | Class for managing the Resistance Temperature Detector (RTD) temperature sensor connector of the Portenta Machine Control.
`class` [`RtcControllerClass`](#class-rtccontrollerclass) | Class for controlling the PCF8563T RTC of the Portenta Machine Control.
`class` [`TCTempProbeClass`](#class-tctempprobeclass) | Class for managing the Thermocouple (TC) temperature sensor connector of the Portenta Machine Control.
`class` [`USBClass`](#class-usbclass) | Class for managing the USB functionality of the Portenta Machine Control.

# class `AnalogInClass`
Class for the Analog IN connector of the Portenta Machine Control.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public ` [`AnalogInClass`](#public-analoginclasspinname-ai0_pin--mc_ai_ai0_pin-pinname-ai1_pin--mc_ai_ai1_pin-pinname-ai2_pin--mc_ai_ai2_pin)`(PinName ai0_pin, PinName ai1_pin, PinName ai2_pin)` | Construct an Analog Input reader for the Portenta Machine Control.
`public ` [`~AnalogInClass`](#public-analoginclass)`()` | Destruct the AnalogInClass object.
`public bool` [`begin`](#public-bool-beginint-sensor_type-int-res_bits--16)`(SensorType sensor_type, int res_bits)` | Initialize the analog reader, configure the sensor type and read resolution.
`public uint16_t` [`read`](#public-uint16_t-readint-channel)`(int channel)` | Read the sampled voltage from the selected channel.

# class `AnalogOutClass`
Class for the Analog OUT connector of the Portenta Machine Control.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public ` [`AnalogOutClass`](#public-analogoutclasspinname-ao0_pin--mc_ao_ao0_pin-pinname-ao1_pin--mc_ao_ao1_pin-pinname-ao2_pin--mc_ao_ao2_pin-pinname-ao3_pin--mc_ao_ao3_pin)`(PinName ao0_pin, PinName ao1_pin, PinName ao2_pin, PinName ao3_pin)` | Construct an Analog Output writer for the Portenta Machine Control.
`public ` [`~AnalogOutClass`](#public-analogoutclass)`()` | Destruct the AnalogOutClass object.
`public bool` [`begin`](#public-bool-begin)`()` | Initialize the PWM, configure the default frequency for all channels (500Hz).
`public void` [`setPeriod`](#public-void-setperiodint-channel-uint8_t-period_ms)`(int channel, uint8_t period_ms)` | Set the PWM period (frequency) on the selected channel.
`public void` [`write`](#public-void-writeint-channel-float-voltage)`(int channel, float voltage)` | Set output voltage value on the selected channel.

# class `CANCommClass`
Class for managing the CAN Bus communication protocol of the Portenta Machine Control.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public ` [`CANCommClass`](#public-cancommclasspinname-can_tx_pin--mc_can_tx_pin-pinname-can_rx_pin--mc_can_rx_pin-pinname-can_stb_pin--mc_can_stb_pin)`(PinName can_tx_pin, PinName can_rx_pin, PinName can_stb_pin)` | Construct a CANCommClass object.
`public ` [`~CANCommClass`](#public-cancommclass)`()` | Destruct the CANCommClass object.
`public bool` [`begin`](#public-bool-begincanbitrate-can_bitrate)`(CanBitRate can_bitrate)` | Begin the CAN communication protocol.
`public int` [`write`](#public-int-writecanmsg-const--msg)`(CanMsg const & msg)` | Write a CAN message to the bus.
`public size_t` [`available`](#public-size_t-available)`()` | Check the number of available CAN messages in the receive buffer.
`public CanMsg` [`read`](#public-canmsg-read)`()` | Read a CAN message from the bus.
`public void` [`end`](#public-void-end)`()` | Close the CAN communication protocol.

# class `DigitalOutputsClass`
Class for the Digital Output connector of the Portenta Machine Control.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public ` [`DigitalOutputsClass`](#public-digitaloutputsclasspinname-do0_pin--mc_do_do0_pin-pinname-do1_pin--mc_do_do1_pin-pinname-do2_pin--mc_do_do2_pin-pinname-do3_pin--mc_do_do3_pin-pinname-do4_pin--mc_do_do4_pin-pinname-do5_pin--mc_do_do5_pin-pinname-do6_pin--mc_do_do6_pin-pinname-do7_pin--mc_do_do7_pin-pinname-latch_pin--mc_do_latch_pin)`(PinName do0_pin, PinName do1_pin, PinName do2_pin, PinName do3_pin, PinName do4_pin, PinName do5_pin, PinName do6_pin, PinName do7_pin, PinName latch_pin)` | Construct a DigitalOutputsClass object.
`public ` [`~DigitalOutputsClass`](#public-digitaloutputsclass)`()` | Destruct the DigitalOutputsClass object.
`public bool` [`begin`](#public-bool-beginbool-latch_mode--true)`(bool latch_mode = true)` | Initialize the DigitalOutputs module with the specified latch mode.
`public void` [`write`](#public-void-writeuint8_t-channel-pinstatus-val)`(uint8_t channel, PinStatus val)` | Write the output value for the given channel.
`public void` [`writeAll`](#public-void-writealluint8_t-val_mask)`(uint8_t val_mask)` | Set the state of all digital outputs simultaneously.

# class `EncoderClass`
Class for managing Quadrature Encoder Interface devices of the Portenta Machine Control.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public ` [`EncoderClass`](#public-encoderclasspinname-enc0_a_pin--mc_enc_0a_pin-pinname-enc0_b_pin--mc_enc_0b_pin-pinname-enc0_i_pin--mc_enc_0i_pin-pinname-enc1_a_pin--mc_enc_1a_pin-pinname-enc1_b_pin--mc_enc_1b_pin-pinname-enc1_i_pin--mc_enc_1i_pin)`(PinName enc0_a_pin, PinName enc0_b_pin, PinName enc0_i_pin, PinName enc1_a_pin, PinName enc1_b_pin, PinName enc1_i_pin)` | Construct an EncoderClass object.
`public ` [`~EncoderClass`](#public-encoderclass)`()` | Destruct the EncoderClass object.
`public void` [`reset`](#public-void-resetint-channel)`(int channel)` | Reset the encoder counter for the specified channel.
`public int` [`getCurrentState`](#public-int-getcurrentstateint-channel)`(int channel)` | Get the current state of the specified encoder channel.
`public int` [`getPulses`](#public-int-getpulsesint-channel)`(int channel)` | Get the number of pulses counted by the specified encoder channel.
`public int` [`getRevolutions`](#public-int-getrevolutionsint-channel)`(int channel)` | Get the number of revolutions counted by the specified encoder channel.

# class `ProgrammableDINClass`
Class for the Programmable Digital Input connector of the Portenta Machine Control.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public ` [`ProgrammableDINClass`](#public-programmabledinclass)`()` | Construct a ProgrammableDINClass object.
`public ` [`~ProgrammableDINClass`](#public-programmabledinclass)`()` | Destruct the ProgrammableDINClass object.
`public bool` [`begin`](#public-bool-begin)`()` | Initialize the ProgrammableDIN module.

# class `ProgrammableDIOClass`
Class for the Programmable Digital IO connector of the Portenta Machine Control.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public ` [`ProgrammableDIOClass`](#public-programmabledioclasspinname-latch_pin--mc_pdio_latch_pin-pinname-latch_pin)`(PinName latch_pin)` | Construct a ProgrammableDIOClass object.
`public ` [`~ProgrammableDIOClass`](#public-programmabledioclass)`()` | Destruct the ProgrammableDIOClass object.
`public bool` [`begin`](#public-bool-beginbool-latch_mode--true)`(bool latch_mode)` | Initialize the ProgrammableDIO module with the specified latch mode.

# class `RS485CommClass`
Class for managing the RS485 and RS232 communication protocols of the Portenta Machine Control.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public ` [`RS485CommClass`](#public-rs485commclassarduino::uart--uart_itf-pinname-rs_tx_pin--mc_rs485_tx_pin-pinname-rs_de_pin--mc_rs485_de_pin-pinname-rs_re_pin--mc_rs485_re_pin)`(arduino::UART& uart_itf, PinName rs_tx_pin, PinName rs_de_pin, PinName rs_re_pin)` | Construct a RS485CommClass object.
`public ` [`~RS485CommClass`](#public-rs485commclass)`()` | Destruct the RS485CommClass object.
`public void` [`begin`](#public-void-beginunsigned-long-baudrate--115200-int-predelay--rs485_default_pre_delay-int-postdelay--rs485_default_post_delay)`(unsigned long baudrate, int predelay, int postdelay)` | Begin the RS485 communication protocol.
`public void` [`end`](#public-void-end)`()` | Close the RS485 communication protocol.
`public void` [`setModeRS232`](#public-void-setmoders232bool-enable)`(bool enable)` | Set RS485 mode to RS232.
`public void` [`setYZTerm`](#public-void-setyztermbool-enable)`(bool enable)` | Set YZ termination for RS485 communication.
`public void` [`setABTerm`](#public-void-setabtermbool-enable)`(bool enable)` | Set AB termination for RS485 communication.
`public void` [`setSlew`](#public-void-setslewbool-enable)`(bool enable)` | Set the slew rate for RS485 communication.
`public void` [`setFullDuplex`](#public-void-setfullduplexbool-enable)`(bool enable)` | Set RS485 communication to Full Duplex mode.

# class `RTDTempProbeClass`
Class for managing RTD temperature sensor inputs of the Portenta Machine Control.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public ` [`RTDTempProbeClass`](#public-rtdtempprobeclasspinname-rtd_cs_pin--mc_rtd_cs_pin-pinname-ch_sel0_pin--mc_rtd_sel0_pin-pinname-ch_sel1_pin--mc_rtd_sel1_pin-pinname-ch_sel2_pin--mc_rtd_sel2_pin-pinname-rtd_th_pin--mc_rtd_th_pin)`(PinName rtd_cs_pin, PinName ch_sel0_pin, PinName ch_sel1_pin, PinName ch_sel2_pin, PinName rtd_th_pin)` | Construct a RTDTempProbeClass object.
`public ` [`~RTDTempProbeClass`](#public-rtdtempprobeclass)`()` | Destruct the RTDTempProbeClass object.
`public bool` [`begin`](#public-bool-beginuint8_t-io_address--three_wire)`(uint8_t io_address)` | Initialize the RTDTempProbeClass with the specified I/O address.
`public void` [`end`](#public-void-end)`()` | Disable the temperature sensors and release any resources.
`public void` [`selectChannel`](#public-void-selectchannelint-channel)`(int channel)` | Select the input channel to be read (3 channels available).

# class `RtcControllerClass`
Class for controlling the PCF8563T RTC.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public ` [`RtcControllerClass`](#public-rtccontrollerclasspinname-int_pin--mc_rtc_int_pin)`(PinName int_pin)` | Construct a RtcControllerClass object with an interrupt pin.
`public ` [`~RtcControllerClass`](#public-rtccontrollerclass)`()` | Destructor for the RtcControllerClass.

# class `TCTempProbeClass`
Class for managing thermocouples temperature sensor of the Portenta Machine Control.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public ` [`TCTempProbeClass`](#public-tctempprobeclasspinname-tc_cs_pin--mc_tc_cs_pin-pinname-ch_sel0_pin--mc_tc_sel0_pin-pinname-ch_sel1_pin--mc_tc_sel1_pin-pinname-ch_sel2_pin--mc_tc_sel2_pin)`(PinName tc_cs_pin, PinName ch_sel0_pin, PinName ch_sel1_pin, PinName ch_sel2_pin)` | Construct a TCTempProbeClass object.
`public ` [`~TCTempProbeClass`](#public-tctempprobeclass)`()` | Destruct the TCTempProbeClass object.
`public bool` [`begin`](#public-bool-begin)`()` | Initialize the TCTempProbeClass.
`public void` [`end`](#public-void-end)`()` | Disable the temperature sensors and release any resources.
`public void` [`selectChannel`](#public-void-selectchannelint-channel)`(int channel)` | Select the input channel to be read (3 channels available).

# class `USBClass`
Class for managing the USB functionality of the Portenta Machine Control.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public ` [`USBClass`](#public-usbclasspinname-power_pin--mc_usb_pwr_pin-pinname-usbflag_pin--mc_usb_flag_pin)`(PinName power_pin, PinName usbflag_pin)` | Construct a USBClass object.
`public ` [`~USBClass`](#public-usbclass)`()` | Destruct the USBClass object.
`public bool` [`begin`](#public-bool-begin)`()` | Begin the USB functionality.
`public void` [`end`](#public-void-end)`()` | End the USB functionality.
`public bool` [`getFaultStatus`](#public-bool-getfaultstatus)`()` | Get the fault status of the USBA VBUS.
