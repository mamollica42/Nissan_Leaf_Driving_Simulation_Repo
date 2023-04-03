Steering Experimental Analysis
----
### Specifications & Constraints
- Must measure angle of rotation of the steering wheel
- Must use the Nissan Leaf OEM steering wheel as the input
- Angle shall be no less than 960 degrees from the left boundary to the right boundary (2 and 2/3 rotations)
- Error of the angle must be within 1 degree of the true steering angle
- Must not lose steering position when power is cycled
- System must be small enough to fit in the area of the vehicle without interfering with the driver or other subsytems
### Analysis
#### SC1
The main function of the steering subsystem is to capture the angle of the steering wheel. Using an absolute rotary encoder, angle is a function of the resolution of the encoder and its current position.
    
    Angle = (Position * Resolution) / 360

where angle is in degrees, and resolution is 1024 for the 10-bit rotary encoder. This function is programed in the Master MCU using the following code:

    angle = (pos*1024)/360;
    
However, the programming alone does not provide the exact angle we are trying to measure. The gear system is in place to map the 360 degree rotation to the 1200 degree rotation of the steering wheel. This gear system was originally designed to be an 8:3 gear ratio based on the previously assumed 960 degrees of rotation of the steering wheel. Although, after some testing, the team discovered that the steering wheel has a 1200 degree of rotation, which must be accounted for with a 10:3 gear ratio. So at the time being, the angle is being measured but it is incorrect in all cases as the gear system must be changed. The new gear design should be ready to be installed in the next week or less.
#### SC2
The Nissan Leaf steering wheel is the input device of the steering subsystem. The rotary encoder measuring the changes in position of the steering wheel is mounted to the steering column of the vehicle so that turning the wheel will rotate the steering column and update the value on the Master MCU.
#### SC3 -> _Modified to "Angle shall be no less than 1200 degrees from the left boundary to the right boundary (3 and 1/3 rotations)"_

### Conclusion
