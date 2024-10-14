#include <iostream>
using namespace std;

// Fungsi untuk mencetak nilai integer menggunakan pointer
void printValue(int* ptr) {
    cout << "Nilai variabel menggunakan pointer: " << *ptr << endl;
}

// Fungsi untuk mengubah nilai integer menggunakan pointer
void changeValue(int* ptr, int newValue) {
    *ptr = newValue;
}

// Fungsi untuk mencetak elemen-elemen array menggunakan pointer
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // 1. Menginisialisasi sebuah variabel integer dengan nilai 10
    int var = 10;

    // Deklarasi pointer yang menunjuk ke var
    int* ptr = &var;

    // 2. Mencetak nilai variabel tersebut menggunakan pointer
    printValue(ptr);

    // 3. Mengubah nilai variabel tersebut menjadi 20 menggunakan pointer
    changeValue(ptr, 20);

    // 4. Mencetak nilai variabel yang telah diubah menggunakan pointer
    printValue(ptr);

    // 5. Mengalokasikan memori untuk array secara dinamis
    int size = 5;
    int* arr = new int[size];

    // Menginisialisasi array dengan nilai 1, 2, 3, 4, 5
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    // 6. Mencetak elemen-elemen array menggunakan pointer
    cout << "Array sebelum diubah: ";
    printArray(arr, size);

    // 7. Mengubah nilai elemen array menggunakan pointer
    for (int i = 0; i < size; i++) {
        changeValue(&arr[i], arr[i] * 2);
    }

    // 8. Mencetak elemen-elemen array yang telah diubah menggunakan pointer
    cout << "Array setelah diubah: ";
    printArray(arr, size);

    // 9. Membebaskan memori yang dialokasikan secara dinamis
    delete[] arr;

    return 0;
}
