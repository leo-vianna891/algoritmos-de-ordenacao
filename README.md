# Análise Comparativa de Algoritmos de Ordenação

Este projeto implementa e compara o desempenho de diversos algoritmos de ordenação (sorting), analisando métricas de tempo de execução, número de comparações e movimentações de registros. O sistema permite a execução de testes em vetores de diferentes tamanhos e estados iniciais.

## 📂 Estrutura do Projeto

O código fonte está dividido em três módulos principais:

* **`main.c`**: Contém o fluxo principal do programa, o gerenciamento dos menus, a geração dos vetores de teste, a coleta de métricas e a exibição dos resultados.
* **`algoritmos.c`**: Implementação de todos os métodos de ordenação. Cada função foi instrumentada para receber ponteiros para contadores de comparações e movimentações.
* **`fila.c`**: Implementação de uma estrutura de dados do tipo Fila (Queue) baseada em listas encadeadas, utilizada especificamente como estrutura auxiliar para o algoritmo **Radix Sort**.

## 🚀 Algoritmos Implementados

O projeto contempla 9 algoritmos distintos:

1.  **Bubble Sort**
2.  **Selection Sort**
3.  **Insertion Sort**
4.  **Shell Sort** (Utilizando a sequência de incrementos de Knuth: $h = 3h + 1$)
5.  **Quick Sort** (Otimizado com pivo "Mediana de 3")
6.  **Heap Sort**
7.  **Merge Sort**
8.  **Contagem dos Menores**
9.  **Radix Sort**

## ⚙️ Funcionalidades e Uso

Para executar o programa, utilize um compilador C no arquivo **`main.c`**.

Após a execução, o usuário será guiado por um fluxo de menus interativos no console para configurar o cenário de teste. O programa roda em um loop contínuo até que o usuário decida encerrar.

### 1. Escolha do Tamanho do Vetor ($N$)
O primeiro menu define a escala do teste. As opções disponíveis são:
* 100 elementos
* 1.000 elementos
* 10.000 elementos
* 100.000 elementos

*(Digite `-1` nesta etapa para encerrar o programa).*

### 2. Escolha do Estado Inicial
Define como os dados estarão dispostos no vetor antes da ordenação:
* **Ordenado:** Vetor crescente $[1, 2, ..., N]$.
* **Reverso:** Vetor decrescente $[N, N-1, ..., 1]$.
* **Aleatório:** Números inteiros pseudoaleatórios gerados via `rand()`.

> **Nota:** Para garantir consistência estatística, se a opção **Aleatório** for selecionada, o algoritmo escolhido será executado **5 vezes**. O resultado final exibido será a média aritmética das execuções.

### 3. Seleção do Algoritmo
O usuário seleciona qual dos 9 algoritmos listados acima será submetido ao teste configurado.

## 📊 Saída de Dados

Após a execução, o programa realiza uma verificação automática para garantir que o vetor foi ordenado corretamente (`correto = true/false`). Em seguida, apresenta os seguintes resultados:

* **Status da Ordenação:** Confirmação de sucesso ou alerta de erro.
* **Repetições:** Quantas vezes o algoritmo rodou (1x para ordenados/reversos, 5x para aleatórios).
* **Número de Comparações:** Total (ou média) de operações de comparação entre chaves.
* **Número de Movimentos:** Total (ou média) de trocas ou atribuições de registros.
* **Tempo (médio) de Execução:** Medido em segundos utilizando `clock()`.

### Exemplo de Fluxo

```text
-=-=-= Escolha o tamanho do vetor (ou -1 para encerrar): -=-=-=
[1] 100
...
> 4

-=-=-= Agora, escolha o estado inicial do vetor -=-=-=
...
[3] Aleatório
> 3

-=-=-= Escolha qual algoritmo de ordenação será usado: =-=-=-
...
[5] QuickSort
> 5

=-=-=- RESULTADOS -=-=-=
Ordenação realizada com sucesso.
O algoritmo foi executado 5 vez(es).
Número de Comparações: 1654320
Número de Movimentos: 540100
Tempo (médio) de execução: 0.014500 segundo(s).
```

## 📝 Detalhes de Implementação
**Tipos de Dados:** Os contadores de métricas utilizam **`long long`** para evitar overflow em testes com *N=100.000* ou algoritmos quadráticos.

**Mediana de 3:** O Quick Sort foi implementado com a técnica de mediana de 3 para escolha do pivô, visando mitigar o pior caso em vetores já ordenados ou reversos.

**Limpeza de Memória:** O vetor principal é alocado dinamicamente (**`malloc`**) e liberado (**`free`**) ao final de cada ciclo de teste no **`main`**.
