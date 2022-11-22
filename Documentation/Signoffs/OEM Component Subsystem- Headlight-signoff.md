OEM Component Subsystem- Headlight
------

## The function of the small part Subsystem
The headlight must send data to the Master microcontroller, and data received by the microcontroller will be a digital signal. 
The digital signal will represent the off, on, high, and low beams to indicate to the microcontroller. Also, The headlight will send data to the microcontroller if it blinks left, right, or both.

### Specification & constraints
   - The headlight shall connect to the Master Microcontroller.
   - The headlight shall produce an output that matches the voltage to the microcontroller and keep the voltage at the same level for the headlight.
   - The headlight shall be powered by the vehicle
   - To much current going to the device
   
Wiring schematic


![image](https://user-images.githubusercontent.com/101354063/203189061-6c70cbb5-0b52-4060-af47-caf9a5024755.png)
### Figure 1: Connect the Nissan leaf with Optocoupler 

Analysis
-------
###### 1. The selection of optocoupler for the subsystem
The objective of the optocoupler for this subsystem is to get feedback out of the headlight without putting strong voltage to the microcontroller or isolating the high voltage from the low voltage. An optocoupler operates by producing infrared light from the input, which a photosensor detects to allow the output to go through. Furthermore, The headlight voltage will allow the Mircocontraoller voltage to be on or off by the optocoupler, as shown in figure 1. Also, The device used for the subsystem will be an optocoupler named LTV-817. 
Overall, the optocoupler will help to detect whether the headlights are on, off, high, low, and beam.


###### 2. precaution for LTV-817
The protection of the device is to prevent the voltage from burning the LTV-817 or too much current by adding a 2.2k resistor to the input of the headlight voltage, which is 12 V.  The reason behind the 2.2 k ohms resistor is because  LVT-817 can handle 20 mA [1]. Furthermore, the reason behind the pull-down resistor is values of input is always in a known state.

###### 3. Side Note
Based on research on the Nissan leaf headlight, depending on the type of headlight used on the vehicle total current drawn by a pair of LED headlights can take around 4.16 amps, or a pair of halogen that can take around 9.16 amps[2]. 


| Part   | Cost   | Qty|
|-------:|:------:|:--:|
| 2.2kohms| $0.10 |  4 |
|10K ohms| $0.10  | 4  |
|LTV-817 | $0.39  | 4  |

reference
---------
[1]https://optoelectronics.liteon.com/upload/download/DS-70-96-0016/LTV-8X7%20series%20201610%20.pdf
[2]https://ledlightinginfo.com/led-headlights-amps#:~:text=So%20the%20total%20amps%20drawn,pair%20would%20be%209.16%20amps.


