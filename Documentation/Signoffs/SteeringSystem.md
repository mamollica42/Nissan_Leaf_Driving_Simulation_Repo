STEERING WHEEL SUBSYSTEM
------------------------
### Function of the Subsystem
The Steering Wheel subsytem shall recieve the input of the Nissan Leaf steering wheel into a sensor
embedded into the steering column of the vehicle. The sensor will measure the steering angle and send
the data into a local microcontroller which will interpret the data and relay it to the simulation.

### Specifications & Constraints
- Must measure angle of rotation of the steering wheel
- Must use the Nissan Leaf OEM steering wheel as the input
- Angle Shall be no more than 960 degrees to the left and right (2 and 2/3 rotations)
- Error of the angle must be within 1% of the true steering angle

The simulation requires an input for the steering angle of the vehicle. In the Nissan Leaf, the steering
is limited to 2 and 2/3 rotations from the center point to each clockwise and counter-clockwise direction.
Therefore, the angle measured must be limited to 960 degrees in each direction. Due to the broader impact 
accuracy constraint, the error of the angle sensed must be within 1% of the true angle to prevent false
representation of the steering.

### Schematic
1. Model


2. Wiring Schematic


![image](https://user-images.githubusercontent.com/100802413/200068429-52157dad-0227-41ef-b2f6-d8c828e3f391.png)


![image](https://user-images.githubusercontent.com/100802413/200068789-5da2dbed-f9f1-4354-88d4-3102560d388f.png)


### Analysis

### BOM
