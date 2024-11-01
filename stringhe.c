#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void conta_occorrenze(char *str);

void main(){
	char str[255];
	printf("Inserisci una stringa: ");
	fgets(str, sizeof(str), stdin);
	printf("str: %s\n", str);
	int i = 0;
	while(str[i] != '\0'){
		if (str[i] >= 'A' && str[i] <= 'Z'){
			 str[i] = str[i] + 32;
		}else if (str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 32;
		i++;
	}
	printf("str con valori invertiti: %s\n", str);
	char tmp;
	int count = 0;
	for (int j = strlen(str)-1; j > count; j--){
		tmp = str[j];
		str[j] = str[count];
		str[count] = tmp;
		count++;
	}
	printf("str inversa: %s\n", str);
	// Conta il massimo numero di occorrenze della stessa lettera
	conta_occorrenze(str);
}


void conta_occorrenze(char *str){
	int count[strlen(str)-1];
	int max_count = 0;
	int saved = 0;
	int sum;
	for (int i = 0; i < strlen(str); i++){
		sum = 1;
		for(int j = i +1; j < strlen(str); j++){
			if (str[i] == str[j]) sum += 1;
		}
		count[i] = sum;
	}

	for (int i = 0; i < (strlen(str) -1); i++){
		if (count[i] > max_count){
			max_count = count[i];
			saved = i;
		}
	}

	printf("Top occurrence: %c, %d \n", str[saved],max_count); 

}
