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
