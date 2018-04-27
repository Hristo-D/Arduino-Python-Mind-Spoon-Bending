
This project is for controlling a servo motor using a MindWave Mobile+ headset and an Arduino.
It uses a Python script to set up the port connections for the Arduino and the MindWave headset.
The Python script runs in an infinite while-loop but can be changed to run for a set time.
Before it goes into the while-loop it prompts a keyboard input, which is just an empty input - ''
After it receives the input it starts executing the while-loop, which checks the attention level of the user.
Attention level is a variable coded into the MindWave headset that calculates a user's "attention" and it varies between 0 and 100.
If the attention level is above a certain threshold (in this case 40) python sends a command every 0.5s to the arduino, which is says 5 and
the Arduino uses this number to increment the position of the servo by 5 degrees.
If the attention level drops below the threshold python sends a flag (in this case 2), which tells the arduino to stop incrementing.

Arduino:

The arduino sketch initiates the position, the PWM pin for the servo (in this case it's 10), and the servo delay.
After it attaches the motor it sets up a variable "a", which is always equal to the value set in python (in this case it's 5).
Then it goes through a series of if statements: if the attention level is above a certain threshold it starts incrementing the position
of the servo motor by 5 (pos=pos+a;); if attention level drops below the threshold it stops incrementing (one can make it reverse);
if the position goes above 90 it resets to zero, where 90 is the position at which the spoon's maximum bending position/ the spoon breaks;
if the position goes above 180 it sets it to 180 as this is the maximum position of the motor.

The numbers for the servo position don't necessarily correspond to degrees. If your motor rotates between 0 and 180 then it's the actual
degrees. If the motor has a different limit of rotation then the numbers wouldn't reflect the actual degree change. This is due to the
servo attach command and the way servos operate as the servo reads the pulse width and not a degree value.
