#ifndef __PINS_MC_H
#define __PINS_MC_H

/** Portenta H7 **/

/* AnalogIn */
#define MC_AI_AI0_PIN       PC_3C
#define MC_AI_AI1_PIN       PC_2C
#define MC_AI_AI2_PIN       PA_1C

#define MC_AI_CH0_IN1_PIN   PD_4
#define MC_AI_CH0_IN2_PIN   PD_5
#define MC_AI_CH0_IN3_PIN   PE_3
#define MC_AI_CH0_IN4_PIN   PG_3

#define MC_AI_CH1_IN1_PIN   PD_7
#define MC_AI_CH1_IN2_PIN   PH_6
#define MC_AI_CH1_IN3_PIN   PJ_7
#define MC_AI_CH1_IN4_PIN   PH_15

#define MC_AI_CH2_IN1_PIN   PH_10
#define MC_AI_CH2_IN2_PIN   PA_4
#define MC_AI_CH2_IN3_PIN   PA_8
#define MC_AI_CH2_IN4_PIN   PC_6

/* AnalogOut */
#define MC_AO_AO0_PIN       PJ_11
#define MC_AO_AO1_PIN       PK_1
#define MC_AO_AO2_PIN       PG_7
#define MC_AO_AO3_PIN       PC_7

/* CAN */
#define MC_CAN_TX_PIN       PB_8
#define MC_CAN_RX_PIN       PH_13
#define MC_CAN_STB_PIN      PA_13

/* DigitalOut */
#define MC_DO_DO0_PIN       PI_6
#define MC_DO_DO1_PIN       PH_9
#define MC_DO_DO2_PIN       PJ_9
#define MC_DO_DO3_PIN       PE_2
#define MC_DO_DO4_PIN       PI_3
#define MC_DO_DO5_PIN       PI_2
#define MC_DO_DO6_PIN       PD_3
#define MC_DO_DO7_PIN       PA_14
#define MC_DO_LATCH_PIN     PB_2

/* Encoder */
#define MC_ENC_0A_PIN       PJ_8
#define MC_ENC_0B_PIN       PH_12
#define MC_ENC_0I_PIN       PH_11
#define MC_ENC_1A_PIN       PC_13
#define MC_ENC_1B_PIN       PI_7
#define MC_ENC_1I_PIN       PJ_10

/* Programmable DIO */
#define MC_PDIO_LATCH_PIN   PH_14

/* RS485/232 */
#define MC_RS485_TX_PIN     PA_0
#define MC_RS485_DE_PIN     PI_13
#define MC_RS485_RE_PIN     PI_10

#define MC_RS485_RX_PIN     PI_9
#define MC_RS485_EN_PIN     PG_9
#define MC_RS485_RS232_PIN  PA_10
#define MC_RS485_FDTERM_PIN PI_15
#define MC_RS485_TERM_PIN   PI_14
#define MC_RS485_SLEW_PIN   PG_14
#define MC_RS485_HF_PIN     PA_9

/* RTC */
#define MC_RTC_INT_PIN      PB_9

/* RTD Temperature probe */
#define MC_RTD_CS_PIN       PA_6
#define MC_RTD_SEL0_PIN     PD_6
#define MC_RTD_SEL1_PIN     PI_4
#define MC_RTD_SEL2_PIN     PG_10
#define MC_RTD_TH_PIN       PC_15

/* TC Temperature probe */
#define MC_TC_CS_PIN        PI_0
#define MC_TC_SEL0_PIN      MC_RTD_SEL0_PIN
#define MC_TC_SEL1_PIN      MC_RTD_SEL1_PIN
#define MC_TC_SEL2_PIN      MC_RTD_SEL2_PIN

/* USB */
#define MC_USB_PWR_PIN      PB_14
#define MC_USB_FLAG_PIN     PB_15

#endif /* __PINS_MC_H */