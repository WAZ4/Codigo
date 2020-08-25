#include <stdio.h>

int pontos = 100;
int aposta;
// A [X] [Y] X Valor da Carta; Y Posicao da Carta.
// B [X] [Y] X Numero da Carta; Y Naipe da Carta

char B[52][2];
int A[52][2];

// dealer [X] [Y] X Numero da Carta; Y Naipe da Carta
// joagador1 [X] [Y] X Numero da Carta; Y Naipe da Carta

char dealer[10][10];
char jogador1[10][10];

int C=0;
int O=1;
int E=2;
int P=3;

int pontos;

int carta;

// Preparar Jogo

void inicaJogo() {
   int e;
   char carta;
   char naipe;
   int ctdNaipe=0;
   int ctdCarta=0;
   pontos = 100;
   for (e = 0;e < 52;e++) {
       ++ctdCarta;
       if (ctdCarta > 13) {
           ctdCarta = 1;
           ++ctdNaipe;
       }
       switch (ctdNaipe) {
           case 0: naipe = 'C';break;
           case 1: naipe = 'O';break;
           case 2: naipe = 'E';break;
           case 3: naipe = 'P';break;
       }
       switch (ctdCarta) {
           case 1: carta='A'; A[e][0] = 14;break;
           case 2: carta='2'; A[e][0] = 2;break;
           case 3: carta='3'; A[e][0] = 3;break;
           case 4: carta='4'; A[e][0] = 4;break;
           case 5: carta='5'; A[e][0] = 5;break;
           case 6: carta='6'; A[e][0] = 6;break;
           case 7: carta='7'; A[e][0] = 7;break;
           case 8: carta='8'; A[e][0] = 8;break;
           case 9: carta='9'; A[e][0] = 9;break;
           case 10:carta='D'; A[e][0] = 10;break;
           case 11:carta='J'; A[e][0] = 11;break;
           case 12:carta='Q'; A[e][0] = 12;break;
           case 13:carta='K'; A[e][0] = 13;break;
       }
       B[e][0]=carta;
       B[e][1]=naipe;
      
   }
   for (e = 0; e<52;e++) {
       A[e][1] = 0;
   }
}
 
int analisa(int n) {
   int i, flag = 0;
   for (i = 0; i<52; i++) {
       if (A[i][1] == n) {
           flag = 1;
       }
   }
   return flag;
}
 
 
void baralhar() {
   srand(time(0));
   //printf(" %d ", (rand() % 52)+1);
   int n, i, ctd = -1;
  
   while (analisa(0) == 1) {
       n = (rand() % 52)+1;
       for (i = 0; i<52; i++) {
           if (analisa(n) == 0) {
               ++ctd;
               A[ctd][1] = n;
           }
       }
   }
}
 
void ordenar() {
       int i, j, a, b, n = 52;
       char c, d;
 
       for (i = 0; i < n; ++i)
       {
           for (j = i + 1; j < n; ++j)
           {
               if (A[i][1] > A[j][1])
               {
                  
                   a =  A[i][1];
                   A[i][1] = A[j][1];
                   A[j][1] = a;
 
                   b =  A[i][0];
                   A[i][0] = A[j][0];
                   A[j][0] = b;
 
 
                   c =  B[i][1];
                   B[i][1] = B[j][1];
                   B[j][1] = c;
                   d =  B[i][0];
                   B[i][0] = B[j][0];
                   B[j][0] = d;
               }
           }
       }
}
 
void mostrarCartas() {
   int e;
   int naipe;
   for (e = 0; e<52; e++) {
      
       switch(B[e][1]) {
           case 'C': naipe = 3;break;
           case 'O': naipe = 4;break;
           case 'E': naipe = 5;break;
           case 'P': naipe = 6;break;
       }
 
       if (B[e][0] == 'D') {
           printf("\n%d %c %d %d", 10, B[e][1], A[e][0], A[e][1]);           
       }
       else {
           printf("\n%c %c %d %d", B[e][0], B[e][1], A[e][0], A[e][1]);
       }
   }
}


void desenhar(char valor, char naipe) {
  if (valor == 'A' || valor == 'J' || valor == 'Q' || valor == 'K') {
    printf("\n _______");
    printf("\n|%c      |", valor);
    printf("\n|       |");
    printf("\n|   %c   |", naipe);
    printf("\n|       |");
    printf("\n|      %c|", valor);
    printf("\n|_______|");
    }
   else if( valor == 'D'){
    printf("\n _______");
    printf("\n|%s     |","10");
    printf("\n|       |");
    printf("\n|   %c   |", naipe);
    printf("\n|       |");
    printf("\n|     %s|","10");
    printf("\n|_______|");
   }
  else {
    printf("\n _______");
    printf("\n|%c      |", valor);
    printf("\n|       |");
    printf("\n|   %c   |", naipe);
    printf("\n|       |");
    printf("\n|      %c|", valor);
    printf("\n|_______|");
    }
}



