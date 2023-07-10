/**
 * @file AnalogInClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the Analog IN connector of the Portenta Machine Control library.
 */

/* Includes -----------------------------------------------------------------*/
#include "AnalogInClass.h"

/* Private defines -----------------------------------------------------------*/
#define CH0_IN1 PD_4
#define CH0_IN2 PD_5
#define CH0_IN3 PE_3
#define CH0_IN4 PG_3

#define CH1_IN1 PD_7
#define CH1_IN2 PH_6
#define CH1_IN3 PJ_7
#define CH1_IN4 PH_15

#define CH2_IN1 PH_10
#define CH2_IN2 PA_4
#define CH2_IN3 PA_8
#define CH2_IN4 PC_6

/* Functions -----------------------------------------------------------------*/
AnalogInClass::AnalogInClass(PinName ai0_pin, PinName ai1_pin, PinName ai2_pin)
                : _ai0{ai0_pin}, _ai1{ai1_pin}, _ai2{ai2_pin}
{
    // Pin configuration for CH0
    pinMode(CH0_IN1, OUTPUT);
    pinMode(CH0_IN2, OUTPUT);
    pinMode(CH0_IN3, OUTPUT);
    pinMode(CH0_IN4, OUTPUT);

    // Pin configuration for CH1
    pinMode(CH1_IN1, OUTPUT);
    pinMode(CH1_IN2, OUTPUT);
    pinMode(CH1_IN3, OUTPUT);
    pinMode(CH1_IN4, OUTPUT);

    // Pin configuration for CH2
    pinMode(CH2_IN1, OUTPUT);
    pinMode(CH2_IN2, OUTPUT);
    pinMode(CH2_IN3, OUTPUT);
    pinMode(CH2_IN4, OUTPUT);
}

AnalogInClass::~AnalogInClass() 
{ }

bool AnalogInClass::begin(int sensor_type, int res_bits) {
    bool ret = true;

    /* Set bit resolution of ADC */
    analogReadResolution(res_bits);

    switch (sensor_type) {
        case MCAI_SENSOR_NTC:
            /* Enable a 100K resistor in series with the reference voltage.	 
             * The voltage sampled is the voltage division between the 100k resistor and the input resistor (NTC/PTC) */
            digitalWrite(CH0_IN1, LOW);
            digitalWrite(CH0_IN2, LOW);
            digitalWrite(CH0_IN3, HIGH);
            digitalWrite(CH0_IN4, HIGH);

            digitalWrite(CH1_IN1, LOW);
            digitalWrite(CH1_IN2, LOW);
            digitalWrite(CH1_IN3, HIGH);
            digitalWrite(CH1_IN4, HIGH);

            digitalWrite(CH2_IN1, LOW);
            digitalWrite(CH2_IN2, LOW);
            digitalWrite(CH2_IN3, HIGH);
            digitalWrite(CH2_IN4, HIGH);
            break;
        case MCAI_SENSOR_0_10V:
            /* Configure the input resistor dividers to have a ratio of 0.28
             * (Maximum input voltage is 10V). */
            digitalWrite(CH0_IN1, HIGH);
            digitalWrite(CH0_IN2, HIGH);
            digitalWrite(CH0_IN3, LOW);
            digitalWrite(CH0_IN4, HIGH);

            digitalWrite(CH1_IN1, HIGH);
            digitalWrite(CH1_IN2, HIGH);
            digitalWrite(CH1_IN3, LOW);
            digitalWrite(CH1_IN4, HIGH);

            digitalWrite(CH2_IN1, HIGH);
            digitalWrite(CH2_IN2, HIGH);
            digitalWrite(CH2_IN3, LOW);
            digitalWrite(CH2_IN4, HIGH);
            break;
        case MCAI_SENSOR_4_20MA:
            /* Enable a 120 ohm resistor to GND to convert the 4-20mA sensor currents to voltage. 
             * Note: 24V are available from the carrier to power the 4-20mA sensors. */
            digitalWrite(CH0_IN1, HIGH);
            digitalWrite(CH0_IN2, LOW);
            digitalWrite(CH0_IN3, HIGH);
            digitalWrite(CH0_IN4, LOW);

            digitalWrite(CH1_IN1, HIGH);
            digitalWrite(CH1_IN2, LOW);
            digitalWrite(CH1_IN3, HIGH);
            digitalWrite(CH1_IN4, LOW);

            digitalWrite(CH2_IN1, HIGH);
            digitalWrite(CH2_IN2, LOW);
            digitalWrite(CH2_IN3, HIGH);
            digitalWrite(CH2_IN4, LOW);
            break;
        default:
            /* Unknown sensor type */
            ret = false;
            break;
    }

    return ret;
}

uint16_t AnalogInClass::read(int channel) {
    uint16_t value = 0;

    switch (channel) {
        case 0:
            value = analogRead(_ai0);
            break;
        case 1:
            value = analogRead(_ai1);
            break;
        case 2:
            value = analogRead(_ai2);
            break;
        default:
            break;
        }

    return value;
}

AnalogInClass MachineControl_AnalogIn;

/**** END OF FILE ****/