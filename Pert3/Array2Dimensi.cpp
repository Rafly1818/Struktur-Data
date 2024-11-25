#include <iostream>

using namespace std;

void searchData2D(int data[][3], int rows, int cols, int target) { 
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (data[i][j] == target) {
        cout << "Data " << target << " ditemukan pada posisi: [" << i << "][" << j << "]" << endl;
        return; 
      }
    }
  }

  cout << "Data " << target << " tidak ditemukan" << endl;
}

int main() {
cout << "Latihan 3 Array 2 dimensi";
  int data[3][3] = {{1, 3, 2}, {10, 5, 8}, {15, 24, 10}};
  int rows = sizeof(data) / sizeof(data[0]); 
  int cols = sizeof(data[0]) / sizeof(data[0][0]);
  int target = 24; 

  searchData2D(data, rows, cols, target);

  return 0;
}