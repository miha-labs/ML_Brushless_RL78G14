/* -----------------------------------------------------------------------------
	include
----------------------------------------------------------------------------- */
#include  "ML_PWM.h"
#include  "ML_GPIO.h"
#include  "../../src/r_cg_timer.h"
#include "../Interface/ML_Config.h"

/* -----------------------------------------------------------------------------
	Local Macro
----------------------------------------------------------------------------- */
/* PWM enable(TRDOER1 MASK) */
#define PWM_EN_MASK_UH   0x02
#define PWM_EN_MASK_UL   0x08
#define PWM_EN_MASK_VH   0x10
#define PWM_EN_MASK_VL   0x40
#define PWM_EN_MASK_WH   0x20
#define PWM_EN_MASK_WL   0x80

/* -----------------------------------------------------------------------------
	Local Variable
----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
	local Structure
----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
	local function
----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
	private function
----------------------------------------------------------------------------- */
static void enablePWM(uint8_t mask)
{
  TRDOER1 &= ~mask;
}

static void disablePWM(uint8_t mask)
{
  TRDOER1 |= mask;
}

static void invertPWM(void)
{
  TRDFCR |= _04_TMRD_NORMAL_PHASE_LEVEl_LH | _08_TMRD_COUNTER_PHASE_LEVEl_LH; 
}

static void non_invertPWM(void)
{
  TRDFCR |= _00_TMRD_NORMAL_PHASE_LEVEl_HL | _00_TMRD_COUNTER_PHASE_LEVEl_HL; 
}

static uint16_t dutyToTRDGRval(uint16_t duty)
{
  uint16_t trdgr_val = MAX_COUNT_GRA0 - ( (duty*32)/10 - 1 );

  return trdgr_val>MAX_COUNT_GRA0? MAX_COUNT_GRA0 : trdgr_val;
}

/* -----------------------------------------------------------------------------
	public function
----------------------------------------------------------------------------- */
void PWM_Startup(void)
{
  PWMout_SetDuty(0);
  R_TMR_RD0_Start();
}

/*---------------------
 * ハイサイド出力 : Lo
 * ローサイド出力 : Lo
---------------------*/
void PWMout_LO_LO(ch_e ch)
{
  switch (ch)
  {
    case CH_U:
      disablePWM(PWM_EN_MASK_UH);
      disablePWM(PWM_EN_MASK_UL);
      GPIO_PIN_MOTOR_UH = 0;
      GPIO_PIN_MOTOR_UL = 0;
      break;

    case CH_V:
      disablePWM(PWM_EN_MASK_VH);
      disablePWM(PWM_EN_MASK_VL);
      GPIO_PIN_MOTOR_VH = 0;
      GPIO_PIN_MOTOR_VL = 0;
      break;

    case CH_W:
      disablePWM(PWM_EN_MASK_WH);
      disablePWM(PWM_EN_MASK_WL);
      GPIO_PIN_MOTOR_WH = 0;
      GPIO_PIN_MOTOR_WL = 0;
      break;
    
    default:
      break;
  }
}

/*---------------------
 * ハイサイド出力 : Lo
 * ローサイド出力 : Hi
---------------------*/
void PWMout_LO_HI(ch_e ch)
{
	switch (ch)
  {
    case CH_U:
      disablePWM(PWM_EN_MASK_UH);
      disablePWM(PWM_EN_MASK_UL);
      GPIO_PIN_MOTOR_UH = 0;
      GPIO_PIN_MOTOR_UL = 1;
      break;

    case CH_V:
      disablePWM(PWM_EN_MASK_VH);
      disablePWM(PWM_EN_MASK_VL);
      GPIO_PIN_MOTOR_VH = 0;
      GPIO_PIN_MOTOR_VL = 1;
      break;

    case CH_W:
      disablePWM(PWM_EN_MASK_WH);
      disablePWM(PWM_EN_MASK_WL);
      GPIO_PIN_MOTOR_WH = 0;
      GPIO_PIN_MOTOR_WL = 1;
      break;
    
    default:
      break;
  }
}

/*---------------------
 * ハイサイド出力 : Hi
 * ローサイド出力 : Lo
---------------------*/
void PWMout_HI_LO(ch_e ch)
{
  switch (ch)
  {
    case CH_U:
      disablePWM(PWM_EN_MASK_UH);
      disablePWM(PWM_EN_MASK_UL);
      GPIO_PIN_MOTOR_UH = 1;
      GPIO_PIN_MOTOR_UL = 0;
      break;

    case CH_V:
      disablePWM(PWM_EN_MASK_VH);
      disablePWM(PWM_EN_MASK_VL);
      GPIO_PIN_MOTOR_VH = 1;
      GPIO_PIN_MOTOR_VL = 0;
      break;

    case CH_W:
      disablePWM(PWM_EN_MASK_WH);
      disablePWM(PWM_EN_MASK_WL);
      GPIO_PIN_MOTOR_WH = 1;
      GPIO_PIN_MOTOR_WL = 0;
      break;
    
    default:
      break;
  }
}

