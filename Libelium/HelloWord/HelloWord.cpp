#include <Waspmote.h>

void setup(){
  USB.ON();
}

void loop(){
  USB.println(F("Hello Word!!!"));
 
  delay(10000);
}
