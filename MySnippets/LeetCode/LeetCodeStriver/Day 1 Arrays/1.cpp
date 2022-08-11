// C++ code
//
const int buttonPin = 7;
const int redPin = 5;
const int greenPin = 4;
const int bluePin = 3;
const int yellowPin = 2;
int counter = -1;
int off = 0;

void setup()
{
    pinMode(buttonPin, INPUT);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
}

void loop()
{
    int buttonState;
    buttonState = digitalRead(buttonPin);
    if (off == 1 && buttonState == HIGH)
        counter++;

    if (buttonState == LOW)
    {
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
        digitalWrite(yellowPin, LOW);
        off = 1;
    }
    else
    {
        off = 0;
        if (counter % 4 == 0)
        {
            digitalWrite(redPin, HIGH);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, LOW);
            digitalWrite(yellowPin, LOW);
        }

        else if (counter % 4 == 1)
        {
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, HIGH);
            digitalWrite(bluePin, LOW);
            digitalWrite(yellowPin, LOW);
        }

        else if (counter % 4 == 2)
        {
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, HIGH);
            digitalWrite(yellowPin, LOW);
        }

        else if (counter % 4 == 3)
        {
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, LOW);
            digitalWrite(yellowPin, HIGH);
        }
    }
}