## Hardware

## Code

//Declare pin functions on Arduino
#define stp 2
#define dir 3
#define fire 13


//Declare variables for functions
char user_input;
int x;
int y;
int state;

void setup() {
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(fire, OUTPUT);
  resetBEDPins(); //Set step, direction, microstep and enable pins to default states
  Serial.begin(9600); //Open Serial connection for debugging
  Serial.println("Begin motor control");

}

//Main loop
void loop() {
  while (Serial.available()) {
    user_input = Serial.read(); //Read user input and trigger appropriate function
    if (user_input == '1')
    {
      StepForwardDefault();
    }
    resetBEDPins();
  }
}

//Reset Big Easy Driver pins to default states
void resetBEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
}

//Default microstep mode function
void StepForwardDefault()
{
  Serial.println("Moving forward at default step mode.");
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for (x = 1; x < 1000; x++) //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp, HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp, LOW); //Pull step pin low so it can be triggered again
    delay(1);
    fireIR();
  }
  
  Serial.println("Enter new option");
  Serial.println();
}

void fireIR()
{
    // Power on the IR trigger circuit to fire the camera
    digitalWrite(fire, HIGH);
    delay(1000);
    digitalWrite(fire, LOW);
    delay(1000);
}
