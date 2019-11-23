int a = 500;
int buz = 6; // buzzer pin
int greenLight = 0; // battery is good; 0 is no, 1 is yes
int redLight = 0; // battery is dead; 0 is no, 1 is yes
int yellowLight = 0; // batery warning; 0 is no, 1 is yes
const int voltage = 0; // battery voltage
int GL = 10; // green LED
int YL = 9; // yellow LED
int RL = 8; // red LED
int i = 0;
void setup() 
{
pinMode(buz,OUTPUT);
pinMode(GL,OUTPUT);
pinMode(YL,OUTPUT);
pinMode(RL,OUTPUT);
}

void loop()
{
  if( voltage <= 8);
  {
    int redLight = 0;
    int yellowLight = 0;
    int greenLight = 1;
  }
  if(voltage <=6);
  {
    int redLight = 0;
    int greenLight = 0;
    int yellowLight = 1;
  }
  if(voltage >6);
  {
    int greenLight = 0;
    int yellowLight = 0;
    int redLight = 1;
  }
  

  if(greenLight = 1);
  {
    digitalWrite(YL, LOW);
    digitalWrite(RL, LOW);
    digitalWrite(GL, HIGH);
  }
  if (yellowLight = 1);
  {
    digitalWrite(GL, LOW);
    digitalWrite(RL, LOW);
    digitalWrite(YL, HIGH);
  }
  if(redLight = 1);
  {
    digitalWrite(GL, LOW);
    digitalWrite(YL, LOW);
    digitalWrite(RL, HIGH);
  
    loop();
    {
        digitalWrite(RL, HIGH);
        for(i = 0; i < a; i++)
        {
          digitalWrite(buz, HIGH);
          delay(1);
          digitalWrite(buz, LOW);
          delay(1);
        }
        digitalWrite(RL, LOW);
        delay(1000);
      }
    }
  
}
