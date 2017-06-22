/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PWM2.c
**     Project   : Project
**     Processor : MC9S12XEP100MAG
**     Component : PWM
**     Version   : Component 02.231, Driver 01.16, CPU db: 3.00.036
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2016/8/10, 13:51
**     Abstract  :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings  :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       2             |  PP2_KWP2_PWM2_SCK1_TIMIOC2
**             ----------------------------------------------------
**
**         Timer name                  : PWM2 [8-bit]
**         Counter                     : PWMCNT2   [$030E]
**         Mode register               : PWMCTL    [$0305]
**         Run register                : PWME      [$0300]
**         Prescaler                   : PWMPRCLK  [$0303]
**         Compare 1 register          : PWMPER2   [$0316]
**         Compare 2 register          : PWMDTY2   [$031E]
**         Flip-flop 1 register        : PWMPOL    [$0301]
**
**         User handling procedure     : not specified
**
**         Output pin
**
**         Port name                   : P
**         Bit number (in port)        : 2
**         Bit mask of the port        : $0004
**         Port data register          : PTP       [$0258]
**         Port control register       : DDRP      [$025A]
**
**         Runtime setting period      : none
**         Runtime setting ratio       : calculated
**         Initialization:
**              Aligned                : Left
**              Output level           : low
**              Timer                  : Disabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 5000000 Hz
**           Initial value of            period        pulse width (ratio 10%)
**             Xtal ticks              : 800           80
**             microseconds            : 50            5
**             seconds (real)          : 0.00005       0.000005
**
**     Contents  :
**         Enable     - byte PWM2_Enable(void);
**         Disable    - byte PWM2_Disable(void);
**         SetRatio16 - byte PWM2_SetRatio16(word Ratio);
**         SetValue   - byte PWM2_SetValue(void);
**         ClrValue   - byte PWM2_ClrValue(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/


/* MODULE PWM2. */

#include "PWM2.h"

#pragma DATA_SEG PWM2_DATA             /* Select data segment "PWM2_DATA" */

#pragma CODE_SEG PWM2_CODE

static bool EnUser;                    /* Enable/Disable device by user */
static word RatioStore;                /* Ratio of L-level to H-level */


/*
** ===================================================================
**     Method      :  HWEnDi (component PWM)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the 
**         component. The method is called automatically as a part of the 
**         Enable and Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void)
{
  if (EnUser) {                        /* Enable device? */
    PWME_PWME2 = 1U;                   /* Run counter */
  } else {                             /* Disable device? */
    PWME_PWME2 = 0U;                   /* Stop counter */
    PWMCNT2 = 0U;                      /* Reset counter */
  }
}

/*
** ===================================================================
**     Method      :  SetRatio (component PWM)
**
**     Description :
**         The method reconfigures the compare and modulo registers of 
**         the peripheral(s) when the speed mode changes. The method is 
**         called automatically as a part of the component 
**         SetHigh/SetLow/SetSlow methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma MESSAGE DISABLE C12056         /* Disable WARNING C12056: SP debug info incorrect because of optimization */
static void SetRatio(void)
{
  PWMDTY2 = (byte)(((0xFAUL * (dword)RatioStore) + 0x8000UL) >> 0x10U); /* Calculate new value according to the given ratio */
}
#pragma MESSAGE DEFAULT C12056         /* Re-enable WARNING C12056 */

/*
** ===================================================================
**     Method      :  PWM2_Enable (component PWM)
**
**     Description :
**         This method enables the component - it starts the signal
**         generation. Events may be generated (<DisableEvent>
**         /<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte PWM2_Enable(void)
{
  if (!EnUser) {                       /* Is the device disabled by user? */
    EnUser = TRUE;                     /* If yes then set the flag "device enabled" */
    HWEnDi();                          /* Enable the device */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  PWM2_Disable (component PWM)
