#include <stdio.h>

// Fungsi rekursif untuk menghitung deret penjumlahan
int S(int n) {
    if (n == 1) {
        return n;
    } else {
        return n + S(n - 1);
    }
}

// Fungsi untuk mencetak deret
void printDeret(int n) {
    if (n == 1) {
        printf("1");
    } else {
        printDeret(n - 1);
        printf("+%d", n);
    }
}

int main() {
    int n;

    // Meminta input dari pengguna
    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    // Mencetak deret
    printf("Output deret S = ");
    printDeret(n);

    // Menghitung hasil deret penjumlahan
    int hasil = S(n);

    // Menampilkan hasil
    printf(" = %d\n", hasil);

    return 0;
}