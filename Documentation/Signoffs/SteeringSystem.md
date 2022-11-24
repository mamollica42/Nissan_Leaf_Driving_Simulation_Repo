STEERING WHEEL SUBSYSTEM
------------------------
### Function of the Subsystem
The Steering Wheel subsytem shall recieve the input of the Nissan Leaf steering wheel into a sensor
embedded into the steering column of the vehicle. The sensor will measure the steering angle and send
the data into a local microcontroller which will interpret the data and relay it to the simulation.

### Specifications & Constraints
- Must measure angle of rotation of the steering wheel
- Must use the Nissan Leaf OEM steering wheel as the input
- Angle shall be no less than 960 degrees from the left boundary to the right boundary (2 and 2/3 rotations)
- Error of the angle must be within 1 degree of the true steering angle
- Must not lose steering position when power is cycled
- System must be small enough to fit in the area of the vehicle without interfering with the driver or other subsytems

The simulation requires an input for the steering angle of the vehicle. In the Nissan Leaf, the steering
is limited to 2 and 2/3 total rotations from the clockwise boundary to the counter-clockwise boundary.
Therefore, the angle measured must be at least 960 degrees total. Due to the broader impact 
accuracy constraint, the error of the angle sensed must be within 1 degree of the true angle to prevent false
representation of the steering.

### Schematic
##### 1. Model

