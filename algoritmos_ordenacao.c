#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos das funções pra organizar o código
void mostrarVetor(int v[], int tam);
void preencherAleatorio(int v[], int tam);
void copiarVetor(int origem[], int destino[], int tam);

int main() {
    int tamanho = 10; // Começando com 10 pra testar se tá funcionando
    int original[tamanho], vetor_teste[tamanho];
    int opcao;
    clock_t inicio, fim;
    double tempo_gasto;

    // Gera os números uma vez pra gente sempre testar os mesmos
    preencherAleatorio(original, tamanho);

    do {
        printf("\n--- TRABALHO DE ORDENACAO ---");
        printf("\n1. Bubble Sort (Implementar)");
        printf("\n2. Selection Sort (Implementar)");
        printf("\n3. Insertion Sort (Implementar)");
        printf("\n4. Quick Sort (Implementar)");
        printf("\n5. Merge Sort (Implementar)");
        printf("\n6. Shell Sort (Implementar)");
        printf("\n0. Sair");
        printf("\nEscolha o algoritmo: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 6) {
            // Toda vez que rodar, a gente reseta o vetor pro original bagunçado
            copiarVetor(original, vetor_teste, tamanho);
            
            printf("\nVetor antes de ordenar: ");
            mostrarVetor(vetor_teste, tamanho);
            
            inicio = clock();
            
            // Aqui vamos chamar as funções nos próximos commits
            printf("\n[Aviso] Codigo da ordenacao ainda sera inserido...\n");
            
            fim = clock();
            tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            
            printf("Vetor depois de ordenar: ");
            mostrarVetor(vetor_teste, tamanho);
            printf("Tempo total: %f segundos\n", tempo_gasto);
        }

    } while (opcao != 0);

    return 0;
}

// Funções utilitarias
void mostrarVetor(int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void preencherAleatorio(int v[], int tam) {
    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        v[i] = rand() % 100; // Números de 0 a 99 pra não virar bagunça
    }
}

void copiarVetor(int origem[], int destino[], int tam) {
    for (int i = 0; i < tam; i++) {
        destino[i] = origem[i];
    }
}
