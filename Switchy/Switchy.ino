// http://arduino.cc/en/Tutorial/ButtonStateChange

int pin;

int switchPin;

int safety;

int type = 1;

boolean test;


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
  test = true;
  
  safety = 13;
  
  pin = 8;
  
  switchPin = 3;
  
  pinMode(safety, OUTPUT);
  pinMode(pin, OUTPUT);
  
  pinMode(switchPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  switch(type)
  {
     case 0:
    {
      expo0();
      
      break;
    }
   
   case 1:
   {
     expo1();
     
     break; 
   }
  }

}

void expo0()
{
  if(test)
  {
    digitalWrite(safety, HIGH);
  }
  
  digitalWrite(pin, HIGH);
  
  delay(250);
  
  if(test)
  {
    digitalWrite(safety, LOW);
  }
  
  digitalWrite(pin, LOW);
  
  trackPin();
  
  delay(250);  
}

void expo1()
{
  digitalWrite(pin, HIGH);
  
  trackPin();
}

void trackPin()
{
  // int readOut = digitalRead(pin);
 
  int readOut = digitalRead(switchPin);
  
  if(readOut == 1)
  {
    digitalWrite(safety, HIGH);
    
    delay(100);
    
    digitalWrite(safety, LOW);
    
    delay(100);
  }
  
  else
  {
    digitalWrite(safety, LOW);
  }
 
  Serial.println(readOut); 
}
