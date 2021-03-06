# Introduction to MPLAB X IDE

## Objectives

The main objective of this laboratory is to provide students with the foundations to fully understand the operation of the PIC18F45K50 microcontroller. This will be achieved through 11 documents that will guide the student to create their own Printed Circuit Board (PCB), and to program the &mu;C to allow the user to interact with it. Some advantages of the PIC microcontrollers over others commercially available, and the reason it is tought in this course, are listed below:
* Easy to operate
* Vast online  documentation
* Cost-efficient 
* High operating speed
* Free and reliable IDE

In this lab work in particular, the student will become familiar with the MPLAB integrated development environment tools. The student will create their first program using the MPLAB software and will put it into the PIC microcontroller (&mu;C for short), making use of the Curiosity development/evaluation board.

## Hardware and Software
The Curiosity HPC Development Board is an 8-bit prototyping board. It is designed from the ground-up to take full advantage of Microchip MPLAB X integrated development environment. The Curiosity Development Board supports Microchip 28- and 40-pin 8-bit PIC MCUs. Programming/debugging is accomplished through the PICkit On Board (PKOB), eliminating the need for an external programming/debugging tool.

MPLAB X Integrated Development Environment (IDE) is an expandable, highly configurable software program that incorporates powerful tools to help you discover, configure, develop, debug and qualify embedded designs for most of Microchip microcontrollers and digital signal controllers. MPLAB X IDE works seamlessly with the MPLAB development ecosystem of software and tools, many of which are completely free.

## Lab Work
### Install the MPLAB IDE
1. Go to https://www.microchip.com/mplab/mplab-x-ide, scroll down to Donloads section and download the MPLAB X IDE software, then installl it on tyour computer.

### Create, Compile and Debug your First Program
2. Connect the Curiosity board to your PC.
3. Start the MPLABX IDE program. Go to File -> New Project and select the Microchip Embedded and Standalone Project options. Then Click on Next.
4. Selecct the PIC18F45K50 device and Click on Next.
5. Choose the Curiosity option and Click on Next
6. Choose the XC8 Compiler Toolchain to build the program ans Click on Next.
   * If the XC8 Compiler is not installed, go to ... to download and install it.
7. Select the Project Location and Project Name. Make sure that the location and the name have no special characters and no spaces in the names of the directories or filenames. Then Click on Finish.
8. Right-Click on Source Files and open a new main.c file. and Click on Finish.
9. Your code must be like the one showed in the figure 16, appended  at the end of the document.
10. Download device_config.h header file from Blackboard. Right-Click on Header Files and Click on Add Existing Item. Choose the downloaded file and Click on Select.
11. Select the Tools and click on Options.
12. Click on Embedded and select following options: Reset vector, Halt at Reset vector
13. Go to File and Click on Project properties. 
14. Ensure that the Low voltage programming mode option is cheked.
15. Selec Build for Debugging Main Project.
16. Select Debug Main Project.
17. You can use the debug buttons to go step by step from beginning to end through the program.
18. Before start, activate the windows that let us to see what is happening inside the microcontroller. On this window you can select what you want to verify, for example general purpose file registers (GPRs), Special file registers (SFRs), etc.
19. Now debug the program by executing the code step-by-step. 