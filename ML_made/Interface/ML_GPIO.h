#ifndef ML_GPIO_H
#define ML_GPIO_H

/* include */
#include "../../src/r_cg_macrodriver.h"
#include "../../src/r_cg_userdefine.h"


/* Macro */
#define GPIO_PIN_HALL_U    (P7_bit.no5)
#define GPIO_PIN_HALL_V    (P7_bit.no6)
#define GPIO_PIN_HALL_W    (P7_bit.no7)

#define GPIO_PIN_MOTOR_UH  (P1_bit.no5)
#define GPIO_PIN_MOTOR_UL  (P1_bit.no4)
#define GPIO_PIN_MOTOR_VH  (P1_bit.no3)
#define GPIO_PIN_MOTOR_VL  (P1_bit.no1)
#define GPIO_PIN_MOTOR_WH  (P1_bit.no2)
#define GPIO_PIN_MOTOR_WL  (P1_bit.no0)
#define GPIO_PIN_MOTOR_EN  (P11_bit.no1)

#define GPIO_PIN_SW        (P13_bit.no7)
#define GPIO_PIN_LED0      (P4_bit.no3)
#define GPIO_PIN_LED1      (P4_bit.no4)


/* variables */


/* Structure */


/* public */
void GPIO_Startup(void);
uint8_t GPIO_ReadHall(void);
void GPIO_EnableMotorDriver(void);
void GPIO_DisableMotorDriver(void);


#endif /* ML_GPIO_H */
