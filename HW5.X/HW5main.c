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
#include <xc.h>

/*
 * 
 */
void write_accel_bars(short *accels){
    int xbar;
    int ybar;
    int startrow = 32;
    int startcol = 64;
    xbar = accels[0]/150;
    ybar = accels[1]/150;
    if (xbar > 20){xbar = 20;}
    else if (xbar < -20){xbar = -20;}
    if (ybar > 20){ybar = 20;}
    else if (ybar < -20){ybar = -20;}
    int i = 0;
    int j = 0;
    if (xbar > 0){
        for (i; i < xbar; i++){
            display_pixel_set(startrow+1,startcol+i,1);
            display_pixel_set(startrow,startcol+i,1);
            display_pixel_set(startrow-1,startcol+i,1);
        }
    }
    else{
        for (i; i > xbar; i--){
            display_pixel_set(startrow+1,startcol+i,1);
            display_pixel_set(startrow,startcol+i,1);
            display_pixel_set(startrow-1,startcol+i,1);
        }
    }
    if (ybar > 0){
            //LATBINV=0b10000000;
        for (j; j < ybar; j++){
            display_pixel_set(startrow+j,startcol+1,1);
            display_pixel_set(startrow+j,startcol,1);
            display_pixel_set(startrow+j,startcol-1,1);
        }
    }
    else{
        for (j; j > ybar; j--){
            display_pixel_set(startrow+j,startcol+1,1);
            display_pixel_set(startrow+j,startcol,1);
            display_pixel_set(startrow+j,startcol-1,1);
        }
    }
    display_draw();
}

void main() {

    PIC32startup();
    display_init();
    acc_setup();

    short accels[3];
    short mags[3];
    short temp;

    acc_read_register(OUT_X_L_A, (unsigned char *) accels, 6);
    acc_read_register(OUT_X_L_M, (unsigned char *) mags, 6);
    acc_read_register(TEMP_OUT_L, (unsigned char *) &temp, 2);

    char message[50];
    //sprintf(message, "x: %d y: %d z: %d", accels[0], accels[1], accels[2]);
    //write_to_screen(message, 7, 2);
    write_accel_bars(accels);
    int go = 0;
    while(1){
        acc_read_register(OUT_X_L_A, (unsigned char *) accels, 6);
        acc_read_register(OUT_X_L_M, (unsigned char *) mags, 6);
        acc_read_register(TEMP_OUT_L, (unsigned char *) &temp, 2);
        if (go >= 1000){
            write_accel_bars(accels);
            display_clear();
           go = 0;
        }
        go += 1;
    }
}


