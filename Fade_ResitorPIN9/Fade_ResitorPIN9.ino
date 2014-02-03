int ledPin = 9;
int brightness = 0;
int fadeAmount = 1;

boolean hack = true;

int testHack = 13; // board led
boolean hackInd = false;

// var boolean
boolean fade_U = false;
boolean fade_D = false;

char testString = 'all ok'; // dont use ""

void setup() 
{
  // put your setup code here, to run once:
  
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  analogWrite(ledPin, brightness);

  if(hack)
  {
    extra();
    
    delay(20);
  }
  
  else
  {
    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;
    
    // reverse the direction of the fading at the ends of the fade:
    if(brightness == 0 || brightness == 255)
    {
      fadeAmount = -fadeAmount;
    }
   
     delay(20); 
  }
  
  trackLED();  
}

void  extra()
{
  if(!hackInd)
  { 
    hackInd = true;
    digitalWrite(testHack, HIGH);
  }
  
  if(brightness < 255 && fade_U)
  {
     brightness = brightness + fadeAmount; 
  }
  
  else
  {
    fade_U = false;
    fade_D = true; 
  }
  
  if(brightness > 0 && fade_D)
  {
    brightness = brightness - fadeAmount;  
  }
  
  else
  {
    fade_U = true;
    fade_D = false ;
  }
}

void  trackLED()
{
  int pinValue = digitalRead(ledPin);
  Serial.println(pinValue);  
  Serial.println(testString); 
}
