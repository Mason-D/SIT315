long previousTime = 0;
long interval = 500; //Delay between printing to serial monitor to reduce spam

void setup()
{
  Serial.begin(9600);
  
  //Output pins for RGB LED
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  //Input pins for RGB potentiometers
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop()
{
  delay(20);
  
  //Read potentiometers
  int red = analogRead(A0) / 4;
  int green = analogRead(A1) / 4;
  int blue = analogRead(A2) / 4;
  
  //Write to LED RGB
  analogWrite(11, red);
  analogWrite(9, green);
  analogWrite(10, blue);
  
  //Print to serial monitor RGB value every 500ms
  if(millis() - previousTime >= interval) {
    previousTime = millis();
  	Serial.println("RGB: " + String(red) + ", " + String(green) + ", " + String(blue));
  }
}