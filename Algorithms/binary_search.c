#include <stdio.h>
#include <stdlib.h>

int binarySearch(int*, int, int);
void sort(int*, int);

int main() {
    int i, * array, tosearch, idx;
    printf("Enter number of elements: ");
    scanf("%d", &i);
    
    array = malloc(sizeof(int) * i);
    
    for (int j = 0; j < i; j++) {
        printf("Enter element at %d index: ", j);
        scanf("%d", &array[j]);
        printf("\n");
    }
    
    printf("Enter element to search: ");
    scanf("%d", &tosearch);
    
    sort(array, i);
    
    idx = binarySearch(array, i, tosearch);
    
    if (idx == -1) printf("element not found\n");
    else printf("element found at %d index", idx);
    
    return 0;
}

void sort(int * array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int swaps = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swaps++;
            }
        }
        if (!swaps) break;
    }
}

int binarySearch(int * array, int size, int data) {
    int L = 0, H = size - 1, mid;
    
    while (L <= H) {
        mid = L + H / 2;
        
        if (array[mid] == data) return mid;
        else if (data < array[mid]) {
            H = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    
    return -1;
}
