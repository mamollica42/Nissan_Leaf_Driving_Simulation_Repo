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

### Schematic
##### 1. Model

![image](https://user-images.githubusercontent.com/100802413/202247129-48c34ae1-a09f-4cb8-bd8c-d6ac9015e4d7.png)

###### _Figure 1: 3D Model of Arduino Mega 2560_

##### 2. Wiring Schematic

![image](https://user-images.githubusercontent.com/100802413/202247317-a1eee532-dc38-4459-80e8-4b402aad2991.png)

###### _Figure 2: Pinout of Arduino Mega 2560_


![image](https://user-images.githubusercontent.com/100802413/202253058-a22657b8-e064-40a9-a72e-62bc426f20ed.png)

###### _Figure 3: Master & Slave Connections_

### Analysis
##### 1. Objective
The MMCU must be able to connect to all other local microcontrollers and communicate via serial communication protocols. The protocols used will either be UART 
or I2C depending on the distance between the local MCUs and the Master. The transmission speed of the data also must meet the real-time requirements and be accurate
as possible.
##### 2. Microcontroller Selection

##### 3. Connectivity  

### BOM

| Part        | Price    |
|:-----------:|:--------:|
| Arduino     | $36.30   |
| TOTAL       | $36.30   |
