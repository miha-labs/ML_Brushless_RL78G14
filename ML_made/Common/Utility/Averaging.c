/* -----------------------------------------------------------------------------
	include
----------------------------------------------------------------------------- */
#include	"Averaging.h"

#include	"Array.h"
#include	"../../Interface/ML_DMA.h"
#include	"../../Interface/ML_Config.h"

/* -----------------------------------------------------------------------------
	Local Macro
----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
	local Structure
----------------------------------------------------------------------------- */
static ary_t ary_spd = NEW_ARRAY(6);
static ary_t ary_crr = NEW_ARRAY(DMA_BUF_SIZE);


/* -----------------------------------------------------------------------------
	Local Variable
----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
	local function
----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
	private function
----------------------------------------------------------------------------- */
static int16_t excludeOutlier(int16_t low)
{
	static int16_t pre = 0;
	
	if( low>MIN_SPEED_RPM || low<-MIN_SPEED_RPM )	low = pre;
	
	pre = low;
	
	return low;
}


/* -----------------------------------------------------------------------------
	public function
----------------------------------------------------------------------------- */
int16_t Ave_Speed(int16_t speed_low)
{
	speed_low = excludeOutlier(speed_low);

	Array_Add(&ary_spd, speed_low);
	return Array_Ave(&ary_spd);
}


int16_t Ave_Current(int16_t current_low)
{
	Array_Add(&ary_crr, current_low);
	return Array_Ave(&ary_crr);
}


void Ave_InitSpeed(int16_t init_val)
{
	Array_Init(&ary_spd, init_val);
}


void Ave_InitCurrent(int16_t init_val)
{
	Array_Init(&ary_crr, init_val);
}