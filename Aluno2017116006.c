// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Antonio MARCOS Vitoria de Moraes Filho
//  email: marcosmoraesf@gmail.com
//  Matrícula: 2017116006
//  Semestre: 2017.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016

// #################################################

#include <stdio.h>
#include <math.h>
#include <locale.h>
void locale(){
printf("\n****** Verificando a localidade corrente ********\n\n");
 printf ("Localidade corrente: %s\n", setlocale(LC_ALL,NULL) );
 printf("Não é possível usar acentuação ou ç corretamente...\n\n");
 
 printf("\n****** Alterando para a localidade do sistema ********\n\n");
 
 //alterando para o padrão do sistema operacional
 printf("A localidade corrente agora é %s \n",setlocale(LC_ALL,""));
 printf("Agora não tem mais problema algum!\n");
 printf("Já posso usar acentuação e também o caracter ç...\n\n\n");
}
/*
Q1 = validar data
@objetivo
Validar uma data
@entrada
uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
0 -> se data inválida
1 -> se data válida
*/
int q1(char *data){
    int datavalida = 1;
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    if(ano>0&&ano<10000)    
        if(mes>0&&mes<13)
            switch(mes){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                if(dia<1||dia>31)
                    datavalida = 0;
                break;
                case 4:
                case 6:
                case 9:
                case 11:
                if(dia<1||dia>30)
                    datavalida = 0;
                break;
                case 2:
                if(!(ano%400)||(!(ano%4)&&(ano%100))){
                    if(dia<1||dia>29)
                        datavalida=0;
                } else
                if(dia<1||dia>28)
                    datavalida=0;
                break;
            }
        else datavalida = 0;
    else datavalida = 0;
    if (datavalida)
        return 1;
    else
        return 0;
}

/*
Q2 = diferença entre duas datas
@objetivo
Calcular a diferença em anos, meses e dias entre duas datas
@entrada
uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
@saida
1 -> cálculo de diferença realizado com sucesso
2 -> datainicial inválida
3 -> datafinal inválida
4 -> datainicial < datafinal
*/
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    int nDias, nMeses, nAnos;
    int diainicial,mesinicial,anoinicial;
    int diafinal,mesfinal,anofinal;
    int resposta = 1;
    if(q1(datainicial)==0) 
        resposta = 2;
    if(q1(datafinal)==0) 
        resposta = 3;
    if(resposta<2){
        sscanf(datainicial, "%d/%d/%d", &diainicial, &mesinicial, &anoinicial);
        sscanf(datafinal, "%d/%d/%d", &diafinal, &mesfinal, &anofinal);
        nDias = diafinal - diainicial;
        nMeses = mesfinal - mesinicial;
        nAnos = anofinal - anoinicial;
        if (nAnos<0) resposta = 4;
        else if (nMeses<0 && nAnos<1) resposta = 4;
        else if (nDias<0 && nMeses<1 && nAnos<1) resposta = 4;
        if(nDias<0){
            nDias+=30;
            nMeses--;
        }
        if(nMeses<0) {
            nMeses+=12;
            nAnos--;
        }
    }
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;
    return resposta;
}


/*
Q3 = encontrar caracter em texto
@objetivo
Pesquisar quantas vezes um determinado caracter ocorre em um texto
@entrada
uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferências entre maiúsculos e minúsculos.
Se isCaseSensitive != 1, a pesquisa não deve  considerar diferências entre maiúsculos e minúsculos.
@saida
Um número n >= 0. 
*/
int q3(char *texto, char c, int isCaseSensitive){
    int i;
    int qtdOcorrencias = 0;
    if((isCaseSensitive==0) && c>='A' && c<='Z')
        c+='a'-'A';
    for(i=0;texto[i];i++){
        if(texto[i]==c)
            qtdOcorrencias++;
        if((isCaseSensitive==0)&&(texto[i]>='A')&&(texto[i]<='Z')&&(texto[i]==(c+'A'-'a')))
            qtdOcorrencias++;
    }
    return qtdOcorrencias;
}

/*
Q4 = encontrar palavra em texto
@objetivo
Pesquisar todas as ocorrências de uma palavra em um texto
@entrada
uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
@saida
Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
posicoes[0] = 13;
posicoes[1] = 16;
Observe que o índice da posição no texto deve começar ser contado a partir de 1.
O retorno da função, n, nesse caso seria 1;

*/
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    locale();
    for(int i=0;strTexto[i];i++)printf("[%d]:%c=%d\t\t",i,strTexto[i],strTexto[i]);
        puts("");
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

/*
Q5 = inverte número
@objetivo
Inverter número inteiro
@entrada
uma int num.
@saida
Número invertido
*/

int q5(int num){
    int acc=0;
    while(num>0){
        acc=acc*10+num%10;
        num/=10;
    }
    num=acc;
    return num;
}

/*
Q5 = ocorrência de um número em outro
@objetivo
Verificar quantidade de vezes da ocorrência de um número em outro
@entrada
Um número base (numerobase) e um número de busca (numerobusca).
@saida
Quantidade de vezes que número de busca ocorre em número base
*/

int q6(int numerobase, int numerobusca){
    int expoente=0;
    int qtdOcorrencias=0;
    int num = numerobase;
    int numb = numerobusca;
    while(numb>0){
        expoente++;
        numb/=10;
    }
    expoente = pow(10,expoente);
    while(num>0){
        if(num%expoente==numerobusca)
            qtdOcorrencias++;
        num/=10;

    }
    return qtdOcorrencias;
}