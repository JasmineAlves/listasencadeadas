#include <stdio.h>
#include <stdlib.h>

// Aula 243: Wagner Gaspar - https://youtu.be/fkfi-KtO8co?list=PLqJK4Oyr5WSgPpLg-lZJfJZN0DQ5bwrfP

// Contrução do nó que vai compor nossa lista
typedef struct no {
    int valor; 
    struct no *proximo;   
} NO;

// Procedimento para inserir no INÍCIO
// Elemento do tipo nó que é ponteiro de ponteiro, pois vai receber o & de um ponteiro (VAR QUE APONTA PRA UM NÓ)
void inserirInicio(NO **lista, int num) {  
    NO *novo = malloc(sizeof(NO));

    // Confere se memória foi alocada corretamente
    if(novo){
        novo->valor = num; // Preenche valor no novo nó
        /* Novo nó aponta para o primeiro elemento da nossa lista atual;
         > Próximo será igual ao início da nossa lista
         > Ponteiro para primeiro nó = conteúdo da variável lista que está no main */
        novo->proximo =  *lista;
        /*Necessário atualizar o ínicio da lista (*lista = conteúdo que está nessa posição)
        > Início da lista passa a ser o novo nó */
        *lista = novo; 
    } else {
        puts("Erro ao alocar memória");
    }
}

void imprimirLista(NO *lista){
    while(lista != NULL){
        printf("%i -> ", lista->valor);
        lista = lista->proximo;
    }
    printf("NULL");
}

int main(){
    NO *lista = NULL;
    inserirInicio(&lista, 30);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 10);
    imprimirLista(lista);
    return 0;
}