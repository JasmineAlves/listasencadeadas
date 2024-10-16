#include <stdio.h>
#include <stdlib.h>

typedef struct sRegistro{
    int valor;
    struct sRegistro *prox;
} REGISTRO;

typedef REGISTRO *LISTA;

void inserir(REGISTRO **ref, int valor){
    REGISTRO *p = (REGISTRO *) malloc(sizeof(REGISTRO));

    p->valor = valor;
    p->prox = *ref;
    *ref = p;
}

void excluir(REGISTRO **ref, int valor){
    REGISTRO *temp = *ref, *ant;

    if(temp != NULL && temp->valor == valor) {
        *ref = temp->prox; 
        free(temp);
        return;
    }
        
    while(temp != NULL && temp->valor != valor){
        ant = temp;  
        temp = temp->prox; 
    }

    if(temp == NULL) return;

    ant->prox = temp->prox;
    free(temp);
}

void mostrar(REGISTRO *p){
    while(p != NULL){
        printf("%i -> ", p->valor);
        p = p->prox;
    }

    printf("NULL\n");
}

void bubbleSort(LISTA *l){
    int troca;
    REGISTRO *atual;
    REGISTRO *proximo = NULL;
    do {
        troca = 0;
        atual = *l;
        
        while (atual->prox != proximo) {
            if (atual->valor > atual->prox->valor) {
            // Trocar os valores
                int tempValor = atual->valor;
                atual->valor = atual->prox->valor;
                atual->prox->valor = tempValor;
                troca = 1;
            }
            atual = atual->prox;
        }
        proximo = atual;
    } while (troca);
}


int main(){
    REGISTRO *inicio = NULL;
    int opcao;

    do {

        puts("------MENU------");
        puts("1 - Inserir REGISTRO");
        puts("2 - Excluir REGISTRO");
        puts("3 - Mostrar LISTA");
        puts("4 - Ordenar LISTA");
        puts("5 - Sair");
        puts("Opção: ");
        scanf("%d", &opcao);

        switch(opcao){

        case 1:
            inserir(&inicio, 20);
            inserir(&inicio, 30);
            inserir(&inicio, 10);
            break;

        case 2:
            excluir(&inicio, 20);
            break;

        case 3:
            mostrar(inicio);
            break;

        case 4:
            bubbleSort(&inicio);
            puts("Lista ordenada!");
            break;

        default:
            break;

        }
    } while(opcao != 5);

    return 0;
}
