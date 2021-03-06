#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListaReparacion
{

    unsigned int phone;
    unsigned int code;
    unsigned int cantidad_de_dias;
    struct ListaReparacion *next;
    struct ListaReparacion *prev;

} ListaReparaciones;

typedef struct Cabecera
{

    ListaReparaciones *first;
    ListaReparaciones *last;

} tCabecera;

typedef ListaReparaciones* tLista;

void Inicializar( tCabecera *c) {

    (*c).first = NULL;
    (*c).last = NULL;

}

tLista GenerarNodo(unsigned int phone, unsigned int code, unsigned cantidad_de_dias)
{

    tLista nuevo;
    nuevo = (tLista)malloc(sizeof(ListaReparaciones));
    nuevo->phone = phone;
    nuevo->code = code;
    nuevo->cantidad_de_dias = cantidad_de_dias;
    nuevo->next = nuevo->prev = NULL;
    return nuevo;
}

void Insertar(tCabecera *cabeza, unsigned int phone, unsigned int code, unsigned cantidad_de_dias)
{

    tLista nuevo;
    tLista act;
    tLista aux;

    nuevo = GenerarNodo(phone, code, name);

    if (!cabeza->first)
    {

        cabeza->first = nuevo; // si el primer item esta vacio
        cabeza->last = nuevo;
    }

    else if (phone < cabeza->first->phone)
    {

        //agregar al inicio
        // correr el primero
        cabeza->first->prev = nuevo;
        nuevo->prev = NULL;
        nuevo = cabeza->first;
        cabeza->first = nuevo;
    }

    else if (phone > cabeza->last->phone)
    {

        //agrego al final
        //apunto nuevo->prev a cabecera->last y cabezacera->last nuevo
        cabeza->last->next = nuevo;
        nuevo->prev = cabeza->last;
        nuevo->next = NULL;
        cabeza->last = nuevo;
    }

    else
    {

        act = cabeza->first->next;
        tLista prev;

        while (act->phone < nuevo->phone)
        {

            prev = act->prev;
            act = act->next;
        }

        act->prev = nuevo;
        nuevo->prev = prev;
        nuevo->next = act;
        prev->next = nuevo;
    }
}

void RecorrerYListar( tCabecera* c ) {

    tLista act = c->first;

    while ( act != NULL )
    {
        printf("\n phone: %d ", act->phone);
        printf("\n phone: %s ", act->name);
        printf("\n phone: %d \n", act->code);

        act = act->next;
    
    }

}

void Ejercicio3 (tCabecera *c, int mind, int maxd ) {

    tLista act = c->first;

    while (act != NULL  ) {

        if ( act->cantidad_de_dias > mind && act->cantidad_de_dias < maxd ) {
        
            printf("\n Telefono: %d ", act->phone);
            printf("\n Codigo: %d ", act->code);
            printf("\n Demora de reparacion: %d \n", act->cantidad_de_dias);
        }
        act = act->next;
    }

}