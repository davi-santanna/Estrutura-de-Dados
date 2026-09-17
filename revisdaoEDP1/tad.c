#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct noA{
    int info;
    struct noA* esq;
    struct noA* dir;
}TNoA;

typedef struct vizinho
{
    int id_vizinho;
    struct vizinho *prox;
} TVizinho;

/*
 * Funções e tipos auxiliares, para uso caso necessário
 */

typedef struct lista
{
    int info;
    struct lista *prox;
} TLista;

TLista *insere_lista(TLista *vet, int info)
{
    TLista *no = (TLista *)malloc(sizeof(TLista));
    no->info = info;
    no->prox = NULL;
    if (vet == NULL)
        return no;

    TLista *pt = vet;
    while (pt->prox != NULL)
        pt = pt->prox;
    pt->prox = no;

    return vet;
}

typedef struct pilha
{
    TLista *topo;
} TPilha;

TPilha *inicializa()
{
    TPilha *pilha = (TPilha *)malloc(sizeof(TPilha));
    pilha->topo = NULL;
    return pilha;
}

void libera(TPilha *p)
{
    TLista *q = p->topo;
    TLista *r;
    while (q != NULL)
    {
        r = q;
        q = q->prox;
        free(r);
    }
    free(p);
}

int pilha_vazia(TPilha *pilha)
{
    if (pilha->topo == NULL)
        return 1; // pilha vazia
    else
        return 0; // pilha tem pelo menos 1 elemento
}

/* *
 * Insere elem no topo da pilha
 * */
void push(TPilha *pilha, int elem)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

/* *
 * Exclui o elemento do topo da pilha
 * retorna o info do elemento excluído
 */
int pop(TPilha *pilha)
{
    if (pilha_vazia(pilha))
    {
        exit(1);
    }
    else
    {
        TLista *aux = pilha->topo;
        int info = aux->info;
        pilha->topo = aux->prox;
        free(aux);
        return info;
    }
}

/* *
 * Consulta o elemento do topo da pilha
 * retorna info do elemento do topo ou -1 caso a pilha esteja vazia
 */
int peek(TPilha *pilha)
{
    if (pilha_vazia(pilha))
        return -1;
    else
    {
        // faz consulta
        return pilha->topo->info;
    }
}

void imprime_pilha(TPilha *pilha)
{
    int x;
    TPilha *aux = inicializa();
    while (!pilha_vazia(pilha))
    {
        x = pop(pilha);
        printf("%d\n", x);
        push(aux, x);
    }
    while (!pilha_vazia(aux))
    {
        push(pilha, pop(aux));
    }
    libera(aux);
    printf("\n");
}

/*
 * Funções de grafo
 */

typedef struct grafo
{
    int id_vertice;
    int cor;
    TVizinho *prim_vizinho;
    struct grafo *prox;
} TGrafo;

TGrafo *insere_vertice(TGrafo *g, int id)
{
    TGrafo *vertice = (TGrafo *)malloc(sizeof(TGrafo));
    vertice->id_vertice = id;
    vertice->cor = -1;
    vertice->prox = g;
    vertice->prim_vizinho = NULL;
    return vertice;
}

void libera_vizinho(TVizinho *vizinho)
{
    if (vizinho != NULL)
    {
        libera_vizinho(vizinho->prox);
        free(vizinho);
    }
}

void libera_vertice(TGrafo *vertice)
{
    if (vertice != NULL)
    {
        libera_vizinho(vertice->prim_vizinho);
        libera_vertice(vertice->prox);
        free(vertice);
    }
}

TGrafo *busca_vertice(TGrafo *vertice, int id)
{
    while ((vertice != NULL) && (vertice->id_vertice != id))
    {
        vertice = vertice->prox;
    }
    return vertice;
}

TVizinho *busca_vizinho(TVizinho *vizinho, int id)
{
    while ((vizinho != NULL) && (vizinho->id_vizinho != id))
    {
        vizinho = vizinho->prox;
    }
    return vizinho;
}

void insere_aresta(TGrafo *g, int origem, int destino)
{
    TGrafo *pv1 = busca_vertice(g, origem);
    TGrafo *pv2 = busca_vertice(g, destino);
    if (pv1 != NULL && pv2 != NULL)
    {
        TVizinho *nova = (TVizinho *)malloc(sizeof(TVizinho));
        nova->id_vizinho = destino;
        nova->prox = pv1->prim_vizinho;
        pv1->prim_vizinho = nova;
    }
}

void insere_aresta_nao_orientada(TGrafo *g, int origem, int destino)
{
    insere_aresta(g, origem, destino);
    insere_aresta(g, destino, origem);
}

void imprime(TGrafo *vertice)
{
    while (vertice != NULL)
    {
        printf("Vertice: %d\n", vertice->id_vertice);
        printf("Vizinhos: ");
        TVizinho *vizinho = vertice->prim_vizinho;
        while (vizinho != NULL)
        {
            printf("%d ", vizinho->id_vizinho);
            vizinho = vizinho->prox;
        }
        printf("\n\n");
        vertice = vertice->prox;
    }
}

int vizinhos(TGrafo *vertice)
{
    int total = 0;
    TVizinho *pt = vertice->prim_vizinho;
    while (pt != NULL)
    {
        pt = pt->prox;
        total++;
    }
    return total;
}