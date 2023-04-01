Power System Experimental Analysis
------
### Specifications & Constraints
- Must utilize the power supply provided for 12 V supply
- Must regulate the supplied source voltage to be within 5% of 12 V
- Must implement a method to disconnect the entire system from the source
- Shall implement safety components to prevent overcurrent on new devices
- Must not exceed wire capabilities
- Must supply required input voltage to the external sensors, external controllers, and 12 V OEM components

### Experimental Analysis
#### SC1 
This specification is met with the power connection being on the provided power supply shown in Figure 1.

![image](https://user-images.githubusercontent.com/117474411/229240812-6b0e1b95-bb54-4b9c-b956-06639d288f57.png)

_Figure 1. The provided power supply installed inside the car._

#### SC2
The source voltage measured from the output on the 

#### SC3
A switch was implemented in series with the positive output of the power supply to break the power connection for the entire system. The current rating is 50 A which is equal to the maximum output of the power supply. Figure 2 shows the met specification with the implemented switch.

![image](https://user-images.githubusercontent.com/117474411/229240969-41e28963-2011-463d-9755-ee20948ad54a.png)

_Figure 2. Switch installed inside the car._

#### SC4 & SC5
All OEM components are powered through the original protection system. Thus, the OEM wiring doesn't require analysis for the OEM safety components. The external component wiring is protected with 100 mA fuses. Figure 3 shows the implemented fuses that were installed. All wire used for the power system is 18 AWG with a current rating of 2.3 A. 

The power was cycled 15 times with leaving the power off for 15 seconds and on for 45 seconds. This allowed for the devices to dissipate all charge when off and then charge back to steady state in the 45 second period. Several actions were completed during the on period with random combinations of changeing the states of the pedals, steering, or auto lights to imitate normal use. No fuses were blown for the 15 trials with a maximum current seen being 80 mA. This meets the specification of protection the additional wiring. 

![image](https://user-images.githubusercontent.com/117474411/229241087-9da85057-5fb0-4527-893f-0c9a378bfdb1.png)

_Figure 3. 100 mA fuses for the external components._

#### SC6
The expected input voltages for all external components 

### Conclusion

Not complete
