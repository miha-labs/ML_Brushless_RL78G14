#ifndef CONTROL_H
#define CONTROL_H

/* include */
#include "../../src/r_cg_macrodriver.h"
#include "../../src/r_cg_userdefine.h"


/* Macro */


/* variables */


/* Structure */
typedef enum
{
	ROT_CW,
	ROT_CCW,
	ROT_FREE,
	ROT_BRAKE,
	ROT_NOTDET
} rot_e;


/* public */
void Ctr_Startup(void);
void Ctr_Task(void);

void Ctr_SetTargetSpeed(int16_t speed);
void Ctr_HallSensorDetection(uint32_t cnt_hall);
void Ctr_HallSensorTimeout(void);
//void Ctr_CurrentDetection(uint16_t ad_val);
void Ctr_Elapsed_10ms(void);

#endif /* CONTROL_H */
