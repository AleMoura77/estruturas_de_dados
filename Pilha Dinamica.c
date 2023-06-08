#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct pilha{
    No *topo;
    int quantidade;
}Pilha;

void inicializar_pilha(Pilha *P){
    P->topo = NULL;
    P->quantidade = 0;
}

int vazia_pilha(Pilha *P){
    return(P->topo == NULL);
}

int topo_pilha(Pilha *P){
    return P->topo->valor;
}

int quantidade_pilha(Pilha *P){
    return P->quantidade;
}

int empilhar(Pilha *P, int valor){
    
    if(quantidade_pilha(P) >= 0){
        No *N = malloc(sizeof(No));
        N->valor = valor;
        N->proximo = P->topo;
        P->topo = N;
        P->quantidade++; 
        return 1;
    }else{
        return 0;
    }
} 

int desempilhar(Pilha *P){
    if(vazia_pilha(P)) return 0;
    else{
        No *aux = malloc(sizeof(No));
        aux = P->topo;
        P->topo = aux->proximo;
        P->quantidade--;
        int valor = aux->valor;
        free(aux);
        return(valor);
    }
    
}

int main(){
    Pilha P;
    inicializar_pilha(&P);
    int op, num, res;
    
    scanf("%d",&op);
    
    do{
        switch(op){
            case 1:
                scanf("%d",&num);
                if (empilhar(&P,num)==1) printf("empilhado\n");
                else printf("Pilha cheia");
                
                break;
            case 2:
                res = desempilhar(&P);
                if(res==0)printf("Pilha vazia");
                else printf("%d\n", res);
                break;
            case 3:
                printf("%d\n", topo_pilha(&P));
                break;
            case -1:
                break;
        }
        if(op!=-1) scanf("%d",&op);  
    }while(op!=-1);

    return 0;
    
}
