#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

#define in A0
#define out A5
#define temperature A1 
#define ledr 12  
#define ledg 7  
#define ledy 4  
#define relay 2
int count=0;

void IN()
{
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(3000);
}

void OUT()
{
  count--;
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(3000);
}
void TEMP()
{
  float reading=analogRead(temperature);
  float temperature=reading*(5.0/1023.0)*100;
  delay(10);
 
  if(temperature>=0&&temperature<50)
  {
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("WAIT!Check Temp");
    lcd.setCursor(4,1);
    lcd.print(temperature);
    lcd.write(1);
    lcd.print("C");
    delay(1000);
    digitalWrite(ledy, HIGH);   
    delay(500);
    digitalWrite(ledy, LOW);   
    delay(500);
    digitalWrite(ledg, LOW);    
    delay(500);
    digitalWrite(ledr, LOW);    
    delay(500); 
  }
  else if(temperature>=50&&temperature<70)
  {
     lcd.clear();
     lcd.setCursor(2,0);
     lcd.print("WELCOME!!");
     lcd.setCursor(4,1);
     lcd.print(temperature);
     lcd.write(1);
     lcd.print("C");
     delay(1000);
     digitalWrite(ledg, HIGH);   
     delay(500);
     digitalWrite(ledg, LOW);   
     delay(500);
     digitalWrite(ledy, LOW);    
     delay(500);
     digitalWrite(ledr, LOW);    
     delay(500); 
  }
  else
  {
     lcd.clear();
     lcd.setCursor(2,0);
     lcd.print("Temperature");
     lcd.setCursor(4,1);
     lcd.print(temperature);
     lcd.write(1);
     lcd.print("C");
     delay(1000);
     digitalWrite(ledr, HIGH);   
     delay(500);
     digitalWrite(ledr, LOW);   
     delay(500);
     digitalWrite(ledy, LOW);    
     delay(500);
     digitalWrite(ledg, LOW);    
     delay(500); 
     
  }
}

void setup()
{
  lcd.begin(16,2);
  lcd.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(temperature, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledy, OUTPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0,1);
  lcd.print(count);
}

void loop()
{ 
  if(digitalRead(in))
  {
    IN(); 
  }
  if(digitalRead(out))
  {
     OUT(); 
  }

   if(count<=0)
  {
    lcd.clear();
    digitalWrite(relay, HIGH);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Light Is Off");
    delay(500);
  }
  else
  {
   digitalWrite(relay, LOW); 
   TEMP(); 
  }
}