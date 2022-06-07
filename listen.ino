String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
#define Led1 7
#define Led2 8
#define Led3 9
#define Led4 10

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.print(" ");
    Serial.print(inputString);
    // clear the string:
    if(inputString.startsWith("ligar led azul")){
      digitalWrite(Led1, HIGH);
    }else if(inputString.startsWith("desligar led azul")){
      digitalWrite(Led1, LOW);
    }
    if(inputString.startsWith("ligar led amarelo")){
      digitalWrite(Led2, HIGH);
    }else if(inputString.startsWith("desligar led amarelo")){
      digitalWrite(Led2, LOW);
    }
    if(inputString.startsWith("ligar led branco")){
      digitalWrite(Led3, HIGH);
    }else if(inputString.startsWith("desligar led branco")){
      digitalWrite(Led3, LOW);
    }
    if(inputString.startsWith("ligar led rgb")){
      digitalWrite(Led4, HIGH);
    }else if(inputString.startsWith("desligar led rgb")){
      digitalWrite(Led4, LOW);
    }
    if(inputString.startsWith("ligar todos os leds")){
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, HIGH);
      digitalWrite(Led4, HIGH);
      
    }else if(inputString.startsWith("desligar todos os leds")){
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, LOW);
      digitalWrite(Led4, LOW);
      
    }
    /*
    if(inputString.startsWith("ligar led 2")){
      digitalWrite(Led2, HIGH);// toggle
    }else if(inputString.startsWith("desligar led 2")){
      digitalWrite(Led2, LOW);
      
    }*/
    
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
