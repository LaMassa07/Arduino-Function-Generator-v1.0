/*
GENERATORE BINARIO 8 BIT
Maso Samuele
5DIT
29/11/2025
*/


/*select your MAX_VALUE and DELAY (microseconds)*/
#define maxValue 255
#define d 1
#define pi 3.141593
#define T 256


void setup() {
  for(int i = 0; i < 8; i++){
    pinMode(i+2, OUTPUT);
  }
  Serial.begin(9600);

  Serial.println("OPZIONI: ");
  Serial.println("T = triangolare");
  Serial.println("S = sinusoidale");
  Serial.println("C = cosinusoidale");
  Serial.println("Q = quadra");
  Serial.println("D = dente di sega");
  Serial.print("---> ");

  while (true) {
    if(Serial.available() > 0){
      char c = Serial.read();

      if(c == 'S'){
        Serial.println("GENERATORE IMPOSTATO COME: onda sinusoidale");
        while(1){
          ondaSinusoidale();
        }
      }else if(c == 'T'){
        Serial.println("GENERATORE IMPOSTATO COME: onda triangolare");
        while(1){
          ondaTriangolare();
        }
      }else if(c == 'C'){
        Serial.println("GENERATORE IMPOSTATO COME: onda cosinusoidale");
        while(1){
          ondaCosinusoidale();
        }
      }else if(c == 'Q'){
        Serial.println("GENERATORE IMPOSTATO COME: onda quadra");
        while(1){
          ondaQuadra();
        }
      }else if(c == 'D'){
        Serial.println("GENERATORE IMPOSTATO COME: onda dente di sega");
        while(1){
          ondaSega();
        }
      }else{
        Serial.print("Carattere non valido: ");
        Serial.println(c);
      }
    }
  }
}

void loop() {}



void ondaTriangolare(){
  //UP
  for(int n = 0; n < maxValue; n++){
    char bin[8];

    for(int i = 7; i >= 0; i--){
      bin[7 - i] = (n & (1 << i)) ? '1' : '0';
    }

    for(int i = 0; i < 8; i++){
      if(bin[i] == '0'){
        digitalWrite(i+2, LOW);
      }else{
        digitalWrite(i+2, HIGH);
      }
    }
    Serial.println(n); //
    delayMicroseconds(d);
  }

  //DOWN
  for(int n = maxValue; n > 0; n--){
    char bin[8];

    for(int i = 7; i >= 0; i--){
      bin[7 - i] = (n & (1 << i)) ? '1' : '0';
    }

    for(int i = 0; i < 8; i++){
      if(bin[i] == '0'){
        digitalWrite(i+2, LOW);
      }else{
        digitalWrite(i+2, HIGH);
      }
    }
    Serial.println(n); //
    delayMicroseconds(d);
  }
}



void ondaCosinusoidale() {
  for (int n = 0; n < T; n++) {
    float angle = ( (float)n / maxValue ) * (2.0 * PI);
    float s = (cos(angle) + 1.0) / 2.0;
    int value = (int)round(s * maxValue);

    char bin[8];

    for(int i = 7; i >= 0; i--){
      bin[7 - i] = (value & (1 << i)) ? '1' : '0';
    }

    for(int i = 0; i < 8; i++){
      if(bin[i] == '0'){
        digitalWrite(i+2, LOW);
      }else{
        digitalWrite(i+2, HIGH);
      }
    }
    Serial.println(value); //
    delayMicroseconds(d);
  }
}

void ondaSinusoidale() {
  for (int n = 0; n < T; n++) {
    float angle = ( (float)n / maxValue ) * (2.0 * PI);
    float s = (sin(angle) + 1.0) / 2.0;
    int value = (int)round(s * maxValue);

    char bin[8];

    for(int i = 7; i >= 0; i--){
      bin[7 - i] = (value & (1 << i)) ? '1' : '0';
    }

    for(int i = 0; i < 8; i++){
      if(bin[i] == '0'){
        digitalWrite(i+2, LOW);
      }else{
        digitalWrite(i+2, HIGH);
      }
    }
    Serial.println(value); //
    delayMicroseconds(d);
  }
}



void ondaQuadra(){
  int n = 255;
  char bin[8];

  for(int i = 7; i >= 0; i--){
    bin[7 - i] = (n & (1 << i)) ? '1' : '0';
  }
  for(int i = 0; i < 8; i++){
    if(bin[i] == '0'){
      digitalWrite(i+2, LOW);
    }else{
      digitalWrite(i+2, HIGH);
    }
  }
  Serial.println(n); //
  delayMicroseconds(2550*d);

  n = 0;
  
  for(int i = 7; i >= 0; i--){
    bin[7 - i] = (n & (1 << i)) ? '1' : '0';
  }
  for(int i = 0; i < 8; i++){
    if(bin[i] == '0'){
      digitalWrite(i+2, LOW);
    }else{
      digitalWrite(i+2, HIGH);
    }
  }
  Serial.println(n); //
  delayMicroseconds(2550*d);
}



void ondaSega(){
  for(int n = 0; n < maxValue; n++){
    char bin[8];

    for(int i = 7; i >= 0; i--){
      bin[7 - i] = (n & (1 << i)) ? '1' : '0';
    }

    for(int i = 0; i < 8; i++){
      if(bin[i] == '0'){
        digitalWrite(i+2, LOW);
      }else{
        digitalWrite(i+2, HIGH);
      }
    }
    Serial.println(n); //
    delayMicroseconds(d);
  }
}