/*---------------------
 * ハイサイド出力 : PWM
 * ローサイド出力 : Lo
---------------------*/
void PWMout_PP_LO(ch_e ch)
{
	switch (ch)
  {
    case CH_U:
      enablePWM(PWM_EN_MASK_UH);
      disablePWM(PWM_EN_MASK_UL);
      GPIO_PIN_MOTOR_UH = 0;
      GPIO_PIN_MOTOR_UL = 0;
      break;

    case CH_V:
      enablePWM(PWM_EN_MASK_VH);
      disablePWM(PWM_EN_MASK_VL);
      GPIO_PIN_MOTOR_VH = 0;
      GPIO_PIN_MOTOR_VL = 0;
      break;

    case CH_W:
      enablePWM(PWM_EN_MASK_WH);
      disablePWM(PWM_EN_MASK_WL);
      GPIO_PIN_MOTOR_WH = 0;
      GPIO_PIN_MOTOR_WL = 0;
      break;
    
    default:
      break;
  }

  invertPWM();
}

/*---------------------
 * ハイサイド出力 : Lo
 * ローサイド出力 : PWM
---------------------*/
void PWMout_LO_PP(ch_e ch)
{
	switch (ch)
  {
    case CH_U:
      disablePWM(PWM_EN_MASK_UH);
      enablePWM(PWM_EN_MASK_UL);
      GPIO_PIN_MOTOR_UH = 0;
      GPIO_PIN_MOTOR_UL = 0;
      break;

    case CH_V:
      disablePWM(PWM_EN_MASK_VH);
      enablePWM(PWM_EN_MASK_VL);
      GPIO_PIN_MOTOR_VH = 0;
      GPIO_PIN_MOTOR_VL = 0;
      break;

    case CH_W:
      disablePWM(PWM_EN_MASK_WH);
      enablePWM(PWM_EN_MASK_WL);
      GPIO_PIN_MOTOR_WH = 0;
      GPIO_PIN_MOTOR_WL = 0;
      break;
    
    default:
      break;
  }

  non_invertPWM();
}

/*---------------------
 * ハイサイド出力 : PWM(補相)
 * ローサイド出力 : PWM
---------------------*/
void PWMout_PN_PP(ch_e ch)
{
	switch (ch)
  {
    case CH_U:
      enablePWM(PWM_EN_MASK_UH);
      enablePWM(PWM_EN_MASK_UL);
      GPIO_PIN_MOTOR_UH = 0;
      GPIO_PIN_MOTOR_UL = 0;
      break;

    case CH_V:
      enablePWM(PWM_EN_MASK_VH);
      enablePWM(PWM_EN_MASK_VL);
      GPIO_PIN_MOTOR_VH = 0;
      GPIO_PIN_MOTOR_VL = 0;
      break;

    case CH_W:
      enablePWM(PWM_EN_MASK_WH);
      enablePWM(PWM_EN_MASK_WL);
      GPIO_PIN_MOTOR_WH = 0;
      GPIO_PIN_MOTOR_WL = 0;
      break;
    
    default:
      break;
  }

  non_invertPWM();
}

/*---------------------
 * ハイサイド出力 : PWM
 * ローサイド出力 : PWM(補相)
---------------------*/
void PWMout_PP_PN(ch_e ch)
{
	switch (ch)
  {
    case CH_U:
      enablePWM(PWM_EN_MASK_UH);
      enablePWM(PWM_EN_MASK_UL);
      GPIO_PIN_MOTOR_UH = 0;
      GPIO_PIN_MOTOR_UL = 0;
      break;

    case CH_V:
      enablePWM(PWM_EN_MASK_VH);
      enablePWM(PWM_EN_MASK_VL);
      GPIO_PIN_MOTOR_VH = 0;
      GPIO_PIN_MOTOR_VL = 0;
      break;

    case CH_W:
      enablePWM(PWM_EN_MASK_WH);
      enablePWM(PWM_EN_MASK_WL);
      GPIO_PIN_MOTOR_WH = 0;
      GPIO_PIN_MOTOR_WL = 0;
      break;
    
    default:
      break;
  }

  invertPWM();
}

/*---------------------
 * Duty比設定
---------------------*/
void PWMout_SetDuty(uint16_t duty)
{
  uint16_t trdgr_val = dutyToTRDGRval(duty);

  TRDGRD0 = trdgr_val;
  TRDGRC1 = trdgr_val;
  TRDGRD1 = trdgr_val;
}


bool PWMout_IsCountUp(void)
{
	return true;
}