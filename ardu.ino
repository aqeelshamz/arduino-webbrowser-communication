#define xecho 2
#define xtrig 3
#define yecho 4
#define ytrig 5
#define ledPin 8

long durationx, durationy;
int distancex, distancey;

void setup() {
  pinMode(xtrig, OUTPUT);
  pinMode(xecho, INPUT);
  pinMode(ytrig, OUTPUT);
  pinMode(yecho, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //X
  digitalWrite(xtrig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(xtrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(xtrig, LOW);
  
  durationx = pulseIn(xecho, HIGH);
  distancex = durationx * 0.034 / 2; 
  
  //Y
  digitalWrite(ytrig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(ytrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ytrig, LOW);
  
  durationy = pulseIn(yecho, HIGH);
  distancey = durationy * 0.034 / 2; 
  delay(1000);
  Serial.print(distancex);
}