#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// La unica diferencia es que ademas de la direccion de memoria del siguiente tambien guardamos la del anterior en la struct nodo.
/// El primer nodo apunta a Anterior = NULL y el ultimo a Siguiente = NULL.
/// La funcion de Iniclista NO cambia.
/// La funcion crear nodo cambia.
/// Podemos recorrerlo con seguidora anterior si estamos parados al final.
/// Importante cuando borramos un nodo fijarse que ademas de apuntar al siguiente tambien al anterior.
typedef struct
{
    char nombre[20];
    int edad;
} Persona;

typedef struct nodoDoble
{
    Persona dato;
    struct nodoDoble* siguiente;
    struct nodoDoble* anterior;
} nodoDoble;

nodoDoble * iniclista();
nodoDoble * crearNodoDoble(Persona dato);
Persona cargarDatos(Persona dato);
nodoDoble * agregarPpioDoble (nodoDoble * lista, nodoDoble * nuevo);
void mostrarNodo(nodoDoble * lista);

int main()
{
    nodoDoble * lista;
    nodoDoble * nuevo;
    Persona dato;
    lista=iniclista();
    nuevo=crearNodoDoble(dato);
    lista=agregarPpioDoble (lista, nuevo);
    mostrarNodo(lista);
    return 0;
}

Persona cargarDatos(Persona dato)
{
    char s = 's';

    printf("Desea cargar datos? ");
    fflush(stdin);
    scanf("%c", &s);

    while(s== 's')
    {
        printf("Ingrese el nombre: \n");
        fflush(stdin);
        scanf("%s", &dato.nombre);

        printf("Ingrese la edad: \n");
        fflush(stdin);
        scanf("%d", &dato.edad);

        printf("Desea seguir cargando datos? ");
        fflush(stdin);
        scanf("%c", &s);

    }
    return dato;
}

nodoDoble * iniclista()
{
    return NULL;
}

nodoDoble * crearNodoDoble (Persona dato)
{
    nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
    aux->dato = cargarDatos(dato);
    aux->anterior = NULL;
    aux->siguiente = NULL;

    return aux;
}

nodoDoble * agregarPpioDoble (nodoDoble * lista, nodoDoble * nuevo)
{
    nuevo->siguiente = lista;
    if(lista != NULL)
        lista->anterior=nuevo;
    return nuevo;
}

void mostrarNodo(nodoDoble * lista)
{
    nodoDoble * seg;
    seg = lista;
    while(seg != NULL)
    {
        printf("Nombre: %s ", seg->dato.nombre);
        printf("Edad: %d", seg->dato.edad);
        seg = seg->siguiente;
    }

}

