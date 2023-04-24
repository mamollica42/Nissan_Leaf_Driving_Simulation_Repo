SPEEDOMETER SUBSYSTEM ANALYSIS
--------------------

### Specifications & Constraints
- C1. Shall be powered by the PC running the simulator via USB 2.0
-	C2. Microcontroller must be able to read speed data from the simulator while it is running using serial communication
-	C3. Data must exit the PC running the simulator and be stored on a microcontroller using serial communication
-	C4. Shall display the speed data in an appropriate manner on a screen inside the car

### Analysis

### C1. 
An Arduino Uno is powered by the PC running the Simulink model.

### C2. C3. and C4.

The speedometer is placed right where the OEM spedometer use to be. The value on the LCD is received from the PC running a Simulink model and is stored on the Arduino. The value is sent using serial communication with a USB 2.0. The speed data is displayed appropriately due to it being displayed the same way as it was with the old speedometer display. The accuracy of the data being sent to the speedometer was checked by using a counter and sending individual numbers. This method of testing is sufficient due to the number displayed always being the number sent.

![image](https://user-images.githubusercontent.com/117474540/228675279-730bf9e5-0c76-493c-bffe-530309cae70f.png)

###### _Figure 1: The speedometer in the car when Simulink sends the value 15

![image](https://user-images.githubusercontent.com/117474540/228675508-213b1afc-ac1e-494f-9b06-23ecefce4c38.png)

###### _Figure 2: The speedometer in the car when Simulink sends the value 43

### Measures of Success
Initially, the signals from the car's speed sensors were to be spoofed, so the OEM speedometer display could still be used. The local MCU would recieve the speed from the PC to then be spoofed. Instead, a LCD was used to display the number acquired from the PC. A 3D printed mount for the LCD replaced the OEM speedometer display to keep the same immersive feel that was strived for initially. Since the accuracy and the immersive feel were still reached, the new design is a success.  

