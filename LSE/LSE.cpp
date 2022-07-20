#include <iostream>
#include <stdlib.h>

struct listaSimples {
    int val;
    struct listaSimples* proximo;
};

struct headLista {
    listaSimples* head;
};

headLista* inicializarLista() {
    headLista* l = new headLista();
    l->head = NULL;
    return l;
}

listaSimples* criarNovoElemento(int v) {
    listaSimples* l = new listaSimples();
    l->val = v;
    l->proximo = NULL;
    return l;
}

bool elementoExisteNaLista(headLista* h, int v) {
    listaSimples* l = h->head;
    while (l->proximo != NULL) {
        if (l->val == v) {
            return true;
        }
        l = l->proximo;
    }
    return false;
}

void inserirElementoFim(headLista* h, int v) {
    listaSimples* l; 
    if (h->head == NULL) {
        l = criarNovoElemento(v);
        h->head = l;
        return;
    }
    listaSimples* q = h->head;
    while (q->proximo != NULL) {
        q = q->proximo;
    }
    l = criarNovoElemento(v);
    q->proximo = l;
}

void inserirInicioLista(headLista *h, int v) {
    listaSimples* l;
    if(h->head == NULL){
        l = criarNovoElemento(v);
        h->head = l;
        return;
    }
    l = criarNovoElemento(v);
    l->proximo = h->head;
    h->head = l; 
}

void varrerLista(headLista *h) {

    listaSimples* l = h->head;
    while (l != NULL) {
        std::cout << l->val << " ";
        l = l->proximo;
    }

}

int main()
{
    headLista* h = inicializarLista();
    /*
    inserirInicioLista(h, 5);
    inserirInicioLista(h, 10);
    inserirInicioLista(h, 15);
    inserirInicioLista(h, 25);
    */
    inserirElementoFim(h, 5);
    inserirElementoFim(h, 10);
    inserirElementoFim(h, 15);
    varrerLista(h);
    //std::cout << elementoExisteNaLista(h, 10);
    return 0;
}