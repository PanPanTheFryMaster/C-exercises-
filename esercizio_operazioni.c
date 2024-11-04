#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct operazioni{
	int id;
	double importo;
	char tipologia[20];
	struct operazioni *next;
} operazioni;

void aggiungi_operazione(operazioni **head, int *id_counter);
void visualizza_operazioni(operazioni *head);
void filtra_tipo(operazioni *head, char *tipo);
double calcola_saldo(operazioni *head);
void rimuovi_operazione(operazioni **head, int id);

int main() {
	operazioni *head = NULL;
	int opzione = 0;
	int id_counter = 1;

	while(1) {
		printf("\n1 - Aggiungi operazione\n2 - Visualizza operazioni\n3 - Filtra per tipo\n");
		printf("4 - Calcola Saldo\n5 - Rimuovi operazione\n\nScegli un'opzione: ");
		scanf("%d", &opzione);

		switch(opzione) {
			case 1:
				aggiungi_operazione(&head, &id_counter);
				break;
			case 2:
				visualizza_operazioni(head);
				break;
			case 3: {
				char tipo[20];
				printf("Inserisci il tipo di operazione da filtrare (Accredito/Addebito): ");
				scanf("%s", tipo);
				filtra_tipo(head, tipo);
				break;
			}
			case 4: {
				double saldo = calcola_saldo(head);
				printf("Il saldo totale è: %.2f\n", saldo);
				break;
			}
			case 5: {
				int id;
				printf("Inserisci l'ID dell'operazione da rimuovere: ");
				scanf("%d", &id);
				rimuovi_operazione(&head, id);
				break;
			}
			default:
				printf("Opzione non valida. Uscita dal programma.\n");
				return 0;
		}
	}
}

void aggiungi_operazione(operazioni **head, int *id_counter) {
	int operation;
	double importo;
	operazioni *new_node = (operazioni *) malloc(sizeof(operazioni));

	if (new_node == NULL) {
		printf("Memoria terminata\n");
		return;
	}

	new_node->id = (*id_counter)++;
	printf("Accredito o Addebito? (0 = Accredito, 1 = Addebito): ");
	scanf("%d", &operation);
	printf("Importo: ");
	scanf("%lf", &importo);

	new_node->importo = importo;
	strcpy(new_node->tipologia, (operation == 0) ? "Accredito" : "Addebito");
	new_node->next = NULL;

	if (*head == NULL) {
		*head = new_node;
	} else {
		operazioni *temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
	}

	printf("Operazione aggiunta con successo!\n");
}

void visualizza_operazioni(operazioni *head) {
	if (head == NULL) {
		printf("La lista è vuota.\n");
		return;
	}

	operazioni *temp = head;
	while (temp != NULL) {
		printf("ID: %d, Tipo: %s, Importo: %.2f\n", temp->id, temp->tipologia, temp->importo);
		temp = temp->next;
	}
}

void filtra_tipo(operazioni *head, char *tipo) {
	operazioni *temp = head;
	int found = 0;

	while (temp != NULL) {
		if (strcmp(temp->tipologia, tipo) == 0) {
			printf("ID: %d, Tipo: %s, Importo: %.2f\n", temp->id, temp->tipologia, temp->importo);
			found = 1;
		}
		temp = temp->next;
	}

	if (!found) {
		printf("Nessuna operazione trovata con tipo %s.\n", tipo);
	}
}

double calcola_saldo(operazioni *head) {
	double saldo = 0.0;
	operazioni *temp = head;

	while (temp != NULL) {
		saldo += (strcmp(temp->tipologia, "Accredito") == 0) ? temp->importo : -temp->importo;
		temp = temp->next;
	}

	return saldo;
}

void rimuovi_operazione(operazioni **head, int id) {
	operazioni *temp = *head;
	operazioni *prev = NULL;

	while (temp != NULL && temp->id != id) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		printf("Operazione con ID %d non trovata.\n", id);
		return;
	}

	if (prev == NULL) {
		*head = temp->next;
	} else {
		prev->next = temp->next;
	}

	free(temp);
	printf("Operazione rimossa con successo.\n");
}

