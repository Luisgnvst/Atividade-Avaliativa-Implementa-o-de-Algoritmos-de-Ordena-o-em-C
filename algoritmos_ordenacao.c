#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos das funções
void mostrarVetor(int v[], int tam);
void preencherAleatorio(int v[], int tam);
void copiarVetor(int origem[], int destino[], int tam);

// Algoritmos dos commits passados
void bubbleSort(int v[], int tam);
void selectionSort(int v[], int tam);

// Novos algoritmos que adicionei agora
void insertionSort(int v[], int tam);
void shellSort(int v[], int tam);

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
        printf("\n3. Insertion Sort");
        printf("\n4. Quick Sort (Pendente)");
        printf("\n5. Merge Sort (Pendente)");
        printf("\n6. Shell Sort");
        printf("\n0. Sair");
        printf("\nEscolha o algoritmo: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 6) {
            copiarVetor(original, vetor_teste, tamanho);
            
            printf("\nVetor antes: ");
            mostrarVetor(vetor_teste, tamanho);
            
            inicio = clock();
            
            // Lógica para rodar o algoritmo escolhido
            if (opcao == 1) {
                bubbleSort(vetor_teste, tamanho);
            } else if (opcao == 2) {
                selectionSort(vetor_teste, tamanho);
            } else if (opcao == 3) {
                insertionSort(vetor_teste, tamanho);
            } else if (opcao == 6) {
                shellSort(vetor_teste, tamanho);
            } else {
                printf("\n[Aviso] Esse ainda nao implementei!\n");
            }
            
            fim = clock();
            tempo_gasto = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            
            printf("Vetor depois: ");
            mostrarVetor(vetor_teste, tamanho);
            printf("Tempo total: %f segundos\n", tempo_gasto);
        }

    } while (opcao != 0);

    return 0;
}

// Implementação do Insertion Sort 
void insertionSort(int v[], int tam) {
    int i, j, chave;
    for (i = 1; i < tam; i++) {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
    }
}

//  Implementação do Shell Sort
void shellSort(int v[], int tam) {
    for (int gap = tam / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tam; i++) {
            int temp = v[i];
            int j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}

// Algoritmos anteriores Bubble e Selectio
void bubbleSort(int v[], int tam) {
    int aux;
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j]; v[j] = v[j + 1]; v[j + 1] = aux;
            }
        }
    }
}

void selectionSort(int v[], int tam) {
    int menor, aux;
    for (int i = 0; i < tam - 1; i++) {
        menor = i;
        for (int j = i + 1; j < tam; j++) {
            if (v[j] < v[menor]) menor = j;
        }
        aux = v[i]; v[i] = v[menor]; v[menor] = aux;
    }
}

// Funções para axulioar
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
