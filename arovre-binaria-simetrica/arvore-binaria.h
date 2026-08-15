#include <stdio.h>
#include <stdlib.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

typedef struct noPilha{
    TNoA* conteudoNo;
    struct noPilha *prox;
} noPilha;

typedef struct pilha{
    noPilha *topo;
}pilha;


TNoA *inicializa(void);
void imprime(TNoA *nodo, int tab);
TNoA *criaNo(char ch);