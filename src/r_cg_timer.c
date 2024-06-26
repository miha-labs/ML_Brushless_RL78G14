/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2021 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_timer.c
* Version      : CodeGenerator for RL78/G14 V2.05.06.02 [08 Nov 2021]
* Device(s)    : R5F104ML
* Tool-Chain   : CCRL
* Description  : This file implements device driver for TAU module.
* Creation Date: 
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_timer.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TAU0_Create
* Description  : This function initializes the TAU0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Create(void)
{
    TAU0EN = 1U;    /* supplies input clock */
    TPS0 = _0000_TAU_CKM0_FCLK_0 | _0030_TAU_CKM1_FCLK_3 | _0000_TAU_CKM2_FCLK_1 | _0000_TAU_CKM3_FCLK_8;
    /* Stop all channels */
    TT0 = _0001_TAU_CH0_STOP_TRG_ON | _0002_TAU_CH1_STOP_TRG_ON | _0004_TAU_CH2_STOP_TRG_ON |
          _0008_TAU_CH3_STOP_TRG_ON | _0200_TAU_CH1_H8_STOP_TRG_ON | _0800_TAU_CH3_H8_STOP_TRG_ON;
    /* Mask channel 0 interrupt */
    TMMK00 = 1U;    /* disable INTTM00 interrupt */
    TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
    /* Mask channel 1 interrupt */
    TMMK01 = 1U;    /* disable INTTM01 interrupt */
    TMIF01 = 0U;    /* clear INTTM01 interrupt flag */
    /* Mask channel 1 higher 8 bits interrupt */
    TMMK01H = 1U;    /* disable INTTM01H interrupt */
    TMIF01H = 0U;    /* clear INTTM01H interrupt flag */
    /* Mask channel 2 interrupt */
    TMMK02 = 1U;    /* disable INTTM02 interrupt */
    TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
    /* Mask channel 3 interrupt */
    TMMK03 = 1U;    /* disable INTTM03 interrupt */
    TMIF03 = 0U;    /* clear INTTM03 interrupt flag */
    /* Mask channel 3 higher 8 bits interrupt */
    TMMK03H = 1U;    /* disable INTTM03H interrupt */
    TMIF03H = 0U;    /* clear INTTM03H interrupt flag */
    /* Set INTTM00 low priority */
    TMPR100 = 1U;
    TMPR000 = 1U;
    /* Set INTTM01 low priority */
    TMPR101 = 1U;
    TMPR001 = 1U;
    /* Channel 0 used as interval timer */
    TMR00 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0000_TAU_TRIGGER_SOFTWARE | _0000_TAU_MODE_INTERVAL_TIMER | _0000_TAU_START_INT_UNUSED;
    TDR00 = _7CFF_TAU_TDR00_VALUE;
    TO0 &= ~_0001_TAU_CH0_OUTPUT_VALUE_1;
    TOE0 &= ~_0001_TAU_CH0_OUTPUT_ENABLE;
    /* Channel 1 used as interval timer */
    TMR01 = _8000_TAU_CLOCK_SELECT_CKM1 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_16BITS_MODE |
            _0000_TAU_TRIGGER_SOFTWARE | _0000_TAU_MODE_INTERVAL_TIMER | _0000_TAU_START_INT_UNUSED;
    TDR01 = _9C3F_TAU_TDR01_VALUE;
    TOM0 &= ~_0002_TAU_CH1_OUTPUT_COMBIN;
    TOL0 &= ~_0002_TAU_CH1_OUTPUT_LEVEL_L;
    TO0 &= ~_0002_TAU_CH1_OUTPUT_VALUE_1;
    TOE0 &= ~_0002_TAU_CH1_OUTPUT_ENABLE;
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel0_Start
* Description  : This function starts TAU0 channel 0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel0_Start(void)
{
    TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
    TMMK00 = 0U;    /* enable INTTM00 interrupt */
    TS0 |= _0001_TAU_CH0_START_TRG_ON;
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel0_Stop
* Description  : This function stops TAU0 channel 0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel0_Stop(void)
{
    TT0 |= _0001_TAU_CH0_STOP_TRG_ON;
    /* Mask channel 0 interrupt */
    TMMK00 = 1U;    /* disable INTTM00 interrupt */
    TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel1_Start
* Description  : This function starts TAU0 channel 1 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel1_Start(void)
{
    TMIF01 = 0U;    /* clear INTTM01 interrupt flag */
    TMMK01 = 0U;    /* enable INTTM01 interrupt */
    TS0 |= _0002_TAU_CH1_START_TRG_ON;
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel1_Stop
* Description  : This function stops TAU0 channel 1 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel1_Stop(void)
{
    TT0 |= _0002_TAU_CH1_STOP_TRG_ON;
    /* Mask channel 1 interrupt */
    TMMK01 = 1U;    /* disable INTTM01 interrupt */
    TMIF01 = 0U;    /* clear INTTM01 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_TMR_RD0_Create
* Description  : This function initializes the TMRD0 and TMRD1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RD0_Create(void)
{
    TRD0EN = 1U;    /* enable input clock supply */
    TRDSTR |= _04_TMRD_TRD0_COUNT_CONTINUES | _08_TMRD_TRD1_COUNT_CONTINUES;
    TRDSTR &= (uint8_t)~_03_TRD_COUNT_STATR_INITIAL_VALUE;  /* disable TMRD operation */
    TRDMK0 = 1U;    /* disable TMRD0 interrupt */
    TRDIF0 = 0U;    /* clear TMRD0 interrupt flag */
    TRDMK1 = 1U;    /* disable TMRD1 interrupt */
    TRDIF1 = 0U;    /* clear TMRD1 interrupt flag */
    TRDMR = _20_TMRD_TRDGRD0_BUFFER | _40_TMRD_TRDGRC1_BUFFER | _80_TMRD_TRDGRD1_BUFFER;
    TRDFCR |= _02_TMRD_TRANSFER_TMRD1_UNDERFLOW | _04_TMRD_NORMAL_PHASE_LEVEl_LH | _00_TMRD_COUNTER_PHASE_LEVEl_HL;
    TRDDF0 = _00_TMRD_TRDIOD_FORCEDCUTOFF_DISABLE | _20_TMRD_TRDIOB_LOW_OUTPUT;
    TRDDF1 = _00_TMRD_TRDIOD_FORCEDCUTOFF_DISABLE | _00_TMRD_TRDIOC_FORCEDCUTOFF_DISABLE |
             _00_TMRD_TRDIOB_FORCEDCUTOFF_DISABLE | _C0_TMRD_TRDIOA_HIGH_OUTPUT;
    TRDOER1 = _01_TMRD_TRDIOA0_OUTPUT_DISABLE | _00_TMRD_TRDIOB0_OUTPUT_ENABLE | _04_TMRD_TRDIOC0_OUTPUT_DISABLE |
              _00_TMRD_TRDIOD0_OUTPUT_ENABLE | _00_TMRD_TRDIOA1_OUTPUT_ENABLE | _00_TMRD_TRDIOB1_OUTPUT_ENABLE |
              _00_TMRD_TRDIOC1_OUTPUT_ENABLE | _00_TMRD_TRDIOD1_OUTPUT_ENABLE;
    TRDCR0 = _00_TMRD_INETNAL_CLOCK_F1_FIH;
    TRDCR1 = _00_TMRD_INETNAL_CLOCK_F1_FIH;
    TRDIER0 = _00_TMRD_IMIA_DISABLE | _00_TMRD_IMIB_DISABLE;
    TRDIER1 = _00_TMRD_IMIA_DISABLE | _00_TMRD_IMIB_DISABLE | _00_TMRD_OVIE_DISABLE;
    TRD0 = _0000_TMRD_RD0_VALUE;
    TRDGRA0 = _0C7E_TMRD_TRDGRA0_VALUE;
    TRDGRB0 = _0C5F_TMRD_TRDGRB0_VALUE;
    TRDGRD0 = _0C5F_TMRD_TRDGRD0_VALUE;
    TRDGRA1 = _0C5F_TMRD_TRDGRA1_VALUE;
    TRDGRB1 = _0C5F_TMRD_TRDGRB1_VALUE;
    TRDGRC1 = _0C5F_TMRD_TRDGRC1_VALUE;
    TRDGRD1 = _0C5F_TMRD_TRDGRD1_VALUE;
    /* Set TRDIOB0 pin */
    POM1 &= 0xDFU;
    P1 &= 0xDFU;
    PM1 &= 0xDFU;
    /* Set TRDIOD0 pin */
    POM1 &= 0xEFU;
    P1 &= 0xEFU;
    PM1 &= 0xEFU;
    /* Set TRDIOA1 pin */
    POM1 &= 0xF7U;
    PMC1 &= 0xF7U;
    P1 &= 0xF7U;
    PM1 &= 0xF7U;
    /* Set TRDIOB1 pin */
    PMC1 &= 0xFBU;
    P1 &= 0xFBU;
    PM1 &= 0xFBU;
    /* Set TRDIOC1 pin */
    POM1 &= 0xFDU;
    P1 &= 0xFDU;
    PM1 &= 0xFDU;
    /* Set TRDIOD1 pin */
    POM1 &= 0xFEU;
    P1 &= 0xFEU;
    PM1 &= 0xFEU;
}

/***********************************************************************************************************************
* Function Name: R_TMR_RD0_Start
* Description  : This function starts TMRD0 and TMRD1 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RD0_Start(void)
{
    volatile uint8_t trdsr_dummy;

    trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
    TRDSTR |= _04_TMRD_TRD0_COUNT_CONTINUES;
    TRDSTR |= _08_TMRD_TRD1_COUNT_CONTINUES;
    TRDSTR |= _03_TRD_COUNT_STATR_INITIAL_VALUE;    /* start TMRD counter */
}

/***********************************************************************************************************************
* Function Name: R_TMR_RD0_Stop
* Description  : This function stops TMRD0 and TMRD1 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RD0_Stop(void)
{
    volatile uint8_t trdsr_dummy;

    TRDSTR |= _04_TMRD_TRD0_COUNT_CONTINUES | _08_TMRD_TRD1_COUNT_CONTINUES;
    TRDSTR &= (uint8_t)~_03_TRD_COUNT_STATR_INITIAL_VALUE;  /* stop TMRD counter */
    trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
