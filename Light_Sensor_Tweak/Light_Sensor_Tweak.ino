// http://arduino.cc/en/Tutorial/SwitchCase

// static setup of sensor sensitivity
const int sensorMin = 0;
const int sensorMax = 600;

// anologue pin of circuit 
int sensorReading;

int safetyPin = 13;
int allOk = false;

boolean notBright = false;

// int range;

void setup() 
{
  // put your setup code here, to run once:
  
  // setup for log / console  
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  //reads the sensor
  sensorReading = analogRead(A0);
  
  // map sensor from pin, sensor setting min, sensor setting max, range low, range high
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // call function (sending parameter range)
  doThis(range);
  
  // delay 
  delay(20); 
}

// recieves signal and sorts
void doThis(int signal)
{
    char* LIGHT;
  
  switch(signal)
 {
    case 0:
    {
        LIGHT = "dark";
      
        // Serial.println("dark");
        break;
    }
    
    case 1:
    {
        LIGHT = "dim";
        //Serial.println("dim");
        break;
    }
    
    case 2:
    {
        LIGHT = "medium";
        //Serial.println("medium");
        break;
    }
    
    case 3:
    {
        LIGHT = "bright";
        //Serial.println("bright"); 
        break; 
    }
 }
 
 if(!allOk)
 {
   allOk = true;
   showSafe(); 
 }
 
 if(allOk)
 {
   Serial.println(LIGHT);
   
   if(LIGHT != "bright" && !notBright)
   {
     notBright = true;
     
     digitalWrite(safetyPin, LOW);
   }
   
   else if(LIGHT == "bright" && notBright)
   {
     notBright = false;
     digitalWrite(safetyPin, HIGH);
   }
 }
 
}

void showSafe()
{
  pinMode(safetyPin, OUTPUT);
  digitalWrite(safetyPin, HIGH);  
}
