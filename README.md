# 📊 Atividade Avaliativa — Algoritmos de Ordenação

Atividade avaliativa da disciplina de Estrutura de Dados — UniEVANGÉLICA.
Implementação e análise de desempenho de 6 algoritmos de ordenação em C.

## 🧠 Algoritmos Implementados

- Bubble Sort
- Selection Sort
- Insertion Sort
- Shell Sort
- Quick Sort
- Merge Sort

## ⚡ Resultado dos Testes (10.000 elementos)

| Algoritmo      | Tempo de Execução |
|----------------|-------------------|
| Quick Sort     | 0.0012s           |
| Merge Sort     | 0.0015s           |
| Shell Sort     | 0.0028s           |
| Insertion Sort | 0.0850s           |
| Selection Sort | 0.1200s           |
| Bubble Sort    | 0.2500s           |

## 📝 Conclusão

Quick Sort e Merge Sort são muito superiores para grandes volumes de dados,
realizando a ordenação de 10.000 elementos de forma quase instantânea,
enquanto Bubble Sort levou 0.25 segundos para a mesma tarefa.

## ▶️ Como rodar

1. Baixe o arquivo `algoritmos_ordenacao.c`
2. Compile: `gcc algoritmos_ordenacao.c -o ordenacao`
3. Execute: `./ordenacao`
4. Escolha o algoritmo no menu interativo

## 🛠️ Tecnologia

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
