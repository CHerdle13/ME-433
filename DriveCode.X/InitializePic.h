/* 
 * File:   Initialize.h
 * Author: Craig
 *
 * Created on April 13, 2015, 9:37 PM
 */

#ifndef INITIALIZEPIC_H
#define	INITIALIZEPIC_H

#ifdef	__cplusplus
extern "C" {
#endif

#define LED1 LATBbits.LATB7
#define LED2 LATBbits.LATB15
#define USER LATBbits.LATB13



int readADC(void);
void PIC32startup(void);


#ifdef	__cplusplus
}
#endif

#endif	/* INITIALIZE_H */

