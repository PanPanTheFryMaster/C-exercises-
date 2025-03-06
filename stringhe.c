#include <stdio.h>

int my_strlen(char str[]);

int main() {
  char str[100];
  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  const int size = my_strlen(str);
  printf("Lunghezza della stringa: %d\n", size);

  // Inverti la stringa
  int last = size - 1;
  for (int first = 0; first < last; first++, last--) {
    char tmp = str[first];
    str[first] = str[last];
    str[last] = tmp;
  }

  printf("Stringa invertita: %s\n", str);
  return 0;
}

int my_strlen(char str[]) {
  int count = 0;
  while (str[count] != '\0') {
    count++;
  }
  return count-1;
}
