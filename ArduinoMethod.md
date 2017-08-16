## Hardware

Connect pins as follows:

Infra red remote control:

Black wire Digital 13 to IR + terminal nearest bulb 
White wire GND to IR terminal furthest from bulb. 

Stepper motor shield to Arduino

Grey wire GND to GND

### Images

This is the setup from the side. From left to right, the parts are the Arduino, the stepper motor shield, the stepper motor, and then the cogs from the stepper motor to the microscope section on which the camera is mounted. 

<img src="images/_MG_5954edit.jpg" alt="image"/>

Below, again, is the full setup, but shown from slightly above. 

<img src="images/_MG_5955edit.jpg" alt="image"/>

This is the set of cogs that allow the stepper motor to drive the microscope block. The cogs are fairly soft plastic and we just got the off the shelf in Maplin. We cut the insides out and they slid easily onto the microscope knob. 

<img src="images/_MG_5958edit.jpg" alt="image"/>

<img src="images/_MG_5941edit.jpg" alt="image"/>
<img src="images/IMG_5942.JPG" alt="image"/>

<img src="images/IMG_5944.JPG" alt="image"/>
<img src="images/IMG_5945.JPG" alt="image"/>
<img src="images/IMG_5946.JPG" alt="image"/>

<img src="images/_MG_5960edit.jpg" alt="image"/>
<img src="images/_MG_5961edit.jpg" alt="image"/>





## Code
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
