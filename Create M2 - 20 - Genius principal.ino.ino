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
