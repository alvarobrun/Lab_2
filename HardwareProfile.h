
#ifndef _HARDWARE_PROFILE_H
#define _HARDWARE_PROFILE_H

// configura puertos de leds como salidas
#define LEDA_SetDigitalOutput() (TRISAbits.TRISA7=0)
#define LEDB_SetDigitalOutput() (TRISBbits.TRISB14=0)

// configura puertos de botones como entradas discretas
#define BTN2_SetDigitalInput() (ANSELBbits.ANSB15=0, TRISBbits.TRISB15=1)
#define BTN3_SetDigitalInput() (ANSELAbits.ANSA13=0, TRISAbits.TRISA13=1)

// configura pull down en entradas para asegurar el cero al abrir los swtches Y DESHABILITA PULL UP!
#define BTN2_SetPullDown() (CNPDBbits.CNPDB15=1, CNPUBbits.CNPUB15=0)
#define BTN3_SetPullDown() (CNPDAbits.CNPDA13=1, CNPUAbits.CNPUA13=0)

// captura estado de entradas de botones 2 y 3
#define BTN2_getvalue   PORTBbits.RB15
#define BTN3_getvalue   PORTAbits.RA13



//habilito interrup multivectores (INTCON), las interrup de CN de puertos A y B (IEC) y las interrup globales (__builtin_enable...)
#define INT_init() do {\
INTCONbits.MVEC= 1;\
IEC0bits.CNAIE = 1;\
IEC0bits.CNBIE = 1;\
__builtin_enable_interrupts( );\
} while(0);



// -------------------------config de interrupcion en PORTA y PORTB  -------------------------------------
      
// habilitamos las interrupciones y tmb cnfiguramos los bits de los registros IEC y IPC2 que son de config de las interrup (prioridad, subprioridad, flag)
// Los registro de configuracion de las interrupciones se pueden ver en el datasheet en la parte de  CHANGE_NOTICE_x_VECTOR

#define BTNA_SetInt() do {\
CNCONAbits.ON=1;\
CNCONAbits.CNSTYLE=1;\
IPC2bits.CNAIP = 2;\
IPC2bits.CNAIS = 1;\
} while(0);

#define BTNB_SetInt() do {\
CNCONBbits.ON=1;\
CNCONBbits.CNSTYLE=1;\
IPC2bits.CNBIP = 2;\
IPC2bits.CNBIS = 1;\
} while(0);
 



// configuramos Leds A y B
#define LEDA_SetHigh()  (LATAbits.LATA7=1)
#define LEDA_SetLow()   (LATAbits.LATA7=0)
#define LEDA_Toggle()   (LATAbits.LATA7=!PORTAbits.RA7)

#define LEDB_SetHigh()  (LATBbits.LATB14=1)
#define LEDB_SetLow()   (LATBbits.LATB14=0)
#define LEDB_Toggle()   (LATBbits.LATB14=!PORTBbits.RB14)




#endif
 
