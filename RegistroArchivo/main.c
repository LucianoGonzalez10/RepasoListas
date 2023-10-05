#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

typedef struct
{
    char nombreEmpresa[30];
    int codigoEmpresa;
    char nombreJuego[30];
    char esrbLetra;
    int lanzamiento[3];
    float precio;
} RegistroArchivo;

typedef struct nodo
{
    RegistroArchivo registro;
    struct nodo * sig;
} nodo;

typedef struct nodo2
{
    RegistroArchivo registro2;
    struct nodo2 * sig;
    struct nodo2 * ante;
} nodo2;

nodo * iniclista();
nodo * crearNodo(RegistroArchivo registro);
nodo * agregarPrincipio(nodo * lista, nodo * nuevo);
nodo * cargarNodo(char nombreArchivo[], nodo * lista, RegistroArchivo registro);
int main()
{
    RegistroArchivo registro;
    char nombreArchivo[30] = "archivo.bin";
    cargarArchivo(nombreArchivo, registro);
    nodo * lista = iniclista();
    lista = cargarNodo(nombreArchivo, lista, registro);
    mostrarNodo(lista);
    return 0;
}

void cargarArchivo(char nombreArchivo[], RegistroArchivo registro)
{
    FILE * buffer = fopen(nombreArchivo, "ab");
    char control = 's';

    printf("Quiere cargar datos? \n");
    fflush(stdin);
    scanf("%c", &control);

    if(buffer)
    {
        while(control == 's')
        {
            printf("Dime el nombre de la empresa: \n");
            fflush(stdin);
            scanf("%s", &registro.nombreEmpresa);

            printf("Dime el codigo de la empresa: \n");
            scanf("%d", &registro.codigoEmpresa);

            printf("Dime el nombre del juego: \n");
            fflush(stdin);
            scanf("%s", &registro.nombreJuego);

            printf("Dime el esrb Letra: \n");
            fflush(stdin);
            scanf("%s", &registro.esrbLetra);

            printf("Dime el lanzamiento: \n");
            scanf("%d", &registro.lanzamiento);

            printf("Dime el precio: \n");
            scanf("%f", &registro.precio);

            fwrite(&registro, sizeof(RegistroArchivo),1, buffer);

            printf("Quiere cargar datos? \n");
            fflush(stdin);
            scanf("%c", &control);
        }
    }
    fclose(buffer);
}

nodo * iniclista()
{
    return NULL;
}

nodo * crearNodo(RegistroArchivo registro){
    nodo * nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->sig = NULL;
    nuevo->registro = registro;
    return nuevo;
}

nodo * agregarPrincipio(nodo * lista, nodo * nuevo){
    if(lista == NULL){
            lista = nuevo;
    }
    else{
        nuevo->sig = lista;
        lista = nuevo;
    }
    return lista;
}

nodo * cargarNodo(char nombreArchivo[], nodo * lista, RegistroArchivo registro){
    FILE * buffer = fopen(nombreArchivo, "rb");
    if(buffer){
        while(fread(&registro, sizeof(RegistroArchivo),1, buffer) > 0){
            nodo * nuevo = crearNodo(registro);
            lista = agregarPrincipio(lista, nuevo);
        }
    }
    fclose(buffer);
    return lista;
}

void mostrarNodo(nodo * lista){
    nodo * seg = lista;
    while(seg != NULL){
        printf("Nombre Empresa: %s \n", seg->registro.nombreEmpresa);
        printf("Codigo Empresa: %d \n", seg->registro.codigoEmpresa);
        printf("Nombre Juego: %s \n", seg->registro.nombreJuego);
        printf("ESRB LETRA: %c \n", seg->registro.esrbLetra);
        printf("Lanzamiento: %d \n", seg->registro.lanzamiento);
        printf("Precio: %.0f \n \n", seg->registro.precio);
        seg = seg->sig;
    }
}

