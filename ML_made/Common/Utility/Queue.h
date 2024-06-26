#ifndef QUEUE_H
#define QUEUE_H

/* include */
#include "../../../src/r_cg_macrodriver.h"
#include "../../../src/r_cg_userdefine.h"


/* Macro */
#define	SIZE		32
#define	NEW_QUEUE	{0,0,{0}}


/* variables */


/* Structure */
typedef struct
{
	uint8_t	head;
	uint8_t	num;
	int16_t	data[SIZE];
} queue_t;


/* public */
bool Enqueue(queue_t *q, int16_t data);
bool Dequeue(queue_t *q, int16_t *data);


#endif /* QUEUE_H */
