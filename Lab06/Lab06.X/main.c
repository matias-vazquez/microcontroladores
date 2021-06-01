/*
 * File:   main.c
 * Author: Labmems
 *
 * Created on 27 de abril de 2021, 12:16 AM
 */

#include "device_config.h"

#define _XTAL_FREQ 8000000

#define LCD_DATA_R          PORTD
#define LCD_DATA_W          LATD
#define LCD_DATA_DIR        TRISD
#define LCD_RS              LATCbits.LATC2
#define LCD_RS_DIR          TRISCbits.TRISC2
#define LCD_RW              LATCbits.LATC1
#define LCD_RW_DIR          TRISCbits.TRISC1
#define LCD_E               LATCbits.LATC0
#define LCD_E_DIR           TRISCbits.TRISC0

void send2LCD(char);
void LCD_rdy(void);
void LCD_init(void);
void LCD_cmd(char);
    
void main(void) {
    OSCCON = 0x74;// Set the internal oscillator to 8MHz and stable
    ANSELC = 0;   // Set port D as Digital for 7 segment anodes
    TRISC  = 0x00;      // for Port D, set all pins as outputs for 7 segment anodes
    ANSELD = 0;   // Set port D as Digital for 7 segment anodes
    TRISD  = 0x00;      // for Port D, set all pins as outputs for 7 segment anodes
    
    LCD_DATA_DIR = 0x00;
    
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_E  = 0;

    LCD_init();

    send2LCD('L');
    send2LCD('a');
    send2LCD('b');
    send2LCD('o');
    send2LCD('r');
    send2LCD('a');
    send2LCD('t');
    send2LCD('o');
    send2LCD('r');
    send2LCD('i');
    send2LCD('o');

    while(1);
}

void send2LCD(char xy){
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_E  = 1;
    LCD_DATA_W = xy;
    Nop();
    Nop();
    LCD_E  = 0;
    __delay_ms(250);
}

void LCD_init(void){
    LATC = 0;               // Make sure LCD control port is low
    LCD_E_DIR = 0;          // Set Enable as output
    LCD_RS_DIR = 0;         // Set RS as output 
    LCD_RW_DIR = 0;         // Set R/W as output
    LCD_cmd(0x38);          // Display to 2x16
    __delay_ms(250);  
    LCD_cmd(0x0F);          // Display on, cursor on and blinking
    __delay_ms(250);  
    LCD_cmd(0x01);          // Clear display and move cursor home
    __delay_ms(250);  
}

void LCD_rdy(void){
    char test;
    // configure LCD data bus for input
    LCD_DATA_DIR = 0xFF;
    test = 0x80;
    while(test){
        LCD_RS = 0;         // select IR register
        LCD_RW = 1;         // set READ mode
        LCD_E  = 1;         // setup to clock data
        test = LCD_DATA_R;
        Nop();
        LCD_E = 0;          // complete the READ cycle
        test &= 0x80;       // check BUSY FLAG 
    }
}

void LCD_cmd(char cx) {
   // LCD_rdy();              // wait until LCD is ready
    LCD_RS = 0;             // select IR register
    LCD_RW = 0;             // set WRITE mode
    LCD_E  = 1;             // set to clock data
    Nop();
    LCD_DATA_W = cx;        // send out command
    Nop();                  // No operation (small delay to lengthen E pulse)
    LCD_E = 0;              // complete external write cycle
}