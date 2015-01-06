
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
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

LiquidCrystal_I2C lcd(0x27,20,4); 

void setup()
{
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Menu Principal");
  lcd.setCursor(0,1);
  lcd.print("1 - Conf. Fases");
  lcd.setCursor(0,2);
  lcd.print("2 - Iniciar");
  lcd.setCursor(0,3);
  lcd.print("a tecla:     *=enter");
}

void loop()
{
  char tecla = Teclado.getKey();
  
  
  if (int(tecla) !=0) 
  {
    lcd.setCursor(9,3);
    lcd.print(tecla);
    if (tecla == '2'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Menu Principal");
    lcd.setCursor(0,1);
    lcd.print("Iniciando Brassagem");
    lcd.setCursor(0,2);
    lcd.print("Fase 1 - temp 68 C");
    }
  }
}
