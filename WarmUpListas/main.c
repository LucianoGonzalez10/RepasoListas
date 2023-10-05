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
    struct nodo * siguiente;
} nodo;

nodo * iniclista();
nodo * crearNodo(persona dato);
nodo * agregarPrincipio(nodo * lista, nodo * nuevo);
nodo * agregarFinal(nodo * lista, nodo * nuevo);
nodo * buscarUltimo(nodo * lista);
nodo * cargarNodo(nodo * lista, persona dato);
void mostrar(nodo * lista);
void mostrarEspecifico(nodo * lista, int edadElegida);
void mostrarRecursivo(nodo * lista);
nodo * eliminarNodo(nodo * lista, int edadElegida);

int main()
{
    persona dato;
    nodo * lista = iniclista();
    lista = cargarNodo(lista, dato);

    printf("\n NORMAL: \n");
    mostrar(lista);

    printf("\n A ELECCION: \n");
    mostrarEspecifico(lista, 12);

    printf("\n RECURSIVA: \n");
    mostrarRecursivo(lista);


    int edadElegida = 15;
    lista = eliminarNodo(lista, edadElegida);
    printf("\n CON ELIMINACION: \n");
    mostrar(lista);

    return 0;
}

nodo * iniclista()
{
    return NULL;
}

nodo * crearNodo(persona dato)
{
    nodo * nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodo * agregarPrincipio(nodo * lista, nodo * nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
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
    }
    return lista;
}

nodo * buscarUltimo(nodo * lista)
{
    nodo * ultimo = lista;
    while(ultimo->siguiente != NULL)
    {
        ultimo = ultimo->siguiente;
    }
    return ultimo;
}
nodo * cargarNodo(nodo * lista, persona dato)
{
    char control = 's';

    printf("Desea cargar datos? \n");
    fflush(stdin);
    scanf("%c", &control);

    while(control == 's')
    {
        printf("Dime el nombre a cargar: \n");
        fflush(stdin);
        scanf("%s", &dato.nombre);

        printf("Dime la edad a cargar: \n");
        scanf("%d", &dato.edad);

        nodo * nuevo = crearNodo(dato);
        lista = agregarFinal(lista, nuevo);

        printf("Desea seguir cargando datos? \n");
        fflush(stdin);
        scanf("%c", &control);

    }
    return lista;
}

void mostrar(nodo * lista)
{
    nodo * seg = lista;
    if(seg != NULL)
    {
        while(seg != NULL)
        {
            printf("Nombre: %s \n", seg->dato.nombre);
            printf("Edad: %d \n", seg->dato.edad);
            printf("---------------------\n");
            seg = seg->siguiente;
        }
    }
}

void mostrarEspecifico(nodo * lista, int edadElegida)
{
    nodo * seg = lista;
    if(seg != NULL)
    {
        while(seg != NULL)
        {
            if(seg->dato.edad == edadElegida)
            {
                printf("Nombre: %s \n", seg->dato.nombre);
                printf("Edad: %d \n", seg->dato.edad);
                printf("---------------------\n");
            }
            seg = seg->siguiente;
        }
    }
}

void mostrarRecursivo(nodo * lista)
{
    nodo * seg = lista;
    if(seg != NULL)
    {
        printf("Nombre: %s \n", seg->dato.nombre);
        printf("Edad: %d \n", seg->dato.edad);
        printf("---------------------\n");
        mostrarRecursivo(lista->siguiente);
    }
}

nodo * eliminarNodo(nodo * lista, int edadElegida)
{
    nodo * seg;
    nodo * ante;
    if((lista != NULL) && (seg->dato.edad == edadElegida))
    {
        nodo * aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else{
        seg = lista;
        while((seg != NULL) && (seg->dato.edad != edadElegida)){
                ante = seg;
                seg = seg->siguiente;
        }
        if(seg!= NULL){
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}
