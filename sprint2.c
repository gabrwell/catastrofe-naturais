// Gabriel Gibin leoncio - RM: 565462
// Rai Augusto Ribeiro - RM: 562870
// Rafael do Nascimento Silva – RM: 566263
// Pedro Henrique dos Santos Cardoso - RM: 563268
// Pedro Henrique Lisboa – RM: 565722


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50

typedef struct {
    char nome[TAM_NOME];
    float consumo;   // em kWh
    int prioridade;  // 1 = Alta, 2 = Média, 3 = Baixa
    int ligado;      // 1 = ligado, 0 = desligado (para simulação)
} Dispositivo;

// Função para cadastrar dispositivos
void cadastrarDispositivos(Dispositivo *disps, int qtd) {
    for (int i = 0; i < qtd; ++i) {
        printf("Cadastro do dispositivo %d:\n", i + 1);

        printf("Nome: ");
        getchar(); // consome o '\n' pendente do scanf anterior
        fgets(disps[i].nome, TAM_NOME, stdin);
        size_t len = strlen(disps[i].nome);
        if (len > 0 && disps[i].nome[len - 1] == '\n')
            disps[i].nome[len - 1] = '\0';

        printf("Consumo estimado (kWh): ");
        scanf("%f", &disps[i].consumo);

        printf("Prioridade (1 = Alta, 2 = Média, 3 = Baixa): ");
        scanf("%d", &disps[i].prioridade);

        disps[i].ligado = 0; // Inicia desligado para simulação

        printf("\n");
    }
}

// Bubble sort para ordenar por prioridade (menor valor = maior prioridade)
void ordenarPorPrioridade(Dispositivo *disps, int qtd) {
    for (int i = 0; i < qtd - 1; ++i) {
        for (int j = 0; j < qtd - i - 1; ++j) {
            if (disps[j].prioridade > disps[j + 1].prioridade) {
                Dispositivo temp = disps[j];
                disps[j] = disps[j + 1];
                disps[j + 1] = temp;
            }
        }
    }
}

// Função de simulação: decide quais dispositivos ficam ligados
float simularConsumo(Dispositivo *disps, int qtd, float energiaDisponivel) {
    float consumoTotal = 0.0;
    ordenarPorPrioridade(disps, qtd); // Ordena para ligar os de maior prioridade primeiro

    for (int i = 0; i < qtd; ++i) {
        if (consumoTotal + disps[i].consumo <= energiaDisponivel) {
            disps[i].ligado = 1; // Liga o dispositivo
            consumoTotal += disps[i].consumo;
        } else {
            disps[i].ligado = 0; // Mantém desligado
        }
    }
    return consumoTotal;
}

// Exibe todos os dispositivos e seu status após simulação
void exibirResultadoSimulacao(const Dispositivo *disps, int qtd) {
    printf("\nResultado da Simulação:\n");
    for (int i = 0; i < qtd; ++i) {
        printf("Dispositivo: %s | Consumo: %.2f kWh | Prioridade: ", disps[i].nome, disps[i].consumo);
        if (disps[i].prioridade == 1) {
            printf("Alta");
        } else if (disps[i].prioridade == 2) {
            printf("Média");
        } else if (disps[i].prioridade == 3) {
            printf("Baixa");
        } else {
            printf("Desconhecida");
        }
        printf(" | Status: %s\n", disps[i].ligado ? "Ligado" : "Desligado");
    }
}

int main() {
    int qtd;
    float energiaDisp;
    
    printf("Quantos dispositivos deseja cadastrar? ");
    scanf("%d", &qtd);

    Dispositivo *dispositivos = (Dispositivo *)malloc(qtd * sizeof(Dispositivo));
    if (dispositivos == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    cadastrarDispositivos(dispositivos, qtd);

    printf("Informe a energia disponível para a casa (em kWh): ");
    scanf("%f", &energiaDisp);

    float consumoFinal = simularConsumo(dispositivos, qtd, energiaDisp);

    exibirResultadoSimulacao(dispositivos, qtd);

    printf("\nConsumo total após simulação: %.2f kWh\n", consumoFinal);
    printf("Energia restante: %.2f kWh\n", energiaDisp - consumoFinal);

    free(dispositivos);
    return 0;
}