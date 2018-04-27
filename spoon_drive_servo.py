
import serial
import time
from NeuroPy import NeuroPy

ser = serial.Serial(port = 'COM5', baudrate = 9600); #set the Arduino port connection   
object1=NeuroPy("COM4",57600) #set the MindWave headset portconnection
#change ports if needed
object1.start() #start reading from the MindWave headset
#t_end = time.time() + 60 * 1 to define time for the while-loop if needed

print 'Are you ready to break a spoon bitch !!!'
a = input('Shall we continue sucker ?') 
#request a keyboard input, which is '' to continue with the script
#this is done to allow time for the servo to go to the initial position

try :
    while True:
        
        if object1.attention>40:
            #this statement tells the arduino to start moving the motor if
            #attention level is over 40 (attention level varies 0-100)
            ser.write('5')
            time.sleep(0.5) 
            #0.5s time delay to make consistent and smooth movement of the motor
            print object1.attention
        else:
            #this statement tells the arduino to stop moving the motor if 
            # attention level is bellow the threshold
            time.sleep(0.5)
            # another time delay for consistency
            ser.write('2')
            print object1.attention
            
        
except KeyboardInterrupt:
    
    #this is set so that if the script is stopped both ports are closed
    ser.close()
    object1.stop()


