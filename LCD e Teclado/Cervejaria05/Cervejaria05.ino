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

int  list,sp=110;
int clciti=38; // config lager config inicial temperatura inicial
// variaveis fase 1
int clcf1ti; // config lager fase 1 temperatura inicial
int clcf1tf; // config lager fase 1 temperatura final
int clcf1t; // config lager fase 1 temperatura 

// variaveis fase 2
int clcf2ti; // config lager fase 1 temperatura inicial
int clcf2tf; // config lager fase 1 temperatura final
int clcf2t; // config lager fase 1 temperatura 

// variaveis fase 3
int clcf3ti; // config lager fase 1 temperatura inicial
int clcf3tf; // config lager fase 1 temperatura final
int clcf3t; // config lager fase 1 temperatura 

// variaveis fase 4
int clcf4ti; // config lager fase 1 temperatura inicial
int clcf4tf; // config lager fase 1 temperatura final
int clcf4t; // config lager fase 1 temperatura 

// variaveis fase 5
int clcf5ti; // config lager fase 1 temperatura inicial
int clcf5tf; // config lager fase 1 temperatura final
int clcf5t; // config lager fase 1 temperatura 


void setup(){
  _menu *r,*s1,*s2,*s3;

  Serial.begin(19200);    
  
  tree.begin(&lcd,20,4); //declare lcd object and screen size to menwiz lib

  r=tree.addMenu(MW_ROOT,NULL,F("Mneu Principal"));
 
  s1=tree.addMenu(MW_SUBMENU,r,F("Config. lager"));

  // configuraço inicial

       s2=tree.addMenu(MW_SUBMENU,s1,F("Config Inicial"));
         s3=tree.addMenu(MW_VAR,s2,F("Temp inicial"));
           s3->addVar(MW_AUTO_INT,&clciti,20,50,01); 

  // configuraçao fase 1  

       s2=tree.addMenu(MW_SUBMENU,s1,F("Config Fase 1"));
         s3=tree.addMenu(MW_VAR,s2,F("Temp inicial"));
           s3->addVar(MW_AUTO_INT,&clcf1ti,50,70,01); 

         s3=tree.addMenu(MW_VAR,s2,F("Temp Final"));
           s3->addVar(MW_AUTO_INT,&clcf1tf,50,70,01); 

         s3=tree.addMenu(MW_VAR,s2,F("Tempo"));
           s3->addVar(MW_AUTO_INT,&clcf1t,50,70,01); 
           
  // configuraçao fase 2  

       s2=tree.addMenu(MW_SUBMENU,s1,F("Config Fase 2"));
         s3=tree.addMenu(MW_VAR,s2,F("Temp inicial"));
           s3->addVar(MW_AUTO_INT,&clcf2ti,50,70,01); 

         s3=tree.addMenu(MW_VAR,s2,F("Temp Final"));
           s3->addVar(MW_AUTO_INT,&clcf2tf,50,70,01); 

         s3=tree.addMenu(MW_VAR,s2,F("Tempo"));
           s3->addVar(MW_AUTO_INT,&clcf2t,50,70,01); 

  // configuraçao fase 2  

       s2=tree.addMenu(MW_SUBMENU,s1,F("Config Fase 3"));
         s3=tree.addMenu(MW_VAR,s2,F("Temp inicial"));
           s3->addVar(MW_AUTO_INT,&clcf2ti,50,70,01); 

         s3=tree.addMenu(MW_VAR,s2,F("Temp Final"));
           s3->addVar(MW_AUTO_INT,&clcf2tf,50,70,01); 

         s3=tree.addMenu(MW_VAR,s2,F("Tempo"));
           s3->addVar(MW_AUTO_INT,&clcf2t,50,70,01); 

  // configuraçao fase 2  

       s2=tree.addMenu(MW_SUBMENU,s1,F("Config Fase 4"));
         s3=tree.addMenu(MW_VAR,s2,F("Temp inicial"));
           s3->addVar(MW_AUTO_INT,&clcf2ti,50,70,01); 

         s3=tree.addMenu(MW_VAR,s2,F("Temp Final"));
           s3->addVar(MW_AUTO_INT,&clcf2tf,50,70,01); 

         s3=tree.addMenu(MW_VAR,s2,F("Tempo"));
           s3->addVar(MW_AUTO_INT,&clcf2t,50,70,01); 

// configuraçao cerveja ale

s1=tree.addMenu(MW_SUBMENU,r,F("Config. ale"));

  // configuraço inicial

       s2=tree.addMenu(MW_SUBMENU,s1,F("Config Inicial"));
         s3=tree.addMenu(MW_VAR,s2,F("Temp inicial"));
           s3->addVar(MW_AUTO_INT,&clciti,20,50,01); 

  // configuraçao fase 1  

       s2=tree.addMenu(MW_SUBMENU,s1,F("Config Fase 1"));
         s3=tree.addMenu(MW_VAR,s2,F("Temp inicial"));
           s3->addVar(MW_AUTO_INT,&clcf1ti,50,70,01); 

         s3=tree.addMenu(MW_VAR,s2,F("Temp Final"));
           s3->addVar(MW_AUTO_INT,&clcf1tf,50,70,01); 

         s3=tree.addMenu(MW_VAR,s2,F("Tempo"));
           s3->addVar(MW_AUTO_INT,&clcf1t,50,70,01); 
    
  
  
  
       tree.navButtons(UP_BOTTON_PIN,DOWN_BOTTON_PIN,LEFT_BOTTON_PIN,RIGHT_BOTTON_PIN,ESCAPE_BOTTON_PIN,CONFIRM_BOTTON_PIN);
  }

void loop(){
  tree.draw(); 
  }

void myfunc(){
  Serial.println("ACTION FIRED");
  }

