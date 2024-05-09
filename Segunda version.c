//En esta version, le agrega la funcion "%[^\n]%*c" porque a la hora de escribir el nombre de la serie, este tenga nombre con espacio... mas tecnico, quiero escribir un carácter o una cadena, según lo que queramos lograr.
//en este caso, quiero que el caracter tenga espacios, El carácter scanset para esta instancia es []. El carácter ^\n le indica al sistema operativo que continúe leyendo la entrada del usuario hasta que encuentre una nueva línea, Por lo tanto, lo escribimos como %[n]s en lugar de %s. Por lo tanto, para obtener una línea de entrada que contenga espacios.
//Y por ultimo, acomode un poco mejor los printf y ademas de que modifique dentro de la struct, que en vez de edad, sea episodios...
//Y acalaracion la línea while(getchar() != '\n'); en la función pedir_datos() se utiliza para limpiar el buffer de entrada después de que se ha leído el número de episodios.
//Esto porque cuando utilizas scanf() para leer un número entero (%d), se lee el número, pero el carácter de nueva línea (\n) que presionas después de ingresar el número permanece en el buffer de entrada. Esto puede causar problemas en las lecturas posteriores, especialmente si se están utilizando funciones de entrada como scanf() o fgets().
//El bucle while que se utiliza en esta línea continúa llamando a getchar() hasta que lee y descarta todos los caracteres restantes en el buffer de entrada, incluyendo el carácter de nueva línea.
#include <stdio.h>
#include <stdlib.h>
#define MAX_AL 30
#define SALIR 3
typedef struct Series{
    char Nombre[30];
    int Episodios;
    struct Series *next;
}alumno_t; 

alumno_t * curso1925=NULL;
void menu(void);
void imprimir_Series(alumno_t);
void pedir_datos(alumno_t * Series);
void ver_lista(void);
void cargar_Series(void);
void liberar_memoria(void);

int main(){
    menu();
    liberar_memoria();
    return 0;
}

void imprimir_Series(alumno_t Series){
    printf("----------------------------------\n");
    printf("Nombre: %s\n",Series.Nombre);
    printf("Episodios: %d\n",Series.Episodios);
    printf("----------------------------------\n");

}
void pedir_datos(alumno_t * Series){
    printf("\n¿Cual es el nombre de la serie?:");
    scanf(" %[^\n]%*c", Series->Nombre);
    printf("¿Cuantos episodios tiene la serie?:");
    scanf("%d",&(Series->Episodios));
    while(getchar() != '\n');
    printf("\n");
}



void menu(void){
    int opcion;
    do{
        printf("Opcion N°1= Cargar una nueva serie\n");
        printf("Opcion N°2= Ver todas las series cargadas\n");
        printf("Opcion N°3= Salir\n\n");
        printf("Tu opcion elegida es: ");
        scanf("%d",&opcion);
        if(opcion==1)cargar_Series();
        if(opcion==2)ver_lista();
    }while(opcion!=SALIR);
    
}

void cargar_Series(){
    alumno_t *alumno_aux;
    alumno_aux=malloc(sizeof(alumno_t));
    if(alumno_aux==NULL){
        printf("Out of memory\n");
    }else{
        pedir_datos(alumno_aux);
        alumno_aux->next=curso1925;
        curso1925=alumno_aux;
    }
     
        
}

void ver_lista(void){
    alumno_t *lista=curso1925;
    while(lista!=NULL){
        imprimir_Series(*lista);
        lista=lista->next;
    }
}
void liberar_memoria(void){
    alumno_t *aux=NULL;
    while(curso1925!=NULL){
        aux=curso1925;
        curso1925=curso1925->next;
        free(aux);

    }
    
}









