Gear Shifter Subsystem Analysis
--------------------------------------

### Specifications & Constraints
-	C1. Must use OEM gear shifter sensor
-	C2. OEM shifter sensor must send a detectable output signal for the shifter positions park, neutral, drive, and reverse.
-	C3. Shall receive the OEM gear shifter signal on a local microcontroller
-	C4. Must have local microcontroller that can be powered by a 12 V source
-	C5. Must have local microcontroller that can communicate with the master MCU via UART communication
-	C6. Must have local microcontroller that samples above or at twice the the measured normal frequency of 4.82 Hz from OEM gear shifter sensor to satisfy the Nyquist rate
-	C7. Must have local microcontroller capable of reading the measured 5 V digital output signal from the OEM shifter sensor
-	C8. Must have local microcontroller with at least 4 digital I/O pins to read the output signals coming from the OEM shifter signal
-	C9. Must have wires capable of handling 5 V to read the output signal from the OEM shifter sensor
-	C10. Must comply with IEEE 576-13 section on splicing wires and having loose wires.

## Analysis

### C1.
The output from the OEM shifter sensor is being captured so the sensor is being used.

### C2. C5. and C6.
The master MCU can sucessfully receive the shifter position signal being sent from the local MCU. The local MCU is successfully detecting the shifter positions for positions Park, Neutral, Reverse, and Drive. Since the local MCU is successfully detecting the position changes, the Nyquist rate is satisfied.

![image](https://user-images.githubusercontent.com/117474540/228677170-6f0c93e7-141d-4cf0-85d4-c3bc76ed39c8.png)

###### _Figure 1: The actual shifter position when compared to what the master MCU is displaying

### C3. 
The wires carrying the signal are wire spliced to a microcontroller.

### C4. 
The Arduino Uno is powered by a 12 V source.

### C7.
The signal being sent to the local MCU is a 5 V voltage signal and, the MCU is successfully detecting the 5 V to 0 V changes.

![image](https://user-images.githubusercontent.com/117474540/228677698-2cb7eefb-3693-491d-aed9-308915547104.png)

###### _Figure 2: The measured voltage being detected by the local MCU

### C8.
The Arduino Uno has 14 digital I/O pins.

### C9.
The wires being used for splicing are 22 gauge wires. 22 gauge wires can easily handle 5 V. 

### C10. 
There are no loose or exposed wires. All spliced wires have heat shirink and electrical tape.


