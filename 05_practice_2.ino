#define PIN_LED 7
unsigned int toggle;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(230400);
  while (!Serial) {
    ;
  }
  Serial.println("Hello World!");
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  delay(1000);
  if (toggle != 1) {
    digitalWrite(PIN_LED, 1);
    delay(1000);

    for (i=0; i < 5; ++i) {
    Serial.println(i);
    digitalWrite(PIN_LED, 0);
    delay(100);
    digitalWrite(PIN_LED, 1);
    delay(100);
    
  }
  
  }
  
  toggle = 1;
  
}
