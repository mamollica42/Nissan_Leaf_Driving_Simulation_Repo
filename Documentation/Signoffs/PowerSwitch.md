Power Switch
-------
### Function of the Subsystem
The Power Switch system allow power to be connected and disconnect without the need to remove wires from different components. The switch will operate as a stop function to quickly disconnect the power to the entire car and sensor system if the need arises.
### Specs & Constraints
- Shall not limit the current flow when the switch is closed.
- Shall include components to ensure the load does not violate Kirchhoff’s current or voltage laws.
-	Shall be easily accessible from the operator’s seat.
-	Shall disconnect the OEM and third-party systems from the power supply when the switch is open.

### Schematics
###### Wiring Diagram

![image](https://user-images.githubusercontent.com/117474411/203227976-1c39a5a5-bcdf-47fb-9f0b-6ac4c078f299.png)

_Figure 1: Switch Circuit & Connected Components_

### Analysis
###### 1. Power Supply
The power supply to be used was given by the Mechanical Engineering Department at Tennessee Tech. It is labeled to supply 12 Volts and 600 Watts of direct current. Using Ohm’s law, the maximum current and worst-case load that could be handled by the power supply is 50 Amps. This means the switch needs to have a maximum that is no less than 50 A to meet the constraint of not restricting the current when closed. 
###### 2. Kirchhoff's Law
The switch by itself breaks the circuit and power flow through the load when it is opened. Kirchhoff developed two laws that need to be accounted for in the design of the switch. The principle in both laws is that energy must be able to flow through a circuit. Kirchhoff Current Law states that the net current value at a node needs to equal zero. This means that all current entering a certain point is equal to the current leaving the point. Kirchhoff’s Voltage Law states that the voltage around a closed loop must be net zero. This means that all voltage produced within a closed loop must be consumed by another element. The use of energy storage elements such as capacitors and inductors impose a problem to the circuit as they release energy after the source is disconnected. In inductive elements, a disruption in power supplied to the element can cause a sudden spike in the voltage. This is due to the flow of energy being disrupted and causing a “flyback” of charge, and potentially causing damage to the component. 

Due to the uncertainty of not knowing the components in the load, an assumption is made that energy storage elements are implemented somewhere within the load. Thus, the switch system needs to be designed to allow for the load to always have a path for current to flow and dissipate the stored energy. This is not a problem while the switch is closed since the energy flows through the source, but a path needs to be designed for when the switch is opened. A flyback diode is introduced to be in parallel with the load and allow energy to circulate through the load until it dissipates completely. 

###### 3. Switch Selection
Through the analysis of the power supply, a switch needs to be selected that can support 50 A. The switch also needs to be able to support 12 V. Digi-Key offers a toggle switch from Switch Components that meets the criteria with the TD1-1A-DC-3-R [1]. The switch is rated for 12 V, 50 A DC and has minimum insulation resistance of 100 Mohm. This switch should provide proper functionality as well as safety for the user.
###### 4. Diode Selection
The diode for the circuit shown in Figure 1 will be a 19TQ015CJ from SMC Diode Solutions [2]. It is designed to have a forward voltage of 360 mV at a maximum of 19 A. The maximum instantaneous power provided by the source is 600 Watts, but the power should dissipate quickly due to the source being disconnected. This assumption allows for the diode to be functional and provide the path for energy to flow and not violate KVL and KCL.
### BOM

| Part             | Price   |
|-----------------:|:--------|
| TD1-1A-DC-3-R    | $5.08   |
| 19TQ015CJ        | $1.30   |
| TOTAL            | $6.38   |

### References
[1] https://www.digikey.com/en/products/detail/switch-components/TD1-1A-DC-3-R/11492919
[2] https://www.digikey.com/en/products/detail/smc-diode-solutions/19TQ015CJ/6022095
