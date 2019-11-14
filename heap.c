#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

#define TAM_INICIAL 11

//--------------------- FUNCION DE COMPARACION ---------------------//

typedef int (*cmp_func_t) (const void *a, const void *b);

//--------------------- STRUCTS ---------------------//

typedef struct heap heap_t{
	void** datos;
	int cantidad;
	int capacidad;
	cmp_func_t cmp;
}heap_t;

//--------------------- HEAP SORT ---------------------

void heapify(void *arreglo[], int tam, cmp_func_t cmp){
	for (int i = cantidad; i > 0; i--){
		downheap(arr, i - 1, cantidad);
	}
}

void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp);

//--------------------- FUNCIONES AUXILIARES ---------------------//

void swap(void** arreglo, int a, int b){
	void* aux = arreglo[a];
	arreglo[a] = b;
	arreglo[b] = aux;
}

void upheap(void** arreglo, int pos, cmp_func_t cmp){
	if(pos == 0){
		return;
	}
	padre = pos_padre(pos);
	if(cmp(arreglo[padre], arreglo[pos]) > 0){
		swap(arreglo, padre, pos);
		upheap(vector, padre, cmp);
	}
}

void downheap(void** arreglo, int capacidad, int pos, cmp_func_t cmp){
	if(pos > tam){
		return;
	}
	max = pos; // Padre
	izq = pos_hijo_izq(pos);
	der = pos_hijo_der(pos);
	if(izq < capacidad && cmp(arreglo[izq], arreglo[max]) > 0){
		max = izq;
	}
	if(der < capacidad && cmp(arreglo[der], arreglo[max]) > 0){
		max = der;
	}
	if(max != pos){
		swap(arreglo, pos, max);
		downheap(arreglo, capacidad, max, cmp);
	}
}

int pos_padre(int pos){
	return (pos - 1) / 2;
}

int pos_hijo_izq(int pos){
	return (pos * 2) + 1;
}

int pos_hijo_der(int pos){
	return (pos * 2) + 2;
}

//--------------------- PRIMITIVAS ---------------------//

heap_t *heap_crear(cmp_func_t cmp){
	heap_t* heap = malloc(sizeof(heap_t));
	if(!heap){
		return NULL;
	}
	heap->cantidad = 0;
	heap->capacidad = TAM_INICIAL;
	heap->cmp = cmp;
	return heap;
}

heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp){
	heap_t* heap = heap_crear(cmp);
	if(!heap){
		return NULL;
	}

}

void heap_destruir(heap_t *heap, void destruir_elemento(void *e));

size_t heap_cantidad(const heap_t *heap);

bool heap_esta_vacio(const heap_t *heap);

bool heap_encolar(heap_t *heap, void *elem);

void *heap_ver_max(const heap_t *heap);

void *heap_desencolar(heap_t *heap);

//--------------------------------------------------------------//