// ===================================================================================
// PROJETO FINAL: Sistema de Gerenciamento Inteligente de Energia Residencial
// DISCIPLINA: [ESTRUTURA DE DADOS E ALGORITMOS]
// ===================================================================================
// INTEGRANTES:
// Gabriel Gibin Leoncio - RM: 565462
// Rai Augusto Ribeiro - RM: 562870
// Rafael do Nascimento Silva – RM: 566263
// Pedro Henrique dos Santos Cardoso - RM: 563268
// Pedro Henrique Lisboa – RM: 565722
// ===================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Biblioteca para medir o tempo de execução

#define TAM_NOME 50

// Estrutura para representar um dispositivo (da Sprint 1)
typedef struct {
    char nome[TAM_NOME];
    float consumo;    // em kWh
    int prioridade;   // 1 = Alta, 2 = Média, 3 = Baixa
    int ligado;       // 1 = ligado, 0 = desligado (adicionado na Sprint 2)
} Dispositivo;

// --- Protótipos das Funções ---
void limparBuffer();
void cadastrarDispositivos(Dispositivo *disps, int qtd);
long long bubbleSort(Dispositivo *disps, int qtd);
long long selectionSort(Dispositivo *disps, int qtd);
long long insertionSort(Dispositivo *disps, int qtd); // NOVO para a Sprint 4
float simularConsumo(Dispositivo *disps, int qtd, float energiaDisponivel, int algoritmo);
void exibirResultadoSimulacao(const Dispositivo *disps, int qtd);

// --- Função Principal ---
int main() {
    int qtd;
    float energiaDisp;
    int escolhaAlgoritmo;

    printf("=========================================================\n");
    printf("  Sistema de Gerenciamento Inteligente de Energia\n");
    printf("=========================================================\n\n");

    printf("Quantos dispositivos deseja cadastrar? ");
    scanf("%d", &qtd);

    // Alocação dinâmica de memória (da Sprint 1)
    Dispositivo *dispositivos = (Dispositivo *)malloc(qtd * sizeof(Dispositivo));
    if (dispositivos == NULL) {
        printf("Erro fatal: Falha na alocação de memória!\n");
        return 1;
    }

    cadastrarDispositivos(dispositivos, qtd);

    printf("Informe a energia total disponível para a casa (em kWh): ");
    scanf("%f", &energiaDisp);

    // Menu para escolha do algoritmo (da Sprint 3, agora com mais uma opção)
    printf("\n--- Escolha do Algoritmo de Ordenação para a Simulação ---\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort (Novo)\n");
    printf("Sua escolha: ");
    scanf("%d", &escolhaAlgoritmo);

    if (escolhaAlgoritmo < 1 || escolhaAlgoritmo > 3) {
        printf("Opção inválida. Usando Bubble Sort como padrão.\n");
        escolhaAlgoritmo = 1;
    }

    // Executa a simulação (lógica da Sprint 2 com análise da Sprint 3)
    float consumoFinal = simularConsumo(dispositivos, qtd, energiaDisp, escolhaAlgoritmo);

    exibirResultadoSimulacao(dispositivos, qtd);

    printf("\n--- Resumo do Consumo ---\n");
    printf("Consumo total simulado: %.2f kWh\n", consumoFinal);
    printf("Energia disponível inicial: %.2f kWh\n", energiaDisp);
    printf("Energia restante: %.2f kWh\n", energiaDisp - consumoFinal);

    // Libera a memória alocada (da Sprint 1)
    free(dispositivos);
    return 0;
}

// --- Implementação das Funções ---

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarDispositivos(Dispositivo *disps, int qtd) {
    for (int i = 0; i < qtd; ++i) {
        printf("\n--- Cadastro do Dispositivo %d ---\n", i + 1);
        printf("Nome: ");
        limparBuffer();
        fgets(disps[i].nome, TAM_NOME, stdin);
        disps[i].nome[strcspn(disps[i].nome, "\n")] = 0; // Remove a nova linha de forma segura

        printf("Consumo estimado (kWh): ");
        scanf("%f", &disps[i].consumo);

        printf("Prioridade (1=Alta, 2=Média, 3=Baixa): ");
        scanf("%d", &disps[i].prioridade);

        disps[i].ligado = 0;
    }
}

