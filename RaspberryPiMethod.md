

##Hardware



##Code

#!/usr/bin/env python

import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

#This assigns the pins of the raspberry pie to variables called "pin".
pin0 = 18
pin1 = 23
pin2 = 24
pin3 = 17

#Set these pins to send messages out rather than listen for messages coming in. 
GPIO.setup(pin0, GPIO.OUT)
GPIO.setup(pin1, GPIO.OUT)
GPIO.setup(pin2, GPIO.OUT)
GPIO.setup(pin3, GPIO.OUT)

#Zero all of the pins between tests. 
def zero_pins():
    time.sleep(0.1)
    GPIO.output(pin0, 0)
    GPIO.output(pin1, 0)
    GPIO.output(pin2, 0)
    GPIO.output(pin3, 0)
	
#This runs the test.
def test():
        
    count = 1
    while (count < 10000):
            print 'The count is:', count
		
            zero_pins()
            GPIO.output(pin0, 1) 

            GPIO.output(pin1, 1)
            zero_pins()             
        
            GPIO.output(pin1, 1)         
            GPIO.output(pin2, 1)      
            zero_pins()
               
            GPIO.output(pin2, 1)       
            GPIO.output(pin3, 1)      
            zero_pins()

            GPIO.output(pin3, 1)       
            GPIO.output(pin0, 1)      
            zero_pins()

count = count + 1
test()
