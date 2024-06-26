#ifndef ML_PWM_H
#define ML_PWM_H

/* include */
#include "../../src/r_cg_macrodriver.h"
#include "../../src/r_cg_userdefine.h"


/* Macro */


/* variables */


/* Structure */
typedef enum
{
	CH_U = 1,
	CH_V = 2,
	CH_W = 3
}ch_e;


/* public */
void PWM_Startup(void);
void PWMout_LO_LO(ch_e ch);
void PWMout_LO_HI(ch_e ch);
void PWMout_HI_LO(ch_e ch);
void PWMout_PP_LO(ch_e ch);
void PWMout_LO_PP(ch_e ch);
void PWMout_PN_PP(ch_e ch);
void PWMout_PP_PN(ch_e ch);
void PWMout_SetDuty(uint16_t duty);
bool PWMout_IsCountUp(void);


#endif /* ML_PWM_H */
