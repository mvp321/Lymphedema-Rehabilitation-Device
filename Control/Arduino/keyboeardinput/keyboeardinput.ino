#include <AX12A.h>

#define DirectionPin  (10u)
#define BaudRate    (1000000ul)
#define ID1    (2u)
#define ID2    (1u)

char input;
 
void setup() {
 ax12a.begin(BaudRate, DirectionPin, &Serial);
 ax12a.setEndless(ID1, ON);
 ax12a.setEndless(ID2, ON);
 
 Serial.begin(9600); 
 delay(2000);  
 
 Serial.println("Type something!");
}
 
void loop() {
    if(Serial.available()){      
        input = Serial.read();
        if(input!='\n')
        {
          Serial.print("You typed: " );
          Serial.println(input);

            if (input=='u'){
              Serial.println("Device is moving up");
              ax12a.turn(ID1, LEFT, 200);
              ax12a.turn(ID2, LEFT, 200);
              delay(1000);
            }else if (input=='d'){
              Serial.println("Device is moving down");
              ax12a.turn(ID1, RIGHT, 200);
              ax12a.turn(ID2, RIGHT, 200);
              delay(1000);
            }else {
              Serial.println("Motor is not running");
              ax12a.ledStatus(ID1, ON);
              ax12a.ledStatus(ID2, ON);
              ax12a.turn(ID1, RIGHT, 0);
              ax12a.turn(ID2, RIGHT, 0);
              delay(1000000);
            }
          }
          
    }
}
