//The full code is in library example file Quick_tour.ino
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <buttons.h>
#include <MENWIZ.h>
#include <EEPROM.h>
#include <Keypad.h> 

const byte linhas = 4;  // Quatro linhas por...
const byte colunas = 4; //  Quatro colunas.

char teclas [linhas][colunas]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte PinosLinhas[linhas]  =  { 9, 8, 7, 6 };
byte PinosColunas[colunas] =  {12, 11, 10, 5 };

Keypad Teclado = Keypad(makeKeymap(teclas),PinosLinhas, PinosColunas, linhas, colunas);
//Keypad Teclado = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


// DEFINE ARDUINO PINS FOR THE NAVIGATION BUTTONS
#define UP_BOTTON_PIN       6
#define DOWN_BOTTON_PIN     5
#define LEFT_BOTTON_PIN     4
#define RIGHT_BOTTON_PIN    3
#define CONFIRM_BOTTON_PIN  2
#define ESCAPE_BOTTON_PIN   1

menwiz tree;
// create lcd obj using LiquidCrystal lib
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int  list,sp=110;

void setup(){
  _menu *r,*s1,*s2;

  Serial.begin(19200);    
  tree.begin(&lcd,20,4); //declare lcd object and screen size to menwiz lib

  r=tree.addMenu(MW_ROOT,NULL,F("Root"));
    s1=tree.addMenu(MW_SUBMENU,r, F("Node1"));
      s2=tree.addMenu(MW_VAR,s1, F("Node3"));
        s2->addVar(MW_LIST,&list);
        s2->addItem(MW_LIST, F("Option1"));
        s2->addItem(MW_LIST, F("Option2"));
        s2->addItem(MW_LIST, F("Option3"));
      s2=tree.addMenu(MW_VAR,s1, F("Node4"));
        s2->addVar(MW_AUTO_INT,&sp,0,120,10);  
    s1=tree.addMenu(MW_VAR,r, F("Node2"));
      s1->addVar(MW_ACTION,myfunc);
       tree.navButtons(UP_BOTTON_PIN,DOWN_BOTTON_PIN,LEFT_BOTTON_PIN,RIGHT_BOTTON_PIN,ESCAPE_BOTTON_PIN,CONFIRM_BOTTON_PIN);
  }

void loop(){
  tree.draw(); 
  }

void myfunc(){
  Serial.println("ACTION FIRED");
  }

