#ifndef LOG_H
#define LOG_H

/* include */
#include "../../../src/r_cg_macrodriver.h"
#include "../../../src/r_cg_userdefine.h"


/* Macro */


/* variables */


/* Structure */


/* public */
void Log_Write(int16_t speed, int16_t current);
int16_t Log_ReadSpeed(void);
int16_t Log_ReadCurrent(void);


#endif /* LOG_H */
