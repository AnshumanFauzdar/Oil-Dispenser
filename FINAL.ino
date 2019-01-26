#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); 

char myArray[12] = {"012345678AB"};
#include<string.h>
#include <LiquidCrystal.h>
const int rs = 31, en = 30, d4 = 28, d5 = 26, d6 = 24, d7 = 22;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int relay = 9;
int pot2 = A2;
int button = 8;
int button2 = 7;
int button3 = 6;
int button4 = 5;
int button5 = 4;
int button6 = 3;
int button7 = 2;

double potvalue2 = 0;
int buttonvalue = 1;
int buttonvalue2 = 1;
int buttonvalue3 = 1;
int buttonvalue4 = 1;
int buttonvalue5 = 1;
int buttonvalue6 = 1;
int buttonvalue7 = 1;
double final_weight = 0;


char weight[7] = "";
double maxvalue = 1;
double maxvalue2 = 1;
char valid[50] = "false";
char valid2[50] = "false";
char valid3[50] = "false";
char valid4[50] = "false";
char valid5[50] = "false";
char valid6[50] = "false";
char valid7[50] = "false";

void setup()
{  
pinMode(relay, OUTPUT);
pinMode(button, INPUT); 
pinMode(button2, INPUT);
Serial.begin(9600);
mySerial.begin(9600);
digitalWrite(relay, 1);
lcd.begin(16, 2);  
}

