Brake Pedal Position System
--------------------------------------
### Function of the Subsystem
This system will obtain the brake pedal posistion and send this signal to a local microcontroller to process its position. The local microcintroller will then send the pedal location to the master microcontroller to implement it to the simulation.  

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

### Wiring Schematic

![BrakePedalSchematic](https://user-images.githubusercontent.com/117474294/217134906-68ba4112-b1f6-4c9f-809d-a28d7ae2ceb4.png)

_Figure 1: The wiring schematic with the desired local MCU and OEM sensors for both pedals being sent to it. 

### Analysis
#### C1. Must use OEM brake pedal to meet customer expectations.
- Customer does not want external brake pedal installed so must use stock pedal.
#### C2. Must send voltage in the range of 0-5V that changes with pedal position to be read by a local microcontroller.
- I am going to use the cars anti-brake system(ABS) deceleration sensor[1] which sends an analog voltage of 0-5V to the ECM. I will wire splice sensor output wires and feed them to local microcontroller analog input pins. 
#### C3. Must have wires able to handle 5V and 20mA to meet the expected voltage range of 0-5V and the expected current of 20mA.
- I am choosing 22 AWG wire since it is rated for 300V and 7A.
#### C4. Shall have an accurate measure of the brake pedal position of at least 1% accuracy to ensure the simulation is an accurate representation of real life.
- Arduino boards convert the analog siganl to digital signal with 4.88mV per step. The smallest signal voltage range was 3.35-3.98V. (3.98-3.35)V/4.88mV = 129 steps and has 1/129 = 0.78% accuracy.
#### C5. Must comply to IEEE 576-13 section on loose wires and splicing of wires.
- This section of standard deals with wire splicing practices and regulation which will be followed when installing the Dorman wire splicing clip that meets regulation. 
#### C6. Must have microcontroller with at least four analog or four digital in ports to read both the gas pedal sensors and the brake pedal sensors.
- I will be using an Arduino Uno Rev3 that has 6 analog pins.
#### C7. Must have microcontroller able to be powered by a 12V source to comply with the power systems design to stay at 12V.
- I chose the Uno over the nano since the uno can be powered by 12V power supply will the nano cannot.
#### C8. Must have microcontroller with UART capability to communicate with the master MCU. 
- The Uno has UART which is haow it will communicate with the Arduino Mega.
#### C9. Must have microcontroller able to convert analog to digital in at least 100ms to be consider real time. (Shown in master MCU signoff)
- The Uno has processing speed of 16MHz which is 62.5ns for one cycle, it takes 13 cycles to convert A to D which takes 0.8125 microseconds which is greater then 100ms.

### Testing 
Brett and I took out the entire brake pedal with the ABS sensor attached and took it to the capstone lab for testing. I turned on the car with the part removed and measured the 4 pin plug and found Vin and GND. Vin is the white wire on pin 3 and GND is the black wire on pin 4. With these pins determined I hooked up those pins to a powersupply and measured the outputs of pin 1 and 2 with a digital multimeter(DMM). I learned that pin 2 has a voltage of 3.35V when not pressed and a voltage of 3.98V while fully pressed. The voltage does change linearly as the brake is pushed. I also learned that pin 1 has a voltage of 2.77V not pressed and 1.58V fully pressed. This voltage also changes linearly as the brake is pushed. With this data I will be able to program the arduino board to get a position based on the change of voltages while the pedal is being pressed. 

### BOM

| Part                         | Price    |
|:----------------------------:|:--------:|
| Arduino Uno Rev 3           | $24.00   |

Sources:
[1] https://www.scribd.com/presentation/344855740/Sensors-Used-in-ABS#


