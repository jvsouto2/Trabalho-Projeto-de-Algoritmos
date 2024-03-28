#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <direct.h>
#include <string.h>

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void maxHeapInsert(int arr[], int key, int* heapSize, int capacity) {
    if (*heapSize == capacity) {
        printf("Falha");
        return;
    }

    (*heapSize)++;
    int i = *heapSize - 1;
    arr[i] = key;

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


int extractMin(int *heap, int *heapSize) {
    if (*heapSize <= 0) return INT_MAX;
    if (*heapSize == 1) {
        (*heapSize)--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[--(*heapSize)];
    minHeapify(heap, *heapSize, 0);

    return root;
}

void insertKey(int *heap, int key, int *heapSize, int capacity) {
    if (*heapSize == capacity) {
        printf("Falha");
        return;
    }


    int i = (*heapSize)++;
    heap[i] = key;


    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void decreaseKey(int *heap, int i, int newVal, int heapSize) {
    heap[i] = newVal;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

int heapExtractMin(int arr[], int* n) {
    if (*n <= 0)
        return INT_MAX;
    if (*n == 1) {
        *n = *n - 1;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[*n - 1];
    *n = *n - 1;
    minHeapify(arr, *n, 0);

    return root;
}

void heapIncreaseKey(int arr[], int i, int key) {
    if (key > arr[i])
        return;
    arr[i] = key;
    while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildMinHeap(arr, n);
    int heap_size = n;
    while (heap_size > 1) {
        swap(&arr[0], &arr[heap_size - 1]);
        heap_size--;
        minHeapify(arr, heap_size, 0);
    }
}



void createDirIfNotExists(const char *path) {
    if (_mkdir(path) == -1) {
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int partition_v1(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j;
    for (j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i];
    arr[i] = arr[low];
    arr[low] = temp;
    return i;
}

void quickSort_v1(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_v1(arr, low, high);
        quickSort_v1(arr, low, pi - 1);
        quickSort_v1(arr, pi + 1, high);
    }
}

int partition_v2(int arr[], int low, int high) {
    int sum = 0;
    for (int i = low; i <= high; i++)
        sum += arr[i];
    int pivot = sum / (high - low + 1);

    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort_v2(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_v2(arr, low, high);
        quickSort_v2(arr, low, pi - 1);
        quickSort_v2(arr, pi + 1, high);
    }
}

int medianOfThree(int a, int b, int c) {
    if ((a - b) * (c - a) >= 0)
        return a;
    else if ((b - a) * (c - b) >= 0)
        return b;
    else
        return c;
}

int partition_v3(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    int pivot = medianOfThree(arr[low], arr[mid], arr[high]);
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort_v3(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_v3(arr, low, high);
        quickSort_v3(arr, low, pi - 1);
        quickSort_v3(arr, pi + 1, high);
    }
}

int partition_v4(int arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    int pivot = arr[random];
    int temp = arr[random];
    arr[random] = arr[high];
    arr[high] = temp;

    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort_v4(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_v4(arr, low, high);
        quickSort_v4(arr, low, pi - 1);
        quickSort_v4(arr, pi + 1, high);
    }
}


void printArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void gerarNumerosAleatorios(int arr[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 1000000; // Números randômicos de 0 a 1.000.000
    }
}

void gerarNumerosCrescentes(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = i;
    }
}

void gerarNumerosDecrescentes(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = tamanho - i;
    }
}

void salvarArrayEmArquivo(int arr[], int tamanho, int tipoOrdenacao, const char *algoritmoStr) {
    char tipoOrdenacaoStr[20];
    if (tipoOrdenacao == 1) {
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "random");
    } else if (tipoOrdenacao == 2) {
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "crescente");
    } else if (tipoOrdenacao == 3) {
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "decrescente");
    } else {
        printf("Tipo de ordenacao invalido\n");
        return;
    }

    createDirIfNotExists(algoritmoStr);

    char subfolderName[60];
    snprintf(subfolderName, sizeof(subfolderName), "%s\\Arquivos de Entrada", algoritmoStr);
    createDirIfNotExists(subfolderName);

    char subfolderTipoOrdenacao[80];
    snprintf(subfolderTipoOrdenacao, sizeof(subfolderTipoOrdenacao), "%s\\%s", subfolderName, tipoOrdenacaoStr);
    createDirIfNotExists(subfolderTipoOrdenacao);

    char filename[80];
    snprintf(filename, sizeof(filename), "%s\\entrada%d.txt", subfolderTipoOrdenacao, tamanho);


    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    fprintf(file, "%d\n", tamanho);

    for (int i = 0; i < tamanho; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

void salvarArrayOrdenadoEmArquivo(int arr[], int tamanho, int tipoOrdenacao, const char *algoritmoStr) {
    char tipoOrdenacaoStr[20];
    if (tipoOrdenacao == 1) {
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "random");
    } else if (tipoOrdenacao == 2) {
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "crescente");
    } else if (tipoOrdenacao == 3) {
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "decrescente");
    } else {
        printf("Tipo de ordenacao invalido\n");
        return;
    }

    createDirIfNotExists(algoritmoStr);

    char subfolderName[60];
    snprintf(subfolderName, sizeof(subfolderName), "%s\\Arquivos de Saida", algoritmoStr);
    createDirIfNotExists(subfolderName);

    char subfolderTipoOrdenacao[80];
    snprintf(subfolderTipoOrdenacao, sizeof(subfolderTipoOrdenacao), "%s\\%s", subfolderName, tipoOrdenacaoStr);
    createDirIfNotExists(subfolderTipoOrdenacao);

    char filename[80];
    snprintf(filename, sizeof(filename), "%s\\ordenado%d.txt", subfolderTipoOrdenacao, tamanho);
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    fprintf(file, "%d\n", tamanho);

    for (int i = 0; i < tamanho; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

void salvarTempoEmArquivo(double tempo, int tamanho, int tipoOrdenacao, const char *algoritmoStr) {
    char tipoOrdenacaoStr[20];
    if (tipoOrdenacao == 1) {
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "random");
    } else if (tipoOrdenacao == 2) {
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "crescente");
    } else if (tipoOrdenacao == 3) {
        snprintf(tipoOrdenacaoStr, sizeof(tipoOrdenacaoStr), "decrescente");
    } else {
        printf("Tipo de ordenacao invalido\n");
        return;
    }

    createDirIfNotExists(algoritmoStr);

    char subfolderName[60];
    snprintf(subfolderName, sizeof(subfolderName), "%s\\Arquivos de Tempo", algoritmoStr);
    createDirIfNotExists(subfolderName);

    char subfolderTipoOrdenacao[80];
    snprintf(subfolderTipoOrdenacao, sizeof(subfolderTipoOrdenacao), "%s\\%s", subfolderName, tipoOrdenacaoStr);
    createDirIfNotExists(subfolderTipoOrdenacao);

    char filename[80];
    snprintf(filename, sizeof(filename), "%s\\tempo%d.txt", subfolderTipoOrdenacao, tamanho);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    fprintf(file, "%d\n", tamanho);

    fprintf(file, "Tempo gasto: %f segundos\n", tempo);

    fclose(file);
}

