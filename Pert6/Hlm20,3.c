#include <stdio.h>

// Fungsi untuk melakukan pencarian berurutan
int sequentialSearch(int* arr, int size, int target) {
    int* ptr = arr;  // Pointer yang menunjuk ke awal array
    for (int i = 0; i < size; i++) {
        if (*ptr == target) {
            return i;  // Mengembalikan indeks jika ditemukan
        }
        ptr++;  // Menggerakkan pointer ke elemen berikutnya
    }
    return -1;  // Mengembalikan -1 jika target tidak ditemukan
}

int main() {
    int data[] = {23, 45, 12, 67, 34, 89, 78};
    int size = sizeof(data) / sizeof(data[0]);
    int target;

    printf("Masukkan angka yang ingin dicari: ");
    scanf("%d", &target);

    int result = sequentialSearch(data, size, target);

    if (result != -1) {
        printf("Angka %d ditemukan pada indeks %d\n", target, result);
    } else {
        printf("Angka %d tidak ditemukan\n", target);
    }

    return 0;
}