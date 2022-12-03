MASTER MICROCONTROLLER
------------------------
### Function of the Subsystem
The master microcontroller (MMCU) must receive data from four seperate local microcontrollers that interface with the
sensors in other subsystems. This MMCU will read serial data from each local MCU and then send that data to the PC to
be processed in the simulation.

### Specifications & Constraints
- Must connect to no less than four local microcontrollers
- Must provide real-time data transfer of under 100 milliseconds
- Shall connect to the PC running the simulation
- Shall have 4 Tx and 4 Rx pins for communication protocols
- Shall be powered by the PC

The definition of real-time is subjective and therefore can not be directly defined. In the case of this system, real-time was
based on the average human reaction time of 250 milliseconds [1]. Given that delay being considerably high for a real-time system, 
the team has decided to cut that number to over 1/2 of its value and target less than 100 milliseconds. This target is based on the 
acceptable latency for gaming which lies between 20 and 100 milliseconds [2].

### Wiring Schematic

![image](https://user-images.githubusercontent.com/100802413/202863978-89cc0d7a-06cd-4679-a6c5-b71eb77ff12f.png)

###### _Figure 1: Master & Slave Connections_

### Analysis
##### 1. Microcontroller Selection
The MCU will be the Arduino Mega 2560 that includes a 16 MHz clock frequency, 54 digtial I/O pins, 4 UARTs, and can be powered via USB. This MCU supports serial communication with up to 4 other local microcontrollers via UART which meets the constraint above. Additionally, the board can be programmed using the Arduino IDE which includes multiple libraries and functions to help manage multiple communications via UART simultaneously without interfering with the data transmitted or received.

Some useful Arduino functions include : 
- Serial.available() : Checks to see if the UART has data waiting to be read
- Serial.read() : Reads the data into the serial buffer
- Serial.write(x) : Sends the data 'x' to through the Tx line

By using these functions, we can use the following code that is from the Official Arduino Forum to connect to four other devices [3]:

![image](https://user-images.githubusercontent.com/100802413/204861114-216f67db-b71b-4e05-a706-6426941dfd11.png)

###### _Figure 2: Multiple Serial Communications on Arduino Mega 2560

By configuring each of the four serial ports and checking their availability before reading or writing data, no packets should be lost or corrupted during transmission. Addtionally, the four different ports will be read in an infinite loop one after the other in a round robin fashsion such that no process is left unserviced.

##### 2. Communication Protocols
The MMCU will use the following forms of communication with the local microcontrollers and the PC: UART and USB. UART is the most basic form of serial communication offered on the Arduino architecture. UART only requires 2 lines for communication: transmit and receive (Tx, Rx). To send and receive the data properly, UART uses special formatting to denote the start of the data packet and the stop as seen in the figure below.

![image](https://user-images.githubusercontent.com/100802413/202495250-64d6a476-42a8-42a9-a2e7-64ba8a31c7c3.png)

###### _Figure 2: UART Packet Structure_

UART stands for Universal Asynchronous Receiver-Transmitter. The UART packet begins with a start bit which denotes the beginning of a data message. Following the start bit is the data being sent to the receiver from the transmitter followed by the parity bit. The parity bit is used for error checking and can be either even or odd. Finally, the stop bit denotes the end of the data packet and allows the receiver to correctly parse the data message. This protocol is simple and the baud rate is configurable so that data can be transmitted and received at a desired speed. For the purposes of this project, the baud rate will be configured to the highest supported rate of 115200 for the fastest data transmission time possible as to meet the real-time constraint of 100 milliseconds. The baud rate of 115200 translates to 14400 bytes per second which is equivalent of sending a data packet of 8 bits every 79 microseconds.

USB stands for Universial Serial Bus and is the most commonly used communication protocol today. USB is standard on nearly every computer device and allows the connected hardware to communicate serially while also providing power. The Arduino Mega 2560 supports USB and will be connected to the PC via USB 2.0. This port will be able to read all of the data sent from the microcontroller network up to 480 Mbps while also powering the MMCU.

##### 3. Calculations
Each serial port will be configured to 115200 baud rate which sends a data packet every 79 microseconds. Because there are four serial ports, it will take four times the 79 microseconds at the very least if other code is disregarded. This will be called as T_ideal
  
    T_ideal = (4) * (79 us) = 316 us = 0.316 ms
    
The time complexity of the if-statements are O(1) which correlates to the time of a single atomic instruction. The time of one atomic instruction in the case of the Arduino Mega with a 16 MHz processor is as follows:

    T_atomic = 1 / (16e6) = 62.5 ns = 0.0000625 ms
    
Given the main code has four if-statements and will also require the four serial transmissions, the total time can be calculated:

    T = T_ideal + (4) * T_atomic = 0.31625 ms << 100 ms for real-time constraint
    
Based on the calculations above, the Arduino Mega can read each of the Arduino UNOs data lines in only 0.316 milliseconds. This allows much more code and data processing to occur within the Mega and still maintain a transmission time of under 100 milliseconds.

### BOM

| Part        | Price    |
|:-----------:|:--------:|
| Arduino     | $36.30   |
| USB 2.0     | $ 7.60   |
| TOTAL       | $43.90   |

### REFERENCES

[1] https://reactiontest.org/#:~:text=The%20average%20human%20response%20time%20is%20about%200.25,traffic%20and%20had%20to%20slam%20on%20their%20brakes.

[2] https://www.bandwidthplace.com/the-importance-of-latency-in-online-gaming/

[3] https://forum.arduino.cc/t/mega-2560-multiple-serial-connections/100542/2
