#include <stdio.h>

int main (void){
    union{
float valor;
unsigned char bytes[4];
}var;



var.valor=-15;
printf("%x\n",var.bytes[0]);
printf("%x\n",var.bytes[1]);
printf("%x\n",var.bytes[2]);
printf("%x\n",var.bytes[3]);
}