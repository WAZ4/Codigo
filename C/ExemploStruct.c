#include <stdio.h>

struct Carta {
  int numero;
  char naipe;
};

int main() {
  struct Carta Baralho[52];
  Baralho[0].numero = 32;
  printf("%d", Baralho[0].numero);
}