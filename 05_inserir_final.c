#include <stdio.h>
#include <stdlib.h>

// Aula 244: Wagner Gaspar - https://youtu.be/nNZgbEGHcMQ?list=PLqJK4Oyr5WSgPpLg-lZJfJZN0DQ5bwrfP

// Contrução do nó que vai compor nossa lista
typedef struct no {
    int valor; 
    struct no *proximo;   
} NO;

// Procedimento para inserir no FINAL
// Elemento do tipo nó que é ponteiro de ponteiro, pois vai receber o & de um ponteiro (VAR QUE APONTA PRA UM NÓ)
void inserirFim(NO **lista, int num) {  
    // Cria-se um nó auxiliar '*aux'
    NO *aux, *novo = malloc(sizeof(NO));

    if(novo){
        novo->valor = num;
        // Insere no final, logo o novo nó será o último nó da lista, logo o próximo será NULL
        novo->proximo = NULL;

        // É o primeiro da lista?
        if(*lista == NULL){
            // Conteúdo (ou primeiro nó) da posição é o endereço do novo nó (ou somente novo nó)
            *lista = novo;
        } else {
            aux = *lista;
            // repetição para percorrer a lista até o último nó, enquanto existir um próximo
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }

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
    inserirFim(&lista, 30);
    inserirFim(&lista, 20);
    inserirFim(&lista, 10);
    imprimirLista(lista);
    return 0;
}