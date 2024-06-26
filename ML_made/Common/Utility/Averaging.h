#ifndef AVERAGING_H
#define AVERAGING_H

/* include */
#include "../../../src/r_cg_macrodriver.h"
#include "../../../src/r_cg_userdefine.h"


/* Macro */


/* variables */


/* Structure */


/* public */
int16_t Ave_Speed(int16_t speed_low);
int16_t Ave_Current(int16_t current_low);
void Ave_InitSpeed(int16_t init_val);
void Ave_InitCurrent(int16_t init_val);


#endif /* AVERAGING_H */
