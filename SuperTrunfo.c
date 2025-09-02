#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta
typedef struct {
    char estado[50];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular a densidade populacional e o PIB per capita
void calcularIndicadores(Carta *carta) {
    if (carta->area != 0) {
        carta->densidadePopulacional = carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0;
    }

    if (carta->populacao != 0) {
        carta->pibPerCapita = carta->pib / carta->populacao;
    } else {
        carta->pibPerCapita = 0;
    }
}

// Função para exibir os dados da carta
void exibirCarta(Carta carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("--------------------------------------\n");
}

// Função para comparar as cartas por um atributo
void compararCartasPorPopulacao(Carta c1, Carta c2) {
    printf("Comparação de cartas (Atributo: População):\n\n");

    printf("Carta 1 - %s (%s): %d habitantes\n", c1.nomeCidade, c1.estado, c1.populacao);
    printf("Carta 2 - %s (%s): %d habitantes\n\n", c2.nomeCidade, c2.estado, c2.populacao);

    if (c1.populacao > c2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
    } else if (c2.populacao > c1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
    } else {
        printf("Resultado: Empate! Ambas as cidades têm a mesma população.\n");
    }
}

// Função principal
int main() {
    // Cadastro das cartas (dados fictícios ou reais)
    Carta carta1 = {
        "São Paulo",
        "SP01",
        "São Paulo",
        12300000,  // população
        1521.11,   // área
        2300.5,    // PIB em bilhões
        15
    };

    Carta carta2 = {
        "Rio de Janeiro",
        "RJ01",
        "Rio de Janeiro",
        6710000,   // população
        1182.3,    // área
        420.3,     // PIB em bilhões
        10
    };

    // Calcular densidade populacional e PIB per capita
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibir os dados das cartas
    printf("========== CARTA 1 ==========\n");
    exibirCarta(carta1);

    printf("========== CARTA 2 ==========\n");
    exibirCarta(carta2);

    // Comparar as cartas pelo atributo escolhido (neste caso: população)
    compararCartasPorPopulacao(carta1, carta2);

    return 0;
}
