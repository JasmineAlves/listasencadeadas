#include <stdio.h>

typedef struct Registro {
    int valor;
    struct registro *proximo;
} REGISTRO;


int main(void){ 
    REGISTRO m1, m2, m3;
    REGISTRO *ptr = &m1; // Ponteiro PTR aponta para m1 (tipo struct REGISTRO)

    m1.valor = 10;
    m2.valor = 20;
    m3.valor = 30;

    // CONCEITO DE LISTA - 
    m1.proximo = &m2;
    m2.proximo = &m3;
    // Último membro
    m3.proximo = NULL; // Ou (REGISTRO *)0; 

    // Enquanto não apontar em NULL, while é executado
    while(ptr != NULL){
        // ptr aponta m1, com valor n (início)
        printf("%i\n", ptr->valor);
        // 'prox' de m1 é m2, com valor n (e assim por diante)
        ptr = ptr->proximo;
    }

    getchar();
    return 0;
}