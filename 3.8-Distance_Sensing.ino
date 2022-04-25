
#define echoPin 2 
#define trigPin 3 
long duration;
int distance; 
int x;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600); 
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance<10){
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  }
  else if(distance>10&&distance<30){
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(9,LOW);
  }
  else{
  digitalWrite(9,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  }
}
