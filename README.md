# LCD4884K
Extends LCD4884 by a get_key function  

The LCD4884 uses the analog pin A0 to indicate pressed keys.  
I used the values from my LCD to determine the values for the different keys. (RIGHT, UP, ...). 
I centered the limits in the middle between two values. It should be robust enough for most modules.  
If not, just adjust the values with your measurements.  

Remark: in the LCD4884 library I removed the auto instatiation of lcd.

