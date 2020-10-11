#include <AX12A.h>

#define DirectionPin  (10u)
#define BaudRate    (1000000ul)
#define ID1    (2u)
#define ID2    (1u)

void setup(){
 ax12a.begin(BaudRate, DirectionPin, &Serial);
 ax12a.setEndless(ID1, ON);
 ax12a.setEndless(ID2, ON);
}

void loop(){
    ax12a.turn(ID1, LEFT, 200);
    ax12a.turn(ID2, LEFT, 200);
    delay(8000);
  
    ax12a.turn(ID1, RIGHT, 200);
    ax12a.turn(ID2, RIGHT, 200);
    delay(5000);

//    ax12a.ledStatus(ID2, OFF);
//    ax12a.turn(ID2, LEFT, 100);
//    delay(1000);

//    ax12a.ledStatus(ID2, OFF);
//    ax12a.turn(ID2, RIGHT, 100);
//    delay(1000);

    ax12a.ledStatus(ID1, ON);
    ax12a.ledStatus(ID2, ON);
    ax12a.turn(ID1, RIGHT, 0);
    ax12a.turn(ID2, RIGHT, 0);
    delay(1000000);
}
