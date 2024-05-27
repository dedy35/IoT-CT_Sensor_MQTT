#include <Arduino.h>
#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>
#include "EmonLib.h"

LiquidCrystal_I2C lcd (0x27, 16, 2);

EnergyMonitor emon1, emon2, emon3, emon4, emon5, emon6, emon7, emon8, emon9, emon10;
float cal = 111.1;

String con1, con2, con3, con4, con5, con6, con7, con8, con9, con10 = "";

//Update Pengiriman
unsigned long last = 0;
//#define update_time 2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  emon1.current(A0, cal);
  emon2.current(A1, cal);
  emon3.current(A2, cal);
  emon4.current(A3, cal);
  emon5.current(A4, cal);
  emon6.current(A5, cal);
  emon7.current(A6, cal);
  emon8.current(A7, cal);
  emon9.current(A8, cal);
  emon10.current(A9,cal);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("MSN=12345678910");
  lcd.setCursor(0,1);
  lcd.print("CON=");

  //pembacaan arus
  double Irms1 = emon1.calcIrms(1484);
  double Irms2 = emon2.calcIrms(1484);
  double Irms3 = emon3.calcIrms(1484);
  double Irms4 = emon4.calcIrms(1484);
  double Irms5 = emon5.calcIrms(1484);
  double Irms6 = emon6.calcIrms(1484);
  double Irms7 = emon7.calcIrms(1484);
  double Irms8 = emon8.calcIrms(1484);
  double Irms9 = emon9.calcIrms(1484);
  double Irms10 = emon10.calcIrms(1484);

  // lcd.setCursor(0,0);
  // lcd.print(Irms1);
  //print serial
//   //CT Sensor 1
//   Serial.print("Current1: ");
//   Serial.print(Irms1*230.0);
//   Serial.print(" ");
//   Serial.print(Irms1);
//   Serial.println(" A");
  
//   //CT Sensor 2
//   Serial.print("Current2: ");
//   Serial.print(Irms2*230.0);
//   Serial.print(" ");
//   Serial.print(Irms2);
//   Serial.println(" A");

//   //CT Sensor 3
//   Serial.print("Current3: ");
//   Serial.print(Irms3*230.0);
//   Serial.print(" ");
//   Serial.print(Irms3);
//   Serial.println(" A");

//   //CT Sensor 4
//   Serial.print("Current4: ");
//   Serial.print(Irms4*230.0);
//   Serial.print(" ");
//   Serial.print(Irms4);
//   Serial.println(" A");

//   //CT Sensor 5
//   Serial.print("Current5: ");
//   Serial.print(Irms5*230.0);
//   Serial.print(" ");
//   Serial.print(Irms5);
//   Serial.println(" A");

//   //CT Sensor 6
//   Serial.print("Current6: ");
//   Serial.print(Irms6*230.0);
//   Serial.print(" ");
//   Serial.print(Irms6);
//   Serial.println(" A");

//   //CT Sensor 7
//   Serial.print("Current7: ");
//   Serial.print(Irms7*230.0);
//   Serial.print(" ");
//   Serial.print(Irms7);
//   Serial.println(" A");

//  //CT Sensor 8
//   Serial.print("Current8: ");
//   Serial.print(Irms8*230.0);
//   Serial.print(" ");
//   Serial.print(Irms8);
//   Serial.println(" A");

//   //CT Sensor 9
//   Serial.print("Current9: ");
//   Serial.print(Irms9*230.0);
//   Serial.print(" ");
//   Serial.print(Irms9);
//   Serial.println(" A");

//   //CT Sensor 10
//   Serial.print("Current10: ");
//   Serial.print(Irms10*230.0);
//   Serial.print(" ");
//   Serial.print(Irms10);
//   Serial.println(" A");


  //kondisi nilai arus
  //sensor 1
  if(Irms1 < 7)
  {
    con1 = "0";
    lcd.setCursor(4,1);
    lcd.print("0");
  }
  else if(Irms1 >= 7)
  {
    con1 = "1";
    lcd.setCursor(4,1);
    lcd.print("1");
  }

  //sensor 2
  if(Irms2 < 10.4)
  {
    con2 = "0";
    lcd.setCursor(5,1);
    lcd.print("0");
  }
  else if(Irms2 >= 10.5)
  {
    con2 = "1";
    lcd.setCursor(5,1);
    lcd.print("1");
  }

  //sensor 3
  if(Irms3 < 3)
  {
    con3 = "0";
    lcd.setCursor(6,1);
    lcd.print("0");
  }
  else if(Irms3 >= 3)
  {
    con3 = "1";
    lcd.setCursor(6,1);
    lcd.print("1");
  }

  //sensor 4
  if(Irms4 < 9)
  {
    con4 = "0";
    lcd.setCursor(7,1);
    lcd.print("0");
  }
  else if(Irms4 >= 9)
  {
    con4 = "1";
    lcd.setCursor(7,1);
    lcd.print("1");
  }

  //sensor 5
  if(Irms5 < 15)
  {
    con5 = "0";
    lcd.setCursor(8,1);
    lcd.print("0");
  }
  else if(Irms5 >= 15)
  {
    con5 = "1";
    lcd.setCursor(8,1);
    lcd.print("1");
  }

  //sensor 6
  if(Irms6 < 5)
  {
    con6 = "0";
    lcd.setCursor(9,1);
    lcd.print("0");
  }
  else if(Irms6 >= 5)
  {
    con6 = "1";
    lcd.setCursor(9,1);
    lcd.print("1");
  }

  //sensor 7
  if(Irms7 < 16)
  {
    con7 = "0";
    lcd.setCursor(10,1);
    lcd.print("0");
  }
  else if(Irms7 >= 16)
  {
    con7 = "1";
    lcd.setCursor(10,1);
    lcd.print("1");
  }

  //sensor 8
  if(Irms8 < 23)
  {
    con8 = "0";
    lcd.setCursor(11,1);
    lcd.print("0");
  }
  else if(Irms8 >= 23)
  {
    con8 = "1";
    lcd.setCursor(11,1);
    lcd.print("1");
  }

  //sensor 9
  if(Irms9 < 170)
  {
    con9 = "0";
    lcd.setCursor(12,1);
    lcd.print("0");
  }
  else if(Irms9 >= 170)
  {
    con9 = "1";
    lcd.setCursor(12,1);
    lcd.print("1");
  }

  //sensor 10
  if(Irms10 < 17)
  {
    con10 = "0";
    lcd.setCursor(13,1);
    lcd.print("0");
  }
  else if(Irms10 >= 17.5)
  {
    con10 = "1";
    lcd.setCursor(13,1);
    lcd.print("1");
  }

  //Kirim data Serial
  if((millis() - last) >= 5000)
  {
    String kirimdata = String(con1) + "#" + String(con2)+ "#" + String(con3)+ "#" + String(con4)+ "#" + String(con5)+ "#" + String(con6)+ "#" + String(con7)+ "#" + String(con8)+ "#" + String(con9)+ "#" + String(con10) + "#" + "OK";
    Serial.println(kirimdata);
    last = millis();
  }
}