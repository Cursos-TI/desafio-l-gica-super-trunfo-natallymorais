#include <stdio.h>
#include <string.h>

// Estrutura representando uma carta de país
typedef struct {
    char nomePais[50];
    int populacao;              // Em milhões
    float area;                 // Em km²
    float pib;                  // Em trilhões
    int pontosTuristicos;
    float densidadeDemografica; // hab/km²
} Carta;

// Calcula a densidade demográfica (população / área)
void calcularDensidade(Carta *carta) {
    if (carta->area != 0) {
        carta->densidadeDemografica = carta->populacao * 1.0f / carta->area;
    } else {
        carta->densidadeDemografica = 0;
    }
}

// Função que mostra o menu e retorna a opção escolhida
int mostrarMenu() {
    int opcao;
    printf("\n===== MENU DE COMPARAÇÃO =====\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de pontos turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Escolha o atributo para comparação (1 a 5): ");
    scanf("%d", &opcao);
    return opcao;
}

// Função que realiza a comparação com base na escolha do usuário
void compararCartas(Carta c1, Carta c2, int opcao) {
    printf("\n===== COMPARAÇÃO ENTRE PAÍSES =====\n");
    printf("Carta 1: %s\n", c1.nomePais);
    printf("Carta 2: %s\n\n", c2.nomePais);

    switch (opcao) {
        case 1:
            // População
            printf("Atributo: População (em milhões)\n");
            printf("%s: %d mi\n", c1.nomePais, c1.populacao);
            printf("%s: %d mi\n", c2.nomePais, c2.populacao);
            if (c1.populacao > c2.populacao) {
                printf("Resultado: %s venceu!\n", c1.nomePais);
            } else if (c2.populacao > c1.populacao) {
                printf("Resultado: %s venceu!\n", c2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            // Área
            printf("Atributo: Área (em km²)\n");
            printf("%s: %.2f km²\n", c1.nomePais, c1.area);
            printf("%s: %.2f km²\n", c2.nomePais, c2.area);
            if (c1.area > c2.area) {
                printf("Resultado: %s venceu!\n", c1.nomePais);
            } else if (c2.area > c1.area) {
                printf("Resultado: %s venceu!\n", c2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            // PIB
            printf("Atributo: PIB (em trilhões)\n");
            printf("%s: %.2f trilhões\n", c1.nomePais, c1.pib);
            printf("%s: %.2f trilhões\n", c2.nomePais, c2.pib);
            if (c1.pib > c2.pib) {
                printf("Resultado: %s venceu!\n", c1.nomePais);
            } else if (c2.pib > c1.pib) {
                printf("Resultado: %s venceu!\n", c2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            // Pontos turísticos
            printf("Atributo: Número de pontos turísticos\n");
            printf("%s: %d\n", c1.nomePais, c1.pontosTuristicos);
            printf("%s: %d\n", c2.nomePais, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", c1.nomePais);
            } else if (c2.pontosTuristicos > c1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", c2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            // Densidade demográfica (regra invertida: menor vence)
            printf("Atributo: Densidade Demográfica (hab/km²)\n");
            printf("%s: %.2f hab/km²\n", c1.nomePais, c1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", c2.nomePais, c2.densidadeDemografica);
            if (c1.densidadeDemografica < c2.densidadeDemografica) {
                printf("Resultado: %s venceu (menor densidade)!\n", c1.nomePais);
            } else if (c2.densidadeDemografica < c1.densidadeDemografica) {
                printf("Resultado: %s venceu (menor densidade)!\n", c2.nomePais);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            // Opção inválida
            printf("Opção inválida! Tente novamente com uma opção de 1 a 5.\n");
            break;
    }
}

int main() {
    // Definindo duas cartas fixas de países
    Carta carta1 = {
        "Brasil",
        213,         // população em milhões
        8515767,     // área em km²
        2.1,         // PIB em trilhões
        25           // pontos turísticos
    };

    Carta carta2 = {
        "Canadá",
        38,          // população em milhões
        9984670,     // área em km²
        1.9,         // PIB em trilhões
        18           // pontos turísticos
    };

    // Calcular a densidade demográfica das duas cartas
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    // Mostrar menu e capturar opção
    int opcao = mostrarMenu();

    // Realizar a comparação
    compararCartas(carta1, carta2, opcao);

    return 0;
}
