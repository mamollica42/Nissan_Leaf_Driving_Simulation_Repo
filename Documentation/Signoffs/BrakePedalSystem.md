Brake Pedal Position System
--------------------------------------
### Function of the Subsystem
This system will obtain the brake pedal posistion and send this signal to a local microcontroller to process its position. The local microcintroller will then send the pedal location to the master microcontroller to implement it to the simulation.  

### Specifications & Constraints
- Must use OEM brake pedal to meet customer expectations.
- Must send voltage in the range of 0-5V that changes with pedal position to be read by a local microcontroller.
- Must have wires able to handle 5V and 20mA to meet the expected voltage range of 0-5V and the expected current of 20mA. 
- Must have microcontroller with at least four analog or four digital in ports to read both the gas pedal sensors and the brake pedal sensors.
- Shall have an accurate measure of the brake pedal position of at least 1% accuracy to ensure the simulation is an accurate representation of real life.
- Must comply to IEEE 576-13 section on loose wires and splicing of wires.
- Must have microcontroller able to be powered by a 12V source to comply with the power systems design to stay at 12V.
- Must have microcontroller with UART capability to communicate with the master MCU. 
- Must have microcontroller able to convert analog to digital in at least 100ms to be consider real time. (Shown in master MCU signoff)

### Wiring Schematic

![BrakePedalSchematic](https://user-images.githubusercontent.com/117474294/217134906-68ba4112-b1f6-4c9f-809d-a28d7ae2ceb4.png)

_Figure 1: The wiring schematic with the desired local MCU and OEM sensors for both pedals being sent to it. 

### Analysis
The car has a ABS decelerator sensor also know as a brake stroke sensor to compare the position of the brake pedal to the rate at which the whells are spinning to determine if the ABS system should engage or not[1]. Since this sensor is measureing the position of the brake pedal it would be able to give us this data if we splice into the output wires of the sensor. Using this sensor will save us money since we don't have to order a third party sensor. This sensor will allow the brake to feel just like it would if the car was working factory on the road. Since the sensor is used in an ABS system, It has to be reliable and accurate as a form of safty. I will use 22 AWG wires with the splice since they are rated for 300V and 7A. The local microcontroller I will be selecting to read this sensor and the accelerator sensor is a Arduino nano rev3[2]. This microcontroller has 8 analog in pins which will cover the 4 sensors output. It is the smallest and cheapest Arduino which is good for our budget. It requires 5V to be powered and is able to measure 0-5V on its analog in pins so it can read all of the sensors voltage ranges.   

### Testing 
Brett and I took out the entire brake pedal with the ABS sensor attached and took it to the capstone lab for testing. I turned on the car with the part removed and measured the 4 pin plug and found Vin and GND. Vin is the white wire on pin 3 and GND is the black wire on pin 4. With these pins determined I hooked up those pins to a powersupply and measured the outputs of pin 1 and 2 with a digital multimeter(DMM). I learned that pin 2 has a voltage of 3.35V when not pressed and a voltage of 3.98V while fully pressed. I also learned that pin 1 has a voltage of 2.77V not pressed and 1.58V fully pressed. With this data I will be able to program the arduino board to get a position based on the change of voltages while the pedal is being pressed. 

### BOM

| Part                         | Price    |
|:----------------------------:|:--------:|
| Arduino Nano Rev 3           | $24.90   |

Sources:
[1] https://www.scribd.com/presentation/344855740/Sensors-Used-in-ABS#

[2] https://store-usa.arduino.cc/products/arduino-nano?selectedStore=us
