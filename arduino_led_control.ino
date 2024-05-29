// C++ code
//
void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int mode = 6; // Change this variable to select the mode (1 to ...)

  switch (mode) {
    case 1:
      singleColorBlink();
      break;
    case 2:
      randomizeColors();
      break;
    case 3:
      generateSecondaryColors();
      break;
    case 4:
      random16MillionColors();
      break;
    case 5:
      increaseBrightness();
      break;
    case 6:
      increaseBrightness2();
      break;
    default:
      Serial.println("Invalid mode selected.");
      break;
  }
}

void singleColorBlink() {
  Serial.println("Mode 1: Single Color Blink");

  digitalWrite(9, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(9, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  digitalWrite(10, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(10, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  digitalWrite(11, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

void randomizeColors() {
  Serial.println("Mode 2: Randomize Colors");

  int randno = random(9, 12);
  Serial.print("Random number = ");
  Serial.println(randno);
  digitalWrite(randno, HIGH);
  delay(100);
  digitalWrite(randno, LOW);
  delay(100);
}

void generateSecondaryColors() {
  Serial.println("Mode 3: Generate Secondary Colors");

  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  digitalWrite(11, HIGH);
  digitalWrite(9, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW);
  digitalWrite(9, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

void random16MillionColors() {
  Serial.println("Mode 4: Random 16 Million Colors");

  int R = random(0, 256);
  Serial.print("RED = ");
  Serial.println(R);

  int B = random(0, 256);
  Serial.print("BLUE = ");
  Serial.println(B);

  int G = random(0, 256);
  Serial.print("GREEN = ");
  Serial.println(G);

  analogWrite(9, G);
  analogWrite(10, B);
  analogWrite(11, R);

  delay(1000); // Add a delay to make the color visible for a while
}

void increaseBrightness() {
  Serial.println("Mode 5: Increase Brightness");

  // Full brightness (100%)
  colorRGB(255, 0, 0, 100);
  delay(1000);

  // Half brightness (50%)
  colorRGB(255, 0, 0, 50);
  delay(1000);

  // Quarter brightness (25%)
  colorRGB(255, 0, 0, 25);
  delay(1000);
}

void colorRGB(int red, int green, int blue, int brightness_percent) {
  const int redPin = 9;
  const int greenPin = 10;
  const int bluePin = 11;

  analogWrite(redPin, red * brightness_percent / 100);
  analogWrite(greenPin, green * brightness_percent / 100);
  analogWrite(bluePin, blue * brightness_percent / 100);
}

void increaseBrightness2(){
  //Increading Brightness for each colour
  Serial.println("Mode 6: Increase Brightness Implementation 2");
  
  for (int R=0; R<=255; R++){
    Serial.print("R = ");
    Serial.println(R);
    analogWrite(11,R);
  }
  analogWrite(11,0);
  
  for (int B=0; B<=255; B++){
    Serial.print("B = ");
    Serial.println(B);
    analogWrite(10,B);
  }
  analogWrite(10,0);
  
  for (int G=0; G<=255; G++){
    Serial.print("G = ");
    Serial.println(G);
    analogWrite(9,G);
  }
  analogWrite(9,0);
}

