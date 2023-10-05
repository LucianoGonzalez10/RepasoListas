#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int id;
    char nombre[20];
    char posicion[20]; /// Guardian, buscador, cazador y golpeador.
    int curso;
    int puntosGanados;
    char equipo[20];
}jugador;

typedef struct nodo
{
    jugador dato;
    struct nodo * anterior;
    struct nodo * siguiente;
}nodo;

nodo * iniclista();
nodo * crearNodo(jugador dato);
nodo * agregarPrincipio(nodo * lista, nodo * nuevo);
void cargarNodos(nodo ** lista, jugador dato);

int main()
{
    jugador dato;
    nodo * lista = iniclista();
    cargarNodos(&lista, dato);
    return 0;
}

nodo * iniclista()
{
    return NULL;
}

nodo * crearNodo(jugador dato)
{
    nodo * nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    return nuevo;
}

nodo * agregarPrincipio(nodo * lista, nodo * nuevo)
{
    nuevo->siguiente = lista;
    if(lista != NULL)
    {
        lista->anterior =  nuevo;
    }

    return nuevo;
}

void cargarNodos(nodo ** lista, jugador dato)
{
    char control = 's';
    printf("Desea cargar datos? \n");
    fflush(stdin);
    scanf("%c", &control);

    while(control == 's')
    {
        dato = cargarJugador(dato);

        nodo * nuevo = crearNodo(dato);
        *lista = agregarPrincipio(lista, nuevo);

        printf("Desea cargar datos? \n");
        fflush(stdin);
        scanf("%c", &control);
    }
}

jugador cargarJugador(jugador dato){

        printf("Dime el ID del jugador: \n");
        scanf("%d", &dato.id);

        printf("Dime el nombre del jugador: \n");
        fflush(stdin);
        scanf("%s", &dato.nombre);

        printf("Dime la posicion del jugador: \n");
        fflush(stdin);
        scanf("%s", &dato.posicion);

        printf("Dime el curso del jugador: \n");
        scanf("%d", &dato.curso);

        printf("Dime los puntos ganador del jugador: \n");
        scanf("%d", &dato.puntosGanados);

        printf("Dime el equipo del jugador: \n");
        fflush(stdin);
        scanf("%s", &dato.equipo);

        return dato;
}
