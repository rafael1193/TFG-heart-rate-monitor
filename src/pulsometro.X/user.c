/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#endif

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* TODO Initialize User Ports/Peripherals/Project here */
 
    //TRISA register sets whether pins on Port A are inputs or outputs
    //We're using an output on Pin 3, which is "RA1" (see datasheet)
    //1=input, 0=output
    TRISAbits.RA1 = 0;
    
//    TRISBbits.RB0 = 1; // Configure port RB1/INT0 as input
 
    //LATA register sets whether voltage on output pin is 5V or 0V
    //0=low voltage(0V), 1=high voltage (5V)
    LATAbits.LA1 = 1;
    /* Setup analog functionality and port direction */

    /* Initialize peripherals */

    /* Configure the IPEN bit (1=on) in RCON to turn on/off int priorities */

    /* Enable interrupts */
    
    TMR0L = 161; // Desfase para que cuente de segundo en segundo
    T0CONbits.T0PS0 = 1;
    T0CONbits.T0PS1 = 1;
    T0CONbits.T0PS2 = 1; //TOPS2:TOPS0 -> 1/2 a 1/256
    T0CONbits.PSA = 0; // Use prescaler: 0
    T0CONbits.T0CS = 0; // 0: Internal instruction cycle clock = Fosc/4
    T0CONbits.TMR0ON = 1;
    T0CONbits.T08BIT = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE = 1;
    // T_t0overflow = 4 * Tosc * 256 * TOPS
    
//    INTCONbits.INT0IF = 0;
//    INTCONbits.INT0IE = 1;
//    INTCON2bits.INTEDG0 = 1;
//    ei();
}

