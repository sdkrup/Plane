
#include <Servo.h> 

Servo myservoThrottle; 
Servo myservoRoll;
Servo myservoPitch;
Servo myservoYaw;
int incomingByte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservoThrottle.attach(4);
  myservoRoll.attach(16);
  myservoPitch.attach(5);
  myservoYaw.attach(2);
   for(int pos = 30; pos <= 150; pos++){
    // tell servo to go to position in variable 'pos' 
      delay(30);  
      
    myservoRoll.write(pos);  
    myservoPitch.write(pos);  
    myservoYaw.write(pos);  
   }
  //Serial.begin(115200);
}
int state = 0; // equals 0 to 4 
int throttle = 100;
int roll = 0;
int pitch = 0;
int yaw = 0;
void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available() > 0) {
        // read the incoming byte:
        incomingByte = Serial.read();
        if (incomingByte == 255){
          // If the state should not be 0
          if (state != 0){
            Serial.print("ERROR: Receved 255 when expecting data byte ");
            Serial.println(state);
            state = 0;
          } else { //If the state expects zero we push the parameters to the airplane
            // push Trottle here also
            myservoThrottle.write(throttle);
            myservoRoll.write(roll);
            myservoPitch.write(pitch);
            myservoYaw.write(yaw);
          }
        } else if (state == 1){
          throttle = incomingByte;
        } else if (state == 2){
          roll = incomingByte;
        } else if (state == 3){
          pitch = incomingByte;
        } else if (state == 4){
          yaw = incomingByte;
        } else if (state == 0){
          Serial.println("Error: Expected 255 and got something else"); 
        }
        state = (state + 1)%5;
        if(state == 0){
          Serial.println(incomingByte);
          Serial.print("T: ");
          Serial.print(throttle);
          Serial.print("R: ");
          Serial.print(roll);
          Serial.print("P: ");
          Serial.print(pitch);
          Serial.print("Y: ");
          Serial.println(yaw);
        }     
        
    }
}
