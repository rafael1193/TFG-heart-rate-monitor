/* Pulsómetro
 * Copyright (C) 2015 Rafael-Bailón Ruiz <rafaelbailon@ieee.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
#include <usart.h>

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
    TRISAbits.RA2 = 0;
    
    TRISCbits.RC2 = 1; // Pin 13, CCP1
 
    //LATA register sets whether voltage on output pin is 5V or 0V
    //0=low voltage(0V), 1=high voltage (5V)
    LATAbits.LA1 = 0;
    LATAbits.LA2 = 0;
    /* Setup analog functionality and port direction */

    /* Initialize peripherals */
    
    /* UART initialization 
     * 
     * Set baud rate at 115K (default of RN42 module)
     * baudrate = F_osc/[16 (n + 1)] -> n~10. With this value, baudrate is 
     * 113.636, meaning an error of -1.36%.
     * (This formula is valid with SYNC = 0 BRGH = 1 BRG16 = 0)
     * See TABLE 20-3 of datasheet
     */
    const unsigned SPBRG = 10;
    OpenUSART( USART_TX_INT_OFF  &
               USART_RX_INT_OFF  &
               USART_ASYNCH_MODE &
               USART_EIGHT_BIT   &
               USART_BRGH_HIGH,
               SPBRG              );

    /* Configure the IPEN bit (1=on) in RCON to turn on/off int priorities */

    /* Enable interrupts */
    
    /* Timer 0 
     * T_t0overflow = 4 * Tosc * 256 * TOPS
     */
    TMR0L = 161; // Desfase para que cuente de segundo en segundo
    T0CONbits.T0PS0 = 1;
    T0CONbits.T0PS1 = 1;
    T0CONbits.T0PS2 = 1; //TOPS2:TOPS0 -> 1/2 a 1/256
    T0CONbits.PSA = 0; // Use prescaler: 0
    T0CONbits.T0CS = 0; // 0: Internal instruction cycle clock = Fosc/4
    T0CONbits.TMR0ON = 1;
    T0CONbits.T08BIT = 1;
    INTCONbits.TMR0IE = 1;


    /* Timer 1 */
    TMR1 = 0;
    T1CONbits.RD16 = 1; // 1: 16bit mode
    T1CONbits.T1CKPS = 0b11; // b11: Prescale 1/8
    T1CONbits.TMR1CS = 0; // 0: Internal clock
    T1CONbits.TMR1ON = 1; // 1: Enables Timer1
    
    /* CCP1 in Capture mode
     * Section 15.0 of Datasheet
     */
    CCP1CONbits.CCP1M = 0b0101; // 0101: Capture every rising edge
    PIE1bits.CCP1IE = 1;
    
    /* Enable interrupts */
    INTCONbits.GIE = 1;
}