int menuSort(int tamanho, int opcaoAlgoritmo) {
    int *arr = (int *)malloc(tamanho * sizeof(int));

    if (arr == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }
    int capacidade = tamanho;
    int heapSize = tamanho;

    if (opcaoAlgoritmo == -1) {
        int heapOperacao;
        printf("\nSelecione a operacao do heap:\n");
        printf("1. HEAP_MINIMUM\n");
        printf("2. HEAP_EXTRACT_MIN\n");
        printf("3. HEAP_INCREASE_KEY\n");
        printf("4. MAX_HEAP_INSERT\n");
        printf("Escolha uma operacao: ");
        scanf("%d", &heapOperacao);

        switch (heapOperacao) {
            case 1: // HEAP_MINIMUM
                buildMinHeap(arr, tamanho);
                printf("Heap construido: ");
                printArray(arr, tamanho);
                printf("Menor elemento (na raiz): %d\n", arr[0]);
                break;
            case 2: // HEAP_EXTRACT_MIN
                buildMinHeap(arr, tamanho);
                printf("Heap antes da extracao: ");
                printArray(arr, tamanho);
                int minimo = heapExtractMin(arr, &tamanho);
                printf("Menor elemento extraido: %d\n", minimo);
                printf("Heap apos extracao: ");
                printArray(arr, tamanho);
                break;
            case 3: // HEAP_INCREASE_KEY
                buildMinHeap(arr, tamanho);
                printf("Digite o indice para aumentar a chave: ");
                int indice;
                scanf("%d", &indice);
                if (indice < 0 || indice >= tamanho) {
                    printf("Indice invalido.\n");
                    break;
                }
                printf("Digite o novo valor menor: ");
                int novoValor;
                scanf("%d", &novoValor);
                heapIncreaseKey(arr, indice, novoValor);
                printArray(arr, tamanho);
                break;
            case 4: // MAX_HEAP_INSERT
                buildMinHeap(arr, tamanho);
                printf("Digite o valor a ser inserido no heap maximo: ");
                int valor;
                scanf("%d", &valor);

                maxHeapInsert(arr, valor, &heapSize, capacidade);
                printArray(arr, tamanho);
                break;
            default:
                printf("Operacao invalida.\n");
                break;
        }

        free(arr);
        return 0;
    }

    char algoritmoStr[20];

    switch (opcaoAlgoritmo) {
        case 1:
            strcpy(algoritmoStr, "InsertionSort");
            break;
        case 2:
            strcpy(algoritmoStr, "SelectionSort");
            break;
        case 3:
            strcpy(algoritmoStr, "ShellSort");
            break;
        case 4:
            strcpy(algoritmoStr, "BubbleSort");
            break;
        case 5:
            strcpy(algoritmoStr, "MergeSort");
            break;
        case 6:
            strcpy(algoritmoStr, "QuickSort_v1");
            break;
        case 7:
            strcpy(algoritmoStr, "QuickSort_v2");
            break;
        case 8:
            strcpy(algoritmoStr, "QuickSort_v3");
            break;
        case 9:
            strcpy(algoritmoStr, "QuickSort_v4");
            break;
        case 10:
            strcpy(algoritmoStr, "heapSort");
            break;

        default:
            printf("Opção de algoritmo inválida.\n");
            free(arr);
            return 1;
    }

    printf("\n");
    printf("|=============================== MENU ====================================|\n");
    printf("|                          %s                                 |\n", algoritmoStr);
    printf("|-------------------------------------------------------------------------|\n");
    printf("|  Digite 1 para gerar números aleatórios                                 |\n");
    printf("|  Digite 2 para gerar números em ordem crescente                         |\n");
    printf("|  Digite 3 para gerar números em ordem decrescente                       |\n");
    printf("|  Digite 0 para sair                                                     |\n");
    printf("|-------------------------------------------------------------------------|\n");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            gerarNumerosAleatorios(arr, tamanho);
            break;
        case 2:
            gerarNumerosCrescentes(arr, tamanho);
            break;
        case 3:
            gerarNumerosDecrescentes(arr, tamanho);
            break;
        case 0:
            free(arr);
            return 0;
        default:
            printf("Opção inválida\n");
            free(arr);
            return 1;
    }

    int *heap = arr;

    int valor, indice;




    //printf("\nEntrada:\n");
    //printArray(arr, tamanho);

    int *arrCopy = (int *)malloc(tamanho * sizeof(int));
    if (arrCopy == NULL) {
        printf("Falha na alocação de memória para arrCopy.\n");
        free(arr);
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        arrCopy[i] = arr[i];
    }

    clock_t t;
    t = clock();

    switch (opcaoAlgoritmo) {
        case 1:
            insertionSort(arr, tamanho);
            break;
        case 2:
            selectionSort(arr, tamanho);
            break;
        case 3:
            shellSort(arr, tamanho);
            break;
        case 4:
            bubbleSort(arr, tamanho);
            break;
        case 5:
            mergeSort(arr, 0, tamanho - 1);
            break;
        case 6:
            quickSort_v1(arr, 0, tamanho - 1);
            break;
        case 7:
            quickSort_v2(arr, 0, tamanho - 1);
            break;
        case 8:
            quickSort_v3(arr, 0, tamanho - 1);
            break;
        case 9:
            quickSort_v4(arr, 0, tamanho - 1);
            break;
        case 10:
            heapSort(arr, tamanho);
            break;
        case 11:
            valor = extractMin(heap, &heapSize);
            printf("Valor minimo extraido: %d\n", valor);
            break;
        case 12:
            printf("Digite o valor a ser inserido no heap: ");
            scanf("%d", &valor);
            insertKey(heap, valor, &heapSize, tamanho);
            break;
        case 13:
            printf("Digite o indice da chave a ser diminuida: ");
            scanf("%d", &indice);
            printf("Digite o novo valor: ");
            scanf("%d", &valor);
            decreaseKey(heap, indice, valor, heapSize);
            break;
    }

    t = clock() - t;
    double tempoGasto = ((double)t) / CLOCKS_PER_SEC;

    //printf("\nSaida Ordenada:\n");
    //printArray(arr, tamanho);

    salvarArrayEmArquivo(arrCopy, tamanho, opcao, algoritmoStr);
    salvarArrayOrdenadoEmArquivo(arr, tamanho, opcao, algoritmoStr);
    salvarTempoEmArquivo(tempoGasto, tamanho, opcao, algoritmoStr);

    free(arr);
    free(arrCopy);

    return 0;
}

