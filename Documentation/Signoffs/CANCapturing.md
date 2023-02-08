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
- Must be able to store up to 2048 different CAN Messages
- PC must have at least 28 Kb of storage space for CAN data

### Wiring Schematic

![image](https://user-images.githubusercontent.com/100802413/217384244-7c12dab6-a51e-4238-bbd4-5a036aa208f1.png)

###### _Figure 1: Arduino Leonardo CAN BUS Board Connection to OBD II Port via DB9 connector_

### Analysis
##### 1. Microcontroller Selection

The board contains the MCP2515 CAN transceiver to read the CAN bus at a rate of up to 1 Mbps and is connected through a DB9 to OBDII cable to the Nissan Leaf. The MCP2515 utilizes its three receive buffers to capture messages from the CAN bus [1]. The most important of these buffers is the Message Assembly Buffer (MAB) which assembles the messages from the CAN bus and always receives the next message [1]. These messages are then transferred into the RXB0 or RXB1 buffers to be read by the MCU once complete [1]. The MAB buffer ensures the messages are valid before sending them to the other two receive buffers so that the data is correctly interpreted [1]. The MCP2515 is built into the Arduino Leonardo CAN BUS Board and communicates via SPI (Serial Periphial Interface) to the on-board MCU. The Arduino will then be powered by and communicating with the PC via USB (Universal Serial Bus).

Arudino IDE can include the MCP2515 CAN-BUS Library in order to write the proper code to capture the data being read
from the CAN bus. Additionally, the library includes functions to help parse the data into sections of the entire CAN 
message to help the readability of the data.

##### 2. Verfication

The Nissan Leaf CAN Bus uses 11-bit identifier which allows for up to 2048 different messages (2^11 = 2048, which means CAN messages must have IDs that range from 0-2047). Each CAN frame can be up to 108 bits long due to acknowledgements, Cyclic Redundancy Check (CRC), Data bits, Start of Frame bit(s) (SOF), End of Frame bit(s), Control bits, and Remote Transmission Request bits (RTR). Therefore, the PC must be able to store at least 2048 * 108 bits = 221,184 bits = 27,648 bytes = 27.648 Kb to capture at least one of each type of CAN message.

The target is to read the CAN messages at no less than 10 Hz which translates to a message every 0.1 s. The CAN transceiver
on the arduino is able to read up to 1 Mbps which is 1 million bits per second. Each message of the Nissan Leaf is 108-bits
which means the subsystem can read the CAN messages at a rate of up to nearly 9259 messages per second, which is well above the 
10 Hz minimum [2].

###### 2.1 Data Storage
Data capture and storage can be done by using the MCP_CAN library in the Arduino IDE along with an application called CoolTerm. The MCP_CAN library includes the readMsgBuf() function which will read the CAN data from the receive buffer of the MCP2515 CAN transceiver and can then be printed to the terminal using the Serial.println() function so that each message and its corresponding ID will be displayed on a different line [3]. However, to store the data in a non-volatile file type such as CSV (Comma Seperated Values) format, CoolTerm will be used to intercept the data on the serial port that the Arduino is connected to and will be able to save the data in CSV format which can be opened in Excel [4].

![image](https://user-images.githubusercontent.com/100802413/216847742-f2e70475-9351-4163-a5e8-c86aebab1934.png)

###### _Figure 2: CAN Message Format_

###### 2.2 Connectivity

![image](https://user-images.githubusercontent.com/100802413/216151029-aff715e4-ca1a-47b0-be1f-a7ce8affa70f.png)
![image](https://user-images.githubusercontent.com/100802413/216151328-315d90bf-ea3d-4cc5-bd8f-ad999e69d378.png)

###### _Figure 3: OBDII Pin Diagram w/ Table [5]_

As seen in the figure above, the OBDII port pins 6 & 14 are connected to the CAN High and CAN Low signals of the Car-CAN as stated in the Nissan Leaf OBDII manual [6]. The output pins of the OBDII port will be connected to a OBDII to DB9 cable.

![image](https://user-images.githubusercontent.com/100802413/216152540-af9bf0cb-b73a-4366-83e3-27e6940f5b0a.png)

###### _Figure 4: Pin Diagram for OBDII to DB9 cable [5]_

The diagram above shows that the CANH & CANL signals from pins 6 & 14 from the OBDII port are connected to pins 7 & 2 of the DB9 port through the cable [7]. The female end of the DB9 connector is soldered to the Arduino and the pins 7 & 2 are directly connected to the CANH & CANL input signals of the MCP2515 CAN transceiver.

![image](https://user-images.githubusercontent.com/100802413/216154259-9e7d8f32-eb69-4c52-8bd4-608f9c1e5c79.png)

###### _Figure 5: Arduino Leonardo CAN Bus Board PCB Underside_

###### 2.3 System Interference

The CAN capturing subsystem connects to the OBDII port of the Nissan Leaf and the PC via USB to power the arduino and receive serial data. The OBDII port is not being used by any other subsystem of the design, so there will be no interference from that connection. The PC will be running the simulation and powering the Master Microcontroller subsystem. However, the Arduino for the CAN Capturing subsystem will be connected to a different USB port on the PC and will not have interaction with the simulation in any manner. So, this subsystem will cause no destructive interference to the other subsystems in the overall design.

### BOM
| Part        | Price    |
|:-----------:|:--------:|
| Arduino     | $21.72   |
| DB9 Cable   | $10.64   |
| TOTAL       | $32.36   |

### References

[1] https://ww1.microchip.com/downloads/aemDocuments/documents/APID/ProductDocuments/DataSheets/MCP2515-Family-Data-Sheet-DS20001801K.pdf

[2] https://www.mynissanleaf.com/viewtopic.php?t=4131#:~:text=The%20messages%20on%20the%20LEAF%20EV%20CAN%20bus,the%20Identifiers%20could%20range%20from%200%20to%200x7FF.

[3] https://reference.arduino.cc/reference/en/libraries/mcp_can/

[4] https://freeware.the-meiers.org/

[5] https://leaf-obd.readthedocs.io/en/latest/tutorial/elm327.html

[6] https://leaf-obd.readthedocs.io/en/latest/diagnostic-connector.html#leaf-diagnostic-connector-contact-designation-legend

[7] https://components101.com/sites/default/files/component_datasheet/OBD2%20Adapter%20Cable%20Datasheet.pdf
