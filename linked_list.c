#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int key;
	struct nodo *next;
}nodo;

void visualizza_lista(nodo *head);
void rimuovi_nodo(nodo **head, int value);

void main(){
	nodo *head = NULL;
	nodo *curr = NULL;
	int flag = 1;
	do{
		nodo *new_node = (nodo *) malloc(sizeof(nodo));
		if (new_node == NULL){
			 printf("Memoria terminata");
		}
		printf("Inserire valore nodo: ");
		scanf("%d", &new_node->key);
		new_node->next = NULL;

		if (head == NULL){
			head = new_node;
			curr = new_node;
		}else{
			curr->next = new_node;
			curr = new_node;
		}
		printf("Inserire nuovo nodo? 0/1 ");
		scanf("%d", &flag);
	}while(flag);

	rimuovi_nodo(&head, 11);
	visualizza_lista(head);
}


void visualizza_lista(nodo *head){
	nodo *curr = head;

	while (curr != NULL){
		printf("Key -> %d ;", curr->key);
		curr = curr->next;
	}

}


void rimuovi_nodo(nodo **head, int value) {
    nodo *curr = *head;
    nodo *prev = NULL;

    // Gestione del caso in cui il nodo da rimuovere sia `head`
    while (curr != NULL && curr->key == value) {
        *head = curr->next;
        free(curr);
        curr = *head;
    }

    // Scorre la lista per rimuovere altri nodi con il valore specificato
    while (curr != NULL) {
        if (curr->key == value) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}
