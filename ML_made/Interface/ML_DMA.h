#ifndef ML_DMA_H
#define ML_DMA_H

/* include */
#include "../../src/r_cg_macrodriver.h"
#include "../../src/r_cg_userdefine.h"


/* Macro */
#define DMA_BUF_SIZE	8


/* variables */



/* Structure */


/* public */
void DMA_Startup(void);
void DMA_Start(void);
void DMA_Stop(void);
void DMA_GetArray(uint16_t *ary);

#endif /* ML_DMA_H */
