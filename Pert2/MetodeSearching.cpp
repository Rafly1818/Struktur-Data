#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi untuk menampilkan menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Sequential Search\n";
    cout << "2. Binary Search\n";
    cout << "3. Interpolation Search\n";
    cout << "Pilih operasi yang ingin dilakukan (1-3): ";
}

// Fungsi untuk mencetak array
void printArray(const vector<int>& arr) {
    cout << "Isi array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Fungsi sequential search untuk mencari dan mengganti nilai dalam array
void sequentialSearch(vector<int>& arr, int target) {
    auto it = find(arr.begin(), arr.end(), target);
    if (it != arr.end()) {
        int index = distance(arr.begin(), it);
        cout << "Nilai " << target << " ditemukan pada indeks: " << index << endl;
        int newValue;
        cout << "Masukkan nilai baru: ";
        cin >> newValue;
        arr[index] = newValue;
        cout << "Nilai " << target << " telah diganti dengan " << newValue << endl;
    } else {
        cout << "Nilai " << target << " tidak ditemukan dalam array." << endl;
    }
}

// Fungsi binary search untuk mencari dan mengganti nilai dalam array
void binarySearch(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int low = 0, high = arr.size() - 1;
    int index = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            index = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (index != -1) {
        cout << "Nilai " << target << " ditemukan pada indeks: " << index << endl;
        int newValue;
        cout << "Masukkan nilai baru: ";
        cin >> newValue;
        arr[index] = newValue;
        cout << "Nilai " << target << " telah diganti dengan " << newValue << endl;
    } else {
        cout << "Nilai " << target << " tidak ditemukan dalam array." << endl;
    }
}

// Fungsi interpolation search untuk mencari dan mengganti nilai dalam array
void interpolationSearch(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int low = 0, high = arr.size() - 1;
    int index = -1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);
        if (arr[pos] == target) {
            index = pos;
            break;
        } else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    if (index != -1) {
        cout << "Nilai " << target << " ditemukan pada indeks: " << index << endl;
        int newValue;
        cout << "Masukkan nilai baru: ";
        cin >> newValue;
        arr[index] = newValue;
        cout << "Nilai " << target << " telah diganti dengan " << newValue << endl;
    } else {
        cout << "Nilai " << target << " tidak ditemukan dalam array." << endl;
    }
}

int main() {
    int choice;
    vector<int> arr;

    cout << "Masukkan jumlah angka dalam array: ";
    int n;
    cin >> n;

    cout << "Masukkan " << n << " angka: ";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    displayMenu();
    cin >> choice;

    int target;
    cout << "Masukkan nilai yang ingin dicari dan diganti: ";
    cin >> target;

    switch (choice) {
        case 1:
            sequentialSearch(arr, target);
            break;
        case 2:
            binarySearch(arr, target);
            break;
        case 3:
            interpolationSearch(arr, target);
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
    }

    cout << "Array setelah diubah:\n";
    printArray(arr);

return 0;
}