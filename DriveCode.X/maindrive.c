/* 
 * File:   maindrive.c
 * Author: Craig
 *
 * Created on June 2, 2015, 4:01 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "InitializePic.h"
#include <xc.h>
#include <sys/attribs.h>

/*
 * 
 */
void main()
{
    PIC32startup();
    while(PORTBbits.RB13)
    {
        ;   //do nothing until the user button is pressed
    }

    LATBINV = 0b10000000;
    // set motor 1 to forward
    OC1RS = 600;
    OC2RS = 0;

    //set motor 2 to forward
    OC3RS = 600;
    OC4RS = 0;

    while(1)
    {
        ;
    }
    
}

