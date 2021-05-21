
#define LedPin 9                          //LED PIN  DEFINATION
#define buttonPin 2                       //BUTTON PIN  DEFINATION

bool lastState = HIGH;                    //DEFINING LASTSTATE OF LED AS HIGH


void setup()                             //BASIC VIOD SETUP
{
    pinMode(LedPin, OUTPUT);                //SETTING THE ARDUINO PINS FOR GETTING THE OUTPUT AT LED
    pinMode(buttonPin, INPUT_PULLUP);       //SETTING THE ARDUINO PINS FOR GETTING THE INPUT FROM BUTTON

    Serial.begin(9600);                     //BAUD RATE REQUIRED FOR SERIAL MONITOR
}

void loop()
{
    bool currentState;                     //DEFINING THE CURRENT STATE OF LED
    currentState = digitalRead(buttonPin);

    if(Serial.available() > 0)
    {
        int a = Serial.read();
        if(a == 49)                          //CONSIDER ASCII VALUES FOR a
        {
            digitalWrite(LedPin, HIGH);

            lastState = currentState;
        }
        else if(a == 48)
        {
            digitalWrite(LedPin, LOW);

            lastState = currentState;
        }
    }

    if((lastState == 0 && currentState == 1) || (lastState == 1 && currentState == 0)) //USING COMPLEMENT PROPERTY
    {
        delay(50);
        if((lastState == 0 && currentState == 1) || (lastState == 1 && currentState == 0))
        {
            if(currentState == LOW)
            {
                digitalWrite(LedPin, HIGH);
                lastState = LOW;
            }
            else if(currentState == HIGH)
            {
                digitalWrite(LedPin, LOW);
                lastState = HIGH;
            }
        }


    }


}
