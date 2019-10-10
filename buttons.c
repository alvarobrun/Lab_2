#include "buttons.h"


void __ISR(_CHANGE_NOTICE_B_VECTOR, IPL2SOFT) _CHANGE_NOTICE_B (void) {
	if (IFS0bits.CNBIF == 1) {
		IFS0CLR = 1 << _IFS0_CNBIF_POSITION; //Clear IFS0bits.CNBIF  ---- ES EL FLAG DE LA INTERRUP DEL PORT B 
	}
}

void __ISR(_CHANGE_NOTICE_A_VECTOR, IPL2SOFT) _CHANGE_NOTICE_A (void) {
	if (IFS0bits.CNAIF == 1) {
		IFS0CLR = 1 << _IFS0_CNAIF_POSITION;
	}
}
