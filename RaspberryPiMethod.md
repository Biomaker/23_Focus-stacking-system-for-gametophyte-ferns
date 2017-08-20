

## Hardware

This section explains what hardware is required for a Raspberry Pi-driven system, and how it is all wired up. We are only covering the electronics here and the other hardware is discussed in the main page. 

### The full setup 

This is the full setup from above. At the top, the microscope block is connected via cogs to the stepper motor. The stepper motor is then wired to a stepper motor shield, which is in turn wired to the Raspberry Pi at the bottom of the photo. 


<img src="images/IMG_5876.JPG" alt="image"/>

This second image shows the setup from the side. On the left is the Raspberry Pi, connected to the stepper motor shield in the centre, which is in turn connected to the stepper motor on the right. The stepper motor drives the microscope focus block via a couple of blue cogs. 

<img src="images/_MG_5890.JPG" alt="image"/>


#### Stepper motor shield to Raspberry Pi:

The stepper motor shield is shown in this image:

<img src="images/_MG_5891.JPG" alt="image"/>

The wire connections from the top left corner of the stepper shield to the Arduino are as follows:

GND to <br>
STEP to <br>
DIR to 

The jumper wires go to the GPIO pins are shown below. 

<img src="images/_MG_5894.JPG" alt="image"/>

The exact positions of the jumper wires on the GPIO pins is shown here.

<img src="images/_MG_5896.JPG" alt="image"/>
<img src="images/_MG_5898.JPG" alt="image"/>
<img src="images/_MG_5899.JPG" alt="image"/>
<img src="images/_MG_5900.JPG" alt="image"/>





## Code
<p>
#!/usr/bin/env python
</p><p>
import RPi.GPIO as GPIO<br>
import time
</p><p>
GPIO.setmode(GPIO.BCM)
</p><p>
#This assigns the pins of the raspberry pie to variables called "pin".<br>
pin0 = 18<br>
pin1 = 23<br>
pin2 = 24<br>
pin3 = 17
</p><p>
#Set these pins to send messages out rather than listen for messages coming in. <br>
GPIO.setup(pin0, GPIO.OUT)<br>
GPIO.setup(pin1, GPIO.OUT)<br>
GPIO.setup(pin2, GPIO.OUT)<br>
GPIO.setup(pin3, GPIO.OUT)
</p><p>
#Zero all of the pins between tests. <br>
def zero_pins():<br>
    time.sleep(0.1)<br>
    GPIO.output(pin0, 0)<br>
    GPIO.output(pin1, 0)<br>
    GPIO.output(pin2, 0)<br>
    GPIO.output(pin3, 0)
	</p><p>
#This runs the test.<br>
def test():
     </p><p>   
    count = 1<br>
    while (count < 10000):<br>
            print 'The count is:', count
</p><p>		
            zero_pins()<br>
            GPIO.output(pin0, 1) 
</p><p>
            GPIO.output(pin1, 1)<br>
            zero_pins()             
 </p><p>       
            GPIO.output(pin1, 1)   <br>      
            GPIO.output(pin2, 1)   <br>   
            zero_pins()
</p><p>               
            GPIO.output(pin2, 1)   <br>    
            GPIO.output(pin3, 1)    <br>  
            zero_pins()
</p><p>
            GPIO.output(pin3, 1)  <br>     
            GPIO.output(pin0, 1)   <br>   
            zero_pins()
</p><p>
count = count + 1<br>
test()
</p>
