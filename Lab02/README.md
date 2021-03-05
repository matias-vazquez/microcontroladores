# PARALLEL PORTS (GPIO)
## Introduction
Whack-a-mole is an arcade game in which players use a mallet to hit toy moles, which appear at random locations, to send they back down into their hiding holes. In this laboratory, you will develop the microcontroller firmware that runs the basic operational logic behind this game. Moreover, you will carry out experimental firmware testing to correct possible logic errors of your design, using development hardware, including the Curiosity board and additional components. 

## Objectives
To become familiar with the basic instructions for configure and operate the microcontroller general purpose input/output (GPIO) ports 
##Activities

### Software implementation
    1 Create a new project in MPLAB X IDE for the Curiosity board (PIC18F45K50 uC).
    2 Start your main C code with the LIBRARIEs / HEADERs section. Here, you will invoke all the required libraries and/or headers using the pre-processor directive #include.
    3 Continue your C code with the DIRECTIVES section, where you will setup symbolic constants using the pre-processor directive #define, for example:
```c
#define _XTAL_FREQ 1000000
``` 4 Continue with the DATA TYPES section. In this section, you declare enumeration tags and define the set integer identifiers using the enum datatype (as an alternative of #define). For example, instead of using the numbers 2 and 8 throughout your code, use bbase and limit constants that belong to exponent datatype, by declaring:
```c
enum exponent{bbase = 2, limit = 8};
```
    5 Now write the FUNCTIONS DECLARATION section. Your code must be structured, so write function prototypes for all user-defined functions you will use. For example, if you need a function to configure the microcontroller ports, declare it as follows:
```c
void portsInit(void);
```
    6 It is time for the MAIN section. In your C code, the main function drives the LEDs of your minimum system card to represent that a toy mole has shown up, in a continuous and random fashion, by turning on one LED out of the 8-LED set. To emulate the use of the mallet to hit the toy moles, the player will push one push-button of the minimum system card, so the firmware must be able to read the button’s state. 
    -  E.g. suppose that LED_4 turns on and the player presses in time button_4, thus you must indicate the match by displaying on the LED array the Knight Rider effect (https://www.youtube.com/watch?v=mjpc1P1vPZQ). A flow diagram of the Whack-a-Mole code is shown in Figure 1.  
    7 Finally, write the FUNCTIOS section. Here, you must write all function definitions of all user-declared functions. You can use the flow diagram shown Figure 2 as a starting point for your code.
