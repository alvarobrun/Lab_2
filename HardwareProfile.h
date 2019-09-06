

#ifndef _HARDWARE_PROFILE_H   /* Guard against multiple inclusion */
#define _HARDWARE_PROFILE_H
#define LEDA_SetDigitalOutput() (TRISAbits.TRISA7 = 0)
#define LEDB_SetDigitalOutput() (TRISBbits.TRISB14 = 0)

//defino mis botones como enrada digital 
#define BTN2_SetDigitalInput() (ANSELAbits.ANSELA13 = 0 , TRISAbits.TRISA13 = 1)//A13 lo config como entrada con tris y digital con ansel
#define BTN3_SetDigitalInput() (ANSELBbits.ANSELB15 = 0 , TRISBbits.TRISB15 = 1)// lo mismo que en con A13

//Leo lo que hay en el registro PORT para saber si se esta apretando el boton 
#define BTN2_getValue() PORTBbits.RB15
#define BTN3_getValue() PORTAbits.RA13


#define LEDA_SetHigh() //LATAbits.LATA7=1;
#define LEDA_SetLow()
#define LEDA_Toggle()

#define LEDB_SetHigh()
#define LEDB_SetLow()
#define LEDB_Toggle()


#endif
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */

