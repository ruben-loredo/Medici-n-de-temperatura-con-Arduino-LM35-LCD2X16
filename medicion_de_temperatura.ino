/* Programa: Medición de temperatura con Arduino+LM35+LCD2X16 
ver video e información en youtube: https://www.youtube.com/watch?v=c6Omj78oojo&feature=gp-n-y&google_comment_id=z12jynujmxejfx1sk23hcnsxozracv00g
suscribete a mi canal: https://www.youtube.com/user/rubyck71
Profesor: Rubén Loredo Amaro, Universidad Tecnológica de Altamira*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);


float centi()
{
  int dato;
  float c;
  dato=analogRead(A0);
  c = (500.0 * dato)/1023;
  return(c);
}

float kelvin(float cent)
{
  float k;
  k=cent+273.15;
  return(k);
}

float fahren(float cent)
{
  float f;
  f = cent*1.8 + 32;
  return f;
}

float rankin(float cent)
{
  float r;
  r=(cent+273.15)*1.8;
  return r;
}
void setup()
{
  lcd.begin(16,2);
  lcd.print("C=      F=");
  lcd.setCursor(0,1);
  lcd.print("K=      R=");
}

void loop()
{
  float Centigrados = centi();
  float Farenheit = fahren(Centigrados);
  float Kelvin = kelvin(Centigrados);
  float Rankin = rankin(Centigrados);

  lcd.setCursor(2,0);
  lcd.print(Centigrados);

  lcd.setCursor(10,0);
  lcd.print(Farenheit);

  lcd.setCursor(2,1);
  lcd.print(Kelvin);

  lcd.setCursor(10,1);
  lcd.print(Rankin);

  delay(200);

}


