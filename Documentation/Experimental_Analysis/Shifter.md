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

### C2. C6. and C5.

### C3. 
The wires carrying the signal are being wire spliced to a microcontroller.

### C4. 

### C7.

### C8.
The Arduino Uno has 14 digital I/O pins.

### C9.

### C10. 


