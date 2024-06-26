#ifndef DETECTION_H
#define DETECTION_H

/* include */
#include "../../src/r_cg_macrodriver.h"
#include "../../src/r_cg_userdefine.h"
#include "Control.h"


/* Macro */


/* variables */


/* Structure */


/* public */
rot_e Det_Rotation(uint8_t sector);
int16_t Det_Speed(uint32_t cnt_hall, rot_e rot);
int16_t Det_Current(uint16_t ad_val);


#endif /* DETECTION_H */
