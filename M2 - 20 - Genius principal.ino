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


--------------------------------------------------------------VARIÁVEIS.H--------------------------------------------------------------------------
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




--------------------------------------------------------------CONFIGURAR.INO--------------------------------------------------------------------------
void configurar() {
/* Configuração dos pinos dos LEDs como saída. */
pinMode(ledAmarelo, OUTPUT);
pinMode(ledAzul, OUTPUT);
pinMode(ledVerde, OUTPUT);
pinMode(ledVermelho, OUTPUT);
/* Configuração dos pinos dos botões como entrada pull-up. */
pinMode(botaoAmarelo, INPUT_PULLUP);
pinMode(botaoAzul, INPUT_PULLUP);
pinMode(botaoVerde, INPUT_PULLUP);
pinMode(botaoVermelho, INPUT_PULLUP);
/* Inicialização da comunicação serial para debug. */
Serial.begin(9600);
/* Inicializa o gerador de números aleatórios. A função lê, pelo analogRead(0)
como parâmetro, o valor do pino analógico do Arduino. Esse pino não está conectado em
nada específico, então ele faz a coleta de valores aleatórios entre 0 e 1023 porque a porta
fica em um estado flutuante, o que gera números aleatórios com um valor diferente toda
vez que o programa é iniciado, garantindo assim que as sequências geradas para nosso
Genius sejam diferentes a cada jogada. */
randomSeed(analogRead(0));
}




--------------------------------------------------------------ESPERARNOVOJOGO.INO--------------------------------------------------------------------------
/* Função para esperar até que um botão seja pressionado para iniciar um novo jogo. */
void esperarNovoJogo() {
/* Mensagem aguardando a ação do jogador para iniciar uma partida. */
Serial.println(“Pressione qualquer botão para iniciar...”);
/* Cria uma espera “infinita” por um botão. */
while (true) {
/* Verifica se um dos 4 botões foi pressionado. */
if (digitalRead(botaoAmarelo) == LOW || digitalRead(botaoAzul) == LOW || digitalRea-
d(botaoVerde) == LOW || digitalRead(botaoVermelho) == LOW) {
/* Aguarda o botão pressionado ser solto. */
while (digitalRead(botaoAmarelo) == LOW || digitalRead(botaoAzul) == LOW || digi-
talRead(botaoVerde) == LOW || digitalRead(botaoVermelho) == LOW) {};
tamanhoSequencia = 0; /* Reinicia o tamanho da sequência. */
gerarSequencia(); /* Gera uma nova sequência. */
tocarMusicaAbertura(); /* Toca a música de abertura com animação de LEDs. */
break;
}
}
}
