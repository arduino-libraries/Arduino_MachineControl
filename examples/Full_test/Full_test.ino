#include <AutomationCarrier.h>

using namespace automation;
#define RREF      400.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0

void setup() {
  Serial.begin(9600);
  inizialization();
  analogReadResolution(16);
  digitalWrite(PI_0, HIGH);
  digitalWrite(PA_6, LOW);
  
}

void loop() {
  //test_dig_in();
  //test_dig_out();
  //test_dig_prog();
  //test_encoders();
  //test_analog_out();
  //test_analog_in_0_10V();
  //test_analog_in_4_20mA();
  //test_analog_in_NTC();
  //test_thermocouples();
  test_RTD();
}

void test_dig_in(){
  //DIGITAL IN, read all channels
  uint16_t dig_in = 0;
  dig_in = digital_inputs.readAll();
  Serial.print("DIGITAL IN TEST, read all CH (binary): ");
  Serial.println(dig_in, BIN);
}

void test_dig_out(){
  //DIGITAL OUT, toggle each channel ON for 1s and OFF for 0.5s
  Serial.println("DIGITAL OUTPUT TEST");
  delay(1000);
  uint16_t i = 0;
  for(i=0; i<8; i++){
    Serial.print("Digital output CH" +String(i) +" is ON for 1s...");
    digital_outputs.set(i, 1);
    delay(1000);
    Serial.println("now OFF for 0.5s");
    digital_outputs.set(i, 0);
    delay(500);
  } 
}

void test_dig_prog(){
  //DIGITAL PROG, toggle each channel ON for 1s and OFF for 0.5s
  Serial.println("DIGITAL PROGRAMMABLE TEST");
  if (!programmable_digital_io.begin()){
    Serial.println("GPIO expander initialization fail!!");
  }
  else {
    programmable_digital_io.initPins();
    programmable_digital_io.setLatch();
    Serial.print("All ON for 2s...");
    int pin_status = 1;
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_00, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_01, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_02, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_03, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_04, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_05, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_06, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_07, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_08, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_09, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_10, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_11, pin_status);
    delay(1500);
    Serial.println("all OFF for 2s");
    
    pin_status = 0;
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_00, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_01, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_02, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_03, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_04, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_05, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_06, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_07, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_08, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_09, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_10, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_11, pin_status);
    delay(250);
  }
}

void test_encoders(){
  Serial.print("Encoder 0 State: ");
  Serial.println(encoders[0].getCurrentState(),BIN);
  Serial.print("Encoder 0 Pulses: ");
  Serial.println(encoders[0].getPulses());
  Serial.print("Encoder 0 Revolutions: ");
  Serial.println(encoders[0].getRevolutions());
  Serial.println();
 
  // put your main code here, to run repeatedly:
  Serial.print("Encoder 1 State: ");
  Serial.println(encoders[1].getCurrentState(),BIN);
  Serial.print("Encoder 1 Pulses: ");
  Serial.println(encoders[1].getPulses());
  Serial.print("Encoder 1 Revolutions: ");
  Serial.println(encoders[1].getRevolutions());
  Serial.println();
  delay(25);
}

void inizialization(){
  //SHUTDOWN OF RS485 LEDS
  digitalWrite(PA_0, LOW);
  digitalWrite(PI_9, LOW);
  //SHUTDOWN OF CAN LEDS
  digitalWrite(PB_8, LOW);
  digitalWrite(PH_13, LOW);
  
  //SHUTDOWN OF DIGITAL PROGRAMMABLE
  Serial.println("DIGITAL PROGRAMMABLE TEST");
  if (!programmable_digital_io.begin()){
    Serial.println("GPIO expander initialization fail!!");
  }
  else {
    programmable_digital_io.initPins();
    programmable_digital_io.setLatch();
    int pin_status = 0;
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_00, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_01, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_02, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_03, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_04, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_05, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_06, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_07, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_08, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_09, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_10, pin_status);
    programmable_digital_io.digitalWrite(IO_WRITE_CH_PIN_11, pin_status);
  }
}

void test_analog_out(){
  Serial.println("Analog OUT test, duty from 0 to 100 in 1s");
  int i = 0;
  for (i=1; i<11; i++){
    Serial.println("Voltage: "+String(i)+"V");
    //CH0
    analog_out.period_ms(0,4);
    analog_out.write(0,i);
    //CH1
    analog_out.period_ms(1,4);
    analog_out.write(1,7);
    //CH2
    analog_out.period_ms(2,4);
    analog_out.write(2,i);
    
    delay(50);
  }
  Serial.println();
  Serial.println();
  Serial.println();
}

void test_analog_in_0_10V(){
  float reference = 3.3;
  float res_divider = 0.28;
  analog_in.set0_10V();
  
  delay(150);
  float raw_voltage_ch0 = analog_in.read(0);
  float voltage_ch0 = (raw_voltage_ch0 * reference) / 65535 / res_divider;
  Serial.print("Voltage ch0: ");
  Serial.print(voltage_ch0, 3);
  Serial.println("V");
  
  delay(150);
  float raw_voltage_ch1 = analog_in.read(1);
  float voltage_ch1 = (raw_voltage_ch1 * reference) / 65535 / res_divider;
  Serial.print("Voltage ch1: ");
  Serial.print(voltage_ch1, 3);
  Serial.println("V");
  
  delay(150);
  float raw_voltage_ch2 = analog_in.read(2);
  float voltage_ch2 = (raw_voltage_ch2 * reference) / 65535 / res_divider;
  Serial.print("Voltage ch2: ");
  Serial.print(voltage_ch2, 3);
  Serial.println("V");
  Serial.println();
  delay(250);
}

