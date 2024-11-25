#include <iostream>
#include <stdlib.h>
#include <ctime> // Untuk fungsi random

using namespace std;

// Deklarasi variabel global
int arrayData[100];
int n;

// Fungsi untuk menukar dua elemen dalam array
void tukar(int a, int b) {
    int t = arrayData[b];
    arrayData[b] = arrayData[a];
    arrayData[a] = t;
}

// Bubble Sort
void bubble_sort() {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (arrayData[j] < arrayData[j - 1]) tukar(j, j - 1);
        }
    }
    cout << "Bubble sort selesai!" << endl;
}

// Exchange Sort
void exchange_sort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrayData[i] > arrayData[j]) tukar(i, j);
        }
    }
    cout << "Exchange sort selesai!" << endl;
}

// Selection Sort
void selection_sort() {
    for (int i = 0; i < n - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (arrayData[j] < arrayData[pos]) pos = j;
        }
        if (pos != i) tukar(pos, i);
    }
    cout << "Selection sort selesai!" << endl;
}

// Insertion Sort
void insertion_sort() {
    for (int i = 1; i < n; i++) {
        int temp = arrayData[i];
        int j = i - 1;
        while (j >= 0 && arrayData[j] > temp) {
            arrayData[j + 1] = arrayData[j];
            j--;
        }
        arrayData[j + 1] = temp;
    }
    cout << "Insertion sort selesai!" << endl;
}

// Quick Sort
void Quicksort(int L, int R) {
    int i = L, j = R;
    int mid = arrayData[(L + R) / 2];
    do {
        while (arrayData[i] < mid) i++;
        while (arrayData[j] > mid) j--;
        if (i <= j) {
            tukar(i, j);
            i++;
            j--;
        }
    } while (i < j);
    if (L < j) Quicksort(L, j);
    if (i < R) Quicksort(i, R);
}

// Input data
void Input() {
    cout << "Masukkan jumlah data = ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan data ke-" << (i + 1) << " = ";
        cin >> arrayData[i];
    }
}

// Tampilkan data
void Tampil() {
    cout << "Data: ";
    for (int i = 0; i < n; i++) {
        cout << arrayData[i] << " ";
    }
    cout << endl;
}

// Acak data
void Acaklagi() {
    srand(time(0)); // Inisialisasi seed untuk random
    for (int i = 0; i < n; i++) {
        int randIndex = rand() % n;
        tukar(i, randIndex);
    }
    cout << "Data sudah teracak!" << endl;
}

// Fungsi untuk membersihkan layar (cross-platform)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Main program
int main() {
    int pil;
    do {
        clearScreen();
        cout << "PROGRAM SORTING" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Exchange Sort" << endl;
        cout << "4. Selection Sort" << endl;
        cout << "5. Insertion Sort" << endl;
        cout << "6. Quick Sort" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Acak Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pil;

        switch (pil) {
            case 1:
                Input();
                break;
            case 2:
                bubble_sort();
                break;
            case 3:
                exchange_sort();
                break;
            case 4:
                selection_sort();
                break;
            case 5:
                insertion_sort();
                break;
            case 6:
                Quicksort(0, n - 1);
                cout << "Quick sort selesai!" << endl;
                break;
            case 7:
                Tampil();
                break;
            case 8:
                Acaklagi();
                break;
            case 0:
                cout << "Keluar program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        system("pause");
    } while (pil != 0);

    return 0;
}
