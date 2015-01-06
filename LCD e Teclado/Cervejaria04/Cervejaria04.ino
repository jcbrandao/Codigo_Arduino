//The full code is in library example file Quick_tour.ino
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <buttons.h>
#include <MENWIZ.h>
#include <EEPROM.h>

// DEFINE ARDUINO PINS FOR THE NAVIGATION BUTTONS
#define UP_BOTTON_PIN       9
#define DOWN_BOTTON_PIN     10
#define LEFT_BOTTON_PIN     7 
#define RIGHT_BOTTON_PIN    8
#define CONFIRM_BOTTON_PIN  12
#define ESCAPE_BOTTON_PIN   11

menwiz tree;
// create lcd obj using LiquidCrystal lib
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int  list,sp=50;
float    f=26.0;

void setup(){
  _menu *r,*s1,*s2, *s3;

  Serial.begin(19200);    
  tree.begin(&lcd,20,4); //declare lcd object and screen size to menwiz lib

  r=tree.addMenu(MW_ROOT,NULL,F("Menu Principal"));
    s1=tree.addMenu(MW_SUBMENU,r, F("Config. Lagers"));
       s2=tree.addMenu(MW_VAR,s1, F("T. Inicial Fase 1"));
        s2->addVar(MW_AUTO_INT,&sp,50,70,05);  
       s2=tree.addMenu(MW_VAR,s1, F("T. Final Fase 1"));
        s2->addVar(MW_AUTO_INT,&sp,50,70,05);  
       s2=tree.addMenu(MW_VAR,s1, F("Tempo Fase 1"));
        s2->addVar(MW_AUTO_INT,&sp,50,70,05);  
 
      
    s1=tree.addMenu(MW_SUBMENU,r, F("Config. Ales"));
      s2=tree.addMenu(MW_VAR,s1, F("Config. Fase 1"));
        s2->addVar(MW_LIST,&list);
        s2->addItem(MW_LIST, F("Temp. Inicial"));
        s2->addItem(MW_LIST, F("Temp. Final"));
        s2->addItem(MW_LIST, F("Tempo"));
      s2=tree.addMenu(MW_VAR,s1, F("Config. Fase 2"));
        s2->addVar(MW_LIST,&list);
        s2->addItem(MW_LIST, F("Temp. Inicial"));
        s2->addItem(MW_LIST, F("Temp. Final"));
        s2->addItem(MW_LIST, F("Tempo"));

    s1=tree.addMenu(MW_SUBMENU,r, F("Config. Especiais"));
      s2=tree.addMenu(MW_VAR,s1, F("Config. Fase 1"));
        s2->addVar(MW_LIST,&list);
        s2->addItem(MW_LIST, F("Temp. Inicial"));
        s2->addItem(MW_LIST, F("Temp. Final"));
        s2->addItem(MW_LIST, F("Tempo"));
      s2=tree.addMenu(MW_VAR,s1, F("Config. Fase 2"));
        s2->addVar(MW_LIST,&list);
        s2->addItem(MW_LIST, F("Temp. Inicial"));
        s2->addItem(MW_LIST, F("Temp. Final"));
        s2->addItem(MW_LIST, F("Tempo"));

       tree.navButtons(UP_BOTTON_PIN,DOWN_BOTTON_PIN,LEFT_BOTTON_PIN,RIGHT_BOTTON_PIN,ESCAPE_BOTTON_PIN,CONFIRM_BOTTON_PIN);
  }

void loop(){
  tree.draw(); 
  }

void myfunc(){
  Serial.println("ACTION FIRED");
  }

