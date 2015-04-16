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
void write_accel_bars(short accels[3]){
    int xbar;
    int ybar;
    int startrow = 32;
    int startcol = 64;
    xbar = accels[0]/50;
    ybar = accels[1]/50;
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
}

void main() {

    acc_setup();

    short accels[3];
    short mags[3];
    short temp;

    acc_read_register(OUT_X_L_A, (unsigned char *) accels, 6);
    acc_read_register(OUT_X_L_M, (unsigned char *) mags, 6);
    acc_read_register(TEMP_OUT_L, (unsigned char *) &temp, 2);

    char message[50];
    sprintf(message, "x: %d y: %d z: %d temp: %d", accels[0], accels[1], accels[2], temp);
    write_to_screen(message, 7, 2);
    write_accel_bars(accels);
    int go = 0;
    while(1){
        if (go >= 100){
            write_accel_bars(accels);
            go = 0;
        }
        go += 1;
    }
}


