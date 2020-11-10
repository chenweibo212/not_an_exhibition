int count=0;
const int pwPin = 6;
long pulse, inches, cm;
int idistance, cdistance;


void setup(){
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop(){
  pinMode(pwPin, INPUT);
  
  pulse = pulseIn(pwPin, HIGH);
  inches = pulse / 147;
  cm = inches * 2.54;

  int idistance = cm;
  
  Serial.println("idistance:");
  Serial.println(idistance); 
  
  delay(1000);

  pulse = pulseIn(pwPin, HIGH);
  inches = pulse / 147;
  cm = inches * 2.54;

  int cdistance = cm;

  Serial.println("cdistance:");
  Serial.println(cdistance);
  
  delay(200);
  if (cdistance < 25)
  {
    for (int count =0;count<40;count++)
    {
       digitalWrite(8, HIGH);
       digitalWrite(7, LOW);
       analogWrite(9, 255);
       delay(80);
       digitalWrite(8, LOW);
       digitalWrite(7, HIGH);
       delay(80);
     } 
     digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     delay(3000);
     Serial.println("done");
     count = 0;
  } else if (cdistance > 25) {
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
  }
}

