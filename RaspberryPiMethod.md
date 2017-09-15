

## Hardware

This section explains what hardware is required for a Raspberry Pi-driven system, and how it is all wired up. We are only covering the electronics here and the other hardware is discussed in the main page. 

### The full setup 

This is the full setup from above. At the top, the microscope block is connected via cogs to the stepper motor. The stepper motor is then wired to a stepper motor shield, which is in turn wired to the Raspberry Pi at the bottom of the photo. 


<img src="images/IMG_5876.JPG" alt="image"/>

This second image shows the setup from the side. On the left is the Raspberry Pi, connected to the stepper motor shield in the centre, which is in turn connected to the stepper motor on the right. The stepper motor drives the microscope focus block via a couple of blue cogs. 

<img src="images/_MG_5890.JPG" alt="image"/>

## Wiring setup on the Raspberru Pi

The exact positions of the jumper wires on the GPIO pins of the Raspberry Pi is shown here.

<img src="images/_MG_5898.JPG" alt="image"/>

The three jumper wires on the left side of the image lead to the stepper motor shield. The black and white wires on the right hand side of this image lead to the infra red camera remote control. 

#### Stepper motor shield to Raspberry Pi:

The stepper motor shield is shown in this image:

<img src="images/_MG_5891.JPG" alt="image"/>

The wire connections from the top left corner of the stepper shield to the Raspberry Pi are as follows:

GND to <br>
STEP to <br>
DIR to 

The jumper wires go to the GPIO pins as shown below. 

<img src="images/_MG_5894.JPG" alt="image"/>

The exact positions of the jumper wires on the GPIO pins of the Raspberry Pi is shown again here.

<img src="images/_MG_5898.JPG" alt="image"/>


#### Stepper motor to stepper motor shield

The stepper motor has four wires which are all unlabelled. It took us some work to figure out which was which, so that we could connect them to the right places. Our four wires are blue, green, red and black. They are connected to the pairs of holes labelled "A" and "B" at the bottom centre of the shield as seen in the photo above.

#### Power cable to stepper motor

The stepper motor needs power to operate, and this is provided via the stepper motor shield. We used a 12V transforner plug, the wires of which are soldered directly onto the stepper motor shield. Those wires are the black wires visible in the bottom left part of the image above. They are soldered to GND and M+.

## Infra red remote control

The infra red remote control is also wired up to the Raspberry Pi, so that the camera shot can be triggered automatically, after each forward movement of the camera. Each time the camera has moved forward, the Raspberry Pi triggers the infra red remote control bulb to light, causing the camera to take a shot. 

The photos below show the position of the remote control in the setup. 

<img src="images/IMG_5243.JPG" alt="image"/>
<img src="images/IMG_5244.JPG" alt="image"/>

The two images below show how the infra red camera trigger is wired up. Tim had to take the case right off and then he soldered on wires, and firmly connected them using a hot glue gun. 

The wiring is shown below. 
<img src="images/_MG_5899.JPG" alt="image"/>
<img src="images/_MG_5900.JPG" alt="image"/>






## Software

Below is the python program that I run on the Raspberry Pi to drive the rail. I do not have a screen attached to the raspberry pi, so I plug in a wireless dongle and then drive it from my laptop. I log into the raspberry pi using putty and then run the scripts from there. The scripts can be modified in between runs, so that if I feel that the movement of the microscope block needs to be a bigger step or a smaller step then I can quickly alter the distance in the programme. I can also alter the timing. For example I can have 1 micron steps with a 3 second gap in between to make sure that there is time for vibration to stop, or I can have a 5 micron step for a larger subject and 1 second gap if there is a risk that the subject will dry out and change shape during the series. 


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
