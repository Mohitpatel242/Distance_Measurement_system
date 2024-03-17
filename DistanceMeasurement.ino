const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance, distanceCM;

void setup() { 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT );
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCM = duration*0.034/2;
  Serial.println(distanceCM);
  delay(10);

  if(distanceCM <= 20){
    distanceCM = 3;
  }
  else if(distanceCM >20 & distanceCM <= 40){
    distanceCM = 2;
  }
  else if(distanceCM >40 & distanceCM <=70) {
    distanceCM = 1;
  }
  else {
    distanceCM = 0;
  }

  if(distanceCM == 0){
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW); 
  }
  else if(distanceCM == 1){
    digitalWrite(5, HIGH); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW); 
  }
  else if(distanceCM == 2){
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }
  else if(distanceCM == 3){
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);    
  }
}
