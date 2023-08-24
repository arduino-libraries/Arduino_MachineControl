/**
 * @file AnalogInClass.cpp
 * @author Leonardo Cavagnis
 * @brief Source file for the Analog IN connector of the Portenta Machine Control library.
 */

/* Includes -----------------------------------------------------------------*/
#include "AnalogInClass.h"

/* Private defines -----------------------------------------------------------*/
#define CH0_IN1 MC_AI_CH0_IN1_PIN
#define CH0_IN2 MC_AI_CH0_IN2_PIN
#define CH0_IN3 MC_AI_CH0_IN3_PIN
#define CH0_IN4 MC_AI_CH0_IN4_PIN

#define CH1_IN1 MC_AI_CH1_IN1_PIN
#define CH1_IN2 MC_AI_CH1_IN2_PIN
#define CH1_IN3 MC_AI_CH1_IN3_PIN
#define CH1_IN4 MC_AI_CH1_IN4_PIN

#define CH2_IN1 MC_AI_CH2_IN1_PIN
#define CH2_IN2 MC_AI_CH2_IN2_PIN
#define CH2_IN3 MC_AI_CH2_IN3_PIN
#define CH2_IN4 MC_AI_CH2_IN4_PIN

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

bool AnalogInClass::begin(SensorType sensor_type, int res_bits) {
    bool ret = true;

    /* Set bit resolution of ADC */
    analogReadResolution(res_bits);

    switch (sensor_type) {
        case SensorType::NTC:
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
        case SensorType::V_0_10:
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
        case SensorType::MA_4_20:
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