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

![image](https://user-images.githubusercontent.com/100802413/215526784-682a9f8f-5de8-495e-bd05-458638799d19.png)

###### _Figure 1: Arduino Leonardo CAN BUS Board Connection to OBD II Port via DB9 connector_

### Analysis
##### 1. Microcontroller Selection
The Arduino Leonardo CAN BUS Board is designed for the very purpose of 
reading CAN bus messages through the OBD (On-Board Diagnostics) port of a vehicle. The OBDII port is a 16-pin port commonly used to detect issues or malfunctions within a vehicle. However, the OBDII port in the Nissan Leaf also allows access to each of the three CAN bus systems in the vehicle through some of the pins on the port [1]. 

- Car-CAN --> Pins 6 & 14
- EV-CAN  --> Pins 12 & 13
- AV-CAN  --> Pins 3 & 11
  
The OBDII pins 6 and 14, which represent the CAN High signal and CAN Low signal respectively, are connected to pins 7 and 2 of the DB9 port through the OBDII to DB9 cable. The DB9 male end that is soldered to the board is connected to the MCP2515 CAN transceiver on the Arduino via CANH (CAN High signal), CANL (CAN Low signal, and GND (Ground). In this case, GND on the OBDII port is pin 5 and is wired to pins 3 and 5 of the DB9.

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

###### 2.1 Connectivity

![image](https://user-images.githubusercontent.com/100802413/216151029-aff715e4-ca1a-47b0-be1f-a7ce8affa70f.png)
![image](https://user-images.githubusercontent.com/100802413/216151328-315d90bf-ea3d-4cc5-bd8f-ad999e69d378.png)

###### _Figure 3: OBDII Pin Diagram w/ Table_

As seen in the figure above, the OBDII port pins 6 & 14 are connected to the CAN High and CAN Low signals of the Car-CAN as stated in the Nissan Leaf OBDII manual [4]. The output pins of the OBDII port will be connected to a OBDII to DB9 cable.

![image](https://user-images.githubusercontent.com/100802413/216152540-af9bf0cb-b73a-4366-83e3-27e6940f5b0a.png)

###### _Figure 4: Pin Diagram for OBDII to DB9 cable_

The diagram above shows that the CANH & CANL signals from pins 6 & 14 from the OBDII port are connected to pins 7 & 2 of the DB9 port through the cable [5]. The female end of the DB9 connector is soldered to the Arduino and the pins 7 & 2 are directly connected to the CANH & CANL input signals of the MCP2515 CAN transceiver.

![image](https://user-images.githubusercontent.com/100802413/216154259-9e7d8f32-eb69-4c52-8bd4-608f9c1e5c79.png)

###### _Figure 5: Arduino Leonardo CAN Bus Board PCB Underside_

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

[4] https://leaf-obd.readthedocs.io/en/latest/diagnostic-connector.html#leaf-diagnostic-connector-contact-designation-legend

[5] https://components101.com/sites/default/files/component_datasheet/OBD2%20Adapter%20Cable%20Datasheet.pdf
