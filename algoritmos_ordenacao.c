#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipos das funções auxiliares
void mostrarVetor(int v[], int tam);
void preencherAleatorio(int v[], int tam);
void copiarVetor(int origem[], int destino[], int tam);

// Protótipos de todos os algoritmos
void bubbleSort(int v[], int tam);
void selectionSort(int v[], int tam);
void insertionSort(int v[], int tam);
void shellSort(int v[], int tam);
void quickSort(int v[], int inicio, int fim);
void mergeSort(int v[], int l, int r);

// Funções auxiliares específicas para Quick e Merge
int particao(int v[], int baixo, int alto);
void merge(int v[], int l, int m, int r);

int main() {
    int tamanho = 10; // Para testar rápido.
    int original[tamanho], vetor_teste[tamanho];
    int opcao;
    clock_t inicio_tempo, fim_tempo;
    double tempo_total;

    preencherAleatorio(original, tamanho);

    do {
        printf("\n--- SISTEMA DE ORDENACAO FINAL ---");
        printf("\n1. Bubble Sort");
        printf("\n2. Selection Sort");
        printf("\n3. Insertion Sort");
        printf("\n4. Quick Sort");
        printf("\n5. Merge Sort");
        printf("\n6. Shell Sort");
        printf("\n0. Sair");
        printf("\nEscolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) break;

        if (opcao >= 1 && opcao <= 6) {
            copiarVetor(original, vetor_teste, tamanho);
            
            printf("\nVetor antes: ");
            mostrarVetor(vetor_teste, tamanho);
            
            inicio_tempo = clock();
            
            switch(opcao) {
                case 1: bubbleSort(vetor_teste, tamanho); break;
                case 2: selectionSort(vetor_teste, tamanho); break;
                case 3: insertionSort(vetor_teste, tamanho); break;
                case 4: quickSort(vetor_teste, 0, tamanho - 1); break;
                case 5: mergeSort(vetor_teste, 0, tamanho - 1); break;
                case 6: shellSort(vetor_teste, tamanho); break;
            }
            
            fim_tempo = clock();
            tempo_total = ((double) (fim_tempo - inicio_tempo)) / CLOCKS_PER_SEC;
            
            printf("Vetor ordenado: ");
            mostrarVetor(vetor_teste, tamanho);
            printf("Tempo de execucao: %f segundos\n", tempo_total);
        }

    } while (opcao != 0);

    return 0;
}

//IMPLEMENTAÇaO DOS ALGORITMOS

void bubbleSort(int v[], int tam) {
    int aux;
    for (int i = 0; i < tam - 1; i++)
        for (int j = 0; j < tam - i - 1; j++)
            if (v[j] > v[j + 1]) {
                aux = v[j]; v[j] = v[j + 1]; v[j + 1] = aux;
            }
}

void selectionSort(int v[], int tam) {
    int menor, aux;
    for (int i = 0; i < tam - 1; i++) {
        menor = i;
        for (int j = i + 1; j < tam; j++)
            if (v[j] < v[menor]) menor = j;
        aux = v[i]; v[i] = v[menor]; v[menor] = aux;
    }
}

void insertionSort(int v[], int tam) {
    int chave, j;
    for (int i = 1; i < tam; i++) {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

//Quick Sort 
int particao(int v[], int baixo, int alto) {
    int pivo = v[alto];
    int i = (baixo - 1), aux;
    for (int j = baixo; j <= alto - 1; j++) {
        if (v[j] < pivo) {
            i++;
            aux = v[i]; v[i] = v[j]; v[j] = aux;
        }
    }
    aux = v[i + 1]; v[i + 1] = v[alto]; v[alto] = aux;
    return (i + 1);
}

void quickSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int pi = particao(v, inicio, fim);
        quickSort(v, inicio, pi - 1);
        quickSort(v, pi + 1, fim);
    }
}

// Merge Sort 
void merge(int v[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) L[i] = v[l + i];
    for (j = 0; j < n2; j++) R[j] = v[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { v[k] = L[i]; i++; }
        else { v[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { v[k] = L[i]; i++; k++; }
    while (j < n2) { v[k] = R[j]; j++; k++; }
}

void mergeSort(int v[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

void shellSort(int v[], int tam) {
    for (int gap = tam / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tam; i++) {
            int temp = v[i], j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap)
                v[j] = v[j - gap];
            v[j] = temp;
        }
    }
}

// FUNÇoES DE SUPORTE 
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
