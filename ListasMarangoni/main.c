#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

/// Dato Abstracto: Es un tipo de dato definido por el programador que se puede manipular de modo similar a los tipos de datos definidos por el sistema.
/// El Dato Abstracto tiene una identidad, un compartamiento y es independiente del lenguaje. Por ejemplo Pilas.

typedef struct
{
    char nombre[20];
    int edad;
} Persona;

typedef struct nodo
{
    Persona dato;
    struct nodo * siguiente;
} nodo;

nodo * iniclista();
nodo * crearNodo(Persona dato);
nodo * agregarPrincipio(nodo * lista, nodo * nuevo);
nodo * agregarFinal(nodo * lista, nodo * nuevo);
nodo * buscarUltimo(nodo * lista);
nodo * cargarNodos(Persona dato, nodo * lista);
nodo * intercalarNodos(nodo * lista, nodo * lista2);
nodo * invertirLista(nodo * lista);
nodo * borrarNodo(nodo * lista, char nombre[20]);

int main()
{
    Persona dato;
    nodo * lista = iniclista(); /// CREAMOS UNA LISTA.
    nodo * nuevo;
    lista = cargarNodos(dato, lista);

    /* nodo * lista2 = iniclista();
    lista2 = cargarNodos(dato, lista2);

    nodo * lista3;
    lista3 = intercalarNodos(lista, lista2);
    mostrar(lista3);

    printf("-----------------------------\n");

    nodo * invertido;
    invertido = invertirLista(lista);
    mostrar(invertido); */

    /* char nombre[20];
    printf("Dime el nombre a buscar: \n");
    fflush(stdin);
    scanf("%s", &nombre);

    int vof = buscarElemento(lista, nombre);

    if(vof == 1)
    {
        printf("EL NOMBRE ESTA EN LA LISTA \n");
    }
    else
    {
        printf("EL NOMBRE NO ESTA EN LA LISTA. \n");
    } */

    char nombre[20];
    printf("Ingrese el nombre del nodo a eliminar \n");
    fflush(stdin);
    scanf("%s", &nombre);

    lista = borrarNodo(lista, nombre);
    mostrar(lista);

    return 0;
}

nodo * iniclista()
{
    return NULL;
}

nodo * crearNodo(Persona dato)
{
    nodo * aux = (nodo*) malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;

    return aux;
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
    nodo * seg = lista;
    while(seg->siguiente != NULL)
    {
        seg = seg->siguiente;
    }
    return seg;
}

nodo * cargarNodos(Persona dato, nodo * lista)
{
    char control = 's';

    printf("Desea cargar datos? \n");
    fflush(stdin);
    scanf("%c", &control);

    while(control == 's' || control == 'S')
    {
        printf("Dime el nombre de la persona a cargar: \n");
        fflush(stdin);
        scanf("%s", &dato.nombre);

        printf("Dime la edad de la persona: \n");
        scanf("%d", &dato.edad);

        printf("Desea seguir cargando datos? \n");
        fflush(stdin);
        scanf("%c", &control);

        nodo * nuevo = crearNodo(dato);
        lista = agregarFinal(lista, nuevo);
    }

    return lista;
}

void mostrar(nodo * lista)
{
    while(lista != NULL)
    {
        printf("Nombre: %s\n", lista->dato.nombre);
        printf("Edad: %d \n", lista->dato.edad);
        lista = lista->siguiente;
    }
}

int buscarElemento(nodo * lista, char nombre[])
{
    int vof = 0;
    while(lista != NULL)
    {
        if(strcmpi((lista->dato.nombre), nombre) == 0)
        {
            vof = 1;
        }
        lista = lista->siguiente;
    }
    return vof;
}

nodo * intercalarNodos(nodo * lista, nodo * lista2)
{
    nodo * lista3;
    lista3 = iniclista();
    nodo * seg = lista;
    nodo * seg2 = lista2;

    while(seg != NULL || seg2 != NULL)
    {
        if(seg != NULL)
        {
            nodo *aux = seg;
            seg=seg->siguiente;
            aux->siguiente=NULL;
            lista3 = agregarFinal(lista3, aux);
        }
        if(seg2 != NULL)
        {
            nodo *aux2 = seg2;
            seg2=seg2->siguiente;
            aux2->siguiente=NULL;
            lista3 = agregarFinal(lista3, aux2);
        }

    }
    return lista3;
}

nodo * invertirLista(nodo * lista)
{
    nodo * invertido = iniclista();
    nodo * seg = lista;
    nodo * aux = seg;

    while(seg != NULL)
    {
        aux = seg;
        seg = seg ->siguiente;
        aux->siguiente = NULL;
        invertido = agregarPrincipio(invertido, aux);
    }
    return invertido;
}

nodo * borrarNodo(nodo * lista, char nombre[])
{
    nodo * seg;
    nodo * ante;
    if((lista != NULL) && (strcmpi(nombre, lista->dato.nombre) == 0 ))
    {
        nodo * aux = lista;
        lista = lista ->siguiente;
        free(aux);
    }
    else
    {
        seg = lista;
        while((seg!=NULL) && (strcmpi(nombre, seg->dato.nombre) != 0 ))
        {
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg != NULL){
            ante->siguiente = seg ->siguiente;
            free(seg);
        }
    }
    return lista;
}



