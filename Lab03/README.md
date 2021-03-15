# Expansion Card Development (part I: Schematics)

## Objectives
Learn by practice the development process of a medium-sized, single layer, through-hole mounted printed circuit board using state-of-the-art software.

## Introduction 
In this lab series of two, we will design the Printed Circuit Board (PCB) of an expansion card to use along with the Curiosity board to expand its hardware interface and make easier to interact with the PIC18F45K50 &mu;C. This process is divided in two parts: part I comprises the circuit schematic, and part II corresponds to the PCB layout and GERBER files generation. Board fabrication will be carried out using laser etching machinery in campus by trained personnel. The expansion card includes the following elements (links to datasheets of relevant components available on table):

<div align="center">

Component | Quantity
:---   | :---:
[16×2 liquid crystal display](https://www.sparkfun.com/datasheets/LCD/HD44780.pdf) | 1
[4×4 membrane keypad](https://circuitdigest.com/microcontroller-projects/4x4-keypad-interfacing-with-pic16f877a)         | 1
[LM35 temperature sensor](https://www.ti.com/lit/ds/symlink/lm35.pdf)     | 1
[Common-cathode 7-segment displays](https://components101.com/displays/7-segment-display-pinout-working-datasheet)          | 4
Push-buttons                | 8
LEDs                        | 8
Resistor 4.7KΩ | 8
Resistor 1KΩ   | 12
Resistor 330Ω  | 12
Potentiometer 10KΩ | 2
Two-terminal power supply connector | 1
Female 8-terminal pin header | 6
Female 3-terminal pin header | 1

</div>
To layout the expansion card, a 6"×8" single copper layer board will be used. The full list of materials for the PCB mounting will be generated at the end of part II.

## Pre-lab Work
1. You have the choice to Install Proteus 8.11 using Tec de Monterrey's student license freely available, or use the remote Work Station you have previously assigned, which has Proteus 8.11 already installed.
   * In case you want to install the software in your personal computer, follow intructions [here](http://bit.ly/proteustec).

## Lab Work
Proteus is a Integrated Development Environment capable of capturing schematic diagrams, running SPICE (electrical) simulations, &mu;C firmware testing and PCB design. Use Proteus to develop the schematics of your minimum system, to, then, lay out the PCB and finally obtain the Gerber files, which are used by manufacturers to fabricate the physical boards for you.

Your minimal system will include input and output hardware components, such as LEDs, push buttons, a keypad, and so on, which will be connected to the I/O ports of the PIC18 &mu;C for you to interact with the &mu;C through wired connections. The comprehensive list of componets of your minimal system board is shown below:

| Component | Quantity |
| --------- | :------: |
| LEDs          | 8           |
| Push buttons  | 8	      |
| 4x4 keypad    | 1	      |
| LCD display   | 1	      |
| LM35		| 1	      |
| R 470		| 8	      |
| R 1K		| 8	      |
| R 4K7		| 8	      |
| POT 10K	| 2	      |





