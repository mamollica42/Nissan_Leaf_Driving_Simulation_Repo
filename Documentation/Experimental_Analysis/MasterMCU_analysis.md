Master MCU Experimental Analysis
------
### Specifications & Constraints
- Must connect to no less than four local microcontrollers
- Must provide real-time data transfer of under 100 milliseconds
- Shall connect to the PC running the simulation
- Shall have 4 Tx and 4 Rx pins for communication protocols
- Shall be powered by the PC

### Analysis
#### SC1 -> _Modified to "Must connect to no less than 1 local microcontroller"_
This constraint has been changed after the first prototype had been implemented. Originally, the Master MCU (Arduino Mega) was designed to connect to 4 different Arduino UNOs via UART for data transmission. However, due to some issues with the serial communication and lack of parts for the CAN Bus Capturing subsystem, the Master MCU must only communicate with one other Arduino UNO that is sends data from the gear shifter. The Arduino Mega is receiving serial data from the gear shifter Arduino UNO via UART successfully and therefore meets the new requirement of only connecting to one local MCU.
#### SC2
The Master MCU must transfer data in under 100 ms to the PC. To test this, the timestamps built into the Arduino IDE terminal were inspected between each data collection point.

![image](https://user-images.githubusercontent.com/100802413/228976120-e2f52b54-1198-4115-bbdc-468870557cdd.png)

_Figure 1: Master MCU Data Collection w/ Timestamps_

Figure 1 shows that the worst-case path in the system is the shifter info as it required _33 ms_ (195 ms - 162 ms going from Park to Neutral). This delay is under the 100 ms requirement. To ensure no outliers exist, the time between two shifter data acquistions was tested several more times:
###### Table 1 - Time between two shifter data acquisitions
| |Timestamp 1 (s)|Timestamp 2 (s)|Difference (ms)|
|--|---------------|---------------|----------|
|1|5.195|5.228|33|
|2|5.228|5.228|0|
|3|5.228|5.260|32|
|4|5.260|5.293|33|
|5|5.293|5.293|0|
|6|5.293|5.325|32|
|7|5.325|5.325|0|
|8|5.325|5.359|34|
|9|5.359|5.359|0|
|10|5.359|5.391|32|

After running the test 10 more times, the worst-case delay between data captures was _34 ms_ which is well under the 100 ms specification.
#### SC3
The PC running the simulation is located in the basement of Brown Hall. The Nissan Leaf vehicle that the Master MCU pulls data from is located in Lewis Hall. Therefore, there is no way for the Master MCU to be connected to the PC running the simulation at this time. So at the time being, this constraint has not been met. Currently, the Master MCU connects to a Team Member's PC to view the data.
#### SC4 -> _Modified to "Shall have 1 Tx and 1 Rx pin for UART communication"_
Due to the same issues mentioned in section **SC1**, the Master MCU must only communicate with the Shifter Arduino UNO via UART, therefore only requiring a single Tx and Rx pin set. The Arduino Mega has 4 of each and therefore meets this specificaton successfully.
#### SC5
The Arduino Mega Master MCU connects to the PC via USB 2.0 cable which provides power. Therefore, this specification has been successfully met.
### Conclusion
Overall, the Master MCU subsystem only fails to meet constraint **SC3**, but is otherwise meeting the conditions of the other specifications and constraints. Given time and permission of the Mechanical Engineering Department, the Master MCU should be able to connect to the PC running the simulation with no issues. As for the measures of success, the real-time requirement is met but within a different time range than the original proposal. Initially, the goal was to be under 25 millisecond delay of data transfer. However, after some research, that time range was changed to 100 milliseconds or less, which is currently being met by the subsystem.
