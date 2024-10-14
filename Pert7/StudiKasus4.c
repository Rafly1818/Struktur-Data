#include <stdio.h>

// Fungsi rekursif untuk menghitung pangkat
int pangkat(int x, int y) {
    if (y == 0) {
        return 1;
    } else {
        return x * pangkat(x, y - 1);
    }
}

int main() {
    int x, y;

    // Meminta input dari pengguna
    printf("Masukkan angka (x): ");
    scanf("%d", &x);

    printf("Masukkan pangkat (y): ");
    scanf("%d", &y);

    // Menghitung hasil pangkat
    int hasil = pangkat(x, y);

    // Menampilkan hasil
    printf("%d pangkat %d adalah %d\n", x, y, hasil);

    return 0;
}