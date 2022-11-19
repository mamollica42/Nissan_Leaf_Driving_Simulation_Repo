MASTER MICROCONTROLLER
------------------------
### Function of the Subsystem
The master microcontroller (MMCU) must receive data from four seperate local microcontrollers that interface with the
sensors in other subsystems. This MMCU will read serial data from each local MCU and then send that data to the PC to
be processed in the simulation.

### Specifications & Constraints
- Must connect to no less than four local microcontrollers
- Must provide real-time data transfer
- Shall connect to the PC running the simulation
- Shall have sufficient GPIO pins for communication protocols
- Shall be powered by the PC

### Wiring Schematic

![image](https://user-images.githubusercontent.com/100802413/202863978-89cc0d7a-06cd-4679-a6c5-b71eb77ff12f.png)

###### _Figure 1: Master & Slave Connections_

### Analysis
##### 1. Microcontroller Selection
The MCU will be the Arduino Mega 2560 that includes a 16 MHz clock frequency, 54 digtial I/O pins, 4 UARTs, and can be powered via USB. This MCU supports serial communication with up to 4 other local microcontrollers via UART which meets the constraint above. Additionally, the board can be programmed using the Arduino IDE which includes multiple libraries and functions to help manage multiple communications via UART simultaneously without interfering with the data transmitted or received. The Arduino Mega also includes I2C pins for an alternate form of communication.
##### 2. Communication Protocols
The MMCU will use the following forms of communication with the local microcontrollers and the PC: UART and USB. UART is the most basic form of serial communication offered on the Arduino architecture. UART only requires 2 lines for communication: transmit and receive (Tx, Rx). To send and receive the data properly, UART uses special formatting to denote the start of the data packet and the stop as seen in the figure below.

![image](https://user-images.githubusercontent.com/100802413/202495250-64d6a476-42a8-42a9-a2e7-64ba8a31c7c3.png)

###### _Figure 2: UART Packet Structure_

UART stands for Universal Asynchronous Receiver-Transmitter. The UART packet begins with a start bit which denotes the beginning of a data message. Following the start bit is the data being sent to the receiver from the transmitter followed by the parity bit. The parity bit is used for error checking and can be either even or odd. Finally, the stop bit denotes the end of the data packet and allows the receiver to correctly parse the data message. This protocol is simple and the baud rate is configurable so that data can be transmitted and received at a desired speed. For the purposes of this project, the baud rate will be configured to the highest supported rate of 115200 for the fastest data transmission time possible as to meet the real-time constraint. The baud rate of 115200 translates to 14400 bytes per second which is equivalent of sending a data packet of 8 bits every 79 microseconds. Real-time is considered anything 20 milliseconds and lower.

USB stands for Universial Serial Bus and is the most commonly used communication protocol today. USB is standard on nearly every computer device and allows the connected hardware to communicate serially while also providing power. The Arduino Mega 2560 supports USB and will be connected to the PC via USB 2.0. This port will be able to read all of the data sent from the microcontroller network up to 480 Mbps while also powering the MMCU. 

### BOM

| Part        | Price    |
|:-----------:|:--------:|
| Arduino     | $36.30   |
| USB 2.0     | $ 7.60   |
| TOTAL       | $43.90   |
