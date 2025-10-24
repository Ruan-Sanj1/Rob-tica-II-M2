#include ".h"

void setup() {
configurar();
}

EEPROM.get(enderecoRecorde, recorde);
Serial.print("Recorde Atual: ");
if (recorde < 0 || recorde > 100) {
Serial.println("0");
} else {
Serial.println(recorde);
}
esperarNovoJogo();

void loop() {
}


--------------------------------------------------------------VARIÁVEIS.H--------------------------------------------------------------------------
#include <EEPROM.h>

#define ledAmarelo 
#define ledAzul 
#define ledVerde 
#define ledVermelho 
#define botaoAmarelo 
#define botaoAzul 
#define botaoVerde 
#define botaoVermelho 
#define buzzer 
#define notaAmarelo 262 /* Dó */
#define notaAzul 294 /* Ré */
#define notaVerde 330 /* Mi */
#define notaVermelho 349 /* Fá */
#define tempoLedAceso 300
#define enderecoRecorde 0

int recorde = ;
int sequencia[100];
int tamanhoSequencia = 0;




--------------------------------------------------------------CONFIGURAR.INO--------------------------------------------------------------------------
void configurar() {
pinMode(ledAmarelo, OUTPUT);
pinMode(ledAzul, OUTPUT);
pinMode(ledVerde, OUTPUT);
pinMode(ledVermelho, OUTPUT);
pinMode(botaoAmarelo, INPUT_PULLUP);
pinMode(botaoAzul, INPUT_PULLUP);
pinMode(botaoVerde, INPUT_PULLUP);
pinMode(botaoVermelho, INPUT_PULLUP);
Serial.begin(9600);
randomSeed(analogRead(0));
}




--------------------------------------------------------------ESPERARNOVOJOGO.INO--------------------------------------------------------------------------
void esperarNovoJogo() {
Serial.println(“Pressione qualquer botão para iniciar...”);

while (true) {
if (digitalRead(botaoAmarelo) == LOW || digitalRead(botaoAzul) == LOW || digitalRea-
d(botaoVerde) == LOW || digitalRead(botaoVermelho) == LOW) {

while (digitalRead(botaoAmarelo) == LOW || digitalRead(botaoAzul) == LOW || digi-
talRead(botaoVerde) == LOW || digitalRead(botaoVermelho) == LOW) {};
tamanhoSequencia = 0; 
gerarSequencia(); 
tocarMusicaAbertura(); 
break;
}
}
}





--------------------------------------------------------------GERARSEQUENCIA.INO--------------------------------------------------------------------------
void gerarSequencia() {
sequencia[tamanhoSequencia] = random(4);
tamanhoSequencia++;
Serial.print("Nível: ");
Serial.println(tamanhoSequencia);
}





---------------------------------------------------------------MUSICAS.INO-------------------------------------------------------------------------
void tocarMusicaAbertura() {
acenderLed(0);
delay(300);
apagarLeds();
delay(100);
acenderLed(1);
delay(300);
apagarLeds();
delay(100);
acenderLed(2);
delay(300);
apagarLeds();
delay(100);
acenderLed(3);
delay(300);
apagarLeds();
delay(1000); 
}

void tocarMusicaDerrota() {
int notas[] = {330, 294, 262, 196, 150, 130, 110, 98};
int duracoes[] = {150, 150, 150, 150, 150, 150, 150, 600}; 
int leds[] = {2, 4, 6, 8}; 
int numLeds = sizeof(leds) / sizeof(leds[0]); 

for (int i = 0; i < 8; i++) {
tone(buzzer, notas[i]);
int ledAleatorio = leds[random(numLeds)]; 
digitalWrite(ledAleatorio, HIGH); 
delay(duracoes[i]); 
noTone(buzzer); 
apagarLeds();
delay(100); 
}
delay(1000); 
}




--------------------------------------------------------------ACENDERLED.INO--------------------------------------------------------------------------

void acenderLed(int led) {
switch (led) {
case 0:
digitalWrite(, HIGH);
tone(buzzer, );
break;
case 1:
digitalWrite(, HIGH);
tone(buzzer, );
break;
case 2:
digitalWrite(, HIGH);
tone(buzzer, );
break;
case 3:
digitalWrite(, HIGH);
tone(buzzer, );
break;
}
}





--------------------------------------------------------------APAGARLEDS.INO--------------------------------------------------------------------------
void apagarLeds() {
digitalWrite(ledAmarelo, LOW);
digitalWrite(ledAzul, LOW);
digitalWrite(ledVerde, LOW);
digitalWrite(ledVermelho, LOW);
noTone(buzzer);
}





--------------------------------------------------------------MOSTRARSEQUENCIA.INO--------------------------------------------------------------------------
void mostrarSequencia() {
for (int i = 0; i < tamanhoSequencia; i++) {
acenderLed(sequencia[i]);
delay(tempoLedAceso);
apagarLeds();
delay(tempoLedAceso);
}
}




--------------------------------------------------------------VERIFICARENTRADAJOGADOR.INO--------------------------------------------------------------------------
bool verificarEntradaJogador() {
for (int i = 0; i < tamanhoSequencia; i++) {
int botaoPressionado = esperarBotaoPressionado();
if (botaoPressionado != sequencia[i]) {
return false;
}
}
return true;
}





--------------------------------------------------------------ESPERARBOTAOPRESSIONADO.INO--------------------------------------------------------------------------
int esperarBotaoPressionado() {
while (true) {
if (digitalRead(botaoAmarelo) == LOW) {
acenderLed(0);
delay(tempoLedAceso);
apagarLeds();
while (digitalRead(botaoAmarelo) == LOW) {};
return 0;
}
if (digitalRead(botaoAzul) == LOW) {
acenderLed(1);
delay(tempoLedAceso);
apagarLeds();
while (digitalRead(botaoAzul) == LOW) {};
return 1;
}
if (digitalRead(botaoVerde) == LOW) {
acenderLed(2);
delay(tempoLedAceso);
apagarLeds();
while (digitalRead(botaoVerde) == LOW) {}; 
return 2;
}
if (digitalRead(botaoVermelho) == LOW) {
acenderLed(3);
delay(tempoLedAceso); 
apagarLeds();
while (digitalRead(botaoVermelho) == LOW) {}; 
return 3;
}
}
}






--------------------------------------------------------------FINALIZACAO--------------------------------------------------------------------------
void loop() {
mostrarSequencia(); 

if (verificarEntradaJogador()) { 
Serial.println("");
delay(1000);
gerarSequencia();
} else {
Serial.println("");
tocarMusicaDerrota();


if (tamanhoSequencia - 1 > recorde) {
recorde = tamanhoSequencia - 1; 
EEPROM.put(enderecoRecorde, recorde);
Serial.print("");
Serial.println(recorde);
} else {
Serial.print("");
Serial.println(recorde);
}
esperarNovoJogo();
}
}
