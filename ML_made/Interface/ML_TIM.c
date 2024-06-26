/* -----------------------------------------------------------------------------
	include
----------------------------------------------------------------------------- */
#include "ML_TIM.h"

#include "../Common/Control.h"
#include "../../src/r_cg_timer.h"
#include "../Interface/ML_Config.h"

/* -----------------------------------------------------------------------------
	Local Macro
----------------------------------------------------------------------------- */



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
static void TAU_init(void)
{
  TPS0 |= _0006_TAU_CKM0_FCLK_6;  // 0.5MHz
  TDR00 = TIM_INITVAL;  // 100msec
}


static uint16_t getCountValue(void)
{
  R_TAU0_Channel0_Stop();
  uint16_t count = TIM_INITVAL - TCR00;
  TCR00 = TIM_INITVAL;
  R_TAU0_Channel0_Start();

  return count;
}


/* -----------------------------------------------------------------------------
	public function
----------------------------------------------------------------------------- */
void TIM_Startup(void)
{
  TAU_init();
  R_TAU0_Channel0_Start();
  R_TAU0_Channel1_Start();

  TIM_HallProcess();
}


void TIM_HallProcess(void)
{
    uint16_t count = getCountValue();
    Ctr_HallSensorDetection(count);
}


void TIM_HallTimeout(void)
{
	Ctr_HallSensorTimeout();
}