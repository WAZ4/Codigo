#include <stdio.h>

float V[11];
char opc;
int WTF = 1;

void listarValores(/* arguments */) {
  /* code */
  int i =0;
  for (i=0; i<12; i++){
    printf("\nMes: %d Valor: %f", (i + 1), V[i]);
  }
  fflush(stdin);
  char escapeKey;
  printf("\nPrima qualquer tecla para Voltar ao Menu? ");
  scanf("%c", &escapeKey);
}

void inserirValor(/* arguments */) {
  /* code */
  int mes;
  float valor;
  printf("\nMes a inserir?  ");
  scanf("%d", &mes);
  printf("\nValor a inserir no mes %d?  ", mes);
  scanf("%f", &valor);

  V[(mes - 1)] = valor;
}

void maiorValor(/* arguments */) {
  /* code */
  int i;
  float valHigh=0;
  int mes;
  for (i=0; i<12; i++){
    if (valHigh < V[i]){
      valHigh = V[i];
      mes = i+1;
    }
  }
  printf("\nO maior Valor obtido foi no mes %d e foi: %f\n", mes, valHigh);
}

void menorValor(/* arguments */) {
  /* code */
  int i;
  float valLow = V[1];
  int mes;
  for (i=0; i<12; i++){
    if (V[i] < valLow){
      valLow = V[i];
      mes = ++i;
    }
  }
  printf("\nO menor Valor obtido foi no mes %d e foi: %f\n", mes, valLow);
}

void menu(/* arguments */) {
  /* code */
  do {
    /* code */
    fflush(stdin);
    printf("\nEscolha uma opcao:");
    printf("\nI - Inserir\nL - Listar\n> - Maior Valor\n< - Menor Valor\nF - Fim\n");
    printf("Escolha a sua opcao: ");
    scanf("%c", &opc );

    switch (opc) {
      case 'I':
        inserirValor();
        break;
      case 'L':
        listarValores();
        break;
      case '<':
        menorValor();
        break;
      case '>':
        maiorValor();
        break;
    }
  } while(opc != 'F');

}

int main(/* arguments */) {
  /* code */
  menu();
}
