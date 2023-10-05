#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

typedef struct
{
    char patente[7];
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
nodo * agregarFinal(nodo * lista, nodo * nuevo);
nodo * buscarUltimo(nodo * lista);
nodo * cargarNodo(nodo * lista, automovil dato);
int cargarArreglo(automovil A[], int dim, automovil dato);
main()
{
    automovil dato;
    nodo * lista = iniclista();
    lista = cargarNodo(lista, dato);
    mostrar(lista);
    int dim = 20;
    automovil A[dim];
    int validos = cargarArreglo(A, dim, dato);

    mostrarArreglo(A, validos);

    return 0;
}

nodo * iniclista()
{
    return NULL;
}

nodo * crearNodo(automovil dato)
{
    nodo * nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = dato;
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


nodo * cargarNodo(nodo * lista, automovil dato)
{
    char control = 's';

    printf("Desea cargar un nodo? \n");
    fflush(stdin);
    scanf("%c", &control);

    while(control == 's')
    {
        printf("Dime la Patente del auto: \n");
        fflush(stdin);
        scanf("%s", &dato.patente);

        printf("Dime el valor del auto: \n");
        scanf("%d", &dato.valor);

        printf("Dime la marca del auto: \n");
        fflush(stdin);
        scanf("%s", &dato.marca);

        nodo * nuevo = crearNodo(dato);
        lista = agregarFinal(lista, nuevo);

        printf("Desea seguir cargando nodos? \n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return lista;
}

void mostrar(nodo * lista)
{
    if(lista != NULL)
    {
        printf("Patente: %s \n", lista->dato.patente);
        printf("Valor: %d \n", lista->dato.valor);
        printf("Marca: %s \n", lista->dato.marca);
        mostrar(lista->siguiente);
    }
}

int cargarArreglo(automovil A[], int dim, automovil dato)
{
    char control = 's';
    int i = 0;
    printf("Desea cargar el arreglo? \n");
    fflush(stdin);
    scanf("%c", &control);

    int validos = 0;
    while(control == 's' && i<dim)
    {
        validos = insertarDatoNuevo(A, dim, i, dato);

        printf("Desea cargar el arreglo? \n");
        fflush(stdin);
        scanf("%c", &control);
        i++;
    }
    return validos;
}

int insertarDatoNuevo(automovil A[], int dim, int validos, automovil dato){
    printf("Dime la patente del auto a cargar: \n");
    fflush(stdin);
    scanf("%s", &dato.patente);

    printf("Dime el valor del auto a insertar: \n");
    scanf("%d", &dato.valor);

    printf("Dime la marca del auto a insertar: \n");
    fflush(stdin);
    scanf("%s", &dato.marca);

    if(validos == dim){
        printf("EL ARREGLO ESTA LLENO. \n");
    }
    else{
        validos = metodoInsercion(A, validos, dato);
    }
    return validos;
}

int metodoInsercion(automovil A[], int validos, automovil dato){
    int i = validos;
    while(i>=0 && dato.valor <A[i].valor){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = dato;
    validos++;
    return validos;
}

void mostrarArreglo(automovil A[], int validos){
    int i = 0;
    while(i<validos){
            printf("PATENTE: %s \n", A[i].patente);
            printf("VALOR : %d \n", A[i].valor);
            printf("MARCA: %s \n", A[i].marca);
            i++;
    }
}