![image](https://user-images.githubusercontent.com/100802413/203094793-8e89066d-e622-4f77-b923-f02e60bc9ed6.png)

LEGEND:
- Black  --> OEM Parts (Steering Column and Mounting Plate)
- Blue   --> Small Gear
- Green  --> Large Gear
- Red    --> Adapter Plate
- Yellow --> JT-035D (Mounting Bracket)
- Orange --> Absolute Encoder

_Figure 1: 3D-Model of Gear and Encoder Connection_

![image](https://user-images.githubusercontent.com/100802413/203189084-4ff750e8-f932-4b92-87c6-e0bdec4e0706.png)

_Figure 2: 2D Model of the Large Gear to be 3D printed_

![image](https://user-images.githubusercontent.com/100802413/203189280-dcae68cb-8ae4-47ec-b419-241335dcf2db.png)

_Figure 3: 2D Model of the Small Gear to be 3D printed_

![image](https://user-images.githubusercontent.com/100802413/203189609-5dd03eb4-6410-4281-a13b-cac1aa31316c.png)

_Figure 4: 2D Model of the Adapter Plate to be 3D printed_

![image](https://user-images.githubusercontent.com/100802413/203190285-c6b2cc0e-e184-4ab3-b42d-a73d2c848b8a.png)

_Figure 5: 2D Model of the Mounting Plate in the Nissan Leaf_

![IMG_7204](https://user-images.githubusercontent.com/100802413/203190383-4d88893a-d795-43c9-b0dd-f7bd2a8ef0a3.jpg)

_Figure 6: Highlighted the Mounting Plate from Figure 5 in the Nissan Leaf_

##### 2. Wiring Schematic

![image](https://user-images.githubusercontent.com/100802413/203655408-eaf541b6-9036-4ff9-b6dc-a94fa89a0a0f.png)

_Figure 7: Encoder Connection to MCU_


### Analysis
##### 1. Angular Rotation

To select the appropriate rotary encoder, the CPR value must be enough to measure each steering position accurately. The equation below is used to capture the angle in degrees based on the CPR and the counts:
      
      A = (C/CPR) * 360       (1)

where C is the number of counts, CPR is the Counts per Revolution, and A is the angle in degrees.

Similarly, the accuracy of the angle is highly important to the selection of an encoder. To find the output sensitivy of the encoder, the following equation is used:
     
     D = 360/(Resolution)       (2)

where D is the degrees of accuracy and Resolution is the how many data bits. 

##### 2. Encoder Selection

This steering wheel design will use a TRD-NA1024NW absolute rotary encoder with a resolution of 1024. The unique property of the absolute encoder is that the output will remain constant even if the encoder is not powered which allows the system to not lose the steering position when power is cycled. The Encoder a voltage rating of 12 to 24 VDC, and a maximum current consumption of 70 mA. The TRD-NA1024NW has 10 data bits, a VDD pin, and a GND pin. This requires a microcontroller with at least 10 digital GPIO pins and that can receive current of up to 32 mA from the rotary encoder.

The encoder has 1024 unique 10-bit outputs than will be read into the MCU. The outputs of each pin are 10 V signals which are too high for the MCU to read becuase the Arduino digital input pins operate at 5 V. To overcome this issue, a simple two resistor voltage divider will be connected to each output of the encoder. To solve for the resitance needed, the below equation is used:

      Vin = Vout*(R2/R1 + R2)   (3)
      
In this case, Vin is 10 V and Vout must be 5 V. Therefore, selecting R1 such that it equals R2 will give a Vout of 5 V because 10 V / 2 = 5 V. For the purposes of this project, R1 and R2 will be 2 W, 100k Ohm resistors to ensure the current of 32 mA will not damage the resistors in the voltage divider circuit. This can be proved by the equation below:

      P = IV                    (4)
      
where P is power dissipated in the resistor, I is current through the resistor, and V is the voltage across the resistor. The resistors are each rated for 2 W of power. If each resistor is placed in the circuit and are equivalent, the current though each resistor will be equal. Additionally, the voltage across each resistor will be 5 V based on Ohm's Law where V = IR. Therefore, the power consumed in each resistor is (5 V)(32 mA / 2) = 0.16 W which is much less than the maximum rating of 2 W.

The output of the encoder changes on rotation of the knob. The knob of the encoder will be connected to a gear system that is mounted to the steering column of the vehicle so that the steering wheel rotation will rotate the knob. Each 10-bit output will increment or decrement a count variable in the MCU code depending on the direction of rotation. That count will be used to calculate the angle of the wheel using equation 1 above.

Our contraint of 1% accuracy means that the encoder must have a resolution high enough to measure values within 1 degree of the true angle. With a 1024 resolution, we are able to cut down the accuracy to 0.9375 degrees, which is highly accurate. This resolution is the lowest possible that allows the team to measure less than a degree of change in the steering angle.


##### 3. Microcontroller Selection

The Arduino UNO REV3 is clocked at 16 MHz, has 14 digital I/O pins, and 6 analog I/O pins. The board can be powered via battery, USB, or the VDD pin and can operate within a voltage range of 7-12 V. Each GPIO pin can receive up to 40 mA and operates at 5 V. The maximum current consumption Given that the encoder requires 10 digital pins, the Arduino UNO can support that requirement and still have leftover pins for communication. Addtionally, the power supplied to the encoder will be supplied by the power system to avoid any possible damage to the microcontroller.

##### 4. Connectivity

The rotary encoder must be connected to the steering column such that the rotation of the wheel can be properly mapped to the encoder. This will be done using a gear system with an 8:3 gear ratio. This value is based on the 960 degree rotation of the Nissan Steering Wheel having to be mapped to the 360 degree rotation of the encoder. The below equation helps analytically verify this calculation:

      Driven/Driving = 960/360 = 8/3 ==> 8:3    (5)
      
The steering wheel is already limited to the 960 degree range by Nissan. This means that the steering wheel physically is unable to exceed 960 degrees of rotation from the left boundary to the right boundary. Therefore, mapping its rotation using the 8:3 gear ratio will also make it physically impossible for the rotation of the encoder to exceed 360 degrees as desired. The TRD-NA1024NW is a 1024 resolution encoder, meaning it displays 1024 unique outputs per revolution. For each turn of the encoder, 0.356 degrees will be measured allowing the angle to be extremely precise. Additionally, by attaching the gear system to the steering column, the OEM steering wheel can be used as the input to the encoder.  

##### 5. Calculations
To find the diameters of the gears that will be used to create the 8:3 gear ratio, we will follow the Law of Gearing:
      
      D2/D1 = T2/T1                             (6)
      
where D1 and D2 are the diameters of the gears, and T1 and T2 are the number of teeth for each gear. To acheive an 8:3 ratio, the driving gear will have 18 teeth and the driven gear will have 48 teeth. This translates to 6 cm and 16 cm respectively for D1 and D2 to maintain the 8:3 ratio while meeting the spacing constraint of the vehicle.

To verify that this ratio would provide accurate mapping of 960 to 360 degrees, we created a MATLAB script to iterate through all possible positions of the encoder as seen in the figure below.

![image](https://user-images.githubusercontent.com/100802413/202862273-5f44f45a-ed0a-4e65-bb63-7dd475245d4e.png)

_Figure 8: MATLAB Verfication for all possible Angles_

##### 6. Gear and Mounting Design
The size constraints for the next closest item in the car are as follows:
- Closest point to the left of the mounting plate: 12 cm
- Closest point behind the mounting plate: 6 cm
- Closest point below the mointing plate (barrier determined to be for operator's feet): 10 cm
- Closest point to the right of the steering column: 7 cm
- Closest point to above the steering column: 9 cm

The steering column has an inch diameter, so the small gear must have a center bore of exactly 1 inch (2.54 cm). To maintain a small size, the small gear was chosen to have a 6 cm pitch diameter to fit around the steering column and comply with size restrictions around the column. When chosing 6 cm for the small gear, 16 cm must be the pitch diameter of the large gear based on the Law of Gearing. The center bore of the large gear must fit the knob of the encoder such that the rotation of the gear is the same rotation for the encoder. In this case, the center bore of the large gear must be 8 mm in diameter and a 0.5 mm notch to secure the knob of the encoder. 

The mounting bracket of the encoder will be connect to the frame of the Leaf via an adapter plate. The gear connected to the encoder needs to be on the same plane as the gear from the steering column to allow the gears to mesh properly. This was done by creating the adapter plate to allow the mounting bracket to be rotated 45 degrees from the frame and be parallel to the steering column. Then the depth of the adapter was determined to be 12.7063 mm based off of the space needed to have the gears far enough to mesh, but also have the gears as close as possible to reduce the backlash between the teeth. These gears will be 3D printed in the Maker's Space in the Angelo & Jennette Volpe Library.

The furthest point that the design extends to the right is the small gear on the steering column, and its farthest point protrudes 2.03 cm from edge of the steering column. The furthest point to the left is the large gear and it should extend 10.38 cm past the edge of the mounting plate. The model should not extend below the mounting plate by any more than 1 cm. The back of the mounting plate is the furthest back that the design goes and should not conflict with the wall. The furthest up the design goes is the 10.45 cm due to the large gear and the closest point is above the steering column. Since the large gear is offset, the closet point to it is 17 cm above the mounting plate. With the specifications of the design, none of the boundaries on the car are exceeded and the size constraints are met.

### BOM

| Part         | Price    |
|:------------:|:--------:|
| TRD-NA1024NWD| $352.00  |
| JT-035D      | $13.00   | (Mounting Bracket)
| Arduino      | $27.60   |
| Resistors    | $7.60    |
| TOTAL        | $400.20  |

_*Note: The filament and the printer will be provided by the university because this is a school project_
