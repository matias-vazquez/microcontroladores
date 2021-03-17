# Expansion Board Fabrication (Part II: PCB Layout)

## Lab work

1. Open the schematic capture of your project and double check that all the power nets of your design are named accordingly: VCC for +5 V and GND for 0 V. As an example, the power supply pins of the board should look like the figure below:
<p align="center">
  <img src="img/power_supply_pins.png">
</p>

2. It is mandatory to configure the power rails before proceeding to laying out the PCB. Go to _**Design → Configure Power Rails...**_, and on the _**Power Rails**_ tab, all the power supplies used in your project will be visible on the drop down menu under tag _**Name**_ (1). Also, verify that all the signals have assigned the class __*POWER*__ (2).
<p align="center">
  <img src="img/power_rails_configuration.PNG">
</p>

3. Check the _**Unconnected power nets**_ field and in case you see there any listed net, add it to the corresponding net class, either VCC/VDD or GND. This way, all the nets that belong to the same class will be part of the same node, even though they are name differently. 

4. Open now the __*Net Class*__ tab. Here we configure the tracks width for the PCB. As you know from steps 1, 2 and 3, we have a __*POWER*__ net class, which connects all the power supply nets along the circuit, thus driving high current magnitudes. The second net class in our circuit is the __*SIGNAL*__ class, which connects all the tracks that drive low-current signals, such as port connections between the board and the &mu;C. Since _**SIGNAL**_ nets can be narrower than __*POWER*__ nets (because they drive lower currents), we can configure the tracks width for both clases to save space on the PCB.

5. Select _**SIGNAL**_ on the _**Net Class**_ drop down menu, and choose _**T15**_ for __*Trace Style*__. This means that all the signal tracks will be routed using a track width of 15 mils. __*1 mil equals 1 thousandth of an inch, or 0.0254 mm*__, thus 15 mils = 0.381 mm. According to the Copper thickness of our board, which is 35 &mu;m, a track with a cross-section of 0.381 mm × 35 &mu;m is able to drive around 500 mA, which is enough for our application ([see further information about track width design](https://www.protoexpress.com/blog/trace-current-capacity-pcb-design/)).