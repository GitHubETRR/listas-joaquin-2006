#include <stdio.h>
float numero;

int main (void){
    
printf("Ingrese su numero:");
scanf("%f", &numero);

    union{
float valor;
unsigned char bytes[4];
}var;

var.valor=numero;
printf("%x\n",var.bytes[0]);
printf("%x\n",var.bytes[1]);
printf("%x\n",var.bytes[2]);
printf("%x\n",var.bytes[3]);

}