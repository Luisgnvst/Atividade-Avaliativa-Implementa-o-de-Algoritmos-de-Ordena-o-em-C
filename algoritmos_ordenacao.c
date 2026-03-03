#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipos das funções que já tínhamos
void mostrarVetor(int v[], int tam);
void preencherAleatorio(int v[], int tam);
void copiarVetor(int origem[], int destino[], int tam);

// Novos protótipos dos algoritmos que adicionei agora
void bubbleSort(int v[], int tam);
void selectionSort(int v[], int tam);

int main() {
    int tamanho = 10; 
    int original[tamanho], vetor_teste[tamanho];
    int opcao;
    clock_t inicio, fim;
    double tempo_gasto;

    preencherAleatorio(original, tamanho);

    do {
        printf("\n--- TRABALHO DE ORDENACAO ---");
        printf("\n1. Bubble Sort");
        printf("\n2. Selection Sort");
        printf("\n3. Insertion Sort (Implementar)");
        printf("\n4. Quick Sort (Implementar)");
        printf("\n5. Merge Sort (Implementar)");
        printf("\n6. Shell Sort (Implementar)");
        printf("\n0. Sair");
        printf("\nEscolha o algoritmo: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 6) {
            copiarVetor(original, vetor_teste, tamanho);
            
            printf("\nVetor antes de ordenar: ");
            mostrarVetor(vetor_teste, tamanho);
            
            inicio = clock();
            
            // Agora o código decide qual função chamar de verdade
            if (opcao == 1) {
                bubbleSort(vetor_teste, tamanho);
            } else if (opcao == 2) {
                selectionSort(vetor_teste, tamanho);
            } else {
                printf("\n[Aviso] Esse algoritmo ainda nao foi feito!\n");
            }
            
            fim = clock();
            tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            
            printf("Vetor depois de ordenar: ");
            mostrarVetor(vetor_teste, tamanho);
            printf("Tempo total: %f segundos\n", tempo_gasto);
        }

    } while (opcao != 0);

    return 0;
}

// Implementaçao do Bubble Sort
void bubbleSort(int v[], int tam) {
    int aux;
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

// Implementação do Selection Sort
void selectionSort(int v[], int tam) {
    int menor, aux;
    for (int i = 0; i < tam - 1; i++) {
        menor = i;
        for (int j = i + 1; j < tam; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

// Funções utilitárias que você já tinha so q arrumadas
void mostrarVetor(int v[], int tam) {
    for (int i = 0; i < tam; i++) printf("%d ", v[i]);
    printf("\n");
}

void preencherAleatorio(int v[], int tam) {
    srand(time(NULL));
    for (int i = 0; i < tam; i++) v[i] = rand() % 100;
}

void copiarVetor(int origem[], int destino[], int tam) {
    for (int i = 0; i < tam; i++) destino[i] = origem[i];
}
