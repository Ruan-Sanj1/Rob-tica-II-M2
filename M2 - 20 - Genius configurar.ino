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
