#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int * valores;
    int posTope;
}Pila;
int main()
{
    Pila p;
    return 0;
}

void inicpila(Pila * p){
    p->valores = malloc(50*sizeof(int));
    p->posTope = 0;
}

void apilar(Pila * p, int dato){
    p->valores[p->posTope] = dato;
    p->posTope = p->posTope + 1;
}

void leer(Pila * p, int dato){
    printf("Dime el dato a ingresar. \n");
    scanf("%d", &dato);
    apilar(p, dato);
}

int desapilar(Pila * p)
{
    int dato = -9999;

    if(p->posTope > 0)
    {
        dato = p->valores[p->posTope-1];
        (p->posTope)--;
    }
    else
    {
        printf("La pila esta vacia");
    }
    return dato;
}

int pilavacia(Pila * p){
    int vof = 0;
    if(p->posTope == 0){
            vof = 1;
    }
    return vof;
}

void mostrar(Pila* p){
    int i = 0;
    int vof = pilavacia(p);
    while(vof != 1){

    }
}


