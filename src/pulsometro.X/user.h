/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */

#define _XTAL_FREQ 20000000

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

unsigned int conteo_timer0;
int led_on = 1;

void InitApp(void);         /* I/O and Peripheral Initialization */
