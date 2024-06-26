/* -----------------------------------------------------------------------------
	include
----------------------------------------------------------------------------- */
#include "Detection.h"
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



/* -----------------------------------------------------------------------------
	public function
----------------------------------------------------------------------------- */
rot_e Det_Rotation(uint8_t sector)
{
	static	uint8_t	pre_sector = 7;
			rot_e		rot = ROT_NOTDET;

	switch(pre_sector)
	{
		case 1:
			if( sector==3 )	rot = ROT_CW;
			if( sector==5 )	rot = ROT_CCW;
			break;
		case 2:
			if( sector==6 )	rot = ROT_CW;
			if( sector==3 )	rot = ROT_CCW;
			break;
		case 3:
			if( sector==2 )	rot = ROT_CW;
			if( sector==1 )	rot = ROT_CCW;
			break;
		case 4:
			if( sector==5 )	rot = ROT_CW;
			if( sector==6 )	rot = ROT_CCW;
			break;
		case 5:
			if( sector==1 )	rot = ROT_CW;
			if( sector==4 )	rot = ROT_CCW;
			break;
		case 6:
			if( sector==4 )	rot = ROT_CW;
			if( sector==2 )	rot = ROT_CCW;
			break;
		default:				rot = ROT_NOTDET;
			break;
	}

	pre_sector = sector;

	return rot;
}


int16_t Det_Speed(uint32_t cnt_hall, rot_e rot)
{
	int32_t speed_rpm = 0;
	
	speed_rpm = TIM_HALL_TO_RPM / cnt_hall;
	
	if( rot==ROT_CCW )	speed_rpm *= -1;
	
	return (int16_t)speed_rpm;
}


int16_t Det_Current(uint16_t ad_val)
{
	int16_t def = VCC_HALF - ad_val;	// -VCC/2
	int32_t curr = def * ADC_TO_CURR;	// ADvalue -> Current[uA]
	
	return (int16_t)(curr/1000);			// Current[uA] -> Current[mA]
}