void loop()
{
 
  
  //Serial.println(analogRead(pot2));
  //delay(100);
  
  {
  while (mySerial.available() > 11)
  {
    myArray[0] = mySerial.read();

    //find the first charater, +
    if (myArray[0] == '+')
    {
      //read the remainding characters
      for (byte i = 1; i < 12; i++)
      {
        myArray[i] = mySerial.read();
        delay(1);
      }

      // Okay, myArray[1]thru myArray[7] has the data needed

      //Test print the characters
      for (byte i = 1; i < 8; i++)
      {
        Serial.print(myArray[i]);
        lcd.setCursor(0, 1);
        lcd.print(myArray);
      }
      
      Serial.println();
    } 

  } 

}
  
  
  
  buttonvalue = digitalRead(button);
  buttonvalue2 = digitalRead(button2);
  buttonvalue3 = digitalRead(button3);
  buttonvalue4 = digitalRead(button4);
  buttonvalue5 = digitalRead(button5);
  buttonvalue6 = digitalRead(button6);
  buttonvalue7 = digitalRead(button7);
  if(!strcmp(valid,"true"))
{
  buttonvalue=1;
}
  if(!strcmp(valid2,"true"))
{
  buttonvalue2=1;
}
  if(!strcmp(valid3, "true"))
  {
    buttonvalue3=1;
    }
if(!strcmp(valid4, "true"))
  {
    buttonvalue4=1;
    }

if(!strcmp(valid5, "true"))
{
  buttonvalue5=1;
  } 
if (!strcmp(valid6, "true"))
{
  buttonvalue6=1;
  } 
  if (!strcmp(valid7, "true"))
{
  buttonvalue7=1;
  }         
//FIRST BUTTON
    
  if(buttonvalue == 1)
  {
    digitalWrite(relay, 0);
    strcpy(valid,"true");
    maxvalue = 000.390;
    lcd.setCursor(1,0);
    lcd.print("Vol INPUT:");
    lcd.print("500 ml");
    if(!strcmp(valid,"true"))
   {
    weight[0] = myArray[1];
    weight[1] = myArray[2];
    weight[2] = myArray[3];
    weight[3] = myArray[4];
    weight[4] = myArray[5];
    weight[5] = myArray[6];
    weight[6] = myArray[7];
    
    final_weight = strtod(weight,NULL);
    
   }
 
    if(final_weight>maxvalue)
    {
     digitalWrite(relay, 1); 
     strcpy(valid,"false");
    }
    }
    
    // SECOND SWITCH
    
  else if(buttonvalue2 == 1)
  {
    digitalWrite(relay, 0);
    strcpy(valid2,"true");
    maxvalue = 00.910;
    lcd.setCursor(1,0);
    lcd.print("Vol INPUT:");
    lcd.print("1 L");
    if(!strcmp(valid2,"true"))
    {
      weight[0] = myArray[1];
    weight[1] = myArray[2];
    weight[2] = myArray[3];
    weight[3] = myArray[4];
    weight[4] = myArray[5];
    weight[5] = myArray[6];
    weight[6] = myArray[7];
    
    final_weight = strtod(weight,NULL);
    
      }
      if(final_weight>maxvalue)
      {
        digitalWrite(relay, 1);
        strcpy(valid2,"false");
        }
       }
       

// 3rd Button 
       
  else if(buttonvalue3 == 1)
  {
    digitalWrite(relay, 0);
    strcpy(valid3,"true");
    maxvalue = 001.800;
    lcd.setCursor(1,0);
    lcd.print("Vol INPUT:");
    lcd.print("2 L");
    if(!strcmp(valid3,"true"))
   {
    weight[0] = myArray[1];
    weight[1] = myArray[2];
    weight[2] = myArray[3];
    weight[3] = myArray[4];
    weight[4] = myArray[5];
    weight[5] = myArray[6];
    weight[6] = myArray[7];
    
    final_weight = strtod(weight,NULL);
    
      }
      if(final_weight>maxvalue)
      {
     digitalWrite(relay, 1); 
     strcpy(valid3,"false");
    }
    }

// 4th Button

else if(buttonvalue4 == 1)
  {
    digitalWrite(relay, 0);
    strcpy(valid4,"true");
    maxvalue = 004.500;
    lcd.setCursor(1,0);
    lcd.print("WT INPUT:");
    lcd.print("5 L");
    if(!strcmp(valid4,"true"))
   {
    weight[0] = myArray[1];
    weight[1] = myArray[2];
    weight[2] = myArray[3];
    weight[3] = myArray[4];
    weight[4] = myArray[5];
    weight[5] = myArray[6];
    weight[6] = myArray[7];
    
    final_weight = strtod(weight,NULL);
    
      }
      if(final_weight>maxvalue)
      {
     digitalWrite(relay, 1); 
     strcpy(valid4,"false");
    }
    }

// 5th Button
    
else if(buttonvalue5 == 1)
  {
    digitalWrite(relay, 0);
    strcpy(valid5,"true");
    maxvalue = 009.000;
    lcd.setCursor(1,0);
    lcd.print("WT INPUT:");
    lcd.print("10 L");
    if(!strcmp(valid5,"true"))
   {
    weight[0] = myArray[1];
    weight[1] = myArray[2];
    weight[2] = myArray[3];
    weight[3] = myArray[4];
    weight[4] = myArray[5];
    weight[5] = myArray[6];
    weight[6] = myArray[7];
    
    final_weight = strtod(weight,NULL);
    
      }
      if(final_weight>maxvalue)
      {
     digitalWrite(relay, 1); 
     strcpy(valid5,"false");
    }
    }

// 6th Button - 15Kg
    
else if(buttonvalue6 == 1)
  {
    digitalWrite(relay, 0);
    strcpy(valid5,"true");
    maxvalue = 013.600;
    lcd.setCursor(1,0);
    lcd.print("WT INPUT:");
    lcd.print("15 L");
    if(!strcmp(valid6,"true"))
   {
    weight[0] = myArray[1];
    weight[1] = myArray[2];
    weight[2] = myArray[3];
    weight[3] = myArray[4];
    weight[4] = myArray[5];
    weight[5] = myArray[6];
    weight[6] = myArray[7];
    
    final_weight = strtod(weight,NULL);
    
      }
      if(final_weight>maxvalue)
      {
     digitalWrite(relay, 1); 
     strcpy(valid6,"false");
    }
    }
/*
// Manual Button-Set value by Potentiometer 
 
  else if(buttonvalue7 == 1)
    {
    digitalWrite(relay, 0);
    strcpy(valid7,"true");
    
    
    if(!strcmp(valid7,"true"))
   {
    potvalue2 = analogRead(pot2)/10;
    
    weight[0] = myArray[1];
    weight[1] = myArray[2];
    weight[2] = myArray[3];
    weight[3] = myArray[4];
    weight[4] = myArray[5];
    weight[5] = myArray[6];
    weight[6] = myArray[7];
    
   final_weight = strtod(weight,NULL);
   maxvalue2 = final_weight;
   lcd.setCursor(1,0);
    lcd.print("WT INPUT:");
    lcd.print(maxvalue2);
    lcd.print("L");
   }
 
  if(final_weight>maxvalue2)
    {
     digitalWrite(relay, 1); 
     strcpy(valid7,"false");
    }
    }
    */    
  }  
