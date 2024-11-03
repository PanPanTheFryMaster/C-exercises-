#include <stdio.h>
#include <stdlib.h>


typedef struct operazioni{
	static int id;
	double importo;
	char tipologia[20];
	struct operazioni *next;
}operazioni;


void aggiungi_operazione(*operazioni head);
void visualizza_operazioni();
void filtra_tipo();
void calcola_saldo();
void rimuovi_operazione();

void main(){
	operazioni *head = NULL;
	int opzione = 0;
	while(1){
		printf("1 - Aggiungi operazione\n 2 - Visualizza operazioni\n 3 - Filtra per tipo\n 4 - Calcola Saldo\n 5 -  Rimuovi operazione \n\n\nScegli un'opzione: ");
		scanf("%d", &opzione);
		switch(opzione){
			case 1:
				aggiungi_operazione();
				break;
			case 2:
				visualizza_operazioni();
				break;
			case 3:
				filtra_tipo();
				break;
			case 4:
				calcola_saldo();
				break;
			case 5:
				rimuovi_operazione();
				break;
			default:
				break;
		}
	}
}


void aggiungi_operazione(operazioni *head){
	int operation;
	int importo;
	printf("Accredito o Addebito? 0/1");
	scanf("%d", &operation);
	printf("Importo: ");
	scanf("%d", &importo);
	operazioni *new_node = NULL;
	new_node = (operazioni *) malloc(sizeof(operazioni));
	if (head == NULL){
		head = new_node;
		new_node = new_node->next;
	}else{
		
	}
}
