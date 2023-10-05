#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

typedef struct
{
    char nombre[20];
    int edad;
} Persona;

typedef struct nodo
{
    Persona dato;
    struct nodo * siguiente;
    struct nodo * anterior;
} nodo;

nodo * iniclista();
nodo * crearNodo(Persona dato);
nodo * agregarFinal(nodo * lista, nodo * nuevo);
nodo * buscarUltimo(nodo * lista);
nodo * cargarNodo(nodo * lista, Persona dato);

int main()
{
    Persona dato;
    nodo * lista = iniclista();
    lista = cargarNodo(lista, dato);
    mostrar(lista);
    return 0;
}

nodo * iniclista()
{
    return NULL;
}

nodo * crearNodo(Persona dato)
{
    nodo * nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    return nuevo;
}

nodo * agregarFinal(nodo * lista, nodo * nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
    return lista;
}

nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;
    while(seg->siguiente != NULL)
    {
        seg = seg->siguiente;
    }
    return seg;
}

nodo * cargarNodo(nodo * lista, Persona dato)
{
    char control = 's';
    printf("Desea cargar datos? \n");
    fflush(stdin);
    scanf("%c", &control);

    while(control == 's' || control == 'S')
    {
        printf("Dime el nombre de la persona: \n");
        fflush(stdin);
        scanf("%s", &dato.nombre);

        printf("Dime la edad de la persona: \n");
        scanf("%d", &dato.edad);

        nodo * nuevo = crearNodo(dato);
        lista = agregarFinal(lista, nuevo);

        printf("Desea cargar datos? \n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return lista;
}

void mostrar(nodo * lista){
    nodo * seg = lista;
    while(seg != NULL){
        printf("Nombre: %s \n", seg->dato.nombre);
        printf("Edad: %d \n", seg->dato.edad);
        seg = seg->siguiente;
    }
}