void test_analog_in_4_20mA(){
  float reference = 3.3;
  analog_in.set4_20mA();

  delay(150);
  float raw_voltage_ch0 = analog_in.read(0);
  float voltage_ch0 = (raw_voltage_ch0 * reference) / 65535;
  float current_ch0 = voltage_ch0 / 120 * 1000;
  Serial.print("Measured Current ch0: ");
  Serial.print(current_ch0);
  Serial.println("mA");

  delay(150);
  float raw_voltage_ch1 = analog_in.read(1);
  float voltage_ch1 = (raw_voltage_ch1 * reference) / 65535;
  float current_ch1 = voltage_ch1 / 120 * 1000;
  Serial.print("Measured Current  ch1: ");
  Serial.print(current_ch1);
  Serial.println("mA");

  delay(150);
  float raw_voltage_ch2 = analog_in.read(2);
  float voltage_ch2 = (raw_voltage_ch2 * reference) / 65535;
  float current_ch2 = voltage_ch2 / 120 * 1000;
  Serial.print("Measured Current  ch2: ");
  Serial.print(current_ch2);
  Serial.println("mA");

  Serial.println();
  delay(250);  
}

void test_analog_in_NTC(){
  float reference = 3.3;
  analog_in.setNTC();

  delay(150);
  float raw_voltage_ch0 = analog_in.read(0);
  float voltage_ch0 = (raw_voltage_ch0 * reference) / 65535;
  float resistance_ch0;
  if (voltage_ch0 < 3) {
    resistance_ch0 = ((-100000) * voltage_ch0) / (voltage_ch0 - 3);
  } else {
    resistance_ch0 = -1;
  }
  Serial.print("Resistance CH0: ");
  Serial.print(resistance_ch0);
  Serial.println("ohm");

  delay(150);
  float raw_voltage_ch1 = analog_in.read(1);
  float voltage_ch1 = (raw_voltage_ch1 * reference) / 65535;
  float resistance_ch1;
  if (voltage_ch1 < 3) {
    resistance_ch1 = ((-100000) * voltage_ch1) / (voltage_ch1 - 3);
  } else {
    resistance_ch1 = -1;
  }
  Serial.print("Resistance CH1: ");
  Serial.print(resistance_ch1);
  Serial.println("ohm");

  delay(150);
  float raw_voltage_ch2 = analog_in.read(2);
  float voltage_ch2 = (raw_voltage_ch2 * reference) / 65535;
  float resistance_ch2;
  if (voltage_ch2 < 3) {
    resistance_ch2 = ((-100000) * voltage_ch2) / (voltage_ch2 - 3);
  } else {
    resistance_ch2 = -1;
  }
  Serial.print("Resistance CH2: ");
  Serial.print(resistance_ch2);
  Serial.println("ohm");
  Serial.println();
  delay(250);
}

void test_thermocouples(){
  // Enables Thermocouples chip select outside loop
  //digitalWrite(PI_0, LOW);
  //digitalWrite(PA_6, HIGH);
  
  temp_probes.resetTH();
  temp_probes.tc.begin();
  
  temp_probes.selectChannel(0);
  delay(150);
  float temp_ch0 = temp_probes.tc.readTemperature(PROBE_K);
  Serial.print("Temperature CH0 [°C]: ");
  Serial.println(temp_ch0);

  temp_probes.selectChannel(1);
  delay(150);
  float temp_ch1 = temp_probes.tc.readTemperature(PROBE_K);
  Serial.print("Temperature CH1 [°C]: ");
  Serial.println(temp_ch1);

  temp_probes.selectChannel(2);
  delay(150);
  float temp_ch2 = temp_probes.tc.readTemperature(PROBE_K);
  Serial.print("Temperature CH2 [°C]: ");
  Serial.println(temp_ch2);
  
  Serial.println();
}

void test_RTD(){
  // Enables Thermocouples chip select outside loop
  //digitalWrite(PI_0, HIGH);
  //digitalWrite(PA_6, LOW);
  
  temp_probes.setTH();
  delay(150);
  temp_probes.rtd.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary
  temp_probes.tc.begin();

  uint16_t i = 0;
  for(i=0; i<3; i++){
    uint16_t rtd = temp_probes.rtd.readRTD();
    temp_probes.selectChannel(i);
    delay(150);
    
    Serial.print("RTD value: "); Serial.println(rtd);
    float ratio = rtd;
    ratio /= 32768;
    Serial.print("Ratio = "); Serial.println(ratio, 8);
    Serial.print("Resistance = "); Serial.println(RREF * ratio, 8);
    Serial.print("Temperature = "); Serial.println(temp_probes.rtd.temperature(RNOMINAL, RREF));
  
    // Check and print any faults
    uint8_t fault = temp_probes.rtd.readFault();
    if (fault) {
      Serial.print("Fault 0x"); Serial.println(fault, HEX);
      if (fault & MAX31865_FAULT_HIGHTHRESH) {
        Serial.println("RTD High Threshold");
      }
      if (fault & MAX31865_FAULT_LOWTHRESH) {
        Serial.println("RTD Low Threshold");
      }
      if (fault & MAX31865_FAULT_REFINLOW) {
        Serial.println("REFIN- > 0.85 x Bias");
      }
      if (fault & MAX31865_FAULT_REFINHIGH) {
        Serial.println("REFIN- < 0.85 x Bias - FORCE- open");
      }
      if (fault & MAX31865_FAULT_RTDINLOW) {
        Serial.println("RTDIN- < 0.85 x Bias - FORCE- open");
      }
      if (fault & MAX31865_FAULT_OVUV) {
        Serial.println("Under/Over voltage");
      }
      temp_probes.rtd.clearFault();
    }
    Serial.println();
    delay(500);
  }
}
