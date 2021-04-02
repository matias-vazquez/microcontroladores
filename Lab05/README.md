<div align="right">

Find support at [![Support Server](https://img.shields.io/discord/591914197219016707.svg?color=7289da&label=ComputaciónTEC&logo=discord&style=flat-square)](https://discord.gg/xfB33VMq)

<!--- https://naereen.github.io/badges/ --->

</div>

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

3. `key_scanner()`. Sweeps each keypad row from top to bottom (bits `0` through `3` of Port A, configured as **outputs**), and scans the columns from left to right (bits `4` to `7` of Port A configured as **inputs**) to detect for a pressed key. Notice that the keypad have hard-wired _*pull-up*_ resistors tying column inputs to V<sub>CC</sub> when a key is not pressed, and short-circuiting them to GND when the key is pressed (_a.k.a._ inverted digital logic). 

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

### Hardware setup
1. Connect the corresponding ports of the PIC18 &mu;C to the appropiate pinheaders of your expansion board, as well as the 4x4 matrix keypad. Use the table below as a reference for your connections.

<div align="center">

&mu;C Port | Type | Peripheral
:---: | :---: |:---:
A [0 to 3] | Input | Keypad [0 to 3]
A [4 to 7] | Output | Keypad [4 to 7]
B [0 to 4] | Output | 7-segment display, cathodes [D4, D3, D2, D1]
D [0 to 7] | Output | 7-segment display, anodes [ABCDEFGP]

</div>

### Firmware development

1. Open the `LAB05_display.X` MPLAB X project; this is the starting point for your labwork. This project contains a 4-digit 7-segment display driver, which displays four different numbers on each dislpay digit, respectively. 

   1. Program your device and observe what is displayed. As you can see, each digit is turned on in a sequence (right to left) each time, while the rest remains off. This way, instead of using 8 pins (7 segments and decimal dot) + 1 pin (enable) to drive a display in parallel, which would add up to 36 pins, we used multiplexed outputs to enable only one digit each time and assign the corresponding value to that digit using the same 8 bits for all four digits. This is common practice to drive 7-segment displays by &mu;Cs, FPGAs and other devices. To be able to see all digits "on" at the same time, the sweeping frequency should be high enough, such as the eye cannot detect when the segments turn off. 
      
      * Reduce the value of the macro `SWEEP_STEP` on _line 8_, to a step value where you consider the four digits are displayed at the same time.  [![Generic badge](https://img.shields.io/badge/TO-REPORT-blue.svg)](https://experiencia21.tec.mx/)
      * Also, change the value of the `num` variable on _line 28_ to display the numbers A, B, C and D. Consider this should be in BCD format for numbers between 0x0 and 0xF. [![Generic badge](https://img.shields.io/badge/TO-REPORT-blue.svg)](https://experiencia21.tec.mx/)

2. Write the function `key_scanner()` for the project to scan for a pressed key on the keypad. 

3. Write the corresponding code on `main()` to show the corresponding numeric value of the pressed key on the keypad, on the 4-digit 7-segment display of your expansion board. Consider the following restrictions:  
      
    * The _*#*_ symbol must show the `0xE` value (`0b1110`), and the __*__ symbol must show the `0xF` value (`0b1111`).

    * When a key is pressed, the number/letter value should be showed in the least significant digit of the 7-segment display (rightmost digit).
    
    * When another key is pressed afterwards, the previous digit should be left-shifted, and the new value should take place on the least significant digit.



