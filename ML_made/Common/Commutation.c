/* -----------------------------------------------------------------------------
	include
----------------------------------------------------------------------------- */
#include	"Commutation.h"

#include	"../Interface/ML_PWM.h"
#include	"../Interface/ML_ADC.h"


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
static void CWTable(uint8_t sector)
{
	switch(sector)
	{
		case 5:
			PWMout_PP_PN(CH_U);	PWMout_LO_HI(CH_V);	PWMout_LO_LO(CH_W);
			ADC_SetChannel(ADC_CH_V);
			break;

		case 1:
			PWMout_PP_PN(CH_U);	PWMout_LO_LO(CH_V);	PWMout_LO_HI(CH_W);
			ADC_SetChannel(ADC_CH_W);
			break;
		
		case 3:
			PWMout_LO_LO(CH_U);	PWMout_PP_PN(CH_V);	PWMout_LO_HI(CH_W);
			ADC_SetChannel(ADC_CH_W);
			break;

		case 2:
			PWMout_LO_HI(CH_U);	PWMout_PP_PN(CH_V);	PWMout_LO_LO(CH_W);
			ADC_SetChannel(ADC_CH_U);
			break;

		case 6:
			PWMout_LO_HI(CH_U);	PWMout_LO_LO(CH_V);	PWMout_PP_PN(CH_W);
			ADC_SetChannel(ADC_CH_U);
			break;

		case 4:
			PWMout_LO_LO(CH_U);	PWMout_LO_HI(CH_V);	PWMout_PP_PN(CH_W);
			ADC_SetChannel(ADC_CH_V);
			break;

		default:
			PWMout_LO_LO(CH_U);	PWMout_LO_LO(CH_V);	PWMout_LO_LO(CH_W);
			ADC_SetChannel(ADC_CH_U);
			break;
	}
}


static void CCWTable(uint8_t sector)
{
	switch(sector)
	{
		case 3:
			PWMout_LO_LO(CH_U);	PWMout_LO_HI(CH_V);	PWMout_PP_PN(CH_W);
			ADC_SetChannel(ADC_CH_V);
			break;
			
		case 1:
			PWMout_LO_HI(CH_U);	PWMout_LO_LO(CH_V);	PWMout_PP_PN(CH_W);
			ADC_SetChannel(ADC_CH_U);
			break;
			
		case 5:
			PWMout_LO_HI(CH_U);	PWMout_PP_PN(CH_V);	PWMout_LO_LO(CH_W);
			ADC_SetChannel(ADC_CH_U);
			break;

		case 4:
			PWMout_LO_LO(CH_U);	PWMout_PP_PN(CH_V);	PWMout_LO_HI(CH_W);
			ADC_SetChannel(ADC_CH_W);
			break;

		case 6:
			PWMout_PP_PN(CH_U);	PWMout_LO_LO(CH_V);	PWMout_LO_HI(CH_W);
			ADC_SetChannel(ADC_CH_W);
			break;
			
		case 2:
			PWMout_PP_PN(CH_U);	PWMout_LO_HI(CH_V);	PWMout_LO_LO(CH_W);
			ADC_SetChannel(ADC_CH_V);
			break;

		default:
			PWMout_LO_LO(CH_U);	PWMout_LO_LO(CH_V);	PWMout_LO_LO(CH_W);
			ADC_SetChannel(ADC_CH_U);
			break;
	}
}


static void FreeTable(void)
{
	PWMout_LO_LO(CH_U);	PWMout_LO_LO(CH_V);	PWMout_LO_LO(CH_W);
	ADC_SetChannel(ADC_CH_U);
}


static void BrakeTable(void)
{
	PWMout_LO_HI(CH_U);	PWMout_LO_HI(CH_V);	PWMout_LO_HI(CH_W);
	ADC_SetChannel(ADC_CH_U);
}


/* -----------------------------------------------------------------------------
	public function
----------------------------------------------------------------------------- */
void Commutation(rot_e rot, uint8_t sector)
{
	switch(rot)
	{
		case ROT_CW:
			CWTable( sector );
			break;

		case ROT_CCW:
			CCWTable( sector );
			break;

		case ROT_FREE:
			FreeTable();
			break;

		case ROT_BRAKE:
			BrakeTable();
			break;

		case ROT_NOTDET:
			FreeTable();
			break;
			
		default:
			assert(0);
			break;
	}
}

