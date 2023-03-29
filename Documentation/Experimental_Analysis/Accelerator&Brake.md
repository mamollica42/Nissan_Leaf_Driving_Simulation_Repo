
## Accelerator

### Specifications & Constraints
- C1. Must use OEM gas pedal to meet customer expectations.
- C2. Must send voltage at the range 0-5V that changes as the position changes to be read by the local microcontroller.
- C3. Must have wires able to handle at least 5V and 20mA due to the expected voltage range 0-5V and expected current of 20mA.
- C4. Shall have an accurate measure of the pedal postion of at least 1% accuracy to ensure the simulation is a accurate representation of real life. 
- C5. Must not have any exposed or loose wire according to IEEE Std 576-13.  

## Brake 

### Specifications & Constraints
- C1. Must use OEM brake pedal to meet customer expectations.
- C2. Must send voltage in the range of 0-5V that changes with pedal position to be read by a local microcontroller.
- C3. Must have wires able to handle 5V and 20mA to meet the expected voltage range of 0-5V and the expected current of 20mA. 
- C4. Shall have an accurate measure of the brake pedal position of at least 1% accuracy to ensure the simulation is an accurate representation of real life.
- C5. Must comply to IEEE 576-13 section on loose wires and splicing of wires.
- C6. Must have microcontroller with at least four analog or four digital in ports to read both the gas pedal sensors and the brake pedal sensors.
- C7. Must have microcontroller able to be powered by a 12V source to comply with the power systems design to stay at 12V.
- C8. Must have microcontroller with UART capability to communicate with the master MCU. 
- C9. Must have microcontroller able to convert analog to digital in at least 100ms to be consider real time. (Shown in master MCU signoff)
