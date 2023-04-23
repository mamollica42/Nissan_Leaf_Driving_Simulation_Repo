# AutoLight Subsystem Experimental Analysis

### I. Specification & constraints
  1.  Must detect the auto light high beams, low beams, and left and right indicators with a voltage of no more than 5 volts and a current below 40 milliamps.
   2. Must use OEM componets as the inputs
   3. The signal input from the autolight must not exceed 5 V 
   4. Implement a way to protect the signal from the input voltage varying from 10 V to 15 V
   5.Current to the signal must be less than 1 percent of the current to the light
   6. Prevent interference among signals through isolation methods

### II. Analysis

### SC1
|    |High Beam | Low beam|Right indicator|Left indicaor|
|----|----------|---------|---------------|--------------|
|Test|Voltage|Voltage|Voltage|Voltage|
|1|4.20V|4.20 V|4.20V|4.00 V|
|2|4.20V|4.00 V|3.60V|3.60 V|
|3|4.00V|4.00 V|3.60V|3.60 V|
|4|4.20V|4.00 V|3.60V|3.60 V|
|5|4.00V|4.20 V|3.80V|3.80 V|
|6|4.00V|4.00 V|3.60V|3.60 V|
|7|4.00V|4.00 V|3.60V|3.60 V|
|8|4.20V|4.20 V|3.60V|3.80 V|
|9|4.00V|4.20 V|3.80V|3.80 V|
|10|4.00V|4.20 V|3.80V|3.80 V|

Figure 1: Each signal input are no more than 5 volt
 
 According to figure1, each signal input is not more than 5 volts. As the Arduino provides the power, it receives 5v. In the experiment, the oscilloscope helped to check each input, and each input produced a voltage below 5 volts, which the Arduino board could detect.



|    |High Beam | Low beam|Left indicator|Right indicaor|
|----|----------|---------|--------------|--------------|
|Test|current|current|current|current|
|1|0.028 A| 0.027 A| 0.015 A| 0.015 A|
|2|0.028 A| 0.027 A| 0.015 A| 0.015 A|
|3|0.028 A| 0.027 A| 0.015 A| 0.015 A|
|4|0.028 A| 0.028 A| 0.015 A| 0.015 A| 
|5|0.028 A| 0.028 A| 0.015 A| 0.015 A|

Figure 2: each wire current from the headlight to optoisolator

   As shown in Figure 2, each wire has a current below 40 milliamps, which meets the requirement. The Multimeters help to measure the current flowing between the fuse cases for the experiment. Also, the data collected from the multimeter shows that the experiment was successful. All the results were within the expected range. The results show that the current will not harm the wire from the headlight to the optoisolator.


### S2
   
   ![Image 6](https://user-images.githubusercontent.com/101354063/228728658-e9466023-0e9e-4d22-82b5-5fc5017103ac.jpeg)

   Figure 3: wire splice form high beam,low beam and left indicator


   ![Image 4](https://user-images.githubusercontent.com/101354063/228728634-3dc5cfa5-c211-45f9-86f4-3aef1d1c9edc.jpeg)

   Figure 4: wire splice form right indicator

### S3
   As shown in figure 1, The input does not go over 5 V because the Arduino is providing power. 
  

### S4
   ![Image](https://user-images.githubusercontent.com/101354063/228734783-8b76cfe9-ef79-45b2-a289-3058b3288f04.jpeg)
   Figure 5 :Protection from the input voltage varying from 10 V to 15 V

   The resistor, fuse, and optoisolator prevent the signal from the input voltage varying from 10 V to 15 V. Also, if a current goes over the limit, the fuse will prevent it and protect the ciruit from frying.


### S5
   ![Image 2](https://user-images.githubusercontent.com/101354063/228732696-bed67f14-d43d-42f4-9fe9-c381a4eb9571.jpeg)

   Figure 6: The current through the light

   - current to the light = 4.79 mA
   - 4.76 mA * 1% = 0.0476 mA
   - As shown in figure 2, the current from the wire is less than 0.0476 mA for the high beam, low beam, left indicator, and right indicator.

### S6
   ![opt](https://user-images.githubusercontent.com/101354063/228733075-1142dd6c-8d4e-4356-abf3-c7ae3806c735.jpeg)
   Figure 7: The optoisolator is isolating the 12 V and 5 V

 The optoisolator prevents any interference from another signal. Also, it will allow 5 V to go through the optoisolator whenever the headlight turns on. Furthermore, it isolates the 12 V from the headlight and 5 v from the Arduino. Using this method prevents the Arduino from being damaged by 12 V signals. Furthermore, it allows the Arduino to detect the headlight when it is on. Finally, it creates a secure connection between the two circuits.

   
## III. Conclusion
Low Beam           |  High Beam
:-------------------------:|:-------------------------:
![low beam](https://user-images.githubusercontent.com/101354063/233819067-fbf7c814-c55e-41a0-beb2-28b690bf1ad3.jpg)|  ![highbeam](https://user-images.githubusercontent.com/101354063/233819068-6a7510cc-74d9-4ffd-bd0b-554d3554274e.jpg)

Left indicator       |  Right indicator 
:-------------------------:|:-------------------------:
![leftInd](https://user-images.githubusercontent.com/101354063/233819070-b466b7c4-5f53-4b78-af71-5f18b05182da.jpg) |  ![right](https://user-images.githubusercontent.com/101354063/233819071-711c404a-aa6c-4aba-865f-a592d5b7939b.jpg)

The four pictures prove that the Arduino was able to detect the voltage. Furthermore, it indicates that there was no inference from another signal. The readings show that the system is working. The results obtained were consistent when the headlight is a different state. Therefore, the circuit is functioning as intended.






