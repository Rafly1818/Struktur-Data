#include <iostream>
#include <string>

using namespace std;

struct Node {
  char data;
  Node* next;
};

Node* head = NULL;

// Fungsi untuk membersihkan layar
void clearScreen() {
  cout << "\033[2J\033[1;1H";
}

// Fungsi untuk menampilkan data dari linked list
void viewData() {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// Fungsi untuk menambahkan data ke dalam linked list
void addData(string str) {
  for (int i = 0; i < str.length(); i++) {
    Node* newNode = new Node;
    newNode->data = str[i];
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
    } else {
      Node* temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  // Menampilkan pesan "Tekan enter untuk melanjutkan..."
  cout << "Tekan enter untuk melanjutkan...";
  cin.ignore();
  cin.get();
}

int main() {
  int choice;

  while (true) {
    clearScreen();
    cout << "Masukkan Pilihan Anda" << endl << endl;
    cout << "1. Tambah" << endl;
    cout << "2. Lihat" << endl;
    cout << "3. Keluar" << endl << endl;
    cout << "Pilihan: ";
    cin >> choice;

    clearScreen();

    switch (choice) {
      case 1: {
        string str;
        cout << "Silahkan isi" << endl << endl;
        cout << "Masukkan string: ";
        cin >> str;
        addData(str);
        break;
      }
      case 2:
        cout << "Hasil output" << endl << endl;
        viewData();
        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        break;
      case 3:
        cout << "Terimakasih";
        exit(0);
      default:
        cout << "Pilihan tidak valid." << endl;
        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
    }
  }

  return 0;
}