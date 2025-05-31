# Sistema de Cadastro de Dispositivos Elétricos

Este projeto consiste em um programa em C para cadastrar e exibir dispositivos elétricos, permitindo ao usuário informar o nome, consumo energético e prioridade de cada aparelho. O objetivo é oferecer uma base para controle e análise do consumo de energia, facilitando a priorização de dispositivos em situações de economia ou gerenciamento.

---

## Funcionalidades

- **Cadastro de Dispositivos:** Permite inserir o nome, consumo (em kWh) e prioridade de cada aparelho.
- **Listagem dos Dispositivos:** Exibe todos os dispositivos cadastrados com seus dados e uma mensagem personalizada conforme a prioridade.
- **Alocação Dinâmica:** O número de dispositivos é definido pelo usuário e a memória é alocada dinamicamente.
- **Validação Básica:** Confere se a alocação de memória foi bem-sucedida.

---

## Estrutura de Dados

Cada dispositivo é modelado como uma `struct`, com os seguintes campos:

```c
typedef struct {
    char nome[50];    // Nome do dispositivo (até 49 caracteres)
    float consumo;    // Consumo estimado em kWh
    int prioridade;   // 1 = Alta, 2 = Média, 3 = Baixa
} Dispositivo;
```

Os dispositivos são armazenados em um vetor alocado dinamicamente, permitindo flexibilidade na quantidade de cadastros.

---

## Exemplo de Uso

### Cadastro

Ao iniciar o programa, o usuário é questionado sobre quantos dispositivos deseja cadastrar. Para cada dispositivo, são solicitados:

- Nome
- Consumo estimado (kWh)
- Prioridade (1 = Alta, 2 = Média, 3 = Baixa)

#### Exemplo:

```
Quantos dispositivos deseja cadastrar? 2
Cadastro do dispositivo 1:
Nome: Geladeira
Consumo estimado (kWh): 30
Prioridade (1 = Alta, 2 = Média, 3 = Baixa): 1

Cadastro do dispositivo 2:
Nome: Ventilador
Consumo estimado (kWh): 5
Prioridade (1 = Alta, 2 = Média, 3 = Baixa): 3
```

---

### Listagem

Após o cadastro, todos os dispositivos são exibidos com suas informações e recomendações de uso:

```
Lista de Dispositivos Cadastrados:
Dispositivo 1:
Nome: Geladeira
Consumo: 30.00 kWh
Prioridade: Alta - Dispositivo essencial! Controle rigoroso sugerido.

Dispositivo 2:
Nome: Ventilador
Consumo: 5.00 kWh
Prioridade: Baixa - Pode ser desligado em momentos críticos de economia.
```

---

## Validação e Tratamento

- O programa verifica se a memória foi alocada corretamente para evitar falhas de execução.
- As prioridades são interpretadas e exibidas com mensagens explicativas.
- O `getchar()` é utilizado para evitar problemas de leitura no buffer ao alternar entre `scanf` e `fgets`.

---


---

## Comentários Finais

- O código está comentado para facilitar o entendimento e a manutenção.
- O programa pode ser usado como base para sistemas maiores de controle energético.

---