// Algoritmo Bubble Sort (da Sprint 2, modificado na Sprint 3)
long long bubbleSort(Dispositivo *disps, int qtd) {
    long long comparacoes = 0;
    for (int i = 0; i < qtd - 1; ++i) {
        for (int j = 0; j < qtd - i - 1; ++j) {
            comparacoes++;
            if (disps[j].prioridade > disps[j + 1].prioridade) {
                Dispositivo temp = disps[j];
                disps[j] = disps[j + 1];
                disps[j + 1] = temp;
            }
        }
    }
    return comparacoes;
}

// Algoritmo Selection Sort (da Sprint 3)
long long selectionSort(Dispositivo *disps, int qtd) {
    long long comparacoes = 0;
    for (int i = 0; i < qtd - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < qtd; j++) {
            comparacoes++;
            if (disps[j].prioridade < disps[min_idx].prioridade) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Dispositivo temp = disps[min_idx];
            disps[min_idx] = disps[i];
            disps[i] = temp;
        }
    }
    return comparacoes;
}

// Insertion Sort (para a Sprint 4)
long long insertionSort(Dispositivo *disps, int qtd) {
    long long comparacoes = 0;
    for (int i = 1; i < qtd; i++) {
        Dispositivo chave = disps[i];
        int j = i - 1;
        
        while (j >= 0) {
            comparacoes++;
            if (disps[j].prioridade > chave.prioridade) {
                disps[j + 1] = disps[j];
                j = j - 1;
            } else {
                break; // Encontrou a posição correta
            }
        }
        disps[j + 1] = chave;
    }
    return comparacoes;
}

// Função de simulação principal (da Sprint 3, agora com 3 opções)
float simularConsumo(Dispositivo *disps, int qtd, float energiaDisponivel, int algoritmo) {
    long long comparacoes = 0;
    clock_t inicio, fim;
    double tempo_gasto;
    char *nomeAlgoritmo;

    inicio = clock();

    // Usando switch para melhor organização
    switch (algoritmo) {
        case 1:
            nomeAlgoritmo = "Bubble Sort";
            comparacoes = bubbleSort(disps, qtd);
            break;
        case 2:
            nomeAlgoritmo = "Selection Sort";
            comparacoes = selectionSort(disps, qtd);
            break;
        case 3:
            nomeAlgoritmo = "Insertion Sort";
            comparacoes = insertionSort(disps, qtd);
            break;
    }

    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\n--- Análise de Desempenho (%s) ---\n", nomeAlgoritmo);
    printf("Tempo de execução da ordenação: %f segundos\n", tempo_gasto);
    printf("Número de comparações realizadas: %lld\n", comparacoes);

    float consumoTotal = 0.0;
    for (int i = 0; i < qtd; ++i) {
        if (consumoTotal + disps[i].consumo <= energiaDisponivel) {
            disps[i].ligado = 1;
            consumoTotal += disps[i].consumo;
        } else {
            disps[i].ligado = 0;
        }
    }
    return consumoTotal;
}

// Exibe o resultado final da simulação (da Sprint 2, com formatação melhorada)
void exibirResultadoSimulacao(const Dispositivo *disps, int qtd) {
    printf("\n--- Resultado da Simulação de Consumo ---\n");
    for (int i = 0; i < qtd; ++i) {
        printf("Dispositivo: %-20s | Consumo: %5.2f kWh | Prioridade: %d | Status: %s\n",
               disps[i].nome,
               disps[i].consumo,
               disps[i].prioridade,
               disps[i].ligado ? "LIGADO" : "DESLIGADO");
    }
}