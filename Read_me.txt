We have made a program where in we can operate a single led with a normal switch button as well as UART communication (serial communication)

 Main part of the program is to operate the switch in its actual mechanism. i.e high means closed and low means open.
 and for serial monitor 49 is 1 and 48 is 0 considering it as high and low respectively (49 and 48 are ascii values)

let us take one case:
  if serial monitor is high,led turns on.
  if serial monitor is low,led turns off.
similarly,
  if switch is closed, led turns on.
  if switch is open, led turns off.


other case:
  if your led is OFF irrespective of your switch or uart, and at the same time your switch is in closed conditon considering it as the laststate.
 
now you want to turn on the led you have to first open the switch and then close it again.
this shows the actual mechanism of the switch.