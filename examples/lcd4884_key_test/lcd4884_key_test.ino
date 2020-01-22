//
//Program: Sainsmart_LCD_Button_Readings
//
//Author: Markus Buehler
//
//Requires: -Sainsmart LCD Keypad Shield
//          -Arduino 
//
/*
  This example shows the use of the LiquidCrystalK library
*/

#include <Arduino.h>
#include <LCD4884K.h>

//Define your lcd pins
LCD4884K lcd;

void setup()
{
 // pinMode(10, OUTPUT);    // LiquidCrystal light. Unfortunately this pin maybe used by other shields as well
 Serial.begin(115200);
}
 
void loop()
{
  char *keystr="";
  char str[14];
  LCD4884K::key_type k;
  k=lcd.get_key();
 
  switch(k){
  case lcd.none  : keystr=" none";   break;
  case lcd.up    : keystr=" up";     break;
  case lcd.down  : keystr=" down";   break;
  case lcd.left  : keystr=" left";   break;
  case lcd.right : keystr=" right";  break;
  case lcd.select: keystr=" select"; break;
  default: keystr=" unknown"; break;
  }

  //Display the readings on the keypad
  sprintf(str,"Key: %d %s",(int)k,keystr);
  lcd.LCD_write_string(0,0,str, MENU_NORMAL);
  Serial.print("Key:");
  Serial.print(k);
  Serial.println(keystr);

    if(k == lcd.select){
      lcd.backlight(OFF); // turn off light
    }else{
      lcd.backlight(ON); // light on
    }
 
  //To help things work nice and pretty-like =)
  delay(1000);
  lcd.LCD_clear();
}
 
