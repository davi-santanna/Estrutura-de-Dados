int arvoreCheia(L*raiz)
{
    if(!raiz) return 1;
    else if(!raiz->esq && !raiz->dir) return 1;
    else if (raiz->esq && raiz->dir){return arvoreCheia(raiz->esq) && arvoreCheia(raiz->dir);}
    else return 0;
}
