#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
typedef struct{
	char nome[20];
	int eta;
	float media;
}studente;


void main(){
	studente *studenti;
	int flag = 1;
	int i = 0;
	char nome[20];
	int eta;
	float media;	
	while(flag){
		i++;
		studenti = (studente *) realloc(studenti, sizeof(studente) * (i+1));
		if (studenti == NULL) printf("Memoria esaurita");
		printf("inserire nome: ");
		fgets(nome, sizeof(nome), stdin);
		printf("inserire eta: ");
		scanf("%d", &eta);
		printf("inserire media: ");
		scanf("%f", &media);
		strcpy(studenti[i].nome,nome);
		studenti[i].eta = eta;
		studenti[i].media = media;
		

		printf("Vuoi inserire un nuovo studente? 0/1 \n");
		scanf("%d", &flag);
	}


	for (int j = 0; j < i; j++){
		printf("Nome: %s, Eta: %d, Media: %f\n",studenti[j].nome, studenti[j].eta, studenti[j].media);

	}

}
