#include <stdio.h>

float numero;
int Bit_elegido = 0;
int Nuevo_valor_del_Bit= 0;
punt1byte_floatNum=1;

int main (void){
    
printf("Ingrese su numero: ");
scanf("%f", &numero);

    union{
float valor;
unsigned char bytes[15];
}var;

var.valor=numero;

for(int i=0; i<4; i++){
    printf(" %x /", var.bytes[i]);
}
do {
        printf("\n\nElige un bit del 0 al 4: ");
        scanf("%d", &Bit_elegido);

        if (Bit_elegido > 4 || Bit_elegido < 0) {
            printf("\nEl bit elegido es incorrecto. Por favor elige un número del 0 al 4.\n");
        } else {
            printf("\nBit elegido correctamente.\n");
        }
    } while (Bit_elegido > 4 || Bit_elegido < 1);

printf("Ahora eliga el nuevo valor del bit (0 o 1) del bit %d: ",Bit_elegido);
scanf("%d", &Nuevo_valor_del_Bit);

char * punt1byte_floatNum = &var;
    for (int i = 0; i < 4; i++){
        printf("\nByte %d del float: \n\t- HEX:%x\n\t- DEC:%d\n",i+1,*punt1byte_floatNum,*punt1byte_floatNum);
        punt1byte_floatNum++;
    }

 return 0;
}