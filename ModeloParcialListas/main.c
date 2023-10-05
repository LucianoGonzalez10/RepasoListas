#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

typedef struct
{
    char patente[6];
    int valor;
    char marca[10];
} automovil;

typedef struct
{
    automovil dato;
    struct nodo * siguiente;
} nodo;

nodo * iniclista();
nodo * crearNodo(automovil dato);
nodo * agregarFinal(nodo * automoviles, nodo * nuevo);
nodo * buscarUltimo(nodo * automoviles);
nodo * cargarNodo(nodo * automoviles, automovil dato);

int main()
{
    nodo * automoviles;
    automovil dato;
    automoviles = iniclista();
    automoviles = cargarNodo(automoviles, dato);
    mostrar(automoviles);
    return 0;
}

nodo * iniclista()
{
    return NULL;
}

nodo * crearNodo (automovil dato)
{
    nodo * aux = (nodo*) malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;
    return aux;
}

nodo * agregarFinal(nodo * automoviles, nodo * nuevo)
{
    if(automoviles == NULL)
    {
        automoviles = nuevo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(automoviles);
        ultimo->siguiente = nuevo;
    }
}

nodo * buscarUltimo(nodo * automoviles)
{
    nodo * seg = automoviles;
    while(automoviles->siguiente != NULL)
    {
        seg = seg->siguiente;
    }
    return seg;
}

nodo * cargarNodo (nodo * automoviles, automovil dato)
{
    char control = 's';
    printf("Desea cargar datos? \n");
    fflush(stdin);
    scanf("%c", &control);

    while(control == 's' || control == 'S')
    {
        printf("Dime la patente del auto: \n");
        fflush(stdin);
        scanf("%s", &dato.patente);

        printf("Dime el valor del auto: \n");
        scanf("%d", &dato.valor);

        printf("Dime la marca del auto: \n");
        fflush(stdin);
        scanf("%s", &dato.marca);

        nodo * nuevo = crearNodo(dato);
        automoviles = agregarFinal(automoviles, nuevo);

        printf("Desea seguir cargando datos? \n");
        fflush(stdin);
        scanf("%c", &control);

    }
    return automoviles;
}

void mostrar (nodo * lista)
{
    while(lista != NULL)
    {
        printf("Patente: %s \n", lista->dato.patente);
        printf("Valor: %d \n", lista->dato.valor);
        printf("Marca: %s \n", lista->dato.marca);
        lista = lista->siguiente;
    }
}

int insertarCelda(automovil A[], int dim, automovil dato, int validos)
{
    char control = 's';
    int i = 0;
    printf("Desea cargar datos? \n");
    fflush(stdin);
    scanf("%c", &control);

    while((control == 's' || control == 'S') && (i<dim))
    {
        printf("Dime la patente del auto: \n");
        fflush(stdin);
        scanf("%s", &dato.patente);

        printf("Dime el valor del auto: \n");
        scanf("%d", &dato.valor);

        printf("Dime la marca del auto: \n");
        fflush(stdin);
        scanf("%s", &dato.marca);

        A[i] = dato;
        i++;

        printf("Desea seguir cargando datos? \n");
        fflush(stdin);
        scanf("%c", &control);
    }
    validos = i;
    return validos;
}