**
**     Description :
**         This method disables the component - it stops the signal
**         generation and events calling. When the timer is disabled,
**         it is possible to call <ClrValue> and <SetValue> methods.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte PWM2_Disable(void)
{
  if (EnUser) {                        /* Is the device enabled by user? */
    EnUser = FALSE;                    /* If yes then set the flag "device disabled" */
    HWEnDi();                          /* Disable the device */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  PWM2_SetRatio16 (component PWM)
**
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. Value 0 - 65535 value
**         is proportional to ratio 0 - 100%. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**         The method is available only if method <SetPeriodMode> is
**         not selected.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte PWM2_SetRatio16(word Ratio)
{
  RatioStore = Ratio;                  /* Store new value of the ratio */
  SetRatio();                          /* Calculate and set up new appropriate values of the duty and period registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  PWM2_SetValue (component PWM)
**
**     Description :
**         This method sets (to "1" = "High") timer flip-flop output
**         signal level. It allows to the user to directly set the
**         output pin value (=flip-flop state), and can set the signal
**         polarity. This method only works when the timer is disabled
**         (Disable) otherwise it returns the error code. <ClrValue>
**         and <SetValue> methods are used for setting the initial
**         state.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_ENABLED - Component is enabled.
**                           Component must be disabled (see "Disable
**                           method")
** ===================================================================
*/
byte PWM2_SetValue(void)
{
  if (EnUser) {                        /* Is the device enabled by user? */
    return ERR_ENABLED;                /* If yes then error */
  }
  PWMPOL_PPOL2 = 1U;                   /* Set output signal level to high */
  PTP_PTP2 = 1U;
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  PWM2_ClrValue (component PWM)
**
**     Description :
**         This method clears (sets to "0" = "Low") timer flip-flop
**         output signal level. It allows to the user to directly set
**         the output pin value (=flip-flop state), and can set the
**         signal polarity. This method only works when the timer is
**         disabled (Disable) otherwise it returns the error code.
**         <ClrValue> and <SetValue> methods are used for setting the
**         initial state.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_ENABLED - Component is enabled.
**                           Component must be disabled (see "Disable
**                           method")
** ===================================================================
*/
byte PWM2_ClrValue(void)
{
  if (EnUser) {                        /* Is the device enabled by user? */
    return ERR_ENABLED;                /* If yes then error */
  }
  PWMPOL_PPOL2 = 0U;                   /* Set output signal level to low */
  PTP_PTP2 = 0U;
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  PWM2_Init (component PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the component's 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PWM2_Init(void)
{
  /* PWMCNT2: PWMCNT2=0 */
  setReg8(PWMCNT2, 0x00U);             /* Reset Counter */ 
  /* PWMSDN: PWMIF=1,PWMIE=0,PWMRSTRT=0,PWMLVL=0,??=0,PWM7IN=0,PWM7INL=0,PWM7ENA=0 */
  setReg8(PWMSDN, 0x80U);              /* Emergency shutdown feature settings */ 
  RatioStore = 0x1999U;                /* Store initial value of the ratio */
  EnUser = FALSE;                      /* Disable device */
  /* PWMDTY2: PWMDTY2=0x19 */
  setReg8(PWMDTY2, 0x19U);             /* Store initial value to the duty-compare register */ 
  /* PWMPER2: PWMPER2=0xFA */
  setReg8(PWMPER2, 0xFAU);             /* and to the period register */ 
  /* PWMPRCLK: ??=0,PCKB2=0,PCKB1=0,PCKB0=0,??=0,PCKA2=0,PCKA1=0,PCKA0=0 */
  setReg8(PWMPRCLK, 0x00U);            /* Set prescaler register */ 
  /* PWMSCLB: BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=1,BIT1=0,BIT0=0 */
  setReg8(PWMSCLB, 0x04U);             /* Set scale register */ 
  /* PWMCLK: PCLK2=1 */
  setReg8Bits(PWMCLK, 0x04U);          /* Select clock source */ 
  HWEnDi();                            /* Enable/disable device according to status flags */
}

/* END PWM2. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
