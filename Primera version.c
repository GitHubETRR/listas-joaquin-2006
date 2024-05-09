//En esta version, lo unico que hice fue acomodar un poco mejor las cosas cuando se imprimen.
//Ademas de que quiero que sea una lista de series en el que te muestre cuantos episodios tiene


#include <stdio.h>
#include <stdlib.h>
#define MAX_AL 30
#define SALIR 3
typedef struct Series{
    char Nombre[30];
    int Edad;
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
    printf("Nombre: %s\n",Series.Nombre);
    printf("Episodios: %d\n",Series.Edad);
    printf("+++++++++++++++++++++++\n");

}
void pedir_datos(alumno_t * Series){
    printf("\n¿Cual es el nombre de la serie?:\n");
    scanf("%s",Series->Nombre);
    printf("¿Cuantos empisodios tiene la serie?:\n");
    scanf("%d",&(Series->Edad));

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



