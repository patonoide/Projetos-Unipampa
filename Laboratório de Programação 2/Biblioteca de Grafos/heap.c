#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "heap.h"

int th = 0; //tamanho heap

Aresta** buildHeap(Aresta** heap, int tamanho, Aresta* elemento) {
    Aresta ** vetor;
    int x = 0;
    tamanho++;
    vetor = (Aresta**) malloc(tamanho * sizeof (Aresta));
    if (tamanho == 1) {
        vetor[0] = elemento;  
    } else {
        for (x = 0; x < tamanho - 1; x++) {
            vetor[x] = heap[x];
        }
        vetor[tamanho - 1] = elemento;
        vetor = percolate(vetor, tamanho);
    }
    setTamanho(tamanho);
    return vetor;
}

Aresta ** deleteHeap(Aresta** heap, int tamanho) {
    int x = 0;
    Aresta ** vetor;
    vetor = (Aresta**) malloc(tamanho * sizeof (Aresta)); //aloco um novo vetor
    heap[0] = NULL;
    vetor = heap;
    tamanho--;
    for (x = 0; x < tamanho; x++) {
        vetor[x] = heap[x + 1];
    }
    vetor = siftDown(vetor, tamanho);
    setTamanho(tamanho);
    return vetor;
}

void printHeap(Aresta** heap, int tamanho) {
    Aresta** temp = heap;
    int x = 0;
    printf("\nHeap:\n");
    for (x = 0; x < tamanho; x++) {
        printf("%i->%i(%i)\n", heap[x]->chave_partida, heap[x]->chave_adj, heap[x]->peso);
    }

}

Aresta** siftDown(Aresta** heap, int tamanho) {
    int x = 0;
    Aresta* aux = (Aresta*) malloc(sizeof (Aresta));
    for (x = 0; x < tamanho - 1; x++) {
        if (heap[x]->peso > heap[x + 1]->peso) {
            aux = heap[x];
            heap[x] = heap[x + 1];
            heap[x + 1] = aux;
        }
    }
    return heap;
}

Aresta **percolate(Aresta** heap, int tamanho) {
    int x = 0;
    Aresta* aux = (Aresta*) malloc(sizeof (Aresta));
    if (tamanho > 1) {
        for (x = tamanho - 1; x > 0; x--) {
            if (heap[x]->peso < heap[x - 1]->peso) {
                aux = heap[x - 1];
                heap[x - 1] = heap[x];
                heap[x] = aux;
            }
        }
    }

    return heap;
}

Aresta* getRaiz(Aresta **heap) {
    return heap[0];
}

int getTamanho() {
    return th;
}

void setTamanho(int novo) {
    th = novo;
}
