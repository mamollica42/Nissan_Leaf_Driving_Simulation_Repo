Power System Experimental Analysis
------
### Specifications & Constraints
- 1. Must utilize the power supply provided for 12 V supply
- 2. Must regulate the supplied source voltage to be within 5% of 12 V
- 3. Must implement a method to disconnect the entire system from the source
- 4. Shall implement safety components to prevent overcurrent on new devices
- 5. Must not exceed wire capabilities
- 6. Must supply required input voltage to the external sensors, external controllers, and 12 V OEM components

### Experimental Analysis
#### SC1 
This specification is met with the power connection being on the provided power supply shown in Figure 1.

![image](https://user-images.githubusercontent.com/117474411/229240812-6b0e1b95-bb54-4b9c-b956-06639d288f57.png)

_Figure 1. The provided power supply installed inside the car._

#### SC2
This constraint for the detailed design is derived from a measure of success in the project proposal's requirement for input voltage. All measurements for this SC were recorded with a voltmeter. The source voltage measured from the output on the power supply is shown in Table 1. The experiment involved 10 samples at 1 second intervals. The average of all the trials was 12.296 V. The voltage needed to remain within 5% of the expected value, which was met as it remained within the range of 11.4 V and 12.6 V. 

Table 1.

Trial | V out (mean)
---|---|
1 | 12.27 V
2 | 12.34 V
3 | 12.40 V
4 | 12.23 V
5 | 12.25 V
6 | 12.23 V
7 | 12.36 V
8 | 12.31 V
9 | 12.28 V
10| 12.29 V

#### SC3
A switch was implemented in series with the positive output of the power supply to break the power connection for the entire system. The current rating is 50 A which is equal to the maximum output of the power supply. Figure 2 shows the met specification with the implemented switch.

![image](https://user-images.githubusercontent.com/117474411/229240969-41e28963-2011-463d-9755-ee20948ad54a.png)

_Figure 2. Switch installed inside the car._

#### SC4 & SC5
All OEM components are powered through the original protection system. Thus, the OEM wiring doesn't require analysis for the OEM safety components. The external component wiring is protected with 100 mA fuses. Figure 3 shows the implemented fuses that were installed. All wire used for the power system is 18 AWG with a current rating of 2.3 A. 

The power was cycled 15 times with leaving the power off for 15 seconds and on for 45 seconds. This allowed for the devices to dissipate all charge when off and then charge back to steady state in the 45 second period. Several actions were completed during the on period with random combinations of changeing the states of the pedals, steering, or auto lights to imitate normal use. No fuses were blown for the 15 trials with a maximum current seen being 80 mA. This meets the specification of protection the additional wiring. Table 2 shows the recorded information from the trials.


Table 2.

Trial | I (Arduino, mA) | I (Encoder, mA)
---|---|---|
1 | 76.230 | 76.125
2 | 75.560 | 78.820
3 | 74.756 | 77.235
4 | 76.853 | 77.625
5 | 78.258 | 79.235
6 | 77.831 | 74.564
7 | 76.463 | 78.264
8 | 79.465 | 77.365
9 | 76.731 | 79.102
10| 78.713 | 78.132
11| 78.201 | 77.216 
12| 76.216 | 76.120
13| 78.382 | 77.027
14| 79.021 | 78.089
15| 76.935 | 77.753

![image](https://user-images.githubusercontent.com/117474411/229241087-9da85057-5fb0-4527-893f-0c9a378bfdb1.png)

_Figure 3. 100 mA fuses for the external components._

#### SC6
The expected input voltages for all external components needed to not exceed 12 V. The two components being powered were the Arduino and Encoder. Both can accepted 10-12 V for the input. This was the target range for both components. 10 trials were conducted for the voltages at the input points. The voltages for all 20 values remained within the range and met the constriants for the devices.

Table 2.

Trial | V (Arduino, V) | V (Encoder, V)
---|---|---|
1 | 11.6 | 11.6
2 | 11.8 | 11.9
3 | 11.7 | 11.9
4 | 11.7 | 11.8
5 | 11.5 | 11.7
6 | 11.3 | 11.4
7 | 11.6 | 11.5
8 | 11.8 | 11.9
9 | 11.7 | 11.8
10| 11.8 | 11.7
### Conclusion

The specifications and constraints were all met per the experimental data. This verifies that the power system is to the designed requirements and does not require improvement to meet the mentioned criteria.
