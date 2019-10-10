// Configuracion de interrupciones para que se interrumpa con flancos de subida, de bajadas o con ambos 

#ifndef Flancos_interrup_config
#define Flancos_interrup_config


//----------- Boton A ----------------

#define BTNA_SetIntLowEdge() do {\
    CNEN0Abits.CNIE0A13=0;\
    CNEN1Abits.CNIE1A13=1;\
} while(0);

     
#define BTNA_SetIntHighEdge() do {\
    CNEN0Abits.CNIE0A13=1;\
    CNEN1Abits.CNIE1A13=0;\
  } while(0);

#define BTNA_SetIntBothEdge() do {\
    CNEN0Abits.CNIE0A13=1;\
    CNEN1Abits.CNIE1A13=1;\
  } while(0);


//------------- Boton B ------------------

#define BTNB_SetIntLowEdge() do {\
    CNEN0Bbits.CNIE0B15=0;\
    CNEN1Bbits.CNIE1B15=1;\
} while(0);

#define BTNB_SetIntHighEdge() do {\
    CNEN0Bbits.CNIE0B15=1;\
    CNEN1Bbits.CNIE1B15=0;\
 }while(0);

#define BTNB_SetIntBothEdge() do {\
    CNEN0Bbits.CNIE0B15=1;\
    CNEN1Bbits.CNIE1B15=1;\
  } while(0);




#endif
