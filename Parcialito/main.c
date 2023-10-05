#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

typedef struct nodo
{
    int num;
    struct nodo * siguiente;
} nodo;

nodo * iniclista();
nodo * crearNodo(int num);
nodo * agregarFinal(nodo * lista, nodo * nuevo);
nodo * buscarUltimo(nodo * lista);
nodo * cargarNodo(nodo * lista, int num);
nodo * eliminarNodoPorPosicion(nodo * lista, int validos, int posicion);
nodo * borrarValores (nodo * lista, int valor);

int main()
{
    int num;
    nodo * lista = iniclista();
    lista = cargarNodo(lista, num);
    printf("NORMAL: \n");
    mostrarIzquierdaDerecha(lista);
    printf("\nDERECHA IZQUIERDA: \n");
    mostrarDerechaIzquierda(lista);
    printf("\nCANTIDAD DE NODOS: \n");
    int validos = cantidadDeNodos(lista);
    printf("| %d |\n", validos);

    int posicion = 0;
    printf("Dime la posicion del nodo a eliminar: ");
    scanf("%d", &posicion);

    lista = eliminarNodoPorPosicion(lista, validos, posicion);
    mostrar(lista);

    int valor = 0;
    printf("Ingrese el valor: \n");
    scanf("%d", &valor);

    lista = borrarValores (lista, valor);
    mostrar(lista);

    return 0;
}

nodo * iniclista()
{
    return NULL;
}

nodo * crearNodo(int num)
{
    nodo * nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->num = num;
    nuevo->siguiente = NULL;

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

nodo * cargarNodo(nodo * lista, int num)
{
    char control = 's';

    printf("Desea cargar datos? \n");
    fflush(stdin);
    scanf("%c", &control);

    while(control == 's' || control == 'S')
    {
        printf("Dime el numero a cargar en la lista: \n");
        scanf("%d", &num);

        nodo * nuevo = crearNodo(num);
        lista = agregarFinal(lista, nuevo);

        printf("Desea seguir cargando datos? \n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return lista;
}

void mostrar(nodo * lista)
{
    while(lista != NULL)
    {
        printf("| %d |", lista->num);
        lista = lista->siguiente;
    }
}

void mostrarIzquierdaDerecha(nodo * lista)
{
    if(lista != NULL)
    {
        printf("| %d |", lista->num);
        mostrarIzquierdaDerecha(lista->siguiente);
    }
}

void mostrarDerechaIzquierda(nodo * lista)
{
    if(lista != NULL)
    {
        mostrarDerechaIzquierda(lista->siguiente);
        printf("| %d |", lista->num);
    }
}

int cantidadDeNodos(nodo * lista)
{
    nodo * seg = lista;
    int i = 0;
    while(seg != NULL)
    {
        i++;
        seg=seg->siguiente;
    }
    return i;
}

nodo * eliminarNodoPorPosicion(nodo * lista, int validos, int posicion)
{
    nodo * ante;
    int i = 1;
    if(lista != NULL && posicion == 1)
    {
        nodo * aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        if(posicion <= validos)
        {
            nodo * seg = lista;

            while(i <= posicion)
            {
                if(i == posicion)
                {
                    ante->siguiente = seg->siguiente;
                    free(seg);
                }
                else
                {
                    ante = seg;
                    seg = seg->siguiente;
                }
                i++;
            }
        }
    }

    return lista;
}

nodo * borrarMayores(nodo * lista, int valor)
{
    nodo * seg = lista;
    nodo * ante;
    int i = 0;

    while(seg != NULL)
    {
        ante = seg;
        int dato = seg->num;
        if(dato > valor)
        {
            nodo * aux = seg;
            ante->siguiente = seg->siguiente;
            free(aux);
        }
        seg = seg->siguiente;
    }

    return lista;
}

nodo * borrarValores (nodo * lista, int valor)
{
    nodo* ante;
    nodo *seg;
    nodo *aux;
    if(lista != NULL)
    {
        while(lista!=NULL && (lista->num) > valor)
        {
            ante=lista;
            lista=lista->siguiente;
            ante->siguiente=NULL;
            free(ante);
        }
        seg=lista->siguiente;
        ante=lista;
        while(seg!=NULL)
        {
            if((seg->num) > valor)
            {
                aux=seg;
                ante->siguiente=seg->siguiente;
                seg=seg->siguiente;
                aux->siguiente=NULL;
                free(aux);
            }
            seg=seg->siguiente;
            ante=ante->siguiente;
        }
    }
    return lista;
}
