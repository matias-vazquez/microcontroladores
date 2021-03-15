# Expansion Card Development (part I: Schematics)

## Objectives
Learn by practice the development process of a medium-sized, single layer, through-hole mounted printed circuit board using state-of-the-art software.

## Introduction 
In this lab series of two, we will design the Printed Circuit Board (PCB) of an expansion card to use along with the Curiosity board to expand its hardware interface and make easier to interact with the PIC18F45K50 &mu;C. This process is divided in two parts: part I comprises the circuit schematic, and part II corresponds to the PCB layout and GERBER files generation. Board fabrication will be carried out using laser etching machinery in campus by trained personnel, as well as card drilling; component mounting is responsability of the student, (soldering iron and tin/lead wire are required). The expansion card includes the following elements (links to datasheets of relevant components available on table):

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
Power supply connector | 1
Female 8-pin header | 6
Female 3-pin header | 1
Male-to-male dupont cables | 40
6"×8" single copper layer board | 1

</div>

## Pre-lab Work
* Install Proteus 8.11 using Tec de Monterrey's student license freely available. Follow the intructions available at [http://bit.ly/proteustec](http://bit.ly/proteustec). 
* _**To access the licenses server and launch Proteus 8.11, you must be connected to TEC's VPN**_. 

## Lab Work
Proteus is a Integrated Development Environment capable of capturing schematic diagrams, running SPICE simulations, &mu;C firmware testing and PCB layout. Use Proteus to develop the schematics of your expansion card, to, then, lay out the PCB and finally obtain the Gerber files, which are used by manufacturers to fabricate the physical boards for you.

Each peripherals on your board will have available port connections for you to manually wire up to a desired PIC18 &mu;C port, or to any other controlling device such as Arduino, Raspberry Pi or FPGA development board. 






