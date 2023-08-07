/**
 * @file EncoderClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the encoder module of the Portenta Machine Control.
 *
 * This library provides a class to manage the Quadrature Encoder Interface devices
 * of the Portenta Machine Control. It allows interfacing with two encoders through
 * the QEI (Quadrature Encoder Interface) library and provides methods to access
 * and control each encoder individually.
 */

#ifndef __ENCODER_CLASS_H
#define __ENCODER_CLASS_H

/* Includes -------------------------------------------------------------------*/
#include "utility/QEI/QEI.h"
#include <Arduino.h>
#include <mbed.h>
#include "pins_mc.h"

/* Class ----------------------------------------------------------------------*/

/**
 * @class EncoderClass
 * @brief Class for managing Quadrature Encoder Interface devices of the Portenta Machine Control.
 * 
 * This class provides methods to interact with two quadrature encoders. Each encoder
 * has two channels (A and B) for quadrature signals and an index channel. The class
 * allows reading the current state, pulses, and revolutions of each encoder.
 */
class EncoderClass {
public:
    /**
     * @brief Construct an EncoderClass object.
     *
     * This constructor initializes the two QEI objects for encoder 0 and encoder 1
     * with the specified pin assignments.
     *
     * @param enc0_A_pin Pin assignment for encoder 0 channel A (default: PJ_8).
     * @param enc0_B_pin Pin assignment for encoder 0 channel B (default: PH_12).
     * @param enc0_I_pin Pin assignment for encoder 0 Index channel (default: PH_11).
     * @param enc1_A_pin Pin assignment for encoder 1 channel A (default: PC_13).
     * @param enc1_B_pin Pin assignment for encoder 1 channel B (default: PI_7).
     * @param enc1_I_pin Pin assignment for encoder 1 Index channel (default: PJ_10).
     */
    EncoderClass(PinName enc0_A_pin = MC_ENC_0A_PIN, PinName enc0_B_pin = MC_ENC_0B_PIN, PinName enc0_I_pin = MC_ENC_0I_PIN,
                 PinName enc1_A_pin = MC_ENC_1A_PIN, PinName enc1_B_pin = MC_ENC_1B_PIN, PinName enc1_I_pin = MC_ENC_1I_PIN);

    /**
     * @brief Destruct the EncoderClass object.
     *
     * This destructor releases any resources used by the EncoderClass object.
     */
    ~EncoderClass();

    /**
     * @brief Reset the encoder counter for the specified channel.
     * 
     * @param channel The encoder channel (0 or 1) to reset.
     */
    void reset(int channel);

    /**
     * @brief Get the current state of the specified encoder channel.
     * 
     * The current state is the value of the encoder counter.
     * 
     * @param channel The encoder channel (0 or 1) to read the state from.
     * @return The current state of the encoder channel as a 2-bit number, where:
     *         bit 0 = The reading from channel B
     *         bit 1 = The reading from channel A
     */
    int getCurrentState(int channel);

    /**
     * @brief Get the number of pulses counted by the specified encoder channel.
     * 
     * This method returns the number of pulses counted by the encoder. Each pulse
     * corresponds to a change in the encoder's quadrature signal.
     * 
     * @param channel The encoder channel (0 or 1) to read the pulses from.
     * @return The number of pulses counted by the encoder channel.
     */
    int getPulses(int channel);

    /**
     * @brief Get the number of revolutions counted by the specified encoder channel.
     * 
     * This method returns the number of full revolutions counted by the encoder.
     * It utilizes the index channel to track revolutions.
     * 
     * @param channel The encoder channel (0 or 1) to read the revolutions from.
     * @return The number of revolutions counted by the encoder channel.
     */
    int getRevolutions(int channel);

private:
    QEI _enc0;  // QEI object for encoder 0
    QEI _enc1;  // QEI object for encoder 1
};

extern EncoderClass MachineControl_Encoders;

#endif /* __ENCODER_CLASS_H */