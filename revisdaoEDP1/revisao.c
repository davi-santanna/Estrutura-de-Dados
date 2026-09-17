#include "tad.c"




int eh_simetrica(TNoA* a)
{
    if(a == NULL) return 1;
    else return espelhamento(a->esq, a->dir);
}
int espelhamento(TNoA*esq, TNoA*dir)
{
    if (esq == NULL && dir == NULL) return 1;
    else if (esq==NULL || dir == NULL) return 0;
    else if (esq->info != dir->info) return 0;
    return espelhamento(esq -> dir, dir->esq) && espelhamento(esq-> esq, dir->dir) ;
}
int mesmoN (TNoA*a, int num)
{
    if (!a) return 0;
    int n = num;
    int numCaminhos = 0;
    int somador = 0;
    TNoA*arvore = a;
    percorreSomando(n, somador, arvore, &numCaminhos);
    return numCaminhos;
    
} 
void percorreSomando(int n, int somador, TNoA* a, int *numCaminhos)
{
    somador += a->info;
    if(a->dir == NULL && a->esq == NULL){
        if (somador == n) (*numCaminhos)++;
        return;}
    if(a->dir) percorreSomando(n, somador, a->dir, numCaminhos);
    if(a->esq) percorreSomando(n, somador, a->esq, numCaminhos);
    
}
int* num_vizinhos(TGrafo*g)
{
    int* vetor = malloc(sizeof(int) * tamVertices(g));
    if (!vetor) return 0;
    TGrafo* aux = g;
    for(int x=0; x<tamVertices(aux); x++){
        vetor[x] = tamVizinhos(aux->prim_vizinho);
        aux=aux->prox;
    }
    return vetor;
}
int tamVizinhos(TVizinho*viz){
    int tam = 0;
    while(viz)
    {
        tam++;
        viz=viz->prox;
    }
    return tam;

}
int tamVertices(TGrafo*g)
{
    int contador = 0;
    while(g){
        contador++;
        g=g->prox;
    }
    return contador;
}


int tamRaiz(TNoA* a)
{
    if (a == NULL)return -1;
    int esq = tamRaiz(a->esq);
    int dir = tamRaiz(a->dir);
    if(esq>dir)return esq+1;
    else return dir+1;

}
TNoA* ehAVL(TNoA*a)
{
    if(a==NULL) return NULL;
    a->esq = ehAVL(a->esq);
    a->dir = ehAVL(a->dir);
    int peso = tamRaiz(a->esq) - tamRaiz(a->dir);
    if(peso < -1) 
    {
        int filhoDir = tamRaiz(a->dir->dir) - tamRaiz(a->dir->esq);
        if (filhoDir>=0) a = rotacaoDir(a);
        else a = rotacaoDirEsq(a);
    }
    if(peso > 1)
    {
        int filhoEsq = tamRaiz(a->esq->dir) - tamRaiz(a->esq->esq);
        if (filhoEsq<=0) a = rotacaoEsq(a);
        else a = rotacaoEsqDir(a);
    }
    return a;
}
TNoA*rotacaoDir(TNoA*a)
{
    TNoA*b = a->esq;
    TNoA* bDir = b->dir;
    b->dir = a;
    a->esq = bDir;
    return b;
    /*
    a > t1 > b > c
        a             b     
        /            / \
       b     ->     c   a
      / \               /
     c   t1            t1  
                      
    */  
}
TNoA*rotacaoEsq(TNoA*a)
{
 TNoA* b = a->dir;
 TNoA* bEsq = b->esq;
 b->esq = a;
 a->dir = bEsq;   
return b;
 /*
    c > b > t1 > a
      a              b     
       \            / \
        b     ->   a   c
       / \         \ 
      t1  c         t1    
                      
    */   
}
TNoA*rotacaoEsqDir(TNoA*a)
{
    a->esq = rotacaoEsq(a->esq);
    return rotacaoDir(a);
}
TNoA*rotacaoDirEsq(TNoA*a)
{
    a->dir = rotacaoDir(a->dir);
    return rotacaoEsq(a);
}