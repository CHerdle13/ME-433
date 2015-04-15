/* 
 * File:   HW5main.c
 * Author: Craig
 *
 * Created on April 15, 2015, 4:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "accel.h"
#include "Initialize.h"
#include "i2c_display.h"
#include "i2c_master_int.h"

/*
 * 
 */
void main() {

    acc_setup();

    short accels[3];
    short mags[3];
    short temp;

    acc_read_register(OUT_X_L_A, (unsigned char *) accels, 6);
    acc_read_register(OUT_X_L_M, (unsigned char *) mags, 6);
    acc_read_register(TEMP_OUT_L, (unsigned char *) &temp, 2);

    char message[20];
    sprintf(message, "x: %d y: %d z: %d temp: %d", accels[0], accels[1], accels[2], temp);
    write_to_screen(message, 32, 2);
    while(1){;};
}

