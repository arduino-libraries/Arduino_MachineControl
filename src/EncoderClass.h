/**
 * @file EncoderClass.h
 * @author Leonardo Cavagnis
 * @brief Header file for the EncoderClass of the Portenta Machine Control.
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

/* Class ----------------------------------------------------------------------*/

/**
 * @class EncoderClass
 * @brief Class for managing Quadrature Encoder Interface devices of the Portenta Machine Control.
 */
class EncoderClass {
public:
    /**
     * @brief Construct an EncoderClass object.
     *
     * This constructor initializes the two QEI objects for encoder 0 and encoder 1
     * with the specified pin assignments.
     *
     * @param enc0_A_pin Pin assignment for encoder 0 channel A (default: PA_0).
     * @param enc0_B_pin Pin assignment for encoder 0 channel B (default: PB_0).
     * @param enc0_I_pin Pin assignment for encoder 0 Index channel (default: PC_0).
     * @param enc1_A_pin Pin assignment for encoder 1 channel A (default: PD_0).
     * @param enc1_B_pin Pin assignment for encoder 1 channel B (default: PE_0).
     * @param enc1_I_pin Pin assignment for encoder 1 Index channel (default: PF_0).
     */
    EncoderClass(PinName enc0_A_pin = PJ_8, PinName enc0_B_pin = PH_12, PinName enc0_I_pin = PH_11,
                 PinName enc1_A_pin = PC_13, PinName enc1_B_pin = PI_7, PinName enc1_I_pin = PJ_10);

    /**
     * @brief Destruct the EncoderClass object.
     *
     * This destructor releases any resources used by the EncoderClass object.
     */
    ~EncoderClass();

    /**
     * @brief Get the QEI object for the specified encoder index.
     *
     * This method returns a reference to the QEI object for the specified encoder index.
     *
     * @param index The index for selecting the encoder (0 or 1).
     * @return A reference to the corresponding QEI object.
     */
    QEI& operator[](int index);

private:
    QEI enc_0;  // QEI object for encoder 0
    QEI enc_1;  // QEI object for encoder 1
};

extern EncoderClass MachineControl_Encoders;

#endif /* __ENCODER_CLASS_H */