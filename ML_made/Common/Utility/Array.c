/* -----------------------------------------------------------------------------
	include
----------------------------------------------------------------------------- */
#include "Array.h"


/* -----------------------------------------------------------------------------
	Local Macro
----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
	local Structure
----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
	Local Variable
----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
	local function
----------------------------------------------------------------------------- */
static void validateArray(ary_t *ary)
{
	assert(ary != NULL);
	assert(ary->size != 0);
	assert(ary->size <= MAX_SIZE);
}


/* -----------------------------------------------------------------------------
	private function
----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
	public function
----------------------------------------------------------------------------- */
void Array_Init(ary_t *ary, int16_t ini_val)
{
	validateArray(ary);
	
	for(uint8_t i = 0; i < ary->size; i++)
	{
		ary->array[i] = ini_val;
	}
}


void Array_Add(ary_t *ary, int16_t add_val)
{
	validateArray(ary);
	
	ary->array[ary->counter] = add_val;
	ary->counter++;

	if( ary->counter >= ary->size )
	{
		ary->counter = 0;
	}
}


int32_t Array_Sum(ary_t *ary)
{
	validateArray(ary);

	int32_t sum = 0;

	for(uint8_t i = 0; i < ary->size; i++)
	{
		sum += ary->array[i];
	}

	return	sum;
}


int16_t Array_Ave(ary_t *ary)
{
	int32_t sum = Array_Sum(ary);
	
	return (int16_t)(sum/ary->size);
}