#include "../../Lab_2.X/platform/buttons.h"
#include "HardwareProfile.h"
#include "../utils/utils.h"
#include <sys/attribs.h> // libreria que tiene la funcion __ISR
#include <xc.h> // libreria que tiene la funcion IFSOCLR y tmb esta definido ahi el _CHANGE_NOTICE_...


void __ISR(_CHANGE_NOTICE_B_VECTOR, IPL2SOFT) _CHANGE_NOTICE_B (void) {
	if (IFS0bits.CNBIF == 1) {
		IFS0CLR = 1 << _IFS0_CNBIF_POSITION; //Clear IFS0bits.CNBIF  ---- ES EL FLAG DE LA INTERRUP DEL PORT B 
		
		if (CNFBbits.CNFB15==1) {
			CNFBCLR=0X8000; //Clear CNFBbits.CNFB15 ------ por que solo pone en 1 el ultimo bit y no los 16 bits del registro?????
			
			LEDB_Toggle();
			UT_delay();
		}
	}
}
