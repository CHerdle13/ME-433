/* 
 * File:   ScreenMain.c
 * Author: Craig
 *
 * Created on April 13, 2015, 11:24 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "initialize.h"
#include <xc.h>
#include <sys/attribs.h>
#include "i2c_master_int.h"
#include "i2c_display.h"

/*
 * 
 */

int row=28;
int col=32;
int display_int=1337;
int size=10;

void main() {


    PIC32startup();
    display_init();

    char message[size];
    sprintf(message, "Hello world %d!", display_int);


    write_to_screen(message, row, col);

    while(1);


}

