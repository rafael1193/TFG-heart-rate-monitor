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
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */

#define _XTAL_FREQ 20000000
#define SYS_FREQ   20000000L
#define FCY        SYS_FREQ/4

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

volatile unsigned int conteo_timer0;
volatile unsigned int timer1_ov_count;
volatile unsigned long int period;
volatile unsigned long int period_tmp;
volatile bool send_value = false;

void InitApp(void);         /* I/O and Peripheral Initialization */
