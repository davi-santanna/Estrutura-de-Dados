#include "arvore-binaria.h"

TNoA *inicializa(void) {
    return NULL;
}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *criaNo(char ch) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    imprime(raiz, 0);
};

//criando funcoes para pilha

void inicializaPilha(pilha*p) {p->topo = NULL;}

void push(pilha*p, TNoA* infoNoArvore){
    noPilha* novoTopo = (noPilha*)malloc(sizeof(noPilha));
    novoTopo->conteudoNo = infoNoArvore;
    novoTopo->prox = p->topo;
    p->topo = novoTopo;
    }

TNoA* pop(pilha*p){
    if(p&&p->topo){
        noPilha* temp;
        TNoA* conteudo;
        temp = p->topo;
        conteudo = temp->conteudoNo;
        p->topo = p->topo->prox;
        free(temp);
        return conteudo;
    }
    else return '\0';
}

void percorreSimetrica(TNoA* raiz)
{
    pilha*p;
    noPilha*ini = (noPilha*)malloc(sizeof(noPilha));
    TNoA*atual = raiz;
    p->topo = ini;
    while(!raiz|| !p->topo){
        while(!raiz){
            push(&p, atual);
            atual = atual->esq;
        }
        atual = pop(&p);
        printf('%c', atual->info);
        atual = atual->dir;
    }
}
