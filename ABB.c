#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *esquerda;
    struct no * direita;
}No;

void inicializarABB(No **pRaiz){
    *pRaiz = NULL;
}

void inserirABB(No **pRaiz, int chave){
    if(*pRaiz == NULL){
        *pRaiz = (No *) malloc(sizeof(No));
        (*pRaiz)->chave = chave;
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
    }else{
        if(chave < (*pRaiz)->chave) inserirABB(&(*pRaiz)->esquerda, chave);
        if(chave > (*pRaiz)->chave) inserirABB(&(*pRaiz)->direita, chave);  
    } 
    
}

No* buscarABB(No **pRaiz, int chave){
    if((*pRaiz) == NULL) return NULL;
    else if((*pRaiz)->chave == chave) return *pRaiz;
    else if(chave < (*pRaiz)->chave) return buscarABB(&(*pRaiz)->esquerda, chave);
    else if(chave > (*pRaiz)->chave) return buscarABB(&(*pRaiz)->direita, chave);
    
}


No* maxValor(No **pRaiz){
    No* atual = (*pRaiz);
    while(atual && atual->direita != NULL){
        atual = atual->direita;
    }
    return atual;
}

No* deletarABB(No **pRaiz, int chave){
    if(*pRaiz == NULL) return (*pRaiz);
    
    if(chave < (*pRaiz)->chave){
        (*pRaiz)->esquerda = deletarABB(&(*pRaiz)->esquerda, chave);
    } else if(chave > (*pRaiz)->chave){
        (*pRaiz)->direita = deletarABB(&(*pRaiz)->direita, chave);
    } else{
        if((*pRaiz)->esquerda==NULL){
            No* aux = (*pRaiz)->direita;
            free(*pRaiz);
            return aux;
        } else if((*pRaiz)->direita==NULL){
            No* aux = (*pRaiz)->esquerda;
            free(*pRaiz);
            return aux;
        }
        
        No* aux = maxValor(&(*pRaiz)->esquerda);
        
        (*pRaiz)->chave = aux->chave;
        
        (*pRaiz)->esquerda = deletarABB(&(*pRaiz)->esquerda, aux->chave);
    }
    
    return(*pRaiz);
}


int Quantidade(No *n){
    if(n == NULL) return 0;
    return Quantidade(n->direita) + Quantidade(n->esquerda) + 1;
}

void mostrarEmNivel(No *n){
    No **fila;
    int i, f;
    
    fila = malloc(Quantidade(n) * sizeof(No*));
    fila[0] = n;
    
    i = 0; f = 1;
    
    while (f > i){
        n = fila[i++];
        printf("%d ", n->chave);
        if(n->esquerda != NULL) fila[f++] = n->esquerda;
        if(n->direita != NULL) fila[f++] = n->direita;
    }
}

void mostrarEmOrdem(No *n){
	if (n != NULL){
		mostrarEmOrdem(n->esquerda);
		printf("%d ", n->chave);
		mostrarEmOrdem(n->direita);
	}
}

void mostrarPreOrdem(No *n){
	if (n != NULL){
	    printf("%d ", n->chave);
		mostrarPreOrdem(n->esquerda);
		mostrarPreOrdem(n->direita);
	}
}


void mostrarPosOrdem(No *n){
	if (n != NULL){
		mostrarPosOrdem(n->esquerda);
		mostrarPosOrdem(n->direita);
		printf("%d ", n->chave);
	}
}

int main(){
    
    No *Arvore;
    inicializarABB(&Arvore);
    
    int op, num;
    
    scanf("%d", &op);
    
   do{
        switch(op){
            case 1:
                scanf("%d",&num);
                inserirABB(&Arvore, num);
                printf("inserido\n");
                break;
            case 2:
                scanf("%d",&num);
                if (buscarABB(&Arvore, num) == NULL) printf("nao encontrado\n");
                else{
                    deletarABB(&Arvore, num);
                    printf("removido\n");
                }
                break;
            case 3:
                scanf("%d",&num);
                if (buscarABB(&Arvore, num) == NULL) printf("nao encontrado\n");
                else{
                    printf("encontrado\n");    
                }
                break;
            case 4:
            	mostrarEmNivel(Arvore);
            	printf("\n"); 
                break;
            case 5:
            	mostrarEmOrdem(Arvore);
            	printf("\n");
                break;
            case 6:
            	mostrarPreOrdem(Arvore);
            	printf("\n");
                break;
            case 7:
            	mostrarPosOrdem(Arvore);
            	printf("\n");
                break;
			case -1:
				break;	    
        }
        if(op!=-1) scanf("%d",&op);  
    }while(op!=-1);

    return 0;
    
}









