
## Accelerator

### Specifications & Constraints
- A1. Must use OEM gas pedal to meet customer expectations.
- A2. Must send voltage at the range 0-5V that changes as the position changes to be read by the local microcontroller.
- A3. Must have wires able to handle at least 5V and 20mA due to the expected voltage range 0-5V and expected current of 20mA.
- A4. Shall have an accurate measure of the pedal postion of at least 1% accuracy to ensure the simulation is a accurate representation of real life. 
- A5. Must not have any exposed or loose wire according to IEEE Std 576-13.  

## Brake 

### Specifications & Constraints
- B1. Must use OEM brake pedal to meet customer expectations.
- B2. Must send voltage in the range of 0-5V that changes with pedal position to be read by a local microcontroller.
- B3. Must have wires able to handle 5V and 20mA to meet the expected voltage range of 0-5V and the expected current of 20mA. 
- B4. Shall have an accurate measure of the brake pedal position of at least 1% accuracy to ensure the simulation is an accurate representation of real life.
- B5. Must comply to IEEE 576-13 section on loose wires and splicing of wires.
- B6. Must have microcontroller with at least four analog or four digital in ports to read both the gas pedal sensors and the brake pedal sensors.
- B7. Must have microcontroller able to be powered by a 12V source to comply with the power systems design to stay at 12V.
- B8. Must have microcontroller with UART capability to communicate with the master MCU. 
- B9. Must have microcontroller able to convert analog to digital in at least 100ms to be consider real time. (Shown in master MCU signoff)

Analysis

A1. and B1.
These are meet by using the cars stock pedals.

A2. and B2.
I tested the voltage range of the outputs for both the gas senor 1 and brake sensor 1 with an oscilloscope. The mean of the voltages are as follows:
Gas sensor 1
Percent pressed | 0% | 50% | 100% 
---|---|---|---|
Voltage read | 815 mV | 1.72 V | 3.65 V |

Brake sensor 1 
Percent pressed | 0% | 50% | 100% 
---|---|---|---|
Voltage read | 1.41 V | 2.02 V | 2.92 V |

