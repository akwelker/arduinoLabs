/*
 * Adam Welker   BYU ECEN 301    02/2021
 * 
 * A program that senses where a user is touching on a 2D capacitance grid
 * 
 * This program is based on a.) An arduino project by Arduino “having11” Guy 
 * posted on the arduino project hub at : https://create.arduino.cc/projecthub/gatoninja236/capacitive-touch-sensing-grid-f98144?ref=search&ref_id=capacitor&offset=3
 * and also on the touchy feely lamp from the starter kit projects
 * 
 * Libraries needed -- CapacitiveSensor: available on the library manager
 */




#define CAP_THRESHOLD 1000
#define MODE  -1 // if mode is below 0, program is in debug mode

// import libraries and set up grid vars

#include<CapacitiveSensor.h>

const int x1_pins[] = {7,6};
const int x2_pins[] = {5,4};
const int x3_pins[] = {3,2};

const int y1_pins[] = {9,8};
const int y2_pins[] = {11,10};
const int y3_pins[] = {13,12};

// make Capacitive Sensors

CapacitiveSensor x1 = CapacitiveSensor(x1_pins[0],x1_pins[1]);
CapacitiveSensor x2 = CapacitiveSensor(x2_pins[0],x2_pins[1]);
CapacitiveSensor x3 = CapacitiveSensor(x3_pins[0],x3_pins[1]);

CapacitiveSensor y1 = CapacitiveSensor(y1_pins[0],y1_pins[1]);
CapacitiveSensor y2 = CapacitiveSensor(y2_pins[0],y2_pins[1]);
CapacitiveSensor y3 = CapacitiveSensor(y3_pins[0],y3_pins[1]);

void setup()
{
  // Open a serial connection
  Serial.begin(9600);
}

void loop()
{
  //Read the capacitance at each grid value
  int x1_read = x1.capacitiveSensor(30);
  /*
  int x2_read = x2.capacitiveSensor(30);
  int x3_read = x3.capacitiveSensor(30);
  
  int y1_read = y1.capacitiveSensor(30);
  int y2_read = y2.capacitiveSensor(30);
  int y3_read = y3.capacitiveSensor(30);
  */
    
  if(MODE < 0)
  {
    Serial.print(x1_read);
    Serial.println('\t');
   /*
    Serial.print(x2_read);
    Serial.print('\t');
    Serial.print(x3_read);
    Serial.print('\t');

    Serial.print(y1_read);
    Serial.print('\t');
    Serial.print(y2_read);
    Serial.print('\t');
    Serial.print(y3_read);
    Serial.print('\n');
    */
  }
}
 
