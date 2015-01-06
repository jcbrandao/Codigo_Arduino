/* programa basico teclado
   Joao Carlos Brandao
*/
#include <Keypad.h>

const byte linhas = 4;
const byte colunas = 4;

byte pinosLinhas[linhas] = {9,8,7,6};
byte pinosColunas[colunas] = {12,11,10,5};

char teclas[linhas][colunas]= {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

//Keypad teclado = Keypad(makekeymap(teclas), pinosLinhas, pinosColunas, linhas, colunas);
// termina o codigo necessario
keypad teclado = keypad(makekeymap(teclas), pinosLinhas, pinosColunas, linhas, colunas);

char tecla;

void setup(){
  Serial.begin(9600);
}

void loop(){
  tecla = teclado.getkey();
  if(tecla != NO_KEY) {
    Serial.print(tecla);
  
  }
}
