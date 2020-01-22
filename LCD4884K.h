#ifndef LCD4884K_H
#define LCD4884K_H

#include <LCD4884.h>

class LCD4884K : public LCD4884{
 public:

  LCD4884K();

  enum key_type { none, up, down, left, right, select };
  key_type get_key();

 private:
  // these are the expects. 
  // my measurements
  const static int LEFT  =   0;
  const static int SELECT= 142;
  const static int DOWN  = 330;
  const static int RIGHT = 508;
  const static int UP    = 742;
  const static int NONE  =1024;

  const static int LIMIT_LEFT   = (SELECT+LEFT)/2; // less than is left
  const static int LIMIT_SELECT = (DOWN+SELECT)/2; // less than is select
  const static int LIMIT_DOWN   = (RIGHT+DOWN)/2;    // less than is down
  const static int LIMIT_RIGHT  = (UP+RIGHT)/2;     // less than is right
  const static int LIMIT_UP     = (NONE+UP)/2;      // less than is up, anything else is none
  initK(); 
};
#endif
