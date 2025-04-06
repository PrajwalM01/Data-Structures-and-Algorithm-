#include <stdio.h>
#include <stdlib.h>

int count = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            count++;
            i++;
        }
        while (arr[j] > pivot) {
            count++;
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);

    return j;
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int k = partition(arr, low, high);
        quicksort(arr, low, k - 1);
        quicksort(arr, k + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of elements that you need to sort\n");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter the array\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("Sorted array\n");
    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
