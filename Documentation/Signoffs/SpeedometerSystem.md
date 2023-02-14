SPEEDOMETER SUBSYSTEM
--------------------
### Functions of the Subsystem
The speedometer subsystem must receive output from the driving simulation and display the speed the user is going. A microcontroller will be used to export the speed data from the simulator and display it on a screen inside the car.
### Specifications & Constraints
- C1. Shall be powered by the PC running the simulator via USB 2.0
-	C2. Microcontroller must be able to read speed data from the simulator while it is running using serial communication
-	C3. Data must exit the PC running the simulator and be stored on a microcontroller using serial communication
-	C4. Shall display the speed data in an appropriate manner on a screen inside the car

### Schematic
##### 1. Screen to Microcontroller Connection

![image](https://user-images.githubusercontent.com/117474540/205758564-ffde40c5-9775-4cfe-a78d-28c376bdf988.png)

_Figure 1. A photograph of the LCD snapping onto the Arduino Uno [1]

##### 2. Wiring Schematic

![image](https://user-images.githubusercontent.com/117474540/218500985-338ea43c-fd82-4689-873e-2978feef5f54.png)

_Figure 2. Schematic for the 3.5 Inch TFT Color LCD Screen Plugging into the Arduino Uno

### Analysis

### C1. Shall be powered by the PC running the simulator via USB 2.0
An Arduino Uno can be powered by a USB 2.0 coming from the PC running the simulator.

### C2. Microcontroller must be able to read speed data from the simulator while it is running using serial communication
Arduino can directly communicate with the simulator that runs on MATLAB via serial communication with a USB 2.0. For the simulator to send data to the Arduino, serial.write() functions will be inserted into the simulator code to continuously send speed data to the Arduino. For the Arduino to receive and display the speed data, serial.read() functions will be used.

### C3. Data must exit the PC running the simulator and be stored on a microcontroller using serial communication
Once the serial.read() function is used, the speed data will be collected and used in the C code that displays the speed. This means that the data has exited the PC and is being processed on another device using a programming language other than MATLAB.

### C4. Shall display the speed data in an appropriate manner on a screen inside the car
#### LCD Display Selection
The The 3.5 Inch TFT Color LCD Screen has 28 pins and can directly snap onto an Arduino UNO REV3. The 3.5" LCD screen can be programmed to display whatever the user wants and is plenty big enough to display the speed data from the simulation. With a module display area that contains 320x480 pixels, the team can add extra embellishments onto the screen to make the speed data that is displayed feel more appropriate to the car.

#### Mounting
The recommended max distance of a USB 2.0 cable is 16 feet. The PC running the simulator will be within 16 feet of the speedometer and the master MCU, so mounting the LED display in the desired position shall have no effect on transmission speeds. To keep the the immersive feel of the inside of the car, the LCD will be mounted exactly where the current speedometer display is located. The stock display will be removed and be replaced with a new mount that will mimic the current one. The new one will of be able to communicate with MATLAB and pull the speed data from the simulator.

![image](https://user-images.githubusercontent.com/117474540/215832669-89579faa-cde7-400d-ae63-a6a877984600.png)

_Figure 3. The mounting for the Uno in the Car 

![image](https://user-images.githubusercontent.com/117474540/215867130-0e203977-f486-433f-9da6-c88cc64bec3f.png)

_Figure 4. The face plate for the mount

The back of the mount will be screwed in to replace the old speedometer display. The face plate will allow for only the LCD screen to be seen by the user of the simulator and will be screwed directly where the old speedometer display was located. All of this should allow for immersive experience for the simulator by not creating an eye sore that sticks out from the rest of the car. The green pieces from the above digrams will be 3D printed in black to blend in with the rest of the components in the car. The pink piece is the Arduino and the yellow piece is the display.

### BOM

| Part        | Price    |
|:-----------:|:--------:|
| Arduino     | $27.60  |
| USB 2.0     | $ 7.60   |
| TFT Color LCD | $ 19.00|
| TOTAL       | $54.20   |

### REFERENCES
[1] https://www.amazon.com/Treedix-Display-Screen-Arduino-Mega2560/dp/B0872S57HG

