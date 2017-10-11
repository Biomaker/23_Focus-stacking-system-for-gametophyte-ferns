
// Number of pictures to take
#define shots 100
// How far to advance between shots
// 128 steps == 1 mark on the fine control == 1 micron
#define MICRON 128L
#define distance (17 * MICRON)

//Declare pin functions on Arduino
#define stp 2
#define dir 3
#define fire 13

void setup() {
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(fire, OUTPUT);
  digitalWrite(stp, LOW);
  digitalWrite(dir, HIGH);
  Serial.begin(9600); //Open Serial connection for debugging
}

//Main loop
void loop() {
    long int i, j;
    char input;

    Serial.println("Press Enter to start");
    do {
        input = Serial.read();
    } while (input != '\n');
    
    for (i = 0; i < shots; i++) {
        trigger();
        for (j = 0; j < distance; j++) {
            step();
        }
    }
}

// Power on the IR trigger circuit to fire the camera
void trigger()
{
    delay(1000); // wait for vibration to settle
    digitalWrite(fire, HIGH); // take the picture
    delay(1000); // wait for that to happen
    digitalWrite(fire, LOW); // disable the IR circuit again
}

// Advance the motor by one step
void step()
{
    digitalWrite(stp, HIGH); //Trigger one step forward
    delayMicroseconds(25);
    digitalWrite(stp, LOW); //Pull step pin low so it can be triggered again
    delayMicroseconds(25);  
}

