#include <stdio.h>
#include <stdlib.h>

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

void myqsort(int *arr, int p, int q) {
    // 4,3,2,1
    // 1,3,2,4
    // 1,3,2,4
    // 1,2,3,4
    if (q <= p)
        return;
    if (p == q - 1)
        return;
    int idx = partition(arr, p, q);
    myqsort(arr, p, idx);
    myqsort(arr, idx + 1, q);
}

void quick_sort(int *arr, int len) {
    myqsort(arr, 0, len);
}

void msort(int *arr, int left, int right) {
    if (right <= left)
        return;
    int mid = left + (right - left)/2;
    msort(arr, left, mid);
    msort(arr, mid + 1, right);
    int size = right - left + 1;
    int *sorted = (int *) (malloc(sizeof(int)*size));
    int p = left, q = mid + 1;
    int curr = 0;
    while (curr < size) {
        if (p <= mid && q <= right) {
            if (arr[p] < arr[q])
                sorted[curr++] = arr[p++];
            else
                sorted[curr++] = arr[q++];
        }
        else if (p <= mid)
            sorted[curr++] = arr[p++];
        else
            sorted[curr++] = arr[q++];
    }

    for (int i = 0; i < size; ++i)
        arr[left + i] = sorted[i];

    return;
}

void merge_sort(int *arr, int len) {
    msort(arr, 0, len - 1);
}

void count_sort(int *arr, int len) {
    int min_val = arr[0], max_val = arr[0];
    for (int i = 0; i < len; ++i) {
        min_val = arr[i] < min_val ? arr[i] : min_val;
        max_val = arr[i] > max_val ? arr[i] : max_val;
    }
    int offset = -min_val;
    int range = max_val - min_val + 1;
    int *counts = (int *) malloc(sizeof(int) * range);
    for (int i = 0; i < range; ++i)
        counts[i] = 0;
    for (int i = 0; i < len; ++i)
        counts[arr[i] + offset]++;
    int c = range - 1, i = len - 1;
    while (i >= 0) {
        if (counts[c] == 0)
            --c;
        else {
            arr[i--] = c - offset;
            --counts[c];
        }
    }
    free(counts);
}

int main(int argc, const char **argv) {
    int arr[] = {4,3,2,1,3,4,1,2};
    int n = 8;
    print_arr(arr, n);
    count_sort(arr, n);
    print_arr(arr, n);
    return 0;
}


