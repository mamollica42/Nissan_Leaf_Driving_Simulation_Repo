CAN Bus Capturing
---------------------------
### Function of the Subsystem
This subsystem must capture the data on the CAN (Controller Area Network) bus 
and store it. This system is not responsible for interpreting the information
that is captured.

### Specifications & Constraints
- Must capture information from CAN bus at no less than 10 Hz
- Must store CAN bus data neatly and in a readable manner on the PC
- Shall not interfere with the functionality with any other subsystem
- Shall receive power from the PC

### Wiring Schematic

![image](https://user-images.githubusercontent.com/100802413/214090672-fc79ca31-7226-4c01-a043-3b9339ff5467.png)

###### _Figure 1: Arduino Leonardo CAN BUS Board Connection to OBD II Port via DB9 connector_

### Analysis
##### 1. Microcontroller Selection
The Arduino Leonardo CAN BUS Board is designed for the very purpose of 
reading CAN bus messages through the OBD (On-Board Diagnostics) port of a vehicle. The OBDII port is a 16-pin port commonly used to detect issues or malfunctions within a vehicle. However, the OBDII port in the Nissan Leaf also allows access to each of the three CAN bus systems in the vehicle through some of the pins on the port [1].

- Car-CAN --> Pins 6 & 14
- EV-CAN  --> Pins 12 & 13
- AV-CAN  --> Pins 3 & 11
  
The board contains the MCP2515 CAN transceiver to read the CAN bus at a rate of up to 1 Mbps and is connected through a DB9 to OBDII cable to the Nissan Leaf. The MCP2515 utilizes its three receive buffers to capture messages from the CAN bus [2]. The most important of these buffers is the Message Assembly Buffer (MAB) which assembles the messages from the CAN bus and always receives the next message [2]. These messages are then transferred into the RXB0 or RXB1 buffers to be read by the MCU once complete [2]. The MAB buffer ensures the messages are valid before sending them to the other two receive buffers so that the data is correctly interpreted [2]. The MCP2515 is built into the Arduino Leonardo CAN BUS Board and communicates via SPI (Serial Periphial Interface) to the on-board MCU. The Arduino will then be powered by and communicating with the PC via USB (Universal Serial Bus).

Arudino IDE can include the MCP2515 CAN-BUS Library in order to write the proper code to capture the data being read
from the CAN bus. Additionally, the library includes functions to help parse the data into sections of the entire CAN 
message to help the readability of the data.

![image](https://user-images.githubusercontent.com/100802413/214094157-84233b60-07c6-49e4-83a5-f8ffab02b584.png)

###### _Figure 2: CAN Message Format_

##### 2. Verfication
The target is to read the CAN messages at no less than 10 Hz which translates to a message every 0.1 s. The CAN transceiver
on the arduino is able to read up to 1 Mbps which is 1 million bits per second. Each message of the Nissan Leaf is 11-bits
which means the subsystem can read the CAN messages at a rate of up to nearly 91000 messages per second, which is well above the 
10 Hz minimum [3].

Data that is captured will print directly to the arduino terminal and can be directly copied into an excel sheet for professional and readable storage.

### BOM
| Part        | Price    |
|:-----------:|:--------:|
| Arduino     | $21.72   |
| DB9 Cable   | $10.64   |
| TOTAL       | $32.36   |

### References
[1] https://leaf-obd.readthedocs.io/en/latest/tutorial/elm327.html

[2] https://ww1.microchip.com/downloads/aemDocuments/documents/APID/ProductDocuments/DataSheets/MCP2515-Family-Data-Sheet-DS20001801K.pdf

[3] https://www.mynissanleaf.com/viewtopic.php?t=4131#:~:text=The%20messages%20on%20the%20LEAF%20EV%20CAN%20bus,the%20Identifiers%20could%20range%20from%200%20to%200x7FF.
