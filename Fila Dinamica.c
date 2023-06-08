#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct fila{
    No *inicio;
    No *final;
    int quantidade;
}Fila;

void inicializa_fila(Fila *F){
    F->inicio=NULL;
    F->final=NULL;
    F->quantidade=0;
}

int vazia_fila(Fila *F){
    return(F->inicio == NULL);
}

int inicio_fila(Fila *F){
    return F->inicio->valor;
}

int quantidade_fila(Fila *F){
    return F->quantidade;
}

int enfilerar(Fila *F, int valor){
    if(quantidade_fila(F)>0){
        No *N = malloc(sizeof(No));
        N->valor = valor;
        F->final->proximo = N;
        F->final = N;
        F->quantidade++;
        return 1;
    }else if(quantidade_fila(F) == 0){
        No *N = malloc(sizeof(No));
        N->valor = valor;
        F->inicio = N;
        F->final = N;
        F->quantidade++;
        return 1;
    }else return 0;
}

int desenfilerar(Fila *F){
    if(vazia_fila(F) == 1) return 0;
    else{
        No *aux = malloc(sizeof(No));
        aux = F->inicio;
        F->inicio =aux->proximo;
        F->quantidade--;
        int valor = aux->valor;
        free(aux);
        return valor;
    }
}

int main(){
    Fila F;
    int op,num,res;

    inicializa_fila(&F);
    
    scanf("%d",&op);
    do{
        switch(op){
            case 1:
                scanf("%d",&num);
                if (enfilerar(&F,num)==1)  printf("inserido\n");
                else printf("fila cheia\n");
                break;
            case 2:
                res = desenfilerar(&F);
                if(res==0)printf("fila vazia\n");
                else printf("%d\n", res);
                break;
            case 3:
                printf("%d\n",inicio_fila(&F));
                break;
            case 4:
                printf("%d\n",quantidade_fila(&F));
                break;
            case -1:
                break;
        }
        if(op!=-1) scanf("%d",&op);  
    }while(op!=-1);

    return 0;
}





















