const int x1Pin = 0;
const int y1Pin = 1;
const int x2Pin = 2;
const int y2Pin = 3;

int x1 = 0;
int y1 = 0;
int x2 = 0;
int y2 = 0;

float x1Mid = 511;
float y1Mid = 516;
float x1Max = 1023;
float y1Max = 1023;
float x1Min = 0;
float y1Min = 0;

float x2Mid = 511;
float y2Mid = 516;
float x2Max = 1023;
float y2Max = 1023;
float x2Min = 0;
float y2Min = 0;

void setup() {

  Serial.begin(9600);
  
  x1Mid = analogRead(x1Pin);
  y1Mid = analogRead(y1Pin);

  x2Mid = analogRead(x2Pin);
  y2Mid = analogRead(y2Pin);

  while (millis() < 5000) {
    x1 = analogRead(x1Pin);
    y1 = analogRead(y1Pin);
    x2 = analogRead(x2Pin);
    y2 = analogRead(y2Pin);

    x1Max = (x1 > x1Max) ? x1 : x1Max;
    x1Min = (x1 < x1Min) ? x1 : x1Min;        
    y1Max = (y1 > y1Max) ? y1 : y1Max;
    y1Min = (y1 < y1Min) ? y1 : y1Min;

    x2Max = (x2 > x2Max) ? x2 : x2Max;
    x2Min = (x2 < x2Min) ? x2 : x2Min;        
    y2Max = (y2 > y2Max) ? y2 : y2Max;
    y2Min = (y2 < y2Min) ? y2 : y2Min;
  }
}

void loop() {
  x1 = toPercent(analogRead(x1Pin),x1Max);
  y1 = toPercent(analogRead(y1Pin),y1Max);
  x2 = toPercent(analogRead(x2Pin),x2Max);
  y2 = toPercent(analogRead(y2Pin),y2Max);
  
  //log();

  Serial.write(255);
  Serial.write(x1);
  Serial.write(y1);
  Serial.write(x2);
  Serial.write(y2);
}

int toPercent(float var, float mmax) {
  
  return (var /mmax ) * 100;
  
}

void log() {
  
  Serial.print (" x1Max: ");
  Serial.print(x1Max);
  Serial.print(" y1Max: " );
  Serial.print( y1Max) ;
  Serial.print (" x1Min: ");
  Serial.print(x1Min);
  Serial.print(" y1Min: " );
  Serial.print( y1Min) ;
  Serial.print (" x1Mid: ");
  Serial.print(x1Mid);
  Serial.print(" y1Mid: " );
  Serial.print( y1Mid) ;

  Serial.print (" x1: ");
  Serial.print(x1);
  Serial.print(" y1: " );
  Serial.print( y1) ;
    
  Serial.print (" x2Max: ");
  Serial.print(x2Max);
  Serial.print(" y2Max: " );
  Serial.print( y2Max) ;
  Serial.print (" x2Min: ");
  Serial.print(x2Min);
  Serial.print(" y2Min: " );
  Serial.print( y2Min) ;
  Serial.print (" x2Mid: ");
  Serial.print(x2Mid);
  Serial.print(" y2Mid: " );
  Serial.print( y2Mid) ;
  
  
  Serial.print (" x2: ");
  Serial.print(x2);
  Serial.print(" y2: " );
  Serial.print( y2) ;
  Serial.println();
  
}


