#include <stdio.h>
#include <stdlib.h>

void inverti_stringa(char *str);
int len(char *str);
void main(){
	char str[255];
	printf("Inserisci stringa: ");
	fgets(str, sizeof(str), stdin);
	inverti_stringa(str);
	fprintf(stdout, "str: %s\n", str);
}

void inverti_stringa(char *str){
	int size = len(str);
	char tmp;
	printf("Size: %d\n", size);
	int i = 0, j = size;
	while (i < j){
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}

}

int len(char *str){
	int i = 0;
	while (str[i] != '\0') i++;
	return i-1;
}
