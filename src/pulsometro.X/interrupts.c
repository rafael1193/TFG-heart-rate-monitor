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
/*Files to Include                                                            */
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
/* Interrupt Routines                                                         */
/******************************************************************************/

/* High-priority service */

#if defined(__XC) || defined(HI_TECH_C)
void interrupt high_isr(void)
#elif defined (__18CXX)
#pragma code high_isr=0x08
#pragma interrupt high_isr
void high_isr(void)
#else
#error "Invalid compiler selection for implemented ISR routines"
#endif
{
    if(INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        if(conteo_timer0 >=152) { // 2 segundos aprox.
            send_value = true;
            conteo_timer0 = 0;
        } else {
            conteo_timer0 += 1; // Incrementar contador de desborde de timer0
        }
        INTCONbits.TMR0IF = 0; // Limpiamos bandera de desborde  
    }
    
    /* Timer1
     * timer1_ov_count se incrementa cada vez que timer1 se desborda para
     * poder registrar intervalos mayores de tiempo a 65536 pulsos
     */
    if(T1CONbits.TMR1ON && PIR1bits.TMR1IF) {
        timer1_ov_count += 1;

        PIR1bits.TMR1IF = 0;
    }
    
    /* CCP interrupt handler
     * Cuando llega un flanco de subida, se almacena en CCPR1 el valor de TMR1
     * y se resetea. El valor de CCPR1 es el periodo de la señal. Se tiene en
     * cuenta el desbordamiento que se hubiera producido en timer1 entre pulsos.
     * 
     * TMR1 debe resetearse manualmente.
     */
    if (PIE1bits.CCP1IE && PIR1bits.CCP1IF) {
        period_tmp = CCPR1 + (65536 * timer1_ov_count);
        /* Almacena el valor del periodo si está entre 40 y 200 PPM */
        if(period_tmp >= 0x02DC6C && period_tmp <= 0x0E4E1C) {
            period = period_tmp;
        }
        timer1_ov_count = 0;
        TMR1 = 0;
        PIR1bits.CCP1IF = 0;
        PIR1bits.TMR1IF = 0;
    }    
}

/* Low-priority interrupt routine */
#if defined(__XC) || defined(HI_TECH_C)
void low_priority interrupt low_isr(void)
#elif defined (__18CXX)
#pragma code low_isr=0x18
#pragma interruptlow low_isr
void low_isr(void)
#else
#error "Invalid compiler selection for implemented ISR routines"
#endif
{

#if 0

#endif

}
