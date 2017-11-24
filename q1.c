#include <stdio.h>

int q1(char *data){
	//char str[]="28/2/1938";
	int dia, mes, ano, valido;
	sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
	valido =1;
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
					valido = 0;
				break;
				case 4:
				case 6:
				case 9:
				case 11:
				if(dia<1&&dia>30)
					valido = 0;
				break;
				case 2:
				if(!(ano%400)||(!(ano%4)&&(ano%100))){
					if(dia<1||dia>29)
						valido=0;
				} else
				if(dia<1||dia>28)
					valido=0;
			}
		else valido = 0;
	else valido = 0;
	return valido;
}
int main(){
	char datainicial[]="31/03/2013";
	char datafinal[]="01/02/2014";
	int nDias, nMeses, nAnos;
	int diainicial,mesinicial,anoinicial;
	int diafinal,mesfinal,anofinal;
    int resposta = 1;
	if(q1(datainicial)==0) resposta = 2;
    if(q1(datafinal)==0) resposta = 3;
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
    
	printf("%d\n%d\n%d\n%d\n",nDias,nMeses,nAnos,resposta );;
}
