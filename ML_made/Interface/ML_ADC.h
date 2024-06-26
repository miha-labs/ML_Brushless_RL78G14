#ifndef ML_ADC_H
#define ML_ADC_H

/* include */
#include "../../src/r_cg_macrodriver.h"
#include "../../src/r_cg_userdefine.h"


/* Macro */


/* variables */


/* Structure */
typedef enum
{
	ADC_CH_U = 0x00,  // ANI0
	ADC_CH_V = 0x01,  // ANI1
	ADC_CH_W = 0x02   // ANI2
} adc_ch_e;


/* public */
void ADC_Startup(void);
void ADC_SetChannel(adc_ch_e ch);

#endif /* ML_ADC_H */
