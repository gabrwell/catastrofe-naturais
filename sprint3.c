// Gabriel Gibin Leoncio - RM: 565462
// Rai Augusto Ribeiro - RM: 562870
// Rafael do Nascimento Silva – RM: 566263
// Pedro Henrique dos Santos Cardoso - RM: 563268
// Pedro Henrique Lisboa – RM: 565722

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Biblioteca para medir o" tempo de execução

#define TAM_NOME 50

typedef struct {
    char nome[TAM_NOME];
    float consumo;    // em kWh
    int prioridade;   // 1 = Alta, 2 = Média, 3 = Baixa
    int ligado;       // 1 = ligado, 0 = desligado (para simulação)
} Dispositivo;

// Protótipos das funções
void cadastrarDispositivos(Dispositivo *disps, int qtd);
long long bubbleSort(Dispositivo *disps, int qtd);
long long selectionSort(Dispositivo *disps, int qtd);
float simularConsumo(Dispositivo *disps, int qtd, float energiaDisponivel, int algoritmo);
void exibirResultadoSimulacao(const Dispositivo *disps, int qtd);

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar dispositivos
void cadastrarDispositivos(Dispositivo *disps, int qtd) {
    for (int i = 0; i < qtd; ++i) {
        printf("Cadastro do dispositivo %d:\n", i + 1);

        printf("Nome: ");
        limparBuffer(); // Limpa o buffer antes de ler a string
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

// Algoritmo Bubble Sort para ordenar por prioridade
// Retorna o número de comparações
long long bubbleSort(Dispositivo *disps, int qtd) {
    long long comparacoes = 0;
    for (int i = 0; i < qtd - 1; ++i) {
        for (int j = 0; j < qtd - i - 1; ++j) {
            comparacoes++; // Incrementa o contador a cada comparação
            if (disps[j].prioridade > disps[j + 1].prioridade) {
                Dispositivo temp = disps[j];
                disps[j] = disps[j + 1];
                disps[j + 1] = temp;
            }
        }
    }
    return comparacoes;
}

// Algoritmo Selection Sort para ordenar por prioridade
// Retorna o número de comparações
long long selectionSort(Dispositivo *disps, int qtd) {
    long long comparacoes = 0;
    for (int i = 0; i < qtd - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < qtd; j++) {
            comparacoes++; // Incrementa o contador a cada comparação
            if (disps[j].prioridade < disps[min_idx].prioridade) {
                min_idx = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        Dispositivo temp = disps[min_idx];
        disps[min_idx] = disps[i];
        disps[i] = temp;
    }
    return comparacoes;
}

// Função de simulação: decide quais dispositivos ficam ligados
float simularConsumo(Dispositivo *disps, int qtd, float energiaDisponivel, int algoritmo) {
    float consumoTotal = 0.0;
    long long comparacoes = 0;
    clock_t inicio, fim;
    double tempo_gasto;

    inicio = clock(); // Marca o tempo de início da ordenação

    if (algoritmo == 1) {
        printf("\nOrdenando com Bubble Sort...\n");
        comparacoes = bubbleSort(disps, qtd);
    } else {
        printf("\nOrdenando com Selection Sort...\n");
        comparacoes = selectionSort(disps, qtd);
    }

    fim = clock(); // Marca o tempo de fim da ordenação

    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Ordenação concluída.\n");
    printf("Tempo de execução do algoritmo: %f segundos\n", tempo_gasto);
    printf("Número de comparações: %lld\n", comparacoes);

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
    int escolhaAlgoritmo;

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

    printf("\nEscolha o algoritmo de ordenação para a simulação:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("Sua escolha: ");
    scanf("%d", &escolhaAlgoritmo);

    if (escolhaAlgoritmo != 1 && escolhaAlgoritmo != 2) {
        printf("Opção inválida. Usando Bubble Sort como padrão.\n");
        escolhaAlgoritmo = 1;
    }

    float consumoFinal = simularConsumo(dispositivos, qtd, energiaDisp, escolhaAlgoritmo);

    exibirResultadoSimulacao(dispositivos, qtd);

    printf("\nConsumo total após simulação: %.2f kWh\n", consumoFinal);
    printf("Energia restante: %.2f kWh\n", energiaDisp - consumoFinal);

    free(dispositivos);
    return 0;
}