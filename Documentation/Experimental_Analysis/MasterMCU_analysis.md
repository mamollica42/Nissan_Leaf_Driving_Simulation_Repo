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
