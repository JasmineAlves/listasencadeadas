#include <stdio.h>

typedef struct Registro{
    int valor;
    struct Registro *prox;
} REGISTRO;


//'**ref' pois 'inicio' já é ponteiro, logo é recebido pela função como ponteiro de ponteiro
void inserir(REGISTRO **ref, int valor){

    // Aloca memória para o novo nó 'p'
    // Malloc sempre retorna um endereço sem tipo, por isso é convertido em (REGISTRO *)
    REGISTRO *p = (REGISTRO *) malloc(sizeof(REGISTRO));

    // Atribuição do valor passado ao novo nó 'p'
    p->valor = valor;
    // Novo nó 'p' aponta para o ínicio atual da lista (próximo nó será o que antes era o ínicio)
    p->prox = *ref;
    // Att o ponteiro que aponta para o início da lista para que aponte para o novo nó
    *ref = p;
}

void imprimir(REGISTRO *p){

    // Enquanto existir registros
    while(p != NULL){
        printf("%i -> ", p->valor);
        p = p->prox;
    }

    printf("NULL\n");
}

void excluir(REGISTRO **ref, int valor){

    // Ponteiro '*temp' recebe inicio da lista, '*ant' será usado para localizar nó anterior
    REGISTRO *temp = *ref, *ant;

    // Se o nó a ser excluído é o primeiro
    if(temp != NULL && temp->valor == valor) {
        *ref = temp->prox; // Att o ponteiro de inicio para o próximo nó, removendo o primeiro
        free(temp);
        return;
    }
        
    // Procura pelo nó a ser excluído (enquanto não chegamos ao fim ou ao valor)
    while(temp != NULL && temp->valor != valor){
        ant = temp; // 'ant' guarda o nó anterior a temp p/ reconectar 
        temp = temp->prox; // 'temp' recebe o ponteiro do próximo nó
    }

    // Se o nó não foi encontrado encerra a função
    if(temp == NULL) return;

    // Se nó foi encontrado, desconecta o nó da lista e libera memória
    ant->prox = temp->prox; // Ponteiro do nó anterior aponta para o do próximo, ignorando o atual 'temp'
    free(temp);
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
excluir(&inicio, 20);
imprimir(inicio);
}