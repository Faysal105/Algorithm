#include <iostream>

void merge(int A[], int B[], int n, int m, int C[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (A[i] <= B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }
    while (i < n) {
        C[k++] = A[i++];
    }
    while (j < m) {
        C[k++] = B[j++];
    }
}

int main() {
    int A[] = {1, 5, 4, 9, 8, 7, 5, 6, 2, 4};
    int B[] = {1, 5, 4, 9, 8, 6, 5, 3, 2, 4};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);
    int C[n + m];

    merge(A, B, n, m, C);

    std::cout << "Merged Array: ";
    for (int i = 0; i < n + m; ++i) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
