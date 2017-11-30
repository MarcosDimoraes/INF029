#include <stdio.h>
#include <string.h>

int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias=-1;
    int iTexto, achou, iBusca, inicio;
    iTexto = achou = 0;
    while(strTexto[iTexto]){
        iBusca = 0;
        if (strTexto[iTexto]==strBusca[iBusca]){
            achou = 1;
            inicio = iTexto+1;
            while(achou&&strBusca[iBusca]){
                if(strTexto[iTexto++]!=strBusca[iBusca++])
                    achou = 0;
            }
            if(achou){
                qtdOcorrencias++;
                posicoes[qtdOcorrencias*2]=inicio;
                posicoes[qtdOcorrencias*2+1]=iTexto;
            }else
                iTexto = --inicio;
        }
        iTexto++;
    }
    return ++qtdOcorrencias;
}
int main(){
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Laboratorio de programacao: para ratos de programacao");
    strcpy(strBusca,"rato");
    printf("ocorrencias %d\n",q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n",posicoes[0]==5);
    printf("%d\n",posicoes[1]==8);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==37);
    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Ola, o mundo e muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca,"mui");
    printf("ocorrencias %d\n",q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n",posicoes[0]==16);
    printf("%d\n",posicoes[1]==18);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==36);
    printf("%d\n",posicoes[4]==52);
    printf("%d\n",posicoes[5]==54);
}
