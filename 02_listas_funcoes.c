#include <stdio.h>

typedef struct Registro {
    int valor;
    struct registro *proximo; // Ponteiro para proximo elemento da lista
} REGISTRO;

void *procurarValor(REGISTRO *pRegistro, int valor){

    while(pRegistro != NULL){
        // Se valor atual é igual ao procurado
        if(pRegistro->valor == valor){
            // Retorna ponteiro para registro onde valor foi encontrado
            return(pRegistro);
        } else {
            // Passa para o próximo registro da lista
            pRegistro = pRegistro->proximo;
        }
    }
    // Se valor não for encontrado
    return(NULL);
}

int main(){

    REGISTRO m1, m2, m3;
    REGISTRO *resultado, *ptr = &m1; //ptr percorre a lista, resultado armazena o resultado
    int busca;

    // Atribui valores aos registros
    m1.valor = 10;
    m2.valor = 20;
    m3.valor = 30;

    // Conexão dos registros
    m1.proximo = &m2; // m1 -> m2
    m2.proximo = &m3; // m2 -> m3
    m3.proximo = NULL; // m3 é o último, -> NULL

    printf("Digite o valor da pesquisa: ");
    scanf("%i", &busca);

    resultado = procurarValor(ptr, busca);

    if(resultado == NULL){
        printf("Valor NAO encontrado!\n");
    } else {
        printf("Valor %i encontrado\n", resultado->valor);
    }


    system("pause");
    return 0;
}

//LINK DO VÍDEO: https://youtu.be/R3SwH_ttpZo?list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW
