/* THE PAPER FOLDER. This program is the code for a robot that folds printer paper in hald hamburger style. */

#define WATCHLED 2
#define STARTBUTTON 3
#include <Servo.h>

Servo myservo_1;  //microservo that rotates metal bar
Servo myservo_2;  //microservo that rotates to lock end of metal bar
Servo myservo_3;  //bigger servo that rotates 90 degress to create crease

int i;
boolean startbutton;

int pos_1 = 90;  //variable to store the servo_1 position
int pos_2 = 90;  //variable to store the servo_2 position
int pos_3 = 0;  //variable to store the servo_3 position

void setup()
{ 
  pinMode(WATCHLED,OUTPUT);
  pinMode(STARTBUTTON,INPUT);

  myservo_1.attach(3);  //attaches servo_1 on pin 4
  myservo_2.attach(4);  //attaches servo_2 on pin 5
  myservo_3.attach(5);  //attaches servo_3 on pin 6
}

void loop() 
{
 startbutton=false;

//-------------Watchdog code
  while (! startbutton) {        // stay in this loop until button pressed
    digitalWrite(WATCHLED,HIGH); // LED on
    for(i=0;i<10;i++) {
      delay(25);                 // wait a bit
      if (digitalRead(STARTBUTTON) == LOW)  // check button
        startbutton=true;        // button is pressed
    }
    digitalWrite(WATCHLED,LOW);  // LED off
    for(i=0;i<30;i++) {
      delay(25);
      if (digitalRead(STARTBUTTON) == LOW)
        startbutton=true;
    }
  } // end of while loop

 digitalWrite(WATCHLED,LOW);    // LED off
 robotcode();                   // go to your robot code
}

void robotcode()
{
   for(pos_2 = 90; pos_2 >= 20; pos_2 -=1){ //servo_2 opens
    myservo_2.write(pos_2);
    delay(50);
  }
  for (pos_1 = 90; pos_1 <= 167; pos_1 +=1){  //servo_1 closes
    myservo_1.write(pos_1);
    delay (50);
  }
   for (pos_2 = 90; pos_2 <= 112; pos_2 +=1){ //servo_2 closes
   myservo_2.write(pos_2);
   delay(50);
  }
  delay (3000);   //servo_2 holds in place
  
//-------------
  for(pos_3 = 0; pos_3 <= 90; pos_3 +=1){   //servo_3 closes
    myservo_3.write(pos_3);
    delay(50);
  }
  
//-------------  

  for(pos_2 = 90; pos_2 >= 20; pos_2 -=1){   //servo_2 reopens
    myservo_2.write(pos_2);
    delay(50);
  }
  for (pos_1 = 167; pos_1 >= 70; pos_1 -=1){  //servo_1 reopens
    myservo_1.write(pos_1);
    delay (50);
  }
}
 



