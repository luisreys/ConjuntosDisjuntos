#include "conjuntos.h"
#include <stdio.h>

/// Incluir aqui las funciones que implementan las tres operaciones bAsicas 
/// en la representaciOn de CONJUNTOS DISJUNTOS mediante MATRICES
/// ......................................................................


void crea(particion C){
	int i;
	
	for(i=0; i<MAXIMO; i++){
		C[i] = i;
	}
	
}

tipoElemento buscar(tipoElemento x, particion C){
	if(x<MAXIMO){
		return C[x];	
	}else{
		return -1;
	}
}

void unir(tipoElemento x, tipoElemento y, particion C){
	int flagError = 0;
	int representanteX;
	int representanteY;
	
	if(x<MAXIMO){
		representanteX = C[x];
	}else{
		flagError = 1;
	}
	if(y<MAXIMO){
		representanteY = C[y];
	}else{
		flagError = 1;
	}
	
	
	if(flagError == 0 && representanteX != representanteY){
		C[y] = representanteX;	
	}
}

//
// Funciones auxiliares para ver contenido de Partición y Clase de Equivalencia
//
void verParticion(particion C)
{ int i;
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf("|%2d",C[i]);
    printf("| contenido  vector\n");
    for (i =0;i<MAXIMO;i++) printf("---");
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf(" %2d",i);
    printf("  índices vector\n\n");
}

void verClaseEquivalencia(tipoElemento x,particion C)
{ int representante,i;
  representante = buscar(x,C);
  printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x,representante);
  for (i=0;i<MAXIMO;i++) if (C[i]==representante) printf("%d ",i);
  printf("\n");

}
