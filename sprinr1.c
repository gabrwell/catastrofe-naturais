#include <stdio.h>      // Inclui as funções de entrada e saída, como printf e scanf
#include <stdlib.h>     // Inclui funções para alocação de memória dinâmica, como malloc e free
#include <string.h>     // Inclui funções para manipulação de strings, como strlen e fgets

#define TAM_NOME 50     // Define um tamanho fixo para o campo de nome

// Definição da estrutura Dispositivo
typedef struct {
    char nome[TAM_NOME];   // Nome do dispositivo, até 49 caracteres + terminador '\0'
    float consumo;         // Consumo estimado em kWh
    int prioridade;        // Prioridade: 1 = Alta, 2 = Média, 3 = Baixa
} Dispositivo;

// Função para cadastrar dispositivos, recebe um ponteiro para vetor de Dispositivo e a quantidade
void cadastrarDispositivos(Dispositivo *disps, int qtd) {
    for (int i = 0; i < qtd; ++i) { // Loop para cada dispositivo
        printf("Cadastro do dispositivo %d:\n", i + 1);

        printf("Nome: ");
        getchar(); // Limpa o buffer do teclado 
        fgets(disps[i].nome, TAM_NOME, stdin); // Lê o nome do dispositivo

        // Remove o caractere '\n' do final, se existir
        size_t len = strlen(disps[i].nome);
        if (len > 0 && disps[i].nome[len - 1] == '\n') {
            disps[i].nome[len - 1] = '\0';
        }

        printf("Consumo estimado (kWh): ");
        scanf("%f", &disps[i].consumo); // Lê o valor do consumo

        printf("Prioridade (1 = Alta, 2 = Média, 3 = Baixa): ");
        scanf("%d", &disps[i].prioridade); // Lê a prioridade

        printf("\n"); 
    }
}

// Função para exibir os dispositivos cadastrados, recebe ponteiro constante e quantidade
void exibirDispositivos(const Dispositivo *disps, int qtd) {
    printf("Lista de Dispositivos Cadastrados:\n");
    for (int i = 0; i < qtd; ++i) { // Loop sobre todos os dispositivos
        printf("Dispositivo %d:\n", i + 1);
        printf("Nome: %s\n", disps[i].nome); // Exibe nome
        printf("Consumo: %.2f kWh\n", disps[i].consumo); // Exibe consumo com duas casas decimais
        printf("Prioridade: ");
        // Verifica a prioridade e exibe mensagem personalizada
        if (disps[i].prioridade == 1) {
            printf("Alta - Dispositivo essencial! Controle rigoroso sugerido.\n");
        } else if (disps[i].prioridade == 2) {
            printf("Média - Importante, mas pode ser adiado em picos de consumo.\n");
        } else if (disps[i].prioridade == 3) {
            printf("Baixa - Pode ser desligado em momentos críticos de economia.\n");
        } else {
            printf("Desconhecida - Prioridade não reconhecida.\n");
        }
        printf("\n"); 
    }
}

int main() {
    int qtd; // Variável para armazenar a quantidade de dispositivos

    printf("Quantos dispositivos deseja cadastrar? ");
    scanf("%d", &qtd); // Lê a quantidade de dispositivos que o usuário quer cadastrar

    // Aloca dinamicamente memória para o vetor de Dispositivo, usando malloc
    Dispositivo *dispositivos = (Dispositivo *)malloc(qtd * sizeof(Dispositivo));
    if (dispositivos == NULL) { // Verifica se a alocação foi bem-sucedida
        printf("Erro de alocação de memória!\n");
        return 1; // Sai do programa com erro
    }

    cadastrarDispositivos(dispositivos, qtd); // Chama função para cadastrar dispositivos
    exibirDispositivos(dispositivos, qtd);    // Chama função para exibir dispositivos

    free(dispositivos); // Libera a memória alocada dinamicamente
    return 0; // Fim do programa
}