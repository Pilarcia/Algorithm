#include <iostream>
#include <iso646.h>
#include "gtest/gtest.h"
 
typedef struct _nodo {
	int valor;
	struct _nodo *siguiente;
} tipoNodo;
 
typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;
 
/* Funciones con listas: */
int
is_empty( Lista lista )
{
	return ( lista == NULL );
}

void
Insertar( Lista *lista, int v )
{1
	
	pNodo nuevo, anterior;
	nuevo = ( pNodo )malloc( sizeof( tipoNodo ));
	nuevo->valor = v;
	if( is_empty( *lista ) or ( *lista )->valor > v ){
		nuevo->siguiente = *lista; 
		*lista = nuevo;
	}else{
		/* Buscar el nodo de valor menor a v */
		anterior = *lista;
		/* Avanzamos hasta el último elemento o hasta que el siguiente tenga 
		   un valor mayor que v */
		while( anterior->siguiente and
		       anterior->siguiente->valor <= v ) 
			anterior = anterior->siguiente;
		/* Insertamos el nuevo nodo después del nodo anterior */
		nuevo->siguiente = anterior->siguiente;
		anterior->siguiente = nuevo;
	}
}

void
Borrar( Lista *lista, int v )
{
	pNodo anterior, nodo;
	nodo = *lista;
	anterior = NULL;
	while( nodo and nodo->valor < v ){
		anterior = nodo; 
		nodo = nodo->siguiente;
	}
	if( !nodo or  nodo->valor != v ) return;
	else { /* Borrar el nodo */
		if( !anterior ) /* Primer elemento */
			*lista = nodo->siguiente;
		else  /* un elemento cualquiera */
			anterior->siguiente = nodo->siguiente;
		free( nodo );
	}   
}


void
BorrarLista( Lista *lista )
{
	pNodo nodo;

	while( *lista ){
		nodo = *lista;
		*lista = nodo->siguiente;
		free( nodo );
	}
}
 
void
MostrarLista( Lista lista ){
	pNodo nodo = lista;
	
	if( is_empty( lista )) printf( "Lista vacía\n" );
	else {
		while( nodo ){
			std::cout << "%d -> " <<
				nodo->valor <<
				std::endl;
			nodo = nodo->siguiente;
		}
	}
}
 
int main() {
	Lista lista = NULL;
	pNodo p;
 
	Insertar(&lista, 20);
	Insertar(&lista, 10);
	Insertar(&lista, 40);
	Insertar( &lista, 30 );

	MostrarLista( lista );

	Borrar(&lista, 10);
	Borrar(&lista, 15);
	Borrar(&lista, 45);
	Borrar(&lista, 30);
	Borrar(&lista, 40);

	MostrarLista(lista);
   
	BorrarLista(&lista);

	return 0;
}










