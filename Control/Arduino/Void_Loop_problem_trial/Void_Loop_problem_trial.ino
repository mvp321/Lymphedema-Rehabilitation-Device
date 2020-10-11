#include <AX12A.h>

#define DirectionPin  (10u)
#define BaudRate    (1000000ul)
#define ID    (2u)

void setup(){
 ax12a.begin(BaudRate, DirectionPin, &Serial);
 ax12a.setEndless(ID, ON);
 
}

void loop(){
  print("Hello");
}
