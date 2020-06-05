#include <stdio.h>

/*
 	R0 = [1.4;2.5]


	Recorri a este site para receber a percentagem de infetados por Idades
	https://olhardigital.com.br/coronavirus/noticia/descubra-se-voce-faz-parte-dos-grupos-mais-suscetiveis-ao-coronavirus/97694
*/

#define max 7000000
#define tempoDeTeste 20 // em meses

int numeroDeInfetados = 1, numeroDeMortos = 0, ctdDePessoas = 0,  geracao = 0;

struct pessoa {
		int infetado;
		int idade;
		int morta;
		int mes;
		int existe;
};

struct pessoa Infetados[max];

float geradorDeProbabilidade(int c, int idade) {
	/* 
		I --> Infetados
		M --> Mortos
	*/

	if (c == 'I') {
		
		/* 
			Estas variaveis calculao dois numeros random entre 14 e 25 para depois dividir por dez
		*/

		float probabilidade1 = (rand() % 12 + 14)/10;

		float probabilidade2 = (rand() % 12 + 14)/10;
		
		/*
			Com este conjunto de If's pretendo fazer mais provavel calhar de 2 
			para cima pois no artigo dizia que maior parte das vezes era 2 
		*/

		if (probabilidade1 >= 2.5 || probabilidade2/10 >= 2.5) {
			return 3;
		}

		else if (probabilidade1 >= 2.0 || probabilidade2 >= 2.0) {
			return 2;
		}
		
		else {
			return 1;
		}
	}
	
	else if (c == 'M') {

		// Nao usei Switch porque nao posso usar entrevalos num switch

		if (idade == 80) {
			return 0.148;
		}
		
		else if (idade >= 70) {
			return 0.08;
		}
		
		else if (idade >= 60) {
			return 0.036;
		}
		
		else if (idade >= 50) {
			return 0.013;
		}
		
		else if (idade >= 40) {
			return 0.004;
		}
		
		else if (idade >= 30) {
			return 0.002;
		}
		
		else if (idade >= 20) {
			return 0.002;
		}
		
		else {
			return 0.002;
		}

	}

	else{
		printf("\n\nErro!!");
	}
}

int geradorDeIdade() {
	int idade [100];
	int ctd, i;
	for (i=0; i<100; i++){

		if (i <= 1) {
			idade[i] = 80;
		}
		
		else if (i <= 10) {
			idade[i] = 70;
		}
		
		else if (i <= 28) {
			idade[i] = 60;
		}
		
		else if (i <= 50) {
			idade[i] = 50;
		}
		
		else if (i <= 68) {
			idade[i] = 40;
		}

		else if (i <= 85) {
			idade[i] = 30;
		}

		else if (i <= 94) {
			idade[i] = 20;
		}


		else if (i <= 100) {
			idade[i] = 10;
		}
		else break;
	}

	return idade[rand() % 100 ];
}

int verificarMorte(int idade) {

	float probabilidadeDeMorte = geradorDeProbabilidade('M', idade)*100;

	if (rand() % 100 < probabilidadeDeMorte) {
		return 1;
	}
	else {
		return 0;
	}


}

void mes() {
	int i, novosInfetados = 0 , novosMortos = 0, morta;
	
	geracao += 1;

	for (i = 1; i <= numeroDeInfetados; i++) {

		novosInfetados += geradorDeProbabilidade('I', 0);
	}

	/*
		Criar o perfil da pessoa infetada
	*/

	for (i = 1; i <= novosInfetados; i++) {
		Infetados[ctdDePessoas].infetado = 1;
		Infetados[ctdDePessoas].idade = geradorDeIdade();
		morta = verificarMorte(Infetados[ctdDePessoas].idade);
		Infetados[ctdDePessoas].morta = morta;
		Infetados[ctdDePessoas].mes = geracao;
		Infetados[ctdDePessoas].existe = 1;

		ctdDePessoas += 1;
		numeroDeMortos += morta;
	}

	numeroDeInfetados += novosInfetados;

}

void analiseDeTestes() {
	int i;

	for (i = 0; i<tempoDeTeste; i++){
		mes();
		printf("\n\n-----Mes %2d-----\nInfetados: %d\nMortos: %d", geracao, numeroDeInfetados, numeroDeMortos);
		}


}
int main() {
	srand (time(NULL));

	analiseDeTestes();

	scanf("%d");

}

/*
	Como fiz o Struct posso analizar todos os casos com um bocado de codigo tipo este:
	for (j = 1; j<max ; j++){
			
		if (Infetados[j].existe == 1) {
			printf("\n\nPessoa nr %d: Infetada = '%d' idade= '%d' morta = '%d' geracao = '%d' ", j, Infetados[j].infetado, Infetados[j].idade, Infetados[j].morta, Infetados[j].mes);
		}
		else break;
	}

*/