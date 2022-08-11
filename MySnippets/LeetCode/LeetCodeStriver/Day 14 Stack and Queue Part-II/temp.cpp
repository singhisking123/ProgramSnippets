#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

long number_1 = 0;
long number_2 = 0;
double number_final = 0;

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
    {'1', '2', '3', '+'},
    {'4', '5', '6', '-'},
    {'7', '8', '9', '*'},
    {'C', '0', '=', '/'}};
byte rowPins[ROWS] = {7, 6, 5, 4}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {3, 2, 1, 0}; // connect to the column pinouts of the keypad

// initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
    lcd.begin(16, 2); // start lcd
    for (int i = 0; i <= 3; i++)
        ;
    lcd.setCursor(0, 0);
    lcd.print("Calculator");
    lcd.setCursor(0, 1);
    lcd.print("by Shahmir Ahmed");
    delay(4000);
    lcd.clear();
    lcd.setCursor(0, 0);
}

void loop()
{

    customKey = customKeypad.getKey();
    switch (customKey)
    {
    case '0' ... '9': // This keeps collecting the number_1 value until a operator is pressed "+-*/"
        lcd.setCursor(0, 0);
        number_1 = number_1 * 10 + (customKey - '0');
        lcd.print(number_1);
        break;

    case '+':
        number_1 = (number_final != 0 ? number_final : number_1);
        lcd.setCursor(0, 1);
        lcd.print("+");
        number_2 = number_2Number(); // get the collected the number_2 number
        number_final = number_1 + number_2;
        lcd.setCursor(0, 3);
        lcd.print(number_final);
        number_1 = 0, number_2 = 0; // reset values back to zero for next use
        break;

    case '-':
        number_1 = (number_final != 0 ? number_final : number_1);
        lcd.setCursor(0, 1);
        lcd.print("-");
        number_2 = number_2Number();
        number_final = number_1 - number_2;
        lcd.setCursor(0, 3);
        lcd.print(number_final);
        number_1 = 0, number_2 = 0;
        break;

    case '*':
        number_1 = (number_final != 0 ? number_final : number_1);
        lcd.setCursor(0, 1);
        lcd.print("*");
        number_2 = number_2Number();
        number_final = number_1 * number_2;
        lcd.setCursor(0, 3);
        lcd.print(number_final);
        number_1 = 0, number_2 = 0;
        break;

    case '/':
        number_1 = (number_final != 0 ? number_final : number_1);
        lcd.setCursor(0, 1);
        lcd.print("/");
        number_2 = number_2Number();
        lcd.setCursor(0, 3);

        number_2 == 0 ? lcd.print("Invalid") : number_final = (float)number_1 / (float)number_2;

        lcd.print(number_final);
        number_1 = 0, number_2 = 0;
        break;

    case 'C':
        number_final = 0;
        lcd.clear();
        break;
    }
}

long number_2Number()
{
    while (1)
    {
        customKey = customKeypad.getKey();
        if (customKey >= '0' && customKey <= '9')
        {
            number_2 = number_2 * 10 + (customKey - '0');
            lcd.setCursor(0, 2);
            lcd.print(number_2);
        }

        if (customKey == '=')
            break; // return number_2;
    }
    return number_2;
}