String inputString = "";         // A string to hold incoming data
bool stringComplete = false;     // Whether the string is complete
int buzzerPin = 12;              // Pin for the buzzer

struct MorseCode {
    char letter;
    const char* code;
};


MorseCode morseMap[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."},
    {'D', "-.."}, {'E', "."},   {'F', "..-."},
    {'G', "--."}, {'H', "...."}, {'I', ".."},
    {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"},  {'N', "-."},  {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."}, {'T', "-"},    {'U', "..-"},
    {'V', "...-"}, {'W', ".--"},  {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}
};

const String getMorseCode(char letter) 
{
    int index = toupper(letter) - 'A'; // Convert letter to uppercase and find its index
    if (index >= 0 && index < 26) {
        return morseMap[index].code;
    }
    return " "; // Return empty string if it's not a letter
}

const String sentenceToCode(String sentence) {
    String morseCode = "";
    for (unsigned int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != ' ') {
            morseCode += getMorseCode(sentence[i]);
            morseCode += " "; // Space between Morse characters
        } else {
            morseCode += "  "; // Longer space between words
        }
    }

    Serial.print("Received: ");
    Serial.println(sentence);
    Serial.print("Morse Code: ");
    Serial.println(morseCode);
    return morseCode;
}

void beepDot()
{
  tone(buzzerPin,1000,150);
  delay(250);
  noTone(buzzerPin);
}

void beepDash()
{
  tone(buzzerPin,1000,1000);
  delay(400);
  noTone(buzzerPin);
}


void morseToBeep(String morse)
{
  for (unsigned int i = 0; i < morse.length(); i++) {
        if (morse[i] != ' ') 
        {
          if(morse[i] == '.')
          {
            beepDot();
          }
          else
          {
            beepDash();
          }
        }
        else
        {
         delay(450);
         noTone(buzzerPin); 
        }
    }

}

void setup() {
    Serial.begin(9600);
    pinMode(buzzerPin, OUTPUT);
    inputString.reserve(200);
    delay(2000);
}


void loop() 
{

  while (Serial.available()) 
  {
    char inChar = (char)Serial.read();
    inputString += inChar;

    if (inChar == '\n') {
        inputString.trim(); // Remove leading/trailing whitespace
        stringComplete = true;
    }
  }

  if (stringComplete) {
      morseToBeep(sentenceToCode(inputString));
      inputString = ""; // Clear the inputString for new data
      stringComplete = false;
    }


}
