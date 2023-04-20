# Nissan Leaf Driving Simulation

## Executive Summary

The Nissan Leaf Driving Simulation is a long-term goal for the ECE and ME Departments at TNTECH. This project consists of data acquistion and initial hardware setup for the future simulation to be built off of. The hopes of the final product are to accurately replicate the look and feel of driving a Nissan Leaf without the actual motion of the vehicle.


## Capabilities

This repository currently contains finalized documents for the project, but future work will be done and uploaded once complete. The proposal contains the specifications and solutions to complete this project over the course of the next several months. The conceptual design layouts out the "what" for the implementation of each subsystem of the overall design. Further details on the "how" can be seen in the Documentation folder and their supporting analysis can be viewed in the Signoffs folder.


## Salient Outcomes
- Measure steering angle from -600 to +600 degrees
  - _Note: After experimentation, the team discovered that the left and right bounds of the steering wheel are NOT equal. That is, the wheel rotates slightly more to the right than it does to the left by approximately 20 degrees._
- Capture break and accelerator percentage of compression
- Detect shifter position and auto-light selection
- Single system power switch with overcurrent protection
- Collect CAN Bus messages >> 10 Hz
- Replaced speedometer with aesthetic 3D printed LCD module
- Use of OEM steering wheel, brake pedal, accelerator pedal, shifter, and auto-light knobs
- All hardware is concealed from the user
- Provide all data to PC in less than 100 milliseconds


## Project Demonstration & Images
Power Supply & Control Switch|Steering Gear System|Shifter Subsystem|
:---------------------------:|:------------------:|:------------------:
![image](https://user-images.githubusercontent.com/100802413/231281842-33e38989-c950-4742-b415-772c64c87afe.png)|![image](https://user-images.githubusercontent.com/100802413/231281007-fba1626d-8299-4a3b-aa15-580663068b0e.png)|![image](https://user-images.githubusercontent.com/100802413/231281449-5a6acad0-abc4-46f6-9848-599c58618a26.png)

Final Vehicle Interior|
:--------------------:|
![image](https://user-images.githubusercontent.com/100802413/233418173-102dd12d-76e9-44bd-b84b-2adc2229814b.png)|




## About Us

### Team

Michael Mollica - CmpE

Gerardo Mateo - CmpE

Chase Colotta - EE

Brett Harden - EE

Ethan Powers - EE


### Faculty Supervisor

Dr. Nan Chen - ECE Department

Mr. Jesse Roberts -  ECE Department

### Stakeholders

Dr. B. Andy Pardue - ME Department


## Repo Organization
### Reports
- Project Proposal
- Conceptual Design

### Documentation
- 3D Models
- Electrical Diagrams
- Images
- Signoffs

### Software
- Documentation -> Software
- Folder includes all Arduino code used to program the MCUs
