# Expansion Board Fabrication (Part I: Schematic Capture)

## Objectives
Learn by practice the development process of a medium-sized, single layer, through-hole mounted printed circuit board using state-of-the-art software Proteus 8.11, to be used as an expansion card for the Curiosity board and PIC18 microcontroller. 

## Introduction 
In this lab series of two, we will design the Printed Circuit Board (PCB) of an expansion card to use along with the Curiosity board to expand its hardware interface and make easier to interact with the PIC18F45K50 &mu;C. This process is divided in two parts: part I comprises the circuit schematic capture, and part II corresponds to PCB layout and Gerber file generation. Board fabrication will be carried out using laser etching machinery in campus by trained personnel, as well as card drilling; to finally assemble the board, which is responsability of the student (soldering iron and tin/lead wire are required).

The expansion board includes the components listed in the table below. (links to datasheets of relevant components available):

<div align="center">

Component | Quantity | Device ID
:---   | :---: | :---
<a href="https://www.sparkfun.com/datasheets/LCD/HD44780.pdf" target="_blank">16×2 liquid crystal display</a> | 1 | ---
<a href="https://www.ti.com/lit/ds/symlink/lm35.pdf" target="_blank">LM35 temperature sensor</a>  | 1 | LM35
<a href="https://circuitdigest.com/microcontroller-projects/4x4-keypad-interfacing-with-pic16f877a" target="_blank">4×4 matrix keypad</a>    | 1 | ---
Four-digit common-cathode 7-segment display          | 4 | 7SEG-MPX4-CC
Push-buttons                | 8 | BUTTON
LEDs                        | 8 | LED
Resistor 4.7KΩ | 8  | MINRES4K7
Resistor 1KΩ   | 12 | MINRES1K
Resistor 330Ω  | 12 | MINRES33R
Potentiometer 10KΩ | 2 | RES-VAR
Female 16-pin header | 1 | 66226-016
Female 10-pin header | 1 | 66226-010
Female 8-pin header | 5 | SIL-100-08
Female 4-pin header | 1 | SIL-100-04
Female 3-pin header | 1 | SIL-100-03
Female 2-pin header | 1 | SIL-100-02
Male-to-male dupont cables | 40 | ---
6"×8" single copper layer board | 1 | ---

</div>

## Pre-lab 
* Install Proteus 8.11 using Tec de Monterrey's student license (free to students). Follow the intructions available at <a href="http://bit.ly/proteustec">http://bit.ly/proteustec</a>. 
* _**To access the licenses server and launch Proteus 8.11, you must be connected to TEC's VPN**_. 

## Lab work
Proteus is an Integrated Development Environment (IDE) capable of capturing schematics, running SPICE simulations, testing &mu;C firmware and designing PCBs. In part I you will use Proteus to capture the schematics of your expansion card, to then, in part II, lay out the PCB and generate the Gerber files, which are used by manufacturers to fabricate the physical boards for you.

Each peripheral on your board will have available port connections for you to manually wire up to a PIC18 &mu;C port, or to any other controlling device such as Arduino, Raspberry Pi or FPGA. 

### **1. Project setup**
1. Open __Proteus 8 Professional__. 
   * The figure below shows the Proteus home page. From the __*Start*__ window, select __*New Project*__. 
<p align="center">
  <img src="img/home_page.PNG">
</p>

2. From the __*New Project Wizard*__, choose a project name and path. Check the __*New Project*__ option and click __*Next*__. 
<p align="center">
  <img src="img/Start.PNG">
</p>

3. Before designing the actual PCB, we need to capture the circuit schematic. For this, select __*Create a schematic from the selected template*__, and use the template __Landscape A4__.
<p align="center">
  <img src="img/schematic_design.PNG">
</p>

4. Then, check the __*Create a PCB layout from the selected template*__, and use the __DEFAULT__ template. This way, we will start out from a clean template an will be able to setup our PCB design according to our requirements. 
<p align="center">
  <img src="img/PCB_layout.PNG">
</p>

