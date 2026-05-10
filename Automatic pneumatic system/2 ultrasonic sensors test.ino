int signal_pin0 = 5; // Set signal pin
int signal_pin1 = 8; // Set signal pin
int trigPin0 = 6;  // Trigger pin
int echoPin0 = 7; // Echo pin
int trigPin1 = 10;  // Trigger pin
int echoPin1 = 9; // Echo pin
long duration0;
long duration1;
int distance0;
int distance1;
void setup() {
  Serial.begin(9600);
  pinMode(signal_pin0, OUTPUT); // Set the signal pin as an output
  pinMode(signal_pin1, OUTPUT); // Set the signal pin as an output
  
    // Set the trigger pin as an OUTPUT
  pinMode(trigPin0, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  
  // Set the echo pin as an INPUT
  pinMode(echoPin0, INPUT);
  pinMode(echoPin1, INPUT);



}


void loop() {
    // Generate a 10us pulse on the trigger pin
  digitalWrite(trigPin0, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin0, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin0, LOW);

  // Measure the duration of the echo pulse
  duration0 = pulseIn(echoPin0, HIGH);

  // Calculate the distance in centimeters (cm)
  distance0 = duration0 * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance0);
  Serial.println(" cm");

  // Wait for a moment before the next measurement
  delay(100);
if (distance0 <=4){

  digitalWrite(signal_pin0, HIGH); // Turn the signal on
}
else{
  digitalWrite(signal_pin0, LOW); // Turn the signal off
}


    // Generate a 10us pulse on the trigger pin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // Measure the duration of the echo pulse
  duration1 = pulseIn(echoPin1, HIGH);

  // Calculate the distance in centimeters (cm)
  distance1 = duration1 * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance1);
  Serial.println(" cm");

  // Wait for a moment before the next measurement
  delay(100);
if (distance1 <=4){

  digitalWrite(signal_pin1, HIGH); // Turn the signal on
}
else{
  digitalWrite(signal_pin1, LOW); // Turn the signal off
}

}
