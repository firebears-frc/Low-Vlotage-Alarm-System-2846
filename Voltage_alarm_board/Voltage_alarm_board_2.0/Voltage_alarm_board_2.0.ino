int buz = 6; // Buzzer pin
float voltage = 0; // Battery voltage
int GL = 10; // Green LED
int YL = 9; // Yellow LED
int RL = 8; // Red LED
float mid = 0; // Extra integer to caluclate voltage
float incvoltage = 0; // Extra integer to caluclate voltage "inc" stands for incoming. Remember that the incoming voltage has been divided by 4.
# include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
  pinMode(buz, OUTPUT);
  pinMode(GL, OUTPUT);
  pinMode(YL, OUTPUT);
  pinMode(RL, OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  lcd.clear();
  mid = analogRead(A0);
  incvoltage = mid / 206.4;
  voltage = incvoltage * 4;
  Serial.print(voltage);
  lcd.setCursor(0, 1);
  lcd.print(" STATUS:");
  lcd.setCursor(0, 0);
  lcd.print("VOLTAGE:       V");
  if(voltage >= 10)
  {
    lcd.setCursor(9, 0);
    lcd.print(voltage);
  }
  else if(voltage < 10)
  {
    lcd.setCursor(10, 0);
    lcd.print(voltage);
  }
  
  if ( voltage >= 8)
  {
    digitalWrite(YL, LOW);
    digitalWrite(RL, LOW);
    digitalWrite(GL, HIGH);
    lcd.setCursor(12, 1);
    lcd.print("GOOD");
    delay(6);
  }
  else if (voltage >= 7)
  {
    digitalWrite(GL, LOW);
    digitalWrite(RL, LOW);
    digitalWrite(YL, HIGH);
    lcd.setCursor(9, 1);
    lcd.print("WARNING");
    delay(6);
  }
  else if (voltage < 7)
  {
    digitalWrite(GL, LOW);
    digitalWrite(YL, LOW);
    digitalWrite(RL, HIGH);
    delay(4000);
    if (voltage >= 7)
    {
      digitalWrite(RL, LOW);
    }
    else
    {
      lcd.setCursor(9, 1);
      lcd.print("REPLACE");
      for (int i = 0; i < 100,000,000; i++)
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


  
