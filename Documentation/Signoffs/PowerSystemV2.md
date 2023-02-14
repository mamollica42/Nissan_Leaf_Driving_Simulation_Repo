Power System
-------
### Function of the Subsystem
The power system is to provide power to all of the components and subsystems within the design. This includes the original car components in its entirety as well as the external subsystems that will be added. This will include replacing the battery with a power converter for continuous supply and implementing safety components to protect the sensors and controllers in the external subsystems. . 

### Specs & Constraints
- Must utilize the power supply provided for 12 V supply
- Must regulate the supplied source voltage to be within 5% of 12 V
- Must implement a method to disconnect the entire system from the source
- Shall implement safety components to prevent overcurrent on new devices
- Must not exceed wire capabilities
- Must supply required input voltage to the external sensors, external controllers, and 12 V OEM components

### Schematics
###### Wiring Diagram

![image](https://user-images.githubusercontent.com/117474411/218824610-17d01ba9-17e7-400f-a1b1-a72dd9e47a0b.png)

_Figure 1: Power Circuit & Connected Components_---

### Analysis
###### 1. Power Supply
The power supply to be used supplies 12 Volts and 600 Watts of direct current. The voltage output of the power supply was tested with an oscilloscope and the peak-to-peak voltage was approximately 800 mV with a 12 V DC offset. This output means that the voltage supplied is between 11.6 and 12.4 V. The variance of +/- 0.4 V means that the supplied voltage is approximately 3.33% of the expected value. This verifies that the power supply’s original output meets the 5% constraint.  

###### 2. Switch Selection
To prevent the master switch from being a restriction, the switch needs to have a rating of 12 V and 50 A DC. Digi-Key offers a toggle switch from Switch Components that meets the criteria with the TD1-1A-DC-3-R [1]. The switch is rated for 12 V, 50 A DC and has minimum insulation resistance of 100 Mohm. The insulation of the switch will not allow a current from a 12 V supply to reach the user that could be felt by the operator while properly disconnecting the entire system from the source.

###### 3. Diode Selection 
Due to the uncertainty of not knowing the components in the OEM components, an assumption is made that energy storage elements are implemented somewhere. The switch system needs to be designed to allow for the load to always have a path for current to flow and dissipate the stored energy. A flyback diode is introduced to be in parallel with the load and allow energy to circulate through the load until it dissipates completely after the switch is opened.
The diode for the circuit shown in Figure 1 will be a 19TQ015CJ from SMC Diode Solutions [2]. It is designed to have a continuous forward voltage of 360 mV at a maximum continuous current of 19 A. The datasheet provides that the diode can handle a peak current of 120 A for an instance before dissipating, which is three times greater than the maximum current that can be supplied.

###### 4. Wiring
The wiring to all of the external components will be 18-gauge wire. This is based around the pre-terminated wire that is sold to be used for the Arduino’s DC jack [3]. The maximum current that is allowed for 18-gauge wire is 2.3 Amps [4]. The current drawn by each external microcontroller or sensor is expected to have a maximum of 70 mA per their respective datasheet. This 70 mA current is within the 2.3 A limit of the 18-gauge wire. The internal resistance of 18-gauge wire is approximately 6.385 Ohms per 1000 ft. For the 6 ft of wire, the resistance is 0.03831 Ohms. This means that the maximum voltage across the wire is 0.08811 V or 88.11 mV.  

###### 5. Voltages and Fuses
Per the datasheet for the Arduino Uno, the microcontroller draws no more than 70 mA and can receive voltages ranging from 6 to 20 volts on the DC jack [5]. The microcontrollers will then be connected directly to the 12 V system due to 12 +/- 0.4 V falling within the range. The rotary encoder used for the steering system states that it can draw up to 70 mA per the data sheet at a range of 10.6 to 24 V. Likewise, the voltage will be within the requirements with the 12 V supply.
A fuse panel will be implemented to protect the wiring from short circuits. The fuses for each system will be 100 mA glass fuses from Digi-Key [6]. These fuses will be used in series as the first point of failure instead of the wire. It is common practice for mechanics and electricians to install wiring for devices that would be around 60-85% of the maximum current rating for the expected load. The 100 mA fuse was chosen to allow for approximately 70% of the maximum tolerance to allow for the event of a device drawing slightly more current than expected. 
To protect the wiring between the power supply and the switch, the internal fuse for the power supply will be the protection. This is designed within the supply and eliminates any issues seen by the terminals.

![image](https://user-images.githubusercontent.com/117474411/217126300-f78afd84-9ca5-42df-b907-6aa4385e1d3c.png)
_Figure 2: Spice Circuit with 70 mA loads_

A Spice simulation was used to determine the expected values of the currents and voltages. The circuit in Figure 2 shows the expected connections for the Unos and encoder with each of the wire resistances placed in series. Two simulations were run with the input voltage V1 being 11.6 V and 12.4 V to cover the maximum variance of the supplied voltages to the wires. The data yields the conclusion that the voltages at the end of the wires will be within the acceptable values for the input of the Unos and Encoder. 

Input: 11.6 V 

| Element | Voltage (V) | Current (mA) |
|--------:|:-----------:|:-------------|
| Uno1    | 11.5973     | 70           |
| Uno2    | 11.5973     | 70           |
| Uno3    | 11.5973     | 70           |
| Encoder | 11.5973     | 70           |

Input: 12.4 V 

| Element | Voltage (V) | Current (mA) |
|--------:|:-----------:|:-------------|
| Uno1    | 12.3973     | 70           |
| Uno2    | 12.3973     | 70           |
| Uno3    | 12.3973     | 70           |
| Encoder | 12.3973     | 70           |


###### 6. OEM Connection
The OEM battery terminals will be connected to bolts that will act as posts to the switch. The OEM safety devices will be utilized since they were designed for the OEM components. 

###### 7. Housing
The components to the power system will be placed inside of a plastic electrical box. The wires will be ran into it and will provide insulation and support to all of the safety compontents. A plastic box was chosen over metal due to the insulation characteristics of plastic.

### BOM

|Item              | Part Number   |Price   |
|-----------------:|:-------------:|:-------|
| Master Switch    | TD1-1A-DC-3-R |$5.08   |
| Flyback Diode    | 19TQ015CJ     |$1.30   |
| Arduino Wiring   | 10-02493      |$30.04  |
| 100 mA Fuses     | 5ST 100-R     |$3.78   |
| Fuse Holder      | 4628          |$2.92   |
| TOTAL            |               |$43.12  |

### References
[1] https://www.digikey.com/en/products/detail/switch-components/TD1-1A-DC-3-R/11492919

[2] https://www.digikey.com/en/products/detail/smc-diode-solutions/19TQ015CJ/6022095

[3] https://www.digikey.com/en/products/detail/tensility-international-corp/10-02493/9134524

[4] https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf

[5] https://docs.arduino.cc/static/6c94080aaecc364dd9013ce042a27790/A000066-datasheet.pdf

[6] https://www.digikey.com/en/products/detail/bel-fuse-inc/5ST-100-R/1009010

