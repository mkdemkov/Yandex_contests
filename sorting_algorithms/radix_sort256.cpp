#include <iostream>

int64_t findMax(const int64_t *arr, int n) {
    int64_t max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int64_t *arr, int n, int64_t exp) {
    auto *output = new int64_t[n];
    int64_t i, count[256] = {0};

    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 256]++;
    }

    for (i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 256] - 1] = arr[i];
        count[(arr[i] / exp) % 256]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    delete[] output;
}

void radixSort(int64_t *arr, int n) {
    int64_t m = findMax(arr, n);

    for (int64_t exp = 1; m / exp > 0; exp *= 256) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n;
    std::cin >> n;
    auto *arr = new int64_t[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    radixSort(arr, n);
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
}
