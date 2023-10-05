#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

void inicpila(Pila * pila){
    pila->lista = inicLista();
}

void apilar(Pila * pila, int dato){
    nodo * aux = crearNodo(dato);
    pila->lista = agregarPrincipio(pila->lista, aux);
}

void leer(Pila* pila){
    int dato;
    printf("Ingrese el dato \n");
    scanf("%i", &dato);

    apilar(pila, dato);
}

int desapilar (Pila * pila){
    int rta = -1;
    if(pila->lista) != NULL){
        rta =retornarPrimerDato(pila->lista);
    }
}

int mostrar(Pila * A){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(A)){
        apilar(&aux, desapilar(A));
    }
    printf("\n BASE .......................................... Tope \n");
    recorrerYmostrar(aux.lista);
    printf("\n BASE .......................................... Tope \n");

    while(!pilavacia(&aux)){
        apilar(&A, desapilar(&aux));
    }
}

