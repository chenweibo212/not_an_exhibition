long randNumber;
int timedelay[4] = {20000,30000,40000,50000};

#define MOTOR_IN1 10
#define MOTOR_IN2 11
int count=0;
 
void setup() {
  Serial.begin(9600);
  
  Serial.print("Start ");
  Serial.println("DRV8871 test");
  
  
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);

  randomSeed(A0);
}
 
void loop() 
{
  long rndVal;

  rndVal = random(4);
  switch (rndVal)
  {
    case 0: rndVal = 20000; break;
    case 1: rndVal = 30000; break;
    case 2: rndVal = 40000; break;
    default: rndVal = 50000; break;
  }
  Serial.print(rndVal);
 
  for (int count =0;count<15;count++)
    {
    digitalWrite(MOTOR_IN1, LOW);
    analogWrite(MOTOR_IN2, 200);
    
    delay(40);
    
    digitalWrite(MOTOR_IN2, LOW);
    analogWrite(MOTOR_IN1, 200);

    delay(40);
    } 
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  Serial.println(rndVal);
  delay(rndVal);
  Serial.println("done");
  count = 0;
} 
