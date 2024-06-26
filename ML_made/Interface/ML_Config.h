#ifndef ML_CONFIG_H
#define ML_CONFIG_H

/* include */
#include "../../src/r_cg_macrodriver.h"
#include "../../src/r_cg_userdefine.h"


/* Macro */

// timer
#define TIM_INITVAL     (50000-1)           // TAU0 ch0初期値
#define MAX_COUNT_GRA0  3198                // TRDGRA0 最大値

// conversion
#define TIM_HALL_TO_RPM ((int32_t)1250000)  // ホールセンサ割り込みカウント値 -> 回転速度[rpm]
#define	VCC_HALF        ((int16_t)530)      // 電流0A時電圧 512から実機に合わせて微調整済
#define	ADC_TO_CURR     ((int32_t)4571)     // ADC読み取り値 -> 電流[uA]

// limit
#define	MAX_DUTY        900                 // PWM Duty比 最大90[%]
#define	MIN_DUTY        50                  // PWM Duty比 最小 5[%]
#define	MIN_SPEED_RPM   6000                // 回転速度最大値[rpm]

// gain
#define	KP              10                  // 速度制御 Pゲイン
#define	KI              5                   // 速度制御 Iゲイン
#define	ILIM            80000               // 速度制御 I上限
#define	DEADBAND        50                  // 速度制御 不感帯


/* variables */


/* Structure */


/* public */



#endif /* ML_CONFIG_H */