Power System
-------
### Function of the Subsystem
The power system is to provide power to all of the components and subsystems within the design. This includes the original car components as well as the external subsystems that will be added. This will include replacing the battery with a power converter for continuous supply and implementing safety components to protect the sensors and controllers in the external subsystems. . 

### Specs & Constraints
-Must regulate the supplied source voltage to be within 5% of the expected value
-Shall implement safety components to prevent overcurrent
-Must not exceed wire capabilities
-Must supply required input voltage to each component
-Must implement a method to disconnect the entire system from the source
-Must utilize the power supply provided 


### Schematics
###### Wiring Diagram

![image](https://user-images.githubusercontent.com/117474411/216243257-0affaccf-8fbd-4382-b7ad-6753cd88b2f7.png)

_Figure 1: Power Circuit & Connected Components_---

### Analysis
###### 1. Power Supply
The power supply to be used was given by the Mechanical Engineering Department at Tennessee Tech. It is labeled to supply 12 Volts and 600 Watts of direct current. Using Ohm’s law, the maximum current and worst-case load that could be handled by the power supply is 50 Amps. The voltage output of the power supply was tested with an oscilloscope and the peak-to-peak voltage was approximately 800 mV. This output means that the voltage supplied is between 11.6 and 12.4 V. The variance of +/- 0.4 V means that the supplied voltage is approximately 3.33% of the expected value. This verifies that the power supply’s original output meets the 5% constraint.  

###### 2. Kirchhoff's Law
The switch by itself breaks the circuit and power flow through the load when it is opened. Kirchhoff developed two laws that need to be accounted for in the design of the switch. The principle in both laws is that energy must be able to flow through a circuit. Kirchhoff Current Law states that the net current value at a node needs to equal zero. This means that all current entering a certain point is equal to the current leaving the point. Kirchhoff’s Voltage Law states that the voltage around a closed loop must be net zero. This means that all voltage produced within a closed loop must be consumed by another element. The use of energy storage elements such as capacitors and inductors impose a problem to the circuit as they release energy after the source is disconnected. In inductive elements, a disruption in power supplied to the element can cause a sudden spike in the voltage. This is due to the flow of energy being disrupted and causing a “flyback” of charge, and potentially causing damage to the component.

Due to the uncertainty of not knowing the components in the load, an assumption is made that energy storage elements are implemented somewhere within the load. Thus, the switch system needs to be designed to allow for the load to always have a path for current to flow and dissipate the stored energy. This is not a problem while the switch is closed since the energy flows through the source, but a path needs to be designed for when the switch is opened. A flyback diode is introduced to be in parallel with the load and allow energy to circulate through the load until it dissipates completely.

###### 3. Switch Selection
To prevent the switch from being a restriction, the master switch needs to have a maximum current limit that is no less than 50. The switch also needs to be able to support 12 V. Digi-Key offers a toggle switch from Switch Components that meets the criteria with the TD1-1A-DC-3-R [1]. The switch is rated for 12 V, 50 A DC and has minimum insulation resistance of 100 Mohm. The insulation of the switch will not allow a current from a 12 V supply to reach the user that could be felt by the operator. This switch should properly disconnect the entire system from the source as well as be safe for the user.

###### 4. Diode Selection
The diode for the circuit shown in Figure 1 will be a 19TQ015CJ from SMC Diode Solutions [2]. It is designed to have a forward voltage of 360 mV at a maximum of 19 A. The maximum instantaneous power provided by the source is 600 Watts, but the power should dissipate quickly due to the source being disconnected. This assumption allows for the diode to be functional and provide the path for energy to flow and not violate KVL and KCL.

###### 5. Wiring
The wiring to all of the external components will be 18-gauge wire. This is based around the pre-terminated wire that is sold to be used for the Arduino’s DC jack [3]. The maximum current that is allowed for 18-gauge wire is 2.3 Amps [4]. The internal resistance is approximately 6.385 Ohms per 1000 ft. For the 6 ft of wire, the resistance is 0.03831 Ohms. This means that the maximum voltage across the wire is 0.08811 V or 88.11 mV.  

###### 6. Voltages and Fuses
Per the datasheet for the Arduino Uno, the microcontroller draws no more than 70 mA and can receive voltages ranging from 6 to 20 volts on the DC jack [5]. This means that the microcontrollers can be connected directly to the 12 V system without needing to have the voltage being adjusted. The range of acceptable voltages for the Uno allows for the 12 V signal to have more fluctuation than the voltage variation that would be expected after the voltage drop of the wiring. The rotary encoder used for the steering system states that it can draw up to 70 mA per the data sheet at a range of 10.6 to 24 V. Likewise, the voltage will be within the requirements with the 12 V supply.
Similar to the voltage, the current needs to be regulated to prevent the wiring from being jeopardized in the event of a short circuit. To prevent overcurrents, a fuse panel will be implemented to protect the wiring. The fuses for each system will be 100 mA glass fuses from Digi-Key [6]. These fuses will be used in series as the first point of failure instead of the wire. It is common practice for mechanics and electricians to install wiring for devices that would be around 60-85% of the maximum current rating for the expected load.  The 100 mA fuse was chosen to allow for approximately 70% of the maximum tolerance to allow for the event of a device drawing slightly more current than expected. 

###### 7. OEM Connection
The OEM battery terminals will be connected to bolts that will act as posts to the switch. The OEM safety devices will be utilized since they were designed for the OEM components. 
BOM

### BOM

| Part             | Price   |
|-----------------:|:--------|
| TD1-1A-DC-3-R    | $5.08   |
| 19TQ015CJ        | $1.30   |
| TOTAL            | $6.38   |

### References
[1] https://www.digikey.com/en/products/detail/switch-components/TD1-1A-DC-3-R/11492919

[2] https://www.digikey.com/en/products/detail/smc-diode-solutions/19TQ015CJ/6022095

[3] https://www.digikey.com/en/products/detail/tensility-international-corp/10-02493/9134524

[4] https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf

[5] https://docs.arduino.cc/static/6c94080aaecc364dd9013ce042a27790/A000066-datasheet.pdf

[6] https://www.digikey.com/en/products/detail/bel-fuse-inc/5ST-100-R/1009010
