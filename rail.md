## Rail Hardware

Here is the rail hardware setup. The focus block, on which the camera rests, is a block from a Nikon Optiphot or Labophot microscope. It was sawn out of the microscope by Doc.Al of the http://www.photomacrography.net/ forum. He also drilled holes in it, which have allowed me to fasten it to the board. The board is a piece of discarded kitchen worktop.

You can see the focus knob under the camera. It allows the top section of the block to be moved back and forth. There is a coarse and fine focus knob. On the other side of the focus block there are identical focus knobs. 

<img src="images/IMG_5249.JPG" alt="image"/>

Switching now to the other side - below, you can also see the stepper motor, and the gearing that allows it to drive the fine focus control. The focusing can be driven by a Raspberry Pi or an Arduino, as shown in the two photographs below. The red board is a stepper motor shield. 

We provide instructions on how to drive the system using either an <a href="https://github.com/BioMakers/23_Focus-stacking-system-for-gametophyte-ferns/blob/master/ArduinoMethod.md">Arduino</a> or a <a href="https://github.com/BioMakers/23_Focus-stacking-system-for-gametophyte-ferns/blob/master/RaspberryPiMethod.md">Raspberry Pi</a>. Please see one or other of these pages for the wiring illustrations, depending on which hardware you are using. Summary tables of the wiring for both systems are provided below, and will make more sense if used in conjunction with the illustrations on the two pages mentioned above.

## Wiring

### Big Easy Driver Wiring

|Big Easy Driver connection	| Destination|
| ------------- | ------------- |
|GND (top left)	| GND|
|STEP (top left)	| 2 Arduino, 24 RPi|
|DIR (top left)	| 3 Arduino, 26 RPi|
|M+ (bottom left)	| Power cable for stepper motor|
|GND (bottom left)	| Power cable for stepper motor|
|A	| “A” wire of the stepper motor|
|A	| “A” wire of the stepper motor|
|B	| “B” wire of the stepper motor|
|B	| “B” wire of the stepper motor|

### Infra Red remote control wiring

|Infra Red remote control	|Raspberry Pi	|Arduino|
| ------------- | ------------- |------------- |
|Non-bulb end	|GND	|GND|
|Bulb-end	|19	|13|

### Stepper motor wiring

The stepper motor is a 4 wire stepper motor, with two circuits. In order to wire it up correctly we checked the wires in pairs with a voltage meter to see which pairs produced a voltage. We designated these pair “A” and pair “B”, which were then wired up as shown in the Big Easy Driver wiring table above. 

### Raspberry Pi setup:

<img src="images/IMG_5239.JPG" alt="image"/>

### Arduino setup:

<img src="images/IMG_5946.JPG" alt="image"/>

The stepper motor is an RS Pro Hybrid Stepper Motor 0.9°, 44 Ncm, 2.8 V, 1.68 A, 4-wire motor, which was bought from http://uk.rs-online.com/. I intentionally brought quite a beefy motor in the hope that it would be less likely to burn out. It is also very square in the body, which helps to brace it against the board. 

Below is a close-up view of the gearing. The gear wheels were bought from http://www.maplin.co.uk/ and then the centres were drilled out or cut out with a hacksaw blade. The plastic gears were very soft, and easy to cut. 

<img src="images/IMG_5238.JPG" alt="image"/>

Below, in close-up, is the driver board that allows the Raspberry Pi or Arduino to drive the stepper motor. The stepper motor is a 4-wire bipolar stepper motor, and requires an H-bridge chip to drive it. The board brought a number of specific advantages over just using an H-bridge and breadboard. The motor is able to turn a single complete turn of its spindle in 400 steps, but with the driver board this can be changed to 16 steps. The current reaching the motor can also be controlled so that the motor does not burn out. 


<img src="images/IMG_5240.JPG" alt="image"/>




Tim devised a system whereby the Raspberry Pi or Arduino could also send a signal to fire the shutter of the camera automatically. He took apart a 3rd-party infra red Canon camera remote control and wired it up to the Raspberry Pi or Arduino terminals. This meant that he could write a single programme to operate the stepper motor, and fire the shutter of the camera alternately. We have tried this and it works well. 

Below is a photograph of the infra red remote control with its new wiring. 

<img src="images/_MG_5899.JPG" alt="image"/>

This is the other side. The wires are attached firmly to the board using the glue from a hot glue gun. 

<img src="images/_MG_5900.JPG" alt="image"/>


Tim has carried out some experiments on the travel that is produced in the focus block using this stepper motor setup. He figured out that a single step of the stepper motor moves the top part of the focus block 1/128th of a μm (micro metre), which is very very good for our purposes. So for 128 steps of the stepper motor we have movement of 1 micron. The movement is very smooth indeed. The depth of field of the optics with the Mitutoyo lens is about 20 microns. In the end I found that 17 microns was enough and this more rapid progress was better for stopping the bright lights from drying out the subject. To achieve a 17 micron step we needed to use 128 x 17 steps of the stepper motor.


## List of Hardware Bits for the Rail

Bit of discarded worktop (£0)<br>
Bit of sawn off Nikon Optiphot or Labophot microscope (£0 this time, but I was very lucky)<br>
Cogs from Maplin (about £15)<br>
Screws (£1 MacKays hardware shop in Cambridge)<br>
Sheet of metal (£1.37 from MacKays hardware shop in Cambridge)<br>
Raspberry Pi B (£34.50) or Arduino Uno (£17.30)<br>
Canon Remote Control RC-06 (£16.99) or amazon version (£6.99)<br>
Jumper wires<br>
12v power supply transformer plug to drive motor via Raspberry Pi or Arduino. <br>
"<a href="https://www.coolcomponents.co.uk/en/big-easy-driver.html?gclid=Cj0KCQjwlMXMBRC1ARIsAKKGuwi1l4njTmxLjw_-HU0Y6a0uq0VRKntCE-Y4QuHq51zZWsJd3BriBewaAuWZEALw_wcB">Big Easy Driver</a>" Stepper motor control board with voltage adjustment (£22)<br>
<a href="http://uk.rs-online.com/web/p/stepper-motors/5350401/">RS Pro Hybrid Stepper Motor</a> 0.9°, 44Ncm, 2.8 V, 1.68 A, 4 Wires (£27.17)<br>
Soldering equipment<br>
Hot glue gun

### Arduino version also requires:

USB cable to connect to laptop

### Raspberry Pi version also requires:

SD card<br>
Wireless dongle 
