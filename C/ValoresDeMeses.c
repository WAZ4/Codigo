#include <stdio.h>

float V[11];
char opc;

void listarValores(/* arguments */) {
  /* code */
  int i =0;
  for (i=0; i<12; i++){
    printf("\nMes: %d Valor: %f", (i + 1), V[i]);
  }
  /*
  fflush(stdin);
  char escapeKey;
  printf("\nPrima qualquer tecla para Voltar ao Menu? ");
  scanf("%c", &escapeKey);
  */
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

void menu(/* arguments */) {
  /* code */
  char opc;

  do {
    /* code */
    fflush(stdin);
    printf("\nEscolha uma opcao:");
    printf("\nI - Inserir\nL - Listar\nF - Fim\n");
    printf("Escolha a sua opcao: ");
    scanf("%c", &opc );

    switch (opc) {
      case 'I':
        inserirValor();
        break;
      case 'L':
        listarValores();
        break;
    }
  } while(opc != 'F');

}

int main(/* arguments */) {
  /* code */
  menu();
}
