#ifndef Flancos_interrup_config
#define Flancos_interrup_config


//----------- Boton A ----------------

#define BTNA_SetIntLowEdge() do {\
CNEN0A = 0;\
CNEN1A = 1;\
} while(0);

#define BTNA_SetIntHighEdge() do {\
CNEN0A = 1;\
CNEN1A =0;\
  } while(0);

#define BTNX_SetIntBothEdge() do {\
CNEN0A = 1;\
CNEN1A =1;\
  } while(0);


//------------- Boton B ------------------

#define BTNB_SetIntLowEdge() do {\
CNEN0A = 0;\
CNEN1A = 1;\
} while(0);

#define BTNB_SetIntHighEdge() do {\
CNEN0A = 1;\
CNEN1A =0;\
  } while(0);

#define BTNB_SetIntBothEdge() do {\
CNEN0A = 1;\
CNEN1A =1;\
  } while(0);




#endif