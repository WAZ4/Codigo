#include <stdio.h>
#include <string.h>
//Variaveis Globais
char frase[100];
char fraseCodificada[100];
int nivel;
// Inicio

void pedirFrase(){
	printf("Digite Frase Secreta: ");
	fflush(stdin);
	gets(frase);
}

void codificarFrase(){
	int i;
	int tamanhoDaFrase;
	tamanhoDaFrase = strlen(frase);
	
	for (i = 0; i<tamanhoDaFrase; i++){
		if (frase[i] != ' '){
			fraseCodificada[i] = '#';
		}
		else{
			fraseCodificada[i] = ' ';
		}
	}	
}

void limparEcra(){
	int i;
	for (i; i <= 500; i++){
		printf("\n");
	}
}

void inicio(){
	pedirFrase();
	codificarFrase();
	limparEcra();
}

void mostrarFraseCodificada(){
	printf("\nAdvinha uma letra desta Frase:");
	printf("\n%s", fraseCodificada);
}

char pedirLetra(){
	char c;
	printf("\nAdvinhe uma Letra: ");
	scanf("%c", &c);
	fflush(stdin);
	return c;
}

void avaliaLetra(char c){
	int i;
	int encontrou;
	encontrou = 0;
	
	for (i = 0; i < strlen(frase); i++){
		if (frase[i] == c){
			encontrou = 1;
			fraseCodificada[i] = c;
		}
	}
	if (encontrou == 0){
		nivel = nivel + 1;
	}

}

void mostrarForca(){
	  switch (nivel){
        
    case 0:
        printf("\n   ___");
	    printf("\n   |  |");
	    printf("\n   |");
	    printf("\n   |");
	    printf("\n   |");
	    printf ("\n   |");
	    printf("\n  ---");
        break;
    
    case 1:
        printf("\n   ___");
	    printf("\n   |  |");
	    printf("\n   |  o");
    	printf("\n   |");
    	printf("\n   |");
    	printf("\n   |");
    	printf("\n  ---");
        break;

    case 2:
        printf("\n   ___");
    	printf("\n   |  |");
    	printf("\n   |  o");
    	printf("\n   |  |");
    	printf("\n   |");
    	printf("\n   |");
    	printf("\n  ---");
        break;

    case 3:
    	printf("\n   ___");
    	printf("\n   |  |");
    	printf("\n   |  o");
    	printf("\n   | <|");
    	printf("\n   |");
    	printf("\n   |");
    	printf("\n  ---");
        break;
    

    case 4:
        printf("\n   ___");
    	printf("\n   |  |");
    	printf("\n   |  o");
    	printf("\n   | <|>");
    	printf("\n   |");
    	printf("\n   |");
    	printf("\n  ---");
        break;

    
    case 5:
    	printf("\n   ___");
    	printf("\n   |  |");
    	printf("\n   |  o");
	    printf("\n   | <|>");
    	printf("\n   | /");
	    printf("\n   |");
    	printf("\n  ---");
        break;
    

    case 6:
        printf("\n   ___");
    	printf("\n   |  |");
    	printf("\n   |  o");
    	printf("\n   | <|>");
    	printf("\n   | / \\  ");
    	printf("\n   |");
    	printf("\n  ---");
    	break;
    }

}

void processamento(){
	char c;
	int terminou = 0;
	nivel = 0;
	while (terminou == 0){
		mostrarFraseCodificada();
		c = pedirLetra();
		avaliaLetra(c);
		mostrarForca();
		if (!strcmp(frase, fraseCodificada)){
			terminou = 1;
		}
		if (nivel == 6){
			terminou = 1;
		}
	}
	mostrarFraseCodificada();
}

void fim(){
	char stop;
	printf("\n!!Acabou o jogo!!");
	scanf("%c", &stop);
	fflush(stdin);
	limparEcra();
}

void jogar(){
	inicio();
	processamento();
	fim();
}

void menu(){
	char opc;
	do{
		printf("\nJ - Jogar\nF - Fim");
		printf("\nEscolha a sua opcao: ");
		scanf("%c", &opc);
		fflush(stdin);
		if (opc == 'J'){jogar();}
	}while(opc != 'F');
}

void main(){
	menu();
}