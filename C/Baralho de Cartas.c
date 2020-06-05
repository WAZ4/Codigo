#include <stdio.h>

struct carta{
    char naipe;
    char numero;
    int valor;
    int posicao;
};

struct carta baralho[52];

void iniciarJogo(){
  
  int i;
  char carta;
  char naipe;
  int ctdCarta;
  int ctdNaipe;

  ctdCarta=0;
  ctdNaipe=0;
  
  for(i=0;i<52;i++){
    
    ++ctdCarta;
    if(ctdCarta>13){
      ctdCarta=1;
      ++ctdNaipe;
    }
    switch(ctdNaipe){
      case 0: naipe='C'; break;
      case 1: naipe='O'; break;
      case 2: naipe='P'; break;
      case 3: naipe='E'; break;
    }
    switch(ctdCarta){
      case 1: carta='A'; baralho[i].valor=14; break;
      case 2: carta='2'; baralho[i].valor=2; break;
      case 3: carta='3'; baralho[i].valor=3; break;
      case 4: carta='4'; baralho[i].valor=4; break;
      case 5: carta='5'; baralho[i].valor=5; break;
      case 6: carta='6'; baralho[i].valor=6; break;
      case 7: carta='7'; baralho[i].valor=7; break;
      case 8: carta='8'; baralho[i].valor=8; break;
      case 9: carta='9'; baralho[i].valor=9; break;
      case 10: carta='D'; baralho[i].valor=10; break;
      case 11: carta='J'; baralho[i].valor=11; break;
      case 12: carta='Q'; baralho[i].valor=12; break;
      case 13: carta='K'; baralho[i].valor=13; break;
    
    }
    baralho[i].numero=carta;
    baralho[i].naipe=naipe;
  }
}

int analisa(int n){
  int i;
  int a;
  a=0;//nao
    for(i=0;i<=51;i++){
      if(baralho[i].posicao==n){
        a=1;//sim
      }
    }
  return a; 
}

void baralhar(){
  int ctd;
  int numero;
  ctd=-1;
    while(analisa(0)==1){
      numero=(rand() %52)+1;
      if(analisa(numero)==0){
        ++ctd;
        baralho[ctd].posicao=numero;
      }
    }
}

void mostrarCartas(){
  int l;
  int naipe;
  for(l=0;l<52;l++){
    switch(baralho[l].naipe){
      case 'C': naipe= 3; break;
      case 'O': naipe= 4; break;
      case 'P': naipe= 5; break;
      case 'E': naipe= 6; break;
    } 
    printf("\n %c %c %2d %2d",baralho[l].numero,baralho[l].naipe,baralho[l].valor,baralho[l].posicao); 
  }
}

void ordenar(){
      int i, j, b, a, n = 52;
    char c, d;
      for (i = 0; i < n; ++i){

           for (j = i + 1; j < n; ++j)

           {

               if (baralho[i].posicao > baralho[j].posicao)

               {

                   a =  baralho[i].posicao;

                   baralho[i].posicao = baralho[j].posicao;

                   baralho[j].posicao = a;
                  
           b =  baralho[i].valor;

                   baralho[i].valor = baralho[j].valor;

                   baralho[j].valor = b;
                   
                   c =  baralho[i].naipe;

                   baralho[i].naipe = baralho[j].naipe;

                   baralho[j].naipe = c;
                  
           d =  baralho[i].numero;

                   baralho[i].numero = baralho[j].numero;

                   baralho[j].numero= d;


               }

           }

       }

}


void main(){
  srand(time(0));
  iniciarJogo();
  baralhar();
  ordenar();
  mostrarCartas();
}


/*

#include <stdio.h>

// A [X] [Y] X Valor da Carta; Y Posicao da Carta.
// B [X] [Y] X Numero da Carta; Y Naipe da Carta

char B[52][2];
int A[52][2];
 
int C=0;
int O=1;
int E=2;
int P=3;

int pontos;

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

void menu() {
    char opc;
    do{
        printf("\nEscolha Uma Opcao: ");
        printf("\n1 - Black Jack\n0 - Sair");
        printf("\nDigite a sua opcao: ");
        scanf("%c", &opc);

        switch (opc)
        {
        //case '1': limparEcra(), jogo1(); break;
        case '0': break;
        default: printf("Opcao Invalida!");
        }
        
    }while(opc != '0');
}

int main() {
   inicaJogo();
   baralhar();
   ordenar();
   mostrarCartas();
}
*/