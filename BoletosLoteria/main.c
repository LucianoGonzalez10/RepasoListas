#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

typedef struct
{
    char nombre[20];
    char DNI[9];
    int nroCarton;
} Persona;

typedef struct
{
    int nroCarton;
    char num[5];
} Boleto;

typedef struct nodo
{
    Persona dato;
    struct nodo * siguiente;
} nodo;

typedef struct nodoDoble
{
    Boleto dato;
    struct nodoDoble * siguiente;
    struct nodoDoble * anterior;
} nodoDoble;

void cargarArchivoBoleto(char nombreAr[]);
void cargarArchivoPersona(char nombreAr2[]);
void mostrarArchivoBoleto(char nombreAr[]);
void mostrarArchivoPersona(char nombreAr2[]);
nodo * iniclista(nodo * lista);
nodo * crearnodo(Persona dato);
nodo * agregarFinal(nodo * lista, nodo * nuevo);
nodo * buscarUltimo(nodo * lista);
nodo * cargarNodo(nodo * lista, Persona dato, char nombreAr2[]);
void mostrarLista(nodo * lista);

int main()
{
    Persona dato;
    char nombreAr[20] = "boleto.bin";
    char nombreAr2[20] = "persona.bin";

    char decision = 's';
    printf("Dime el archivo que quieres cargar. Si es Persona = p, si es Boleto = b \n");
    fflush(stdin);
    scanf("%c", &decision);

    if(decision == 'p' || decision == 'P')
    {
        cargarArchivoPersona(nombreAr2);
    }

    if(decision == 'b' || decision == 'B')
    {
        cargarArchivoBoleto(nombreAr);
    }
    printf("BOLETO: \n");
    mostrarArchivoBoleto(nombreAr);
    printf("----------------- \n \n");

    printf("PERSONA: \n");
    mostrarArchivoPersona(nombreAr2);

    nodo * lista = iniclista(lista);
    lista = cargarNodo(lista, dato, nombreAr2);
    mostrarLista(lista);

    return 0;
}

void cargarArchivoBoleto(char nombreAr[])
{
    FILE * buffer = fopen(nombreAr, "ab");
    Boleto dato;
    char control = 's';

    printf("Desea cargar datos? \n");
    fflush(stdin);
    scanf("%c", &control);

    if(buffer)
    {
        while(control == 's')
        {
            printf("Dime el numero de Boleto: \n");
            scanf("%d", &dato.nroCarton);

            printf("Dime el num del boleto:  \n");
            fflush(stdin);
            scanf("%s", &dato.num);

            fwrite(&dato, sizeof(Boleto), 1, buffer);

            printf("Desea seguir cargando datos? \n");
            fflush(stdin);
            scanf("%c", &control);

        }
    }
    fclose(buffer);
}

void cargarArchivoPersona(char nombreAr2[])
{
    FILE * buffer = fopen(nombreAr2, "ab");
    Persona dato;
    char control = 's';

    printf("Desea cargar datos? \n");
    fflush(stdin);
    scanf("%c", &control);

    if(buffer)
    {
        while(control == 's')
        {

            printf("Dime el nombre de la persona:  \n");
            fflush(stdin);
            scanf("%s", &dato.nombre);

            printf("Dime el DNI de la persona: \n");
            fflush(stdin);
            scanf("%s", &dato.DNI);

            printf("Dime el numero de carton de la persona: \n");
            scanf("%d", &dato.nroCarton);

            fwrite(&dato, sizeof(Persona), 1, buffer);

            printf("Desea seguir cargando datos? \n");
            fflush(stdin);
            scanf("%c", &control);

        }
    }
    fclose(buffer);
}

void mostrarArchivoBoleto(char nombreAr[])
{
    FILE * buffer = fopen(nombreAr, "rb");
    Boleto dato;
    if(buffer)
    {
        while(fread(&dato, sizeof(Boleto), 1, buffer) > 0)
        {
            printf("Numero de Carton: %d \n", dato.nroCarton);
            printf("Numero: %s \n \n", dato.num);

        }
    }
    fclose(buffer);
}

void mostrarArchivoPersona(char nombreAr2[])
{
    FILE * buffer = fopen(nombreAr2, "rb");
    Persona dato;
    if(buffer)
    {
        while(fread(&dato, sizeof(Persona), 1, buffer) > 0)
        {
            printf("Nombre: %s \n", dato.nombre);
            printf("DNI: %s \n", dato.DNI);
            printf("Numero de Carton: %d \n\n", dato.nroCarton);

        }

    }
    fclose(buffer);
}

nodo * iniclista(nodo * lista)
{
    return NULL;
}

nodo * crearnodo(Persona dato)
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

nodo * cargarNodo(nodo * lista, Persona dato, char nombreAr2[])
{
    FILE * buffer = fopen(nombreAr2, "rb");
    if(buffer)
    {
        while(fread(&dato, sizeof(Persona),1, buffer) > 0)
        {
            nodo * nuevo = crearnodo(dato);
            lista = agregarFinal(lista, nuevo);
        }
    }
    fclose(buffer);
    return lista;
}


void mostrarLista(nodo * lista)
{
    nodo * seg = lista;
    while(seg != NULL)
    {
        printf("NOMBRE: %s \n", seg->dato.nombre);
        printf("DOCUMENTO: %s \n", seg->dato.DNI);
        printf("NUMERO CARTON: %d \n", seg->dato.nroCarton);
        printf("--------------------------------------\n");
        seg = seg->siguiente;
    }
}
