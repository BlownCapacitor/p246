const int led = 21;
const int channel = 0;
const int pot = 34;
const int frequency = 500;
const int resolution = 8; 
const int dutyCycleM = (int)(pow(2, resolution) - 1);

void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);

 
  ledcSetup(channel, frequency, resolution);
  ledcAttachPin(led, channel);
}

void loop() {
  int potVal = analogRead(pot);
  int dutyCycle = map(potVal, 0, 4095, 0, dutyCycleM);
  ledcWrite(channel, dutyCycle);

  Serial.println((String)potVal + ", " + dutyCycle);
  
  delay(1000);
}
