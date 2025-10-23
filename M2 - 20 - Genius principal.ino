/* Inclui o preâmbulo a partir da aba variaveis.h */
#include "variaveis.h"
void setup() {
/* Chama a função que faz as configurações necessárias. */
configurar();
}
/* Carrega o recorde da EEPROM. */
EEPROM.get(enderecoRecorde, recorde);
Serial.print("Recorde Atual: ");
if (recorde < 0 || recorde > 100) {
Serial.println("0");
} else {
Serial.println(recorde);
}
/* Espera pelo jogador para iniciar a partida. */
esperarNovoJogo();


--------------------------------------------------------------VARIÁVEIS--------------------------------------------------------------------------
  /* Biblioteca que permitirá a gravação de dados na memória eeprom
do Arduino. */
#include <EEPROM.h>
/* Definição dos pinos dos LEDs. */
#define ledAmarelo 10
#define ledAzul 8
#define ledVerde 6
#define ledVermelho 4
/* Definição dos pinos dos botões. */
#define botaoAmarelo 11
#define botaoAzul 9
#define botaoVerde 7
#define botaoVermelho 5
/* Definição do pino do buzzer. */
#define buzzer 2
/* Notas musicais correspondentes aos LEDs. */
#define notaAmarelo 262 /* Dó */
#define notaAzul 294 /* Ré */
#define notaVerde 330 /* Mi */
#define notaVermelho 349 /* Fá */
/* Tempo que o LED fica aceso em milissegundos. */
#define tempoLedAceso 300
/* Endereço na EEPROM para armazenar o recorde (0 a 1023). */
#define enderecoRecorde 0
/* Variável para armazenar o recorde. */
int recorde = 0;
/* Array para armazenar a sequência gerada pelo jogo. */
/* O tamanho do array é 100, o que significa que ele pode armazenar
até 100 elementos. */
int sequencia[100];
/* Variável para controlar o tamanho atual da sequência gerada. */
/* Indica quantos elementos da sequência foram gerados e devem ser
reproduzidos pelo jogador. */
int tamanhoSequencia = 0;
