#include <iostream>

void countingSort(int *arr, int size) {
    int *additional_arr = new int[1000001];
    int *minus_numbers = new int[1000001];
    for (int i = 0; i < 1000001; ++i) {
        additional_arr[i] = 0;
        minus_numbers[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            minus_numbers[abs(arr[i])]++;
        } else {
            additional_arr[arr[i]]++;
        }
    }
    int j = 0;
    for (int i = 1000000; i > -1; --i) {
        if (minus_numbers[i] != 0) {
            while (minus_numbers[i] != 0) {
                arr[j++] = -i;
                minus_numbers[i]--;
            }
        }
    }
    for (int i = 0; i < 1000001; ++i) {
        if (additional_arr[i] != 0) {
            while (additional_arr[i] != 0) {
                arr[j++] = i;
                additional_arr[i]--;
            }
        }
    }
    delete[] minus_numbers;
    delete[] additional_arr;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    countingSort(arr, n);
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
}
