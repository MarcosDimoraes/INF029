#include<stdio.h>
#define TAM 3
char tabuleiro [TAM][TAM];
void limpaTabuleiro();
void mostraTabuleito();
int verificaVencedor();
int main(){
	limpaTabuleiro();
	mostraTabuleito();
}
void limpaTabuleiro(){
	int i,j;
	for(i=0;i<TAM;i++)
		for(j=0;j<TAM;j++)
			tabuleiro[i][j]=' ';
}
void mostraTabuleito(){
	int i,j;
	puts("  1 2 3");
	for(i=0;i<TAM;i++){
		if (i) puts(" --+-+--");
		printf("%c",i+'A');
		for(j=0;j<TAM;j++){
			printf("%c",tabuleiro[i][j]);
			if(j)printf("|");
		}
		printf("\n");
	}
	//puts(" +-+-+-+");
}