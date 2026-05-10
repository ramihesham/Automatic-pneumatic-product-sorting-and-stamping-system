#define signalpin_v 8
#define trigPin1 9
#define echoPin1 10
#define signalpin_h1 7
#define trigPin2 11
#define echoPin2 3
#define signalpin_h2 2
#define S0_PIN 12
#define S1_PIN 13
#define S2_PIN 4
#define S3_PIN 5
#define OUT_PIN 6

void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(signalpin_v, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(signalpin_h1, OUTPUT);
  pinMode(signalpin_h2, OUTPUT);
  pinMode(S0_PIN, OUTPUT);
  pinMode(S1_PIN, OUTPUT);
  pinMode(S2_PIN, OUTPUT);
  pinMode(S3_PIN, OUTPUT);
  pinMode(OUT_PIN, INPUT);
  digitalWrite(S0_PIN, HIGH);
  digitalWrite(S1_PIN, LOW);
}

void loop() {
  int r, g, b;
  // iltrasonic 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  // iltrasonic 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  if(distance <= 10 ){

    digitalWrite(signalpin_v, HIGH); // Turn the relay on
    delay (500);
  }
  else {
  digitalWrite(signalpin__v, LOW); // Turn the relay off
  delay (500);
  }
  if(distance <= 10 ){

    digitalWrite(signalpin_h1, HIGH); // Turn the relay on
    delay (500);
  }
  else {
    digitalWrite(signalpin__h1, LOW); // Turn the relay off
    delay (500);
  }
 
  r = process_red_value();
  delay(200);
  g = process_green_value();
  delay(200);
  b = process_blue_value();
  delay(200);
  Serial.print("r = ");
  Serial.print(r);
  Serial.print(" ");
  Serial.print("g = ");
  Serial.print(g);
  Serial.print(" ");
  Serial.print("b = ");
  Serial.print(b);
  Serial.print(" ");
  Serial.println();
  if (r < 42){
      Serial.println("Colour Pink");
  }
  else if (g < 63)
  {
      Serial.println("Colour Green");
  }
  else if (r < 64)
  {
    Serial.println("Colour Red");
  }

  if (r>b) 
  {
    Serial.println("blue");

  }
  else if (b>r){
    Serial.println("Red");    
  }

}
    