int traduzCarta(char c, int total) {
  switch (c) {
    case 'A':
      if (total > 10)return 1;
      else return 11;
    case '2': return 2; break;
    case '3': return 3; break;
    case '4': return 4; break;
    case '5': return 5; break;
    case '6': return 6; break;
    case '7': return 7; break;
    case '8': return 8; break;
    case '9': return 9; break;
    case 'D': return 10;break;
    case 'J': return 10;break;
    case 'Q': return 10;break;
    case 'K': return 10;break;
    default: return 0;
  }
}

void limparEcra() {
  int i;
  for (i = 0; i < 100; i++){
    printf("\n\n");
  }
}

void pedeAposta() {
  int flag = 0;
  limparEcra();
  do {
    printf("\nQuanto quer apostar? ");
    scanf("%d", &aposta);
    fflush(stdin);

    if (aposta <= pontos && aposta > 0){ 
      flag = 1;
    }
    else {
      printf("Voce nao tem %d pontos para apostar", aposta);
    }
  }while (flag == 0);
  limparEcra();
}

// Jogo1

int analisaJogo(int dealer, int jogador1, int a) {
  if (a == 0){
    if (dealer == jogador1) {
      return 3;
    }
    else if (dealer >= 21 || jogador1 == 21) {
      return 2;
    }
    else if (jogador1 >= 21 || dealer == 21) {
      return 1;
    }
    else {
      return 0;
    }
  }
  else{
    if (dealer == jogador1) {
      return 3;
    }
    else if (dealer >= 21 || (jogador1 > dealer && jogador1 <= 21)) {
      return 2;
    }
    else if (jogador1 >= 21 || (dealer > jogador1 && dealer <= 21)) {
      return 1;
    }
    else {
      return 0;
    }
  }
}

void mostrarCartasDealer(int nrCartas) {
  int i;
  for (i = 0; i < nrCartas; i++) {
    desenhar(dealer[i][0], dealer[i][1]);
  }

}

void mostrarCartasJogador1(int nrCartas) {
  int i;
  for (i = 0; i < nrCartas; i++) {
    desenhar(jogador1[i][0], jogador1[i][1]);
  }
}

