void __ISR(_CHANGE_NOTICE_B_VECTOR, IPL2SOFT) _CHANGE_NOTICE_B (void) {
	if (IFS0bits.CNBIF == 1) {
		IFS0CLR= 1 << _IFS0_CNBIF_POSITION; //Clear IFS0bits.CNBIF  ---- ES EL FLAG DE LA INTERRUP DEL PORT B 
		
		if (CNFBbits.CNFB15==1) {
			CNFBCLR=0X8000; //Clear CNFBbits.CNFB15 ------ por que solo pone en 1 el ultimo bit y no los 16 bits del registro?????
			
			.............................CODIGO NUESTRO ........................
			LEDB_Toggle();
			UT_delay();
		}
	}
}





En la implementación de la función CLK_init para setear el Clock del sistema (antes de configurar el Timer 2) se reemplazaron las siguientes líneas:
Corregir: 
SYSTEM_RegUnlock();	SYSKEY = 0x0; //write invalid key to force lock
SYSKEY = 0xAA996655; //write Key1 to SYSKEY
SYSKEY = 0x556699AA; //write Key2 to SYSKEY
SYSTEM_RegLock();	SYSKEY = 0x00000000;



CNSTATx:
El registro CNSTATx indica si un cambio
ocurrió en el pin correspondiente desde la última lectura
del bit PORTx.

IFS0<8> FLAG DE LA INTERRUPCION EN CHNGE_NOTICE_A_VECTOR
IFS0<9> FLAG DE LA INTERRUPCION EN CHNGE_NOTICE_B_VECTOR


CNFx: (pregunta para hacerrrrrrrr)
El registro CNFx se implementa para cada puerto. Este registro contiene banderas para eventos de notificación de cambio.
Estas banderas se establecen si el borde de transición válido, seleccionado en los registros CNEN0x y CNEN1x, se detecta.
CNFx bits must be cleared in software to get the next Change Notification interrupt


