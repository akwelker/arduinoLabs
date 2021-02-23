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




#define X1_CAP 100
#define X2_CAP 70
#define Y1_CAP 40
#define Y2_CAP 30


#define MODE  1 // if mode is below 0, program is in debug mode

// import libraries and set up grid vars

#include<CapacitiveSensor.h>

const int y1_pins[] = {11,8};
const int y2_pins[] = {11,13};

const int x1_pins[] = {5,7};
const int x2_pins[] = {5,2};

// make Capacitive Sensors

CapacitiveSensor x1 = CapacitiveSensor(x1_pins[0],x1_pins[1]);
CapacitiveSensor x2 = CapacitiveSensor(x2_pins[0],x2_pins[1]);

CapacitiveSensor y1 = CapacitiveSensor(y1_pins[0],y1_pins[1]);
CapacitiveSensor y2 = CapacitiveSensor(y2_pins[0],y2_pins[1]);

void setup()
{
  // Open a serial connection
  Serial.begin(9600);
}

void loop()
{
  //Read the capacitance at each grid value
  int x1_read = x1.capacitiveSensor(30);
  int x2_read = x2.capacitiveSensor(30);
  
  int y1_read = y1.capacitiveSensor(30);
  int y2_read = y2.capacitiveSensor(30);
    
  if(MODE < 0)
  {
    Serial.print(x1_read);
    Serial.print('\t');
    Serial.print(x2_read);
    Serial.print('\t');


    Serial.print(y1_read);
    Serial.print('\t');
    Serial.println(y2_read);
  }

  else
  {
    int x_index = 0;
    int y_index = 0;

    if(x1_read > X1_CAP)
    {
      x_index = 1;
    }
    else if(x2_read > X2_CAP)
    {
      x_index = 2;
    }

    if(y1_read > Y1_CAP)
    {
      y_index = 1;
    }
    else if(y2_read > Y2_CAP)
    {
      y_index = 2;
    }

    if(x_index == 0 || y_index == 0)
    {
      Serial.println("Screen is not being touched");
    }
    else
    {
      Serial.print("(");
      Serial.print(x_index);
      Serial.print(',');
      Serial.print(y_index);
      Serial.println(')');
    }
    
    
  }
}
 
