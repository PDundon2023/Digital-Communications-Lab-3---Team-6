String inputStr, keyStr, outputStr;
int input, output, keyword, inputLength, keyLength;

void loadData() {
  while (Serial.available() == 0) {}
  inputStr = Serial.readString();
  Serial.println(inputStr);
  Serial.print("Insert Key:");
  while (Serial.available() == 0) {}
  keyStr = Serial.readString();
  Serial.println(keyStr);

}

void inputCheck() {
  inputLength = inputStr.length();
  int i = 0;
  while (i < inputLength) {
    if (inputStr[i] > 95 && inputStr[i] < 123) {
      inputStr[i] -= 32;
    }
    i++;
  }
}

void keyCheck() {
  inputLength = inputStr.length();
  keyLength = keyStr.length();
  int i = 0;
  while (i < keyLength) {
    if (keyStr[i] > 95 && keyStr[i] < 123) {
      keyStr[i] -= 32;
    }
    else if (!isAlpha(keyStr[i])) {
      Serial.println("! ! ! Keyword can contain only alphabet characters ! ! !\n");
      break;
    }
    i++;
  }
  while (keyLength < inputLength) { //make the key as long as the input phrase
    keyStr = keyStr + keyStr;
    keyLength = keyStr.length();
  }
  Serial.print("Cipher: ");
}

void encodeStr() {
  int i = 0, j = 0;
  while (i < inputLength) {
    if (isWhitespace(inputStr[i])) {
      i++;
    }
    else if (!isAlpha(inputStr[i])) {
      Serial.write(inputStr[i]);
      i++;
    }
    else {
      input = inputStr[i];
      keyword = keyStr[j];
      output = (((input - 65) + (keyword - 65)));
      if (output > 25) {
        output = output + 39;
      }
      else {
        output = output + 65;
      }
      Serial.write(output);
      i++;
      j++;
    }
  }
}

void decodeStr() {
  int i = 0, j = 0;
  while (i < inputLength) {
    if (isWhitespace(inputStr[i])) {
      i++;
    }
    else if (!isAlpha(inputStr[i])) {
      Serial.write(inputStr[i]);
      i++;
    }
    else {
      input = inputStr[i];
      keyword = keyStr[j];
      output = (((input - 65) - (keyword - 65)));
      if (output < 0) {
        output = output + 91;
      }
      else {
        output = output + 65;
      }
      Serial.write(output);
      i++;
      j++;
    }
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {

  Serial.println("\n\nWhat would you like to do: \n 1. Encode \n 2. Decode");
  while (Serial.available() == 0) {}
  int choice = Serial.read();

  switch (choice) {

    case 49:
      Serial.print("Insert phrase for encoding:");
      loadData();
      inputCheck();
      keyCheck();
      encodeStr();
      break;
    case 50:
      Serial.print("Insert phrase for decoding:");
      loadData();
      inputCheck();
      keyCheck();
      decodeStr();
      break;
    default:
      Serial.println("Wrong selection.");
  }
}