int exibirMenu() {
    int opcao;

    printf("================================ MENU ======================================\n");
    printf("|                          Algoritmos de Ordenacao                        |\n");
    printf("|-------------------------------------------------------------------------|\n");
    printf("|  Digite 1 para o Insertion Sort                                         |\n");
    printf("|  Digite 2 para o Selection Sort                                         |\n");
    printf("|  Digite 3 para o Shell Sort                                             |\n");
    printf("|  Digite 4 para o Bubble Sort                                            |\n");
    printf("|  Digite 5 para o Merge Sort                                             |\n");
    printf("|  Digite 6 para o Quick Sort (Versão 1)                                  |\n");
    printf("|  Digite 7 para o Quick Sort (Versão 2)                                  |\n");
    printf("|  Digite 8 para o Quick Sort (Versão 3)                                  |\n");
    printf("|  Digite 9 para o Quick Sort (Versão 4)                                  |\n");
    printf("|  Digite 10 para o Heap Sort                                             |\n");
    printf("|  Digite 11 para Operações de Heap                                       |\n");
    printf("|  Digite 12 para Sair                                                    |\n");
    printf("|-------------------------------------------------------------------------|\n");

    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    if (opcao == 11) {
        return -1;
    }



    return opcao;
}

int main() {
    int opcao, tamanhoOpcao;
    int tamanhos[] = {10, 100, 1000, 10000, 100000, 1000000};

    do {
        opcao = exibirMenu();
        if (opcao > 0) {
            printf("Escolha o tamanho do vetor:\n");
            printf("1. 10\n");
            printf("2. 100\n");
            printf("3. 1000\n");
            printf("4. 10000\n");
            printf("5. 100000\n");
            printf("6. 1000000\n");
            printf("Digite a opção desejada: ");
            scanf("%d", &tamanhoOpcao);
            if (tamanhoOpcao >= 1 && tamanhoOpcao <= 6) {
                menuSort(tamanhos[tamanhoOpcao - 1], opcao);
            } else {
                printf("Opção de tamanho inválida.\n");
            }
        } else if (opcao == -1) {
            menuSort(0, -1);
        }
    } while (opcao != 12);

    return 0;
}
