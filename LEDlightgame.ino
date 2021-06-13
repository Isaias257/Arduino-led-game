#include <LiquidCrystal.h>


#define button1 2
#define button2 3
#define led1 23
#define led2 22
#define led3 25
#define ledwin2 39
#define ledwin1 38


unsigned long previousMillis = 0;
const long interval = 250;
void setup(){
  Serial.begin(9600);
  // button inputs
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  // led outputs 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

int button1currentstate = 1;
int button1off = 0;
int button2currentstate = 1;
int led1currentstate = 0;
int led2currentstate = 0;
int led3currentstate = 0;

int led_iter = 1;
int led_update = 1;

void loop(){
 
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    led_pattern();
  }

  int button1currentstate = digitalRead(button1);
  int button2currentstate = digitalRead(button2);

  button1_check(button1currentstate);
  button2_check(button2currentstate);

  Serial.print(button2currentstate);
  Serial.print("     ");
  Serial.print("led current");
  Serial.print(led_iter);
  Serial.print("\n");

}
// ===================================================================================
// LED PATTERNS 
void led_pattern(){
  if (led_iter == 1){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      led_update = 2;
      led_iter = led_update;
    }
  else if (led_iter == 2){
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      led_update = 3;
      led_iter = led_update;
    }
  else if (led_iter == 3){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      led_update = 1;
      led_iter = led_update;
      }
  }

void button1_check(int button1currentstate){
  if (button1currentstate == 0 && led_iter == 1){
  Serial.print("button1 is pressed   ");
  for (int i=1;i<4;i++){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(ledwin1, HIGH);
    delay(250);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(ledwin1, LOW);
    delay(250);
    }
  }
}

void button2_check(int button2currentstate){
  if (button2currentstate == 0 && led_iter == 3){
  Serial.print("button1 is pressed   ");
  for (int i=1;i<4;i++){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(ledwin2, HIGH);
    delay(250);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(ledwin2, LOW);
    delay(250);
    }
  }
}

void led_blink(){
      if (led1currentstate == 0){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      led1currentstate = 1;
    }
    else if(led1currentstate == 1){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      led1currentstate = 0;
    }
  }

  // -----------------------------------------------------------------------
