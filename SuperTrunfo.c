#include <stdio.h>

int main (){
    // declarando variaveis
    int populacao, NPT;
    float area, PIB, densidadePopulacional, PIBpercapita;
    char estado, codigoDaCarta, nomeDaCidade, cidadeVencedora;

    printf("Digite o código da cidade: ");
    scanf("%s", codigoDaCarta);

    densidadePopulacional = (populacao / area);
    PIBpercapita = (PIB / populacao);

    if (populacaoA > populacaoB) {
        printf("Cidade 1 tem maior população.\n");
    } else {
        printf("Cidade 2 tem maior população.\n");
    }

    printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}