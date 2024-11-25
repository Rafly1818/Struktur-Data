#include <iostream>

using namespace std;

void searchData1D(int arr[], int size, int target) {
  int foundIndices[size]; 
  int foundIndexCount = 0; 

  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      foundIndices[foundIndexCount++] = i; 
    }
  }

  if (foundIndexCount == 0) {
    cout << "Data " << target << " tidak ditemukan" << endl;
  } else {
    cout << "Data " << target << " ditemukan pada indeks: ";
    for (int i = 0; i < foundIndexCount; i++) {
      cout << foundIndices[i] << " "; 
    }
    cout << endl;
  }
}

int main() {
  cout << "Latihan 3 Array 1 Dimensi " << endl << endl;
  int arr[] = {12, 14, 15, 12, 5}; 
  int size = sizeof(arr) / sizeof(arr[0]); 
  int target = 12; 

  searchData1D(arr, size, target);

  return 0;
}