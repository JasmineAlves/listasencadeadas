#include <stdio.h>

typedef struct Registro{
    int valor;
    struct Registro *prox;
} REGISTRO;


//'**ref' pois 'inicio' já é ponteiro, logo é recebido pela função como ponteiro de ponteiro
void inserir(REGISTRO **ref, int valor){

    // Aloca memória para o novo nó 'p'
    // Malloc sempre retorna um endereço sem tipo, por isso é convertido em (REGISTRO *)
    REGISTRO *aux, *p = (REGISTRO *) malloc(sizeof(REGISTRO));

    // Atribuição do valor passado ao novo nó 'p'
    p->valor = valor;
    // Novo nó 'p' aponta para o último elemento da lista (Próximo do novo nó é o último elemento)
    p->prox = NULL;
    
    // Se é o primeiro nó da lista
    if(*ref == NULL){
        *ref = p; 
    } else { 
        // Necessário percorrer a lista pra achar o úlitmo nó, criado *aux
        aux = *ref;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        // Próximo de aux vai receber o novo nó
        aux->prox = p;
    }
}

void imprimir(REGISTRO *p){

    // Enquanto existir registros
    while(p != NULL){
        printf("%i -> ", p->valor);
        p = p->prox;
    }

    printf("NULL\n");
}

void excluir(REGISTRO **ref){
    REGISTRO *p = *ref;

    // Verifica se o pronteiro que contém o início da lista é NULL (está vazia, logo não há exclusões)
    if(*ref == NULL) {
        puts("A lista esta VAZIA!");
        return;
    }

    /* Verifica se a lista tem apenas 1 elemento; caso tenha o próximo será NULL (sem mais nós)
    > p->prox é o mesmo que (*ref)->prox, ou seja, confere o próximo do primeiro nó da lista */
    if(p->prox == NULL){    
        free(p);
        p = NULL; // Ajuste de p (primeiro item) para null, tornando a lista vazia
        return;
    }


    /* Se tem mais de um elemento, é preciso encontrar o penúltimo nó
    > Penúltimo nó: aquele que o seu proximo aponta para o último elemento da lista
    > se prox->prox = NULL, o nó atual é o penúltimo */
    while(p->prox->prox != NULL){
        p = p->prox;
    }

    free(p->prox);
    // Ajuste do proximo para NULL
    p->prox = NULL;
    
}

void main(){

// Ponteiro 'inicio' para struct do tipo registro
REGISTRO *inicio = NULL;

//Chama função inserir - endereço de início + valor
inserir(&inicio, 10);
inserir(&inicio, 20);
inserir(&inicio, 30);

//Função imprimir
imprimir(inicio);

//Excluir e imprimir
excluir(&inicio);
imprimir(inicio);
}