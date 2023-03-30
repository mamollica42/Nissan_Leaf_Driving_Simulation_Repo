# AutoLight Subsystem Experimental Analysis
### I. Specification & constraints
  - Must detect the auto light high beams, low beams, and left and right indicators with a voltage of no more than 5 volts and a current below 40 milliamps.
   - Must use OEM componets as the inputs
   - The signal input from the autolight must not exceed 5 V 
   - Implement a way to protect the signal from the input voltage varying from 10 V to 15 V
   - Current to the signal must be less than 1 percent of the current to the light
   - Prevent interference among signals through isolation methods

### II. Analysis
   1. ### *Must detect the auto light high beams, low beams, and left and right indicators with a voltage of no more than 5 volts and a current below 40 milliamps.*
   
   High Beam-red\
   Low Beam- grey\
   Left indicator-Blue\
   Right indicator-Yellow

   

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


|    |High Beam | Low beam|Left indicator|Right indicaor|
|----|----------|---------|--------------|--------------|
|Test|current|current|current|current|
|1|0.028 A| 0.027 A| 0.015 A| 0.015 A|
|2|0.028 A| 0.027 A| 0.015 A| 0.015 A|
|3|0.028 A| 0.027 A| 0.015 A| 0.015 A|
|4|0.028 A| 0.028 A| 0.015 A| 0.015 A| 
|5|0.028 A| 0.028 A| 0.015 A| 0.015 A|

Figure 2: each wire current from the headlight to optoisolator

2. ### *The signal input from the autolight must not exceed 5 V* 
   

3. ### *Must use OEM componets as the inputs*
   
   ![Image 6](https://user-images.githubusercontent.com/101354063/228728658-e9466023-0e9e-4d22-82b5-5fc5017103ac.jpeg)

   Figure 3: wire splice form high beam,low beam and left indicator


   ![Image 4](https://user-images.githubusercontent.com/101354063/228728634-3dc5cfa5-c211-45f9-86f4-3aef1d1c9edc.jpeg)

   Figure 4: wire splice form right indicator

  

4. ### *Implement a way to protect the signal from the input voltage varying from 10 V to 15 V*
   ![Image](https://user-images.githubusercontent.com/101354063/228734783-8b76cfe9-ef79-45b2-a289-3058b3288f04.jpeg)
   Figure 5 : wire splice form right indicator



5. ### *Current to the signal must be less than 1 percent of the current to the light*
   ![Image 2](https://user-images.githubusercontent.com/101354063/228732696-bed67f14-d43d-42f4-9fe9-c381a4eb9571.jpeg)
   Figure 6: The current through the light

   - current to the light = 4.79 mA
   - 4.76 mA * 1% = 0.0476 mA
   - As shown in figure 2, the current from the wire is less than 0.0476 mA for the high beam, low beam, left indicator, and right indicator.

6. ### *Prevent interference among signals through isolation methods*
   ![opt](https://user-images.githubusercontent.com/101354063/228733075-1142dd6c-8d4e-4356-abf3-c7ae3806c735.jpeg)
   Figure 7: The optoisolator is isolating the 12 V and 5 V

   The optoisolator prevents any interference from another signal. Also, it will allow 5 V to go through the optoisolator whenever the headlight turns on. Furthermore, it isolates the 12 V from the headlight and 5 v from the Arduino. 

   










