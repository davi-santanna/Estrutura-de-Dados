#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

typedef struct No{
    int info;
    struct No* prox;
} No;

typedef struct{
    No*topo;
}pilha;

pilha* inicializar_pilha ( pilha* p)
{
    p->topo = NULL;
}

void push (pilha*p, int valor)
{
    No*novo = (No*)malloc(sizeof(No)){
        if(!novo) printf("RAM cheia");
        return;}
    novo->info = valor;
    novo->prox = p->topo;
    p->topo = novo;
}
int pop(pilha*p){
    if(!p->topo){
        printf("pilha vazia!");
        return;}
    No*temp = p->topo;
    int valor = temp->info;
    p->topo = p->topo->prox;
    free(temp);
    return(valor);
}


void altera(TLista* li, int vantigo, int vnovo) {
    TLista *inicio = li;
    if(li == NULL){
        printf("Lista Vazia!");
    }
    else{
       TLista* inicio = li;
        while(inicio != NULL){
            if(inicio->info == vantigo){
                inicio->info = vnovo;
            }
            inicio = inicio->prox;
        }
    }

 }

void imprime_lista(TLista *li) {
    TLista* p;
    for (p = li; p != NULL; p = p->prox)
        printf("%d ", p->info);
        
}

TLista* insere_fim (TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    TLista* p = li;
    TLista* q = li;
    while (p != NULL) {
        /* encontra o ultimo elemento */
        q = p;
        p = p->prox;
    }
    if (q != NULL) /* se a lista original não estiver vazia */
        q->prox = novo;
    else
        li = novo;
    return li;
}

int main (void) {
    /* A função main lê os dados de entrada, cria a lista e chama a função altera
     * depois imprime a lista resultante
     * Ela NÃO DEVE SER MODIFICADA
     * */
    TLista* lista = NULL;
    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int valor;
    int valor_antigo, valor_novo;


    /* lê valores para criar a lista
     * valores devem ser informados separados por traço
     * exemplo: 1-3-5-2-7-9-21-6 */
    scanf("%s", l);
    //quebra a string de entrada
    ptr = strtok(l, delimitador);
    while(ptr != NULL) {
        valor = atoi(ptr);
        lista = insere_fim(lista, valor);
        ptr = strtok(NULL, delimitador);
    }

    //Le dados da alteracao a ser realizada
    scanf("%d", &valor_antigo);
    scanf("%d", &valor_novo);
    altera(lista, valor_antigo, valor_novo);
    imprime_lista(lista);
}

