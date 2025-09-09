// Connections to the Arduino Uno
const int trig = 12; // Ultrasonic sensor
const int echo = 11; // Ultrasonic sensor
const int leftForward = 2; // DC Motor
const int leftBackward = 3; // DC Motor
const int rightForward = 4; // DC Motor
const int rightBackward = 5; // DC Motor

int duration = 0;
int distance = 0;

void setup()
{
  pinMode(trig , OUTPUT);       // Ultrasonic sensor
  pinMode(echo , INPUT);        // Ultrasonic sensor
  pinMode(leftForward , OUTPUT); // DC Motor
  pinMode(leftBackward , OUTPUT); // DC Motor
  pinMode(rightForward , OUTPUT); // DC Motor
  pinMode(rightBackward , OUTPUT); // DC Motor

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig , HIGH);       // Send trigger pulse
  delayMicroseconds(500);          // Short delay
  digitalWrite(trig , LOW);

  duration = pulseIn(echo , HIGH);  // Read pulse
  distance = (duration / 2) / 28.5; // Convert to cm
  Serial.println(distance);         // Debugging output

  if (distance < 30)
  {
    // Reverse left, forward right -> turn away
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    delay(500);

    // Stop briefly
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , LOW);
  }
  else
  {
    // Forward
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);

    delay(500);

    // Stop briefly
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(rightBackward , LOW);
  }
}