void jogo1() {
  int pede = 0, cartasDealer = 0, cartasJogador1 = 0, totalDealer = 0, totalJogador1 = 0, acabouJogo = 0; // Se acabouJogo doe 0 o jogo ainda esta a andar se for 1 o dealer Ganha se for 2 o Jogador1 ganha
  //                                                                                               Se for 3 e um Empate
  char pedeCarta;

  //Distribuir as primeiras cartas
  printf("\nCartas do Dealer:\n");
  desenhar(B[carta][0], B[carta][1]);
  dealer[cartasDealer][0] = B[carta][0];
  dealer[cartasDealer][1] = B[carta][1];
  totalDealer += traduzCarta(dealer[cartasDealer][0], totalDealer);
  printf("\nTotal das Cartas: %d", totalDealer);

  carta += 1;
  cartasDealer += 1;

  printf("\nCartas do Jogador1:\n");
  desenhar(B[carta][0], B[carta][1]);
  jogador1[cartasJogador1][0] = B[carta][0];
  jogador1[cartasJogador1][1] = B[carta][1];
  totalJogador1 += traduzCarta(jogador1[cartasJogador1][0], totalJogador1);
  printf("\nTotal das Cartas: %d", totalJogador1);

  carta += 1;
  cartasJogador1 += 1;

  printf("\n Mais uma carta - S\n");
  printf("\n Dobrar Aposta - D\n");
  printf("\n Passar - N\n");
  printf("\n \n");
  scanf("%c", &pedeCarta);
  fflush(stdin);

  limparEcra();
    

  do {

    if (pede == 1){

      printf("\n Mais uma carta - S");
      printf("\n Passar - N\n Opcao: ");
      scanf("%c", &pedeCarta);
      fflush(stdin);

      limparEcra();
    }

    if (pedeCarta == 'S') {
      printf("\n\nCartas do Dealer:\n");
      mostrarCartasDealer(cartasDealer);
      printf("\nTotal das Cartas: %d", totalDealer);

      printf("\n\nCartas do Jogador1:\n");
      mostrarCartasJogador1(cartasJogador1);
      desenhar(B[carta][0], B[carta][1]);
      jogador1[cartasJogador1][0] = B[carta][0];
      jogador1[cartasJogador1][1] = B[carta][1];
      totalJogador1 += traduzCarta(jogador1[cartasJogador1][0], totalJogador1);
      printf("\nTotal das Cartas: %d", totalJogador1);

      carta += 1;
      cartasJogador1 += 1;
      pede = 1;

    }
    else if(pedeCarta == 'D'){
      printf("\n\nCartas do Dealer:\n");
      mostrarCartasDealer(cartasDealer);
      printf("\nTotal das Cartas: %d", totalDealer);

      printf("\n\nCartas do Jogador1:\n");
      mostrarCartasJogador1(cartasJogador1);
      desenhar(B[carta][0], B[carta][1]);
      jogador1[cartasJogador1][0] = B[carta][0];
      jogador1[cartasJogador1][1] = B[carta][1];
      totalJogador1 += traduzCarta(jogador1[cartasJogador1][0], totalJogador1);
      printf("\nTotal das Cartas: %d", totalJogador1);

      carta += 1;
      cartasJogador1 += 1;
      pedeCarta = 'N';
      pede = 0;
      aposta *= 2;
    }
    else if (pedeCarta == 'N') {
      do{
        carta += 1;
        dealer[cartasDealer][0] = B[carta][0];
        dealer[cartasDealer][1] = B[carta][1];
        totalDealer += traduzCarta(dealer[cartasDealer][0], totalDealer);

        cartasDealer += 1;

        printf("\n\nCartas do Dealer:\n");
        mostrarCartasDealer(cartasDealer);
        printf("\nTotal das Cartas: %d", totalDealer);

        printf("\n\nCartas do Jogador1:\n");
        mostrarCartasJogador1(cartasJogador1);
        printf("\nTotal das Cartas: %d", totalJogador1);
      }while ((totalJogador1 >= totalDealer) && totalDealer <= 17);
      break;
    }
    acabouJogo = analisaJogo(totalDealer, totalJogador1, 0);
  } while(acabouJogo == 0);
      
  switch (analisaJogo(totalDealer, totalJogador1, 1)) {
    case 1: printf("\n\n\n\n    !!!Perdeu!!!    \n\n\n"); pontos -= aposta; break;
    case 2: printf("\n\n\n\n    !!!Ganhou!!!    \n\n\n"); pontos += aposta; break;
    case 3: printf("\n\n\n\n    !!!Empate!!!    \n\n\n"); break;
    }
  }

void limparJogo() {
  int i;
  for (i=0; i<10; i++) {
    dealer[i][0] = '0';
    dealer[i][1] = '0';

    jogador1[i][0] = '0';
    jogador1[i][1] = '0';
  }
}

void menu() {
  char opc;
  do{
    printf("\n!!!Bem Vindo ao Casino!!!\n Voce tem %d pontos\n   A - BlackJack\n   B - Sair", pontos);
    printf("\nEscolha Uma Opcao: ");
    scanf("%c", &opc);
    fflush(stdin);

    switch (opc) {
      case 'A': limparEcra(); pedeAposta(); jogo1(); aposta = 0; break;
      case 'B': break;
      default: printf("Opcao Invalida Digite outra vez!");
    }
  }while(opc != 'B');
}
/*
void desenharDuas(char valor1, char naipe1, char valor2, char naipe2) {
  char val1 [2];
  char val2 [2];
  if (valor1 == 'D') {
    val1[0] = '1';
    val1[1] = '0';
  }
  else {
    val1[0] = valor2;
    val1[1] = ' ';
  }
  if (valor2 == 'D') {
    val2[0] = '1';
    val2[1] = '0';
  }
  else {

    val2[0] = valor2;
    val2[1] = ' ';
  }

  printf("\n _______");                        printf("    _______"); 
  printf("\n|%c%c     |", val1[0], val1[1]);   printf("  |%c%c     |", val2[0], val2[1]);
  printf("\n|       |");                       printf("  |       |");
  printf("\n|   %c   |", naipe1);               printf("  |   %c   |", naipe2);
  printf("\n|       |");                       printf("  |       |");
  printf("\n|     %c%c|", val1[0], val1[1]);   printf("  |     %c%c|", val2[0], val2[1]);
  printf("\n|_______|");                       printf("  |_______|");

}
*/

int main() {
   inicaJogo();
   baralhar();
   ordenar();
//   mostrarCartas();
   menu();
   limparJogo();
   }