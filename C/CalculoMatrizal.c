#include <stdio.h>

int A [10][10];
int B [10][10];
int C [10][10];

void Matriz(char c) {
  int i, j;
    for (i=0; i<10; i++){
      for (j = 0; j<10; j++){
        if (c == 'A') {
          A[i][j] = (rand() % 10) + 1;
          printf("%.2d ", A[i][j] );
        }
        else if( c == 'B') {
          B[i][j] = (rand() % 10) + 1;
          printf("%.2d ", B[i][j] );
        }
        else if( c == 'C') {
        printf("%.2d ", (A[i][j] + B[i][j]) );
        }
      }
      printf("\n");
    }
    printf("\nMatriz %c Prenchida\n\n", c);
}
void main() {
  srand(time(0));
  Matriz('A');
  Matriz('B');
  Matriz('C');
}
