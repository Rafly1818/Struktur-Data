#include <iostream>
using namespace std;

// Fungsi untuk menukar dua elemen array
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk mengurutkan array menggunakan Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Fungsi untuk menampilkan elemen array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    // Menerima input ukuran array dari pengguna
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];

    // Menerima input elemen array dari pengguna
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Mengurutkan array menggunakan Bubble Sort
    bubbleSort(arr, n);

    // Menampilkan array yang sudah diurutkan
    cout << "Array yang sudah diurutkan: ";
    printArray(arr, n);

    return 0;
}