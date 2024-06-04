#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>

const int ledpin1 = 8; 
const int ledpin2 = 12; 
const int ledpin3 = 3; 
const int ledpin4 = 4; 

void setup() {
    pinMode(ledpin1, OUTPUT);
    pinMode(ledpin2, OUTPUT);
     pinMode(ledpin3, OUTPUT);
    pinMode(ledpin4, OUTPUT);
    
    Serial.begin(115200);
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
    if (IrReceiver.decode()) {
        if (IrReceiver.decodedIRData.protocol != UNKNOWN) {
          Serial.println(IrReceiver.decodedIRData.command);
            switch(IrReceiver.decodedIRData.command) {

                case 12://1
                   digitalWrite(ledpin2, LOW);
                   digitalWrite(ledpin3, LOW);
                   digitalWrite(ledpin4, LOW);
                   digitalWrite(ledpin1, HIGH);
                    delay(1000); 
                    
                    break;
                case 24://2
                digitalWrite(ledpin1, LOW);
                   digitalWrite(ledpin3, LOW);
                   digitalWrite(ledpin4, LOW);
                   digitalWrite(ledpin2, HIGH);
                    delay(1000); 
                   break;
                case 94://3
               digitalWrite(ledpin2, LOW);
                   digitalWrite(ledpin4, LOW);
                   digitalWrite(ledpin1, LOW);
                   digitalWrite(ledpin3, HIGH); 
                    delay(1000); 
                   break;
                case 8://4
               digitalWrite(ledpin2, LOW);
                   digitalWrite(ledpin3, LOW);
                   digitalWrite(ledpin1, LOW);
                   digitalWrite(ledpin4, HIGH); 
                    delay(1000); 
                   break;
                     case 28://5
               digitalWrite(ledpin2, HIGH);
                   digitalWrite(ledpin3, HIGH);
                   digitalWrite(ledpin1, HIGH);
                   digitalWrite(ledpin4, HIGH); 
                    delay(1000); 
                   break;
                     case 90://6
               digitalWrite(ledpin2, LOW);
                   digitalWrite(ledpin3, LOW);
                   digitalWrite(ledpin1, LOW);
                   digitalWrite(ledpin4, LOW); 
                    delay(1000); 
                   break;
                       case 66://7
               
                   digitalWrite(ledpin3, LOW);
                   digitalWrite(ledpin1, HIGH);
                    delay(200);
                    digitalWrite(ledpin1, LOW);
                    digitalWrite(ledpin3, LOW);
                   digitalWrite(ledpin2, LOW);
                   digitalWrite(ledpin4, LOW);
                  digitalWrite(ledpin2, HIGH);
                    delay(200);
                    digitalWrite(ledpin2, LOW);
                    digitalWrite(ledpin3, HIGH);
                    delay(200);
                     digitalWrite(ledpin3, LOW);
                     digitalWrite(ledpin4, HIGH);
                    delay(200); 
                   break;
                default:
                   break;
            }
        }
        IrReceiver.resume();
      } 
}
