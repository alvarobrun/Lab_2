/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
#include "Clock.h"
#include "xc.h"
#include "stdint.h"



/*  A brief description of a section can be given directly below the section
    banner.
 */
void CLOCK_Initialize( void ) 
{
        //SYSTEM_RegUnlock(); // ORPOL disabled; SIDL disabled; SRC SOSC; TUN Center frequency; POL disabled; ON disabled;
        SYSKEY = 0x0; //write invalid key to force lock
        SYSKEY = 0xAA996655; //write Key1 to SYSKEY
        SYSKEY = 0x556699AA; //write Key2 to SYSKEY
        OSCTUN = 0x0 ;   // PLLODIV 1:4; PLLMULT 12x; PLLICLK POSC;
        _8MHz();  //SPLLCON ; // SBOREN disabled; VREGS disabled; RETEN disabled;
        PWRCON = PWRCON | 0x0 ; // configure REFO to request POSC :POSC Errata workaround
        REFO1CON = 0x9002 ; // delay for 9 ms :POSC Errata workaround
        unsigned int start = __builtin_mfc0(_CP0_COUNT, _CP0_COUNT_SELECT);
        while ((__builtin_mfc0(_CP0_COUNT, _CP0_COUNT_SELECT)) - start < ( unsigned int )( 0.009 * 8000000 / 2 )); //Clear NOSC,CLKLOCK and OSWEN bits :POSC Errata workaround
        OSCCONCLR = _OSCCON_NOSC_MASK | _OSCCON_CLKLOCK_MASK |
        _OSCCON_OSWEN_MASK;
        // CF No Clock Failure; FRCDIV FRC/1; SLPEN Device will enter Idle mode when a
        //WAIT instruction is issued; NOSC SPLL; SOSCEN Disable Seconday Oscillator
        //(configure SOSCSEL=ON for GPIO operation); CLKLOCK Clock and PLL selections are
        //not locked and may be modified; OSWEN Switch is Complete;
        OSCCON = ( 0x100 | _OSCCON_OSWEN_MASK);
        SYSKEY = 0x00000000;
        // wait for switch
        while (OSCCONbits.OSWEN == 1 );
        REFO1CONCLR = 0x9002 ;
        // ON disabled; DIVSWEN disabled; RSLP disabled; ROSEL SYSCLK; OE disabled; SIDL disabled; RODIV 0;
        REFO1CON = REFO1CON | 0x0 ;
        while (!REFO1CONbits.ACTIVE & REFO1CONbits.ON);
        // ROTRIM 0;
        REFO1TRIM = REFO1TRIM | 0x0 ;
}
/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */



/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Description
    Full description, explaining the purpose and usage of the function.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Precondition
    List and describe any required preconditions. If there are no preconditions,
    enter "None."

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>

  @Remarks
    Describe any special behavior not described above.
    <p>
    Any additional remarks.

  @Example
    @code
    if(ExampleFunctionName(1, 2) == 0)
    {
        return 3;
    }
 */


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

// *****************************************************************************

/** 
  @Function
    int ExampleInterfaceFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */


/* *****************************************************************************
 End of File
 */
