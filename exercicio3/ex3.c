#include <stdio.h>
#include <stdlib.h> 
#define MEDIA_APROVACAO 7.0

float calcularMediaTurma(float notas[], int numEstudantes) {
    float soma = 0.0;
    int i;
    if (numEstudantes <= 0) {
        return 0.0;
    }
    for (i = 0; i < numEstudantes; i++) {
        soma += notas[i];
    }
    return soma / numEstudantes;
}


void imprimirResultados(float notas[], int numEstudantes) {
    int i;
    printf("\n Resultados Individuais \n");
    for (i = 0; i < numEstudantes; i++) {
        printf("Estudante %d (Nota %.1f): ", i + 1, notas[i]);
        if (notas[i] >= MEDIA_APROVACAO) {
            printf("Aprovado\n");
        } else {
            printf("Recuperação\n");
        }
    }
}

int main() {
    int numEstudantes;
    float *notas; 
    float mediaDaTurma;
    int i;
    printf("Digite o número de estudantes: ");
    scanf("%d", &numEstudantes);
    if (numEstudantes <= 0) {
        printf("Número de estudantes inválido. O programa será encerrado.\n");
        return 1; 
    }
    notas = (float *) malloc(numEstudantes * sizeof(float));

    if (notas == NULL) {
        printf("Erro ao alocar memória. O programa será encerrado.\n");
        return 1;
    }
    printf("\nInsira a nota final de cada estudante:\n");
    for (i = 0; i < numEstudantes; i++) {
        printf("Nota do Estudante %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    mediaDaTurma = calcularMediaTurma(notas, numEstudantes);
    printf("A média geral da turma é: %.2f\n", mediaDaTurma);
    imprimirResultados(notas, numEstudantes);
    float notas[numEstudantes];
    return 0;