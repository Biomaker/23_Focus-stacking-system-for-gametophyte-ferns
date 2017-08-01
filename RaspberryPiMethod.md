

## Hardware


<img src="images/IMG_5876.jpg" alt="image"/>
<img src="images/IMG_5877.jpg" alt="image"/>
<img src="images/IMG_5878.jpg" alt="image"/>
<img src="images/IMG_5879.jpg" alt="image"/>
<img src="images/IMG_5890.jpg" alt="image"/>
<img src="images/IMG_5891.jpg" alt="image"/>
<img src="images/IMG_5892.jpg" alt="image"/>
<img src="images/IMG_5894.jpg" alt="image"/>
<img src="images/IMG_5896.jpg" alt="image"/>
<img src="images/IMG_5898.jpg" alt="image"/>
<img src="images/IMG_5899.jpg" alt="image"/>
<img src="images/IMG_5900.jpg" alt="image"/>





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
