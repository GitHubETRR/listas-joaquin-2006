//Esta es la version final, solo que mas lindo visualmente el codigo y un poco mas proligo
//Ademas de que le agregue de que sea hasta 10 bits.


#include <stdio.h>

int main(void) {
    float numero;
    int Bit_elegido = 0;
    int Nuevo_valor_del_Bit = 0;

    printf("Ingrese su numero: ");
    scanf("%f", &numero);

    union {
        float valor;
        unsigned char bytes[10];
    } var;

    var.valor = numero;

    for (int i = 0; i < 10; i++) {
        printf(" %x /", var.bytes[i]);
    }

    do {
        printf("\n\nElige un bit del 0 al 10: ");
        scanf("%d", &Bit_elegido);

        if (Bit_elegido > 10 || Bit_elegido < 0) {
            printf("\nEl bit elegido es incorrecto. Por favor elige un número del 0 al 10.\n");
        } else {
            printf("\nBit elegido correctamente.\n");
        }
    } while (Bit_elegido > 10 || Bit_elegido < 0);

    printf("Ahora elige el nuevo valor del bit (0 o 1) del bit %d: ", Bit_elegido);
    scanf("%d", &Nuevo_valor_del_Bit);

    unsigned char *punt1byte_floatNum = var.bytes;

    for (int i = 0; i < 10; i++) {
        printf("\nByte %d del float: \n\t- HEX:%x\n\t- DEC:%d\n", i + 1, *punt1byte_floatNum, *punt1byte_floatNum);
        punt1byte_floatNum++;
    }

    return 0;
}
