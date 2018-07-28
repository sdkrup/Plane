const int xPin = 0;
const int yPin = 1;
const int swPin = 2;
float x = 0;
float y = 0;
boolean sw = false;

float xMid = 5;
float yMid = 5;
float xMax = 10;
float yMax = 10;
float xMin = 0;
float yMin = 0;

void setup() {

  Serial.begin(9600);
  
  xMid = analogRead(xPin);
  yMid = analogRead(yPin);

  while (millis() < 5000) {
    x = analogRead(xPin);
    y = analogRead(yPin);

    xMax = (x > xMax) ? x : xMax;
    xMin = (x < xMin) ? x : xMin;        
    yMax = (y > yMax) ? y : yMax;
    yMin = (y < yMin) ? y : yMin;
  }
}

void loop() {
  x = toPercent(analogRead(xPin),xMax);
  y = toPercent(analogRead(yPin),yMax);
  sw = analogRead(swPin);

  log();
}

float toPercent(float var, float mmax) {
  
  return (var /mmax ) * 100;
  
}

void log() {
  Serial.print (" xMax: ");
  Serial.print(xMax);
  Serial.print(" yMax: " );
  Serial.print( yMax) ;
  Serial.print (" xMin: ");
  Serial.print(xMin);
  Serial.print(" yMin: " );
  Serial.print( yMin) ;
  Serial.print (" xMid: ");
  Serial.print(xMid);
  Serial.print(" yMid: " );
  Serial.print( yMid) ;
  
  
  Serial.print (" x: ");
  Serial.print(x);
  Serial.print(" y: " );
  Serial.print( y) ;
  Serial.print(" sw: " );
  Serial.print(sw);
  Serial.println();
}


