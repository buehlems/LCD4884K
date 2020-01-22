#include <Arduino.h>
#include <LCD4884K.h>

/****f* 
  *  NAME
  *    LCD4884K -- 
  *  SYNOPSIS
  *   LCD4884K(...)
  *  FUNCTION
  *    all functions just call the parent constructor and set pin A0 to input
  *  INPUTS
  *    ---
  *  RESULT
  *    ---
   ******
*/

LCD4884K::LCD4884K() :LCD4884()
{
  initK();
  LCD_init();
  LCD_clear();
}
/****f* 
  *  NAME
  *    initK -- 
  *  SYNOPSIS
  *   initK();
  *  FUNCTION
  *    set pin A0 to input
  *  INPUTS
  *    ---
  *  RESULT
  *    ---
   ******
*/

LCD4884K::initK(){
  pinMode(A0, INPUT);     //pin 'A0' is your keypad's input.
  LCD_init();
  LCD_clear();
}

LCD4884K::key_type LCD4884K::get_key(){
  int kin = analogRead(A0);
  byte k;
  if(kin<=LIMIT_LEFT)
    k=left;
  else if (kin <= LIMIT_SELECT)
    k=select;
  else if (kin <= LIMIT_DOWN)
    k=down;
  else if (kin <= LIMIT_RIGHT)
    k=right;
  else if (kin <= LIMIT_UP)
    k=up;
  else 
    k=none;

  return(k);
}
