// Projeto 26 - Teclado matricial 4x4 básico

#include <Keypad.h>  // Biblioteca para controle do teclado de matrizes.

const byte ROWS = 4;  // Quatro linhas por...
const byte COLS = 4; //  Quatro colunas.

// Define o Keypad (mapa do circuito do teclado).
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Conecta o teclado matricial em linha 0, linha 1, linha 2, linha 3 e linha 4 dos pinos do arduino.
byte rowPins[ROWS] = { 9, 8, 7, 6 };

// Conecta o teclado matricial em coluna 0, coluna 1, coluna 2, coluna 3 e coluna 4 do arduino.
byte colPins[COLS] = { 12, 11, 10, 5 };

// Cria um objto Keypad.
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define ledpin 13  // Led conectado no pino 13 do arduino.

void setup()
{
  pinMode(ledpin,OUTPUT);  // Define o pino 13 como sendo de saída.
  digitalWrite(ledpin, HIGH);  // incializa com o led ligado.
  Serial.begin(9600);  // Inicia o Serial Monitor.
}

void loop()
{
  char key = kpd.getKey();
  if(key)  // Checa se um botão foi precionado.
  {
    switch (key)
    {
      case '*':  // Se for precionado...
        digitalWrite(ledpin, LOW);  // o led apaga.
        break;  // Parada, aguardando precionar outro botão.
      case '#':  // Se for precionado...
        digitalWrite(ledpin, HIGH);  // o led ascende.
        break;
        case 'A':
        digitalWrite(ledpin, HIGH);
        break;
        case 'B':
        digitalWrite(ledpin, LOW);
        break;
        case 'C':
        digitalWrite(ledpin, HIGH);
        break;
        case 'D':
        digitalWrite(ledpin, LOW);
        break;
        default:
        Serial.println(key);
    }
  }
}

