int trigpin = 8; //connecting the trigger pin of the US sensor to digital pin 8
int echopin = 9; // connecting the echo pin to digital pin 9
void setup() {
  Serial.begin(9600); //initializing serial monitor for output
  pinMode(trigpin,OUTPUT); //setting the trigger pin to output mode
  pinMode(echopin,INPUT); //setting the echo pin to input mode
}

void loop() {
  long duration, distance; // duration is the value of how much time does the sound wave take from transmission to receiving, making a round trip
  
  //the following sets the trigpin high, transmitting ultrasonic wave, but just for 10 microseconds, and then sets it low, creating an ultrasonic pulse

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  
  //duration can be calculated using pulseIn function, where pulseIn starts a timer, setting echo pin to high, and the stops it when echo pin receives an input, thus noting down the value of the time taken for the roundtrip

  duration = pulseIn(echopin, HIGH); //in microsec
  distance = (duration * 0.0343)/2; // speed of sound in cm/microsec = 0.0343, and dividing by 2 because we need the distance of one-way travel
  
  Serial.println("Distance: ");
  Serial.println(distance);
  delay(1000); //goes back to loop after 1 second

}
