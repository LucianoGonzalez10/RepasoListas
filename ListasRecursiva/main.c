#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char nombre[20];
    int edad;
} persona;

typedef struct nodo
{
    persona dato;
    struct nodo *siguiente;
    struct nodo *anterior;
} nodo;

nodo * ingresarDatos(nodo * lista, persona dato);
nodo * iniclista();
nodo * crearNodo(persona dato);
nodo * buscarUltimo(nodo *lista);
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo);
void mostrarLista(nodo *lista);
int sumarLista(nodo * lista);


int main()
{
    nodo * lista = iniclista();
    nodo * nuevoNodo;
    persona dato;
    lista = ingresarDatos(lista, dato);
    mostrarLista(lista);
    return 0;
}

nodo * iniclista()
{
    return NULL;
}

nodo * ingresarDatos(nodo*lista, persona dato)
{
    char control = 's';
    printf("Desea cargar datos? \n");
    fflush(stdin);
    scanf("%c", &control);

    while(control == 's')
    {
        printf("Ingrese el nombre de la persona \n");
        fflush(stdin);
        scanf("%s", &dato.nombre);

        printf("Ingrese la edad de la persona \n");
        scanf("%d", &dato.edad);

        printf("Desea seguir cargando datos? \n");
        fflush(stdin);
        scanf("%c", &control);

        nodo * nuevoNodo = crearNodo(dato);
        lista = agregarFinal(lista, nuevoNodo);
    }
    return lista;
}

nodo * crearNodo(persona dato)
{
    nodo * aux = (nodo*) malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;

    return aux;
}
nodo * buscarUltimo(nodo *lista)
{
    nodo * seg = lista;
        while(seg->siguiente != NULL)
        {
            seg = seg -> siguiente;
        }
    return seg;
}
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}
void mostrarLista(nodo* lista)
{
    if(lista!=NULL)
    {
        printf("Nombre: %s ", lista->dato.nombre);
        printf("Edad: %d \n ",  lista->dato.edad);
        printf("--------------------------\n");
        mostrarLista(lista->siguiente);
    }
}

int sumarLista(nodo*lista)
{
    int suma = 0;
    if(lista != NULL)
    {
        suma = (lista->dato.edad) + sumarLista(lista->siguiente);
    }
    else
    {
        suma = sumarLista(lista->siguiente);
    }
    return suma;
}

nodo * borrarNodo(nodo* lista, int dato){
    if(lista != NULL){
        if(lista->dato.edad == dato){
            nodo * aBorrar = lista; /// Cuando encuentra el Nodo a borrar hace que apunte al dato.
            lista = lista->siguiente; /// Lista avanza y apunta al siguiente.
            free(aBorrar); /// Borro el nodo y libero el espacio de memoria que ocupaba ese dato.
        }
        else{
            lista->siguiente = borrarNodo(lista->siguiente, dato);
        }
    }
    return lista;
}

nodo* insertarEnOrden(nodo* lista, nodo* nuevoNodo){
    if(lista==NULL){
        lista = nuevoNodo;
    }
    else{
        if(nuevoNodo->dato.edad < lista->dato.edad){
            nuevoNodo->siguiente = lista;
            lista = nuevoNodo;
        }
        else{
            lista->siguiente = insertarEnOrden(lista->siguiente, nuevoNodo);
        }
    }
    return lista;
}
