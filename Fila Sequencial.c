#include <stdio.h>
#define TAM 10

typedef struct fila {
    int dados[TAM];
    int n;
}Fila;

//implemente as funcoes da fila aqui

void inicializar(Fila *f, int valor1, int valor2){
    f->n = valor1;
    int i;
    for(i=0; i<TAM; i++){
        f->dados[i]=valor2;
    }
}

int cheia(Fila *f){
    return(f->n >= TAM);
}

int vazia(Fila *f){
    return(f->n <= 0);
}

int primeiro(Fila *f){
    return(f->dados[0]);
}

int quantidade(Fila *f){
    return(f->n);
}

int enfilerar(Fila *f, int valor){
    if(cheia(f)==1)return 0;
    else{
        f->dados[f->n]=valor;
        f->n++;
        return 1;
    }
}

int desenfilerar(Fila *f){
    if(vazia(f)==1)return 0;
    else{
    	int i;
        int sair = f->dados[0];
        for(i=0;i< f->n ;i++){
            f->dados[i]=f->dados[i+1];    
        }
        f->n--;
		return(sair);
    }
}


int main(){
    struct fila F;
    int op,num,res;
    
    inicializar(&F,0,-999);
    
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
                printf("%d\n",primeiro(&F));
                break;
            case 4:
                printf("%d\n",quantidade(&F));
                break;
            case -1:
                break;
        }
        if(op!=-1) scanf("%d",&op);  
    }while(op!=-1);

    return 0;
}


