#ifndef PID_H
#define PID_H

/* include */
#include "../../src/r_cg_macrodriver.h"
#include "../../src/r_cg_userdefine.h"


/* Macro */
#define	NEW_PID(kp, ki, kd, ilim)	{ 0, 0, 0, kp, ki, kd, ilim }


/* variables */


/* Structure */
typedef struct
{
	int16_t	prop;		// 偏差
	int32_t	intg;		// 積分値 (static)
	int16_t	diff;		// 微分値 (static)
	int16_t	kp;			// 比例ゲイン
	int16_t	ki;			// 積分ゲイン
	int16_t	kd;			// 積分ゲイン
	int32_t	ilim;		// 積分上限値
} PID_t;


/* public */
int32_t PID_Control(PID_t *pid);
int16_t PID_DeadBand(int16_t target, int16_t dead_band);


#endif /* PID_H */
