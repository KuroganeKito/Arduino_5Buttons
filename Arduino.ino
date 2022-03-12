String result="";

int inputPin[5] = {3, 4, 5, 6, 7};
int checkDelay[5] = {0, 0 ,0 ,0 ,0};

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);

  for(int index = 0; index < 5; index++)
    pinMode(inputPin[index], INPUT);
}

void loop() {
  if(!Serial.available()){
    delay(1);

    for(int pinIndex = 0; pinIndex < 5; pinIndex++){
      if(digitalRead(inputPin[pinIndex]) == LOW) {
        checkDelay[pinIndex] = 0;
      } else {
        checkDelay[pinIndex] += 1;
      }
    }

    if(result == "") {
      for(int pinIndex = 0; pinIndex < 5; pinIndex++) {
        if(checkDelay[pinIndex] >= 20) {
          result += String(pinIndex + 1) + "-";
        } else {
          result += " -";
        }
      }
    }    
  } else {
    Serial.readString();
    Serial.print(result);
    result = "";
  }
}