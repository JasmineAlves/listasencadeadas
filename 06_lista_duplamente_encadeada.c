#include <stdio.h>

typedef struct Registro{
    int valor;
    struct Registro *prox;
    struct Registro *ant;
} REGISTRO;

void inserir(REGISTRO **p_inicio, int valor) {
    // Aloca memória para o novo registro
    REGISTRO *novo = (REGISTRO*)malloc(sizeof(REGISTRO));

    novo->valor = valor;
    // Aponta o novo nó para o início da lista atual
    novo->prox = *p_inicio;
    novo->ant = NULL;

    // Se a lista não estiver vazia
    if (*p_inicio != NULL) {
        (*p_inicio)->ant = novo;    
    }

    // O novo nó se torna o início da lista
    *p_inicio = novo;
}

void imprimir(REGISTRO *p){
    // Enquanto existir registros
    while(p != NULL){
        printf("%i -> ", p->valor);
        p = p->prox;
    }
    printf("NULL\n");
}

void excluir(REGISTRO **p_inicio, int valor) {

    REGISTRO *aux = *p_inicio;

    // Procura o primeiro registro que tenha o valor
    while (aux != NULL && aux->valor != valor) {
        aux = aux->prox;
    }

    // Se encontrou o nó com o valor
    if (aux != NULL) {

        // Ajusta o ponteiro do próximo nó, se existir
        if (aux->prox != NULL) {
            aux->prox->ant = aux->ant;
        }

         // Ajusta o ponteiro do nó anterior, se existir
        if (aux->ant != NULL) {
            aux->ant->prox = aux->prox;
        } else {
            // Se é o primeiro, ajusta o início
            *p_inicio = aux->prox;
        }

        // Libera memória do nó a ser removido
        free(aux);  
    }
}

int main(){ 
    // Ponteiro 'inicio' para struct do tipo registro
    REGISTRO *inicio = NULL;

    //Chama função inserir - endereço de início + valor
    inserir(&inicio, 10);
    inserir(&inicio, 20);
    inserir(&inicio, 30);

    //Função imprimir
    imprimir(inicio);

    //Excluir e imprimir
    excluir(&inicio, 20);
    imprimir(inicio);

    return 0;
}