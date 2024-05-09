#include <stdio.h>

int main() {
  char str[100];

  printf("Please enter your full name: ");
  scanf("%[^\n]s", str);
  printf("\nYour name is: %s", str);

  return 0;
}







