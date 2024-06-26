#ifndef ARRAY_H
#define ARRAY_H

/* include */
#include "../../../src/r_cg_macrodriver.h"
#include "../../../src/r_cg_userdefine.h"


/* Macro */
#define	NEW_ARRAY(size)	{ size, 0, {0} }
#define	MAX_SIZE			16


/* variables */



/* Structure */
typedef struct
{
	uint8_t size;
	uint8_t counter;
	int16_t array[MAX_SIZE];
} ary_t;


/* public */
void Array_Init(ary_t *ary, int16_t ini_val);
void Array_Add(ary_t *ary, int16_t add_val);
int32_t Array_Sum(ary_t *ary);
int16_t Array_Ave(ary_t *ary);


#endif /* ARRAY_H */
