#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    int Nim;
    string nama;
    float ipk;
    Mahasiswa* next;
};

Mahasiswa* head = nullptr;
int currentNim = 1;

bool isEmpty() {
    return head == nullptr;
}

void tambahDepan() {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->Nim = currentNim++;
    cout << "Masukkan Biodata Mahasiswa" << endl << endl;
    cout << "Masukkan nama mahasiswa: ";
    cin >> newNode->nama;
    cout << "Masukkan IPK: ";
    cin >> newNode->ipk;
    cout << endl;

    if (isEmpty()) {
        head = newNode;
        head->next = head;
    } else {
        Mahasiswa* bantu = head;
        while (bantu->next != head) {
            bantu = bantu->next;
        }
        newNode->next = head;
        bantu->next = newNode;
        head = newNode;
    }
}

void hapusDepan() {
    if (isEmpty()) {
        cout << "Data kosong!" << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Mahasiswa* bantu = head;
        while (bantu->next != head) {
            bantu = bantu->next;
        }
        Mahasiswa* temp = head;
        head = head->next;
        bantu->next = head;
        delete temp;
    }
    cout << "Data depan telah dihapus." << endl << endl;
}

void hapusBelakang() {
    if (isEmpty()) {
        cout << "Data kosong!" << endl << endl;
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Mahasiswa* bantu = head;
        Mahasiswa* prev = nullptr;
        while (bantu->next != head) {
            prev = bantu;
            bantu = bantu->next;
        }
        prev->next = head;
        delete bantu;
    }
    cout << "Data belakang telah dihapus." << endl << endl;
}

void cetak() {
    if (!isEmpty()) {
        Mahasiswa* bantu = head;
        do {
            cout << "NIM: " << bantu->Nim << endl;
            cout << "Nama: " << bantu->nama << endl;
            cout << "IPK: " << bantu->ipk << endl;
            cout << "-----------------------" << endl;
            bantu = bantu->next;
        } while (bantu != head);
        cout << endl;
    } else {
        cout << "Data kosong!" << endl << endl;
    }
}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

int main() {
    int pilihan;
    do {
        clearScreen();
        cout << "Silahkan Masukkan Pilihan Anda" << endl << endl;
        cout << "1. Tambah Depan\n2. Cetak\n3. Hapus Depan\n4. Hapus Belakang\n5. Keluar" << endl << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        clearScreen();
        switch (pilihan) {
            case 1:
                tambahDepan();
                break;
            case 2:
                cetak();
                break;
            case 3:
                hapusDepan();
                break;
            case 4:
                hapusBelakang();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        if (pilihan != 5) {
            cout << "Tekan enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
    } while (pilihan != 5);

    return 0;
}