5. On the __*PCB Layer Stackup*__ window we will select the number of conductive layers we need for our design. Initially, a two-layer setup will be presented, which includes a core layer of FR4 material (fire retardant), two Copper layers (Bottom and Top) for signal routing, and two Resist (protective) layers. We need to change this setup to a <u>single layer board</u>.
<p align="center">
  <img src="img/stackup_2l.PNG">
</p>

6. Click on __*Stackup Wizard*__ button and select __*1*__ on __*No. of Copper Layers*__. Leave the rest of parameters unchanged and click __*Ok*__.
<p align="center">
  <img src="img/stackup_wizard.PNG">
</p>

7. The PCB layer stackup should now include only one Copper layer (Bottom), along with the core and resist layers, as shown below:
<p align="center">
  <img src="img/stackup.PNG">
</p>

8. To finish the PCB board configuration, you have to define the tye of vias you will use on the _**Drill Pairs**_ window. There are different types of vias than can be used in a PCB, such as *through hole*, *blind via*, *buried via* and *microvia*. Since we are using a single conductive layer, only *through holes* can be fabricated. Notice that column __*Type*__ already pre-selected this type of via in your design. 
<p align="center">
  <img src="img/drill_pairs.PNG">
</p>

9. A preview of the board (transversal cut) is then shown for a final checkup. As expected, the through hole via runs from top to bottom of the board. These vias are the mounting sites for all our components. Since the Resist layer is not mandatoy, and not used in this design, the final board thickness is 1.6 mm (Core) + 35 &mu;m (Cu layer).
<p align="center">
  <img src="img/board_preview.PNG">
</p>

10. On the _**Firmware**_ window, leave __*No Firmware Project*__ checked, since we are not writing firmware for a microcontroller (this time).
<p align="center">
  <img src="img/firmware.PNG">
</p>

11. Finally, a summary of the project setup is presented for a final review. Double check that __*Schematic*__ and __*Layout*__ are selected and finish the setup. 
<p align="center">
  <img src="img/summary.PNG">
</p>

### **2. Schematic Capture**

The schematic diagram of the expansion board is shown below. A high-resolution PDF is also available [here](EXBOARD-PIC18.PDF). 
<p align="center">
  <img src="img/schematic_diagram.png">
</p>

1. A blank workspace will be initially shown for two different tab windows: __*Schematic Capture*__ and __*PCB Layout*__. Click on the __*Schematic Capture*__ tab to open the correspoding workspace (gray background).
<p align="center">
  <img src="img/sch_cap_01.PNG">
</p>

2. It is good practice to add the full list of components first, and then wire them up. To add the component list to your workspace, open the component library: __*Library → Pick Parts*__ (or press **P** on your keyboard).
<p align="center">
  <img src="img/sch_cap_02.PNG">
</p>

Use the __*Keywords*__ field to look up for components. Double click on the desired component to add it to the component list (shown on the left side of the screen). Your list should look similar to the one below:
<p align="center">
  <img src="img/sch_cap_03.PNG">
</p>

__Note: when after adding the push buttons, right-click on each of them, choose *Edit Properties* and name them all on *Part Reference* field. Use a logic sequence to identify these components (e.g. PB1, PB2, PB3...).__

3. On the leftmost panel, select the __*Terminals Mode*__ button to show the available terminals. Use __*POWER*__ to connect the VCC lines, and __*GROUND*__ for Ground reference.
<p align="center">
  <img src="img/sch_cap_04.PNG">
</p>

4. Make all the necessary connections to complete your schematic. Once you're done, name the power rails accordingly (V<sub>CC</sub> and GND) by double-clicking the __*POWER*__ and __*GROUND*__ terminals. 
<p align="center">
  <img src="img/sch_cap_05.PNG">
</p>

5. When finished, your design is ready for PCB layout, since simulation is not required. Save your project and export the schematic diagram as a image or PDF file to include in your report: __*File → Export Graphics*__. You can now continue to Part II: PCB Layout.

<p align="right">Last update: March 16th, 2021</p>