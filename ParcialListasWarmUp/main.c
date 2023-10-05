#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

typedef struct
{
    int num;
} numero;

typedef struct nodo
{
    numero dato;
    struct nodo * siguiente;
} nodo;

nodo * iniclista();
nodo * crearNodo(numero dato);
nodo * agregarPrincipio(nodo * lista, nodo * nuevo);
nodo * agregarFinal(nodo * lista, nodo * nuevo);
nodo * buscarUltimo(nodo * lista);
nodo * cargarNodo(nodo * lista, numero dato);
void mostrarReves(nodo * lista);
nodo * eliminarNodo(nodo * lista, int numEliminar);
nodo * eliminarPorLimite(nodo * lista, int numLimite);

int main()
{
    numero dato;
    nodo * lista = iniclista();
    lista = cargarNodo(lista, dato);
    mostrar(lista);

    printf("\n");
    mostrarReves(lista);
    printf("\n");

    int validos = contarElementos(lista);
    printf("Cantidad de nodos: %d \n", validos);

    int pos = 2;

    /* int numEliminar = 0;
    printf("Dime el numero a eliminar: \n");
    scanf("%i", &numEliminar);

    lista = eliminarNodo(lista, numEliminar);
    mostrar(lista); */

    int numLimite = 0;
    printf("Dime el numero limite para los nodos: \n");
    scanf("%d", &numLimite);

    lista = eliminarPorLimite(lista, numLimite);
    mostrar(lista);



    return 0;
}

nodo * iniclista()
{
    return NULL;
}

nodo * crearNodo(numero dato)
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
        nuevo->siguiente = NULL;
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

nodo * cargarNodo(nodo * lista, numero dato)
{

    char control = 's';

    printf("Desea cargar un nodo? \n");
    fflush(stdin);
    scanf("%c", &control);

    while(control == 's' || control == 'S')
    {
        printf("Dime el numero a cargar \n");
        scanf("%d", &dato.num);

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
    printf("\n");
    while(seg != NULL)
    {
        printf("| %d |   ", seg->dato.num);
        seg = seg->siguiente;
    }
    printf("\n");
}

void mostrarReves(nodo * lista)
{
    if(lista != NULL)
    {
        mostrarReves(lista->siguiente);
        printf("| %d |   ", lista->dato.num);
    }
    else
    {
        printf("\n La lista llego a su fin. \n");
    }
}

int contarElementos(nodo * lista)
{
    nodo * seg = lista;
    int i = 0;
    while(seg != NULL)
    {
        i++;
        seg = seg->siguiente;
    }
    return i;
}

nodo * eliminarNodo(nodo * lista, int numEliminar)
{
    nodo * aux; // Almacena el nodo que quiero eliminar.
    nodo * ante; // Elimina el nodo anterior del que elimino.

    if( (lista != NULL) && (lista->dato.num == numEliminar) )
    {
        aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        aux = lista;
        while((aux != NULL) && (aux->dato.num != numEliminar))
        {
            ante = aux;
            aux = aux->siguiente;
        }
        if(aux != NULL)
        {
            ante->siguiente = aux->siguiente;
            free(aux);
        }
    }
    return lista;
}

nodo * eliminarPorLimite(nodo * lista, int numLimite)
{
    nodo * aux;
    nodo * ante;

    aux = lista;
    while(aux != NULL)
    {
        ante = aux;
        if((aux->dato.num) < numLimite)
        {
            ante->siguiente = aux->siguiente;
            free(aux);
        }
        aux = aux->siguiente;
    }
return lista;
}
