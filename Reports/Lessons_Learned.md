# Lessons Learned
----------
### Michael Mollica
1. The overall project approach of tapping into existing sensors worked tremendously well. Additionally, the steering system using a rotary encoder was a fantastic approach to capturing steering angle. However, our initial choice of local MCUs for each subsystem did not go well. This was a failure and ended up being almost completely void by the end of the project. The subsystem breakdown and organization was a success regardless of the modifications made to the design choices.
2. The largest unanticipated problem was the UART communication with 4 MCUs. This was almost never working properly and should have never been the approach to the system design in the first place. The other slight problem was the shifter debouncing when switching from neutral to drive or reverse. This was discovered late in the process of experimentation but was able to be fixed with some software changes.
3. I would make the system dependent on a single MCU for each subsystem because of the issues with UART. This was the most avoidable issue, but also the biggest setback in our project.
4. Some best practices I have learned through this project is to heavily document and comment code, keep all old and new versions of code, keep track of all experimental results, and never assume something will work without testing it.
5. Do not expect everything to work how it was designed. There is so many extraneous errors and mistakes that can occur when physically connecting devices and when designing complex systems. Always have a backup plan and always test your devices extensively.
6. I have learned to program in Arduino much better than I had early in college. I have also learned a lot more about how serial communication works and its proper use.

### Brett Harden
1.
2.
3.
4.
5.
6.

### Chase Colotta
1.
2.
3.
4.
5.
6.

### Gerardo Mateo
1.
2.
3.
4.
5.
6.

### Ethan Powers
1.
2.
3.
4.
5.
6.
