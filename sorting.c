#include <stdio.h>

// 3,4,1,5
// 3,1,4,5
// 1,3,4,5

void print_arr(int* arr, int len) {
    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubble_sort(int *arr, int len) {
    for(int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int partition(int *arr, int p, int q) {
    int pivot = arr[q - 1];
    int idx = p;
    for(int i = p; i < q - 1; ++i) {
        if (arr[i] < pivot) {
            int tmp = arr[idx];
            arr[idx] = arr[i];
            arr[i] = tmp;
            idx++;
        }
    }
    arr[q - 1] = arr[idx];
    arr[idx] = pivot;
    return idx;
}

void qsort(int *arr, int p, int q) {
    // 4,3,2,1
    // 1,3,2,4
    // 1,3,2,4
    // 1,2,3,4
    if (q <= p)
        return;
    if (p == q - 1)
        return;
    int idx = partition(arr, p, q);
    qsort(arr, p, idx);
    qsort(arr, idx + 1, q);
}

void quick_sort(int *arr, int len) {
    qsort(arr, 0, len);
}


int main(int argc, const char **argv) {
    int arr[] = {4,3,2,1};
    int n = 4;
    print_arr(arr, n);
    quick_sort(arr, n);
    print_arr(arr, n);
    return 0;
}


