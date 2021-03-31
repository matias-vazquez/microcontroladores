# 4x4 Matrix Keypad Driver

## Introduction
In a logic circuit is very important to ensure, at every moment, a known state for a signal (High, Low). A pull-up resistor is used to ensure a well-defined voltage (i.e. Vcc or Gnd), and in combination with switches this level can be changed, as shown in Fig. 1.

The basic principle of a matrix keypad is that we connect more than switch to a single input of a microcontroller, as shown in Fig. 2.

### Workload assignment
This laboratory is broken down into four assignments that are distributed among all team members. Each team member has the responsability to complete their individual assignment and explain their part of the code on the demonstration video. Moreover, the whole team is in charge of assembling the final code into a single file and carry out the corresponding firmware and hardware tests. The required functions to complete the laboratory are:

1. `char_to_seg()`. Unsigned char to 7-segment encoder. Converts the four least-significant bits of an 8-bit binary value stored in an `uint8_t` variable, into an 8-bit value corresponding to the 7-segment codification, stored in a `uint8_t` variable. Use the following table as a reference:

<div align="center">

Decimal value | Binary value (input) | 7-segment code (output)
:---: | :---: | :---:
0  | 0000 | 00111111
1  | 0001 | 00000110
2  | 0010 | 01011011
3  | 0011 | 01001111
4  | 0100 | 01100110
5  | 0101 | 01101101
6  | 0110 | 01111101
7  | 0111 | 00000111
8  | 1000 | 01111111
9  | 1001 | 01100111
10 | 1010 | 01110111
11 | 1011 | 01111100
12 | 1100 | 01011000
13 | 1101 | 01011110
14 | 1110 | 01111001
15 | 1111 | 01110001

</div>

2. `send_to_disp()`. Breaks down a 32-bit word (`uint32_t`) containing four 8-bit binary numbers (`0x00 + 0x00 + 0x00 + 0x00`), encodes each 8-bit digit by calling the `uint8_t char_to_seg(uint8_t)` function, and sends the encoded byte to the display.

<div align="center">

Team member | Appointment | Assignment | % Responsability
:---: | :--- | :--- | :---:
A0282931 | Full stack developer* | Assignment 1 | 50
A0292213 | FPGA design engineer | Assignment 2 | 30
A0028281 | Digital systems architect | Assignment 3 | 20

<!---
AVAILABLE APPOINTMENTS
Full stack developer
Lead Embedded Design Engineer
FPGA design engineer
Digital systems architect
Electronics engineer
---> 

</div>

### Materials and software resources

<div align="center">

Qty | Material 
:---: | :---
1 | Curiosity board
1 | Expansion board
1 | 4x4 matrix keypad
4 | 220&Omega; resistor
| | MPLAB X IDE 


</div>

<!---
## Pre-lab work
--->

## Procedure
### Firmware development

1. Create a C program to do the following:
   1. Show the corresponding numeric value of the pressed key on the 4x4 matrix keypad, on the 4-digit 7-segment display of your expansion board.  
      * NOTE: The _*#*_ symbol must show the `0xE` value (`0b1110`), and the __*__ symbol must show the `0xF` value (`0b1111`).
   2. When a key is pressed, the number/letter value should be showed in the least significant digit of the 7-segment display (rightmost digit).
   3. When another key is pressed afterwards, the previous digit should be left-shifted to the, and the new value should take place on the least significant digit.
   4. Use the following program structure and code the corresponding parts to write your keypad driver. 

```C

////+++++++++++++++++++++++++++++++++++| LIBRARIES / HEADERS |+++++++++++++++++++++++++++++++++++++
#include "device_config.h"
//+++++++++++++++++++++++++++++++++++++| DIRECTIVES |+++++++++++++++++++++++++++++++++++++
#define _XTAL_FREQ 1000000

//+++++++++++++++++++++++++++++++++++++| DATA TYPES |+++++++++++++++++++++++++++++++++++++
enum por_dir{ output, input };              // output = 0, input = 1
//...

//+++++++++++++++++++++++++++++++++++++| ISRs |+++++++++++++++++++++++++++++++++++++
// ISR for high priority
void __interrupt ( high_priority ) high_isr( void );
// ISR for low priority
void __interrupt ( low_priority ) low_isr( void ); 

//+++++++++++++++++++++++++++++++++++++| FUNCTION DECLARATIONS |+++++++++++++++++++++++++++++++++++++
void portsInit( void );

//+++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++
void main( void ){
    portsInit();
    while(1){

    }
}

//+++++++++++++++++++++++++++++++++++++| FUNCTIONS |+++++++++++++++++++++++++++++++++++++
void portsInit( void ){

}

```

### Hardware implementation
   5. Connect PortB of PIC18 to the appropiate pinhead of your expansion board, then connect the 4x4 matrix keypad to the opposite pinhead, and finally connect PortD of the microcontroller to the LEDs set. Your connection must look like the one shown in Fig. 5 at the end of this document.
