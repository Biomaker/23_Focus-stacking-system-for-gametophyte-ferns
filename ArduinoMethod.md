## Hardware

This section explains what hardware is required for an Arduino-driven system, and how it is all wired up. We are only covering the electronics here and the other hardware is discussed in the main page. 

### The full setup from several angles

This is the full setup from above. From top to bottom, the parts are the microscope block connected via cogs to the stepper motor. The stepper motor is then wired to a stepper motor shield, which is in turn wired to the Arduino at the bottom of the photo. 

<img src="images/IMG_5946.JPG" alt="image"/>

This is the same setup from the side. From left to right, the parts are the Arduino, the stepper motor shield, the stepper motor, and then the cogs from the stepper motor to the microscope section on which the camera is mounted. 

<img src="images/_MG_5954edit.jpg" alt="image"/>

Below, again, is the full setup, but shown from slightly above. 

<img src="images/_MG_5955edit.jpg" alt="image"/>


### Wiring positions on the Arduino

The three images below show in detail where the jumper wires need to be connected. Further information about where these wires go is given in the following sections. 

<img src="images/IMG_5945.JPG" alt="image"/>
<img src="images/IMG_5942.JPG" alt="image"/>
<img src="images/IMG_5944.JPG" alt="image"/>

#### Stepper motor shield to Arduino:

The stepper motor shield is shown in this image:

<img src="images/IMG_5941edit.jpg" alt="image"/>

The wire connections from the top left corner of the stepper shield to the Arduino are as follows:

GND to GND<br>
STEP to Digital 2<br>
DIR to Digital 3

#### Stepper motor to stepper motor shield

The stepper motor has four wires which are all unlabelled. It took us some work to figure out which was which, so that we could connect them to the right places. Our four wires are blue, green, red and black. They are connected to the pairs of holes labelled "A" and "B" at the bottom centre of the shield as seen in the photo above.

#### Power cable to stepper motor

The stepper motor needs power to operate, and this is provided via the stepper motor shield. We used a 12V transforner plug which, the wires of which are soldered directly onto the stepper motor shield. Those wires are the black wires visible in the bottom left part of the image above. They are soldered to GND and M+.

#### Infra red remote control:

The two images below show how the infra red camera trigger is wired up. Tim had to take the case right off and then soldered on wires, and firmly connected them using a hot glue gun. 

<img src="images/_MG_5960edit.jpg" alt="image"/>
<img src="images/_MG_5961edit.jpg" alt="image"/>

These wires are connected to the Arduino as follows:

Digital 13 to IR + terminal nearest bulb 
GND to IR terminal furthest from bulb. 

### The cogs

Lastly, below is the set of cogs that allow the stepper motor to drive the microscope block. The cogs are fairly soft plastic and we just got them off the shelf in Maplin. We cut the insides out and they slid easily onto the microscope knob. 

<img src="images/_MG_5958edit.jpg" alt="image"/>



## Code

This is the code that we use to drive the system. All it does is to move the microscope block forward by some tiny amount (how ever far we tell it to go), and then it pauses for the system to settle and triggers the camera to take a shot. 

//Declare pin functions on Arduino<br />
#define stp 2<br />
#define dir 3<br />
#define fire 13<br />
<br />
<br />
//Declare variables for functions<br />
char user_input;<br />
int x;<br />
int y;<br />
int state;<br />
<br />
void setup() {<br />
&nbsp; pinMode(stp, OUTPUT);<br />
&nbsp; pinMode(dir, OUTPUT);<br />
&nbsp; pinMode(fire, OUTPUT);<br />
&nbsp; resetBEDPins(); //Set step, direction, microstep and enable pins to default states<br />
&nbsp; Serial.begin(9600); //Open Serial connection for debugging<br />
&nbsp; Serial.println("Begin motor control");<br />
<br />
}<br />
<br />
//Main loop<br />
void loop() {<br />
&nbsp; while (Serial.available()) {<br />
&nbsp; &nbsp; user_input = Serial.read(); //Read user input and trigger appropriate function<br />
&nbsp; &nbsp; if (user_input == '1')<br />
&nbsp; &nbsp; {<br />
&nbsp; &nbsp; &nbsp; StepForwardDefault();<br />
&nbsp; &nbsp; }<br />
&nbsp; &nbsp; resetBEDPins();<br />
&nbsp; }<br />
}<br />
<br />
//Reset Big Easy Driver pins to default states<br />
void resetBEDPins()<br />
{<br />
&nbsp; digitalWrite(stp, LOW);<br />
&nbsp; digitalWrite(dir, LOW);<br />
}<br />
<br />
//Default microstep mode function<br />
void StepForwardDefault()<br />
{<br />
&nbsp; Serial.println("Moving forward at default step mode.");<br />
&nbsp; digitalWrite(dir, LOW); //Pull direction pin low to move "forward"<br />
&nbsp; for (x = 1; x &lt; 1000; x++) //Loop the forward stepping enough times for motion to be visible<br />
&nbsp; {<br />
&nbsp; &nbsp; digitalWrite(stp, HIGH); //Trigger one step forward<br />
&nbsp; &nbsp; delay(1);<br />
&nbsp; &nbsp; digitalWrite(stp, LOW); //Pull step pin low so it can be triggered again<br />
&nbsp; &nbsp; delay(1);<br />
&nbsp; &nbsp; fireIR();<br />
&nbsp; }<br />
&nbsp;<br />
&nbsp; Serial.println("Enter new option");<br />
&nbsp; Serial.println();<br />
}<br />
<br />
void fireIR()<br />
{<br />
&nbsp; &nbsp; // Power on the IR trigger circuit to fire the camera<br />
&nbsp; &nbsp; digitalWrite(fire, HIGH);<br />
&nbsp; &nbsp; delay(1000);<br />
&nbsp; &nbsp; digitalWrite(fire, LOW);<br />
&nbsp; &nbsp; delay(1000);<br />
}
