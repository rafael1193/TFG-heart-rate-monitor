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

      /* This code stub shows general interrupt handling.  Note that these
      conditional statements are not handled within 3 seperate if blocks.
      Do not use a seperate if block for each interrupt flag to avoid run
      time errors. */

    
      /* TODO Add High Priority interrupt routine code here. */

      /* Determine which flag generated the interrupt */
    if(INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        if(conteo_timer0 >=38) { // Si se desborda 75 veces, ha pasado casi un segundo (0.999987s)
            led_on ^= 1; // ^= makes led_on toggle its value
            conteo_timer0 = 0;
            TMR0L = 39; // 75 para 1s, 
        } else {
            conteo_timer0 += 1; // Incrementar contador de desborde de timer0
        }
        INTCONbits.TMR0IF = 0;      // Limpiamos bandera de desborde
        
    }
    
    /* Timer1
     * timer1_ov_count se incrementa cada vez que timer1 se desborda para
     * poder registrar intervalos mayores de tiempo a 65536 pulsos
     */
    if(T1CONbits.TMR1ON && PIR1bits.TMR1IF) {
        led1_on ^= 1;
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
        TMR1 = 0;
        timer1_ov_count = 0;
        period = CCPR1 + (65536 * timer1_ov_count);
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

      /* This code stub shows general interrupt handling.  Note that these
      conditional statements are not handled within 3 seperate if blocks.
      Do not use a seperate if block for each interrupt flag to avoid run
      time errors. */

#if 0

      /* TODO Add Low Priority interrupt routine code here. */

      /* Determine which flag generated the interrupt */
      if(<Interrupt Flag 1>)
      {
          <Interrupt Flag 1=0>; /* Clear Interrupt Flag 1 */
      }
      else if (<Interrupt Flag 2>)
      {
          <Interrupt Flag 2=0>; /* Clear Interrupt Flag 2 */
      }
      else
      {
          /* Unhandled interrupts */
      }

#endif

}
