int buz = 6; // buzzer pin
int voltage = 0; // battery voltage
int GL = 10; // green LED
int YL = 9; // yellow LED
int RL = 8; // red LED
int mid = 0; // etra integer to caluclate voltage
int incvoltage = 0; // etra integer to caluclate voltage "inc" stands for incoming. member that the incoming voltage has been divide by 4.
void setup()
{
  Serial.begin(9600);
  pinMode(buz, OUTPUT);
  pinMode(GL, OUTPUT);
  pinMode(YL, OUTPUT);
  pinMode(RL, OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  mid = analogRead(A0);
  incvoltage = mid / 206.4;
  voltage = incvoltage * 4;
  Serial.print(voltage);
  
  
  
  if ( voltage >= 8)
  {
    digitalWrite(YL, LOW);
    digitalWrite(RL, LOW);
    digitalWrite(GL, HIGH);
  }
  else if (voltage >= 6)
  {
    digitalWrite(GL, LOW);
    digitalWrite(RL, LOW);
    digitalWrite(YL, HIGH);
  }
  else if (voltage < 6)
  {
    digitalWrite(GL, LOW);
    digitalWrite(YL, LOW);
    digitalWrite(RL, HIGH);
    delay(4000);
    digitalWrite(RL, LOW);
    if (voltage < 6)
    {
      loop();
      {
        digitalWrite(RL, HIGH);
        for (int i = 0; i < 500; i++)
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
}


  
