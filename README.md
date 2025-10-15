# Projeto Final: Sistema de Gerenciamento Inteligente de Energia Residencial

## Integrantes do Grupo

* **Gabriel Gibin Leoncio** - RM: 565462
* **Rai Augusto Ribeiro** - RM: 562870
* **Rafael do Nascimento Silva** – RM: 566263
* **Pedro Henrique dos Santos Cardoso** - RM: 563268
* **Pedro Henrique Lisboa** – RM: 565722

## 📄 Descrição do Projeto

Este projeto, desenvolvido integralmente em **Linguagem C**, simula um sistema de gerenciamento inteligente de consumo de energia para uma residência. O programa permite que o usuário cadastre dinamicamente múltiplos dispositivos eletrônicos, especificando seu nome, consumo em kWh e nível de prioridade (Alta, Média ou Baixa).

Com base em um limite de energia fornecido pelo usuário, o sistema utiliza um algoritmo de ordenação para organizar os dispositivos por prioridade e, em seguida, decide quais deles podem permanecer ligados sem exceder o teto de consumo. O principal objetivo do projeto é analisar e comparar a eficiência de três algoritmos de ordenação clássicos (**Bubble Sort**, **Selection Sort** e **Insertion Sort**) na resolução deste problema prático, medindo seu tempo de execução e número de operações.

## 🚀 Evolução do Sistema ao Longo das Sprints

O projeto foi construído de forma incremental ao longo de quatro sprints, cada uma com objetivos específicos:

* **Sprint 1: Estruturação e Cadastro Dinâmico**
    * Criação da estrutura de dados (`struct`) para representar os dispositivos.
    * Implementação do cadastro de múltiplos dispositivos utilizando alocação dinâmica de memória (`malloc` e `free`), permitindo flexibilidade ao usuário.

* **Sprint 2: Lógica de Simulação Inteligente**
    * Introdução da lógica de simulação de consumo, onde o sistema decide quais dispositivos ligar com base na energia disponível.
    * Implementação do algoritmo **Bubble Sort** para ordenar os dispositivos por prioridade, garantindo que os mais essenciais sejam ativados primeiro.

* **Sprint 3: Análise Comparativa de Algoritmos**
    * Aprimoramento do sistema para análise de desempenho, com a adição do **Selection Sort**.
    * Integração da biblioteca `<time.h>` para medir o tempo de execução e de contadores para registrar o número de comparações de cada algoritmo.

* **Sprint 4: Consolidação e Entregável Final**
    * Finalização do código com a adição do **Insertion Sort** para enriquecer a análise comparativa.
    * Consolidação de todas as funcionalidades em um programa único e robusto.
    * Produção da documentação final, incluindo este README, um relatório técnico e um vídeo de apresentação.

## ✨ Funcionalidades

* Cadastro dinâmico de um número ilimitado de dispositivos.
* Simulação de consumo de energia com base em um limite pré-definido.
* Menu interativo para escolha entre 3 algoritmos de ordenação: Bubble Sort, Selection Sort e Insertion Sort.
* Análise de desempenho em tempo real, exibindo o tempo de execução e o número de comparações do algoritmo escolhido.
* Relatório final claro sobre o status (Ligado/Desligado) de cada dispositivo e o consumo total de energia.

## 🛠️ Tecnologias Utilizadas

* **Linguagem C** (Padrão C99/C11)
* Bibliotecas Padrão: `stdio.h`, `stdlib.h`, `string.h`, `time.h`

## ⚙️ Instruções de Compilação e Execução

### Pré-requisitos

Para compilar e executar este projeto, você precisará de um compilador C. O **GCC** é o mais comum.
* **No Linux/macOS:** Geralmente já vem instalado ou pode ser instalado via gerenciador de pacotes (`sudo apt-get install gcc`).
* **No Windows:** Recomenda-se a instalação do **MinGW-w64**.

### Compilação

1.  Abra o seu terminal ou prompt de comando.
2.  Navegue até o diretório onde você salvou o arquivo `.c` do projeto.
3.  Execute o seguinte comando para compilar o programa:

    ```bash
    gcc nome_do_arquivo.c -o simulador_energia
    ```
    *(Substitua `nome_do_arquivo.c` pelo nome real do seu arquivo fonte)*.

### Execução

1.  Após a compilação, um arquivo executável será criado. Para executá-lo, utilize o comando:

    * No **Linux/macOS**:
        ```bash
        ./simulador_energia
        ```
    * No **Windows**:
        ```bash
        simulador_energia.exe
        ```
2.  Siga as instruções interativas no console para usar o programa.

## 📊 Resultados Comparativos

Para obter os seguintes resultados, o programa foi executado com um conjunto de dispositivos cujas prioridades foram geradas em ordem aleatória, simulando um cenário de caso de uso comum.

***Nota: Substitua os valores entre colchetes `[*...]` pelos resultados que você obteve ao executar o programa.***

### Cenário de Teste 1: 500 Dispositivos

| Algoritmo       | Tempo de Execução (s)   | Número de Comparações |
| :-------------- | :---------------------- | :-------------------- |
| **Bubble Sort** | `*[insira o tempo aqui]*`   | `*[124750]*`            |
| **Selection Sort**| `*[insira o tempo aqui]*`   | `*[124750]*`            |
| **Insertion Sort**| `*[insira o tempo aqui]*`   | `*[insira as comps aqui]*` |

### Cenário de Teste 2: 5000 Dispositivos

| Algoritmo       | Tempo de Execução (s)   | Número de Comparações  |
| :-------------- | :---------------------- | :--------------------- |
| **Bubble Sort** | `*[insira o tempo aqui]*`   | `*[12497500]*`           |
| **Selection Sort**| `*[insira o tempo aqui]*`   | `*[12497500]*`           |
| **Insertion Sort**| `*[insira o tempo aqui]*`   | `*[insira as comps aqui]*`  |

*(O número de comparações para Bubble e Selection Sort é fixo e dado por `n(n-1)/2`. Para o Insertion Sort, este valor varia dependendo da ordem inicial dos dados).*

---
