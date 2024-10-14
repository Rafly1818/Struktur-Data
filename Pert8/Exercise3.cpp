#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct Buku {
    int nomor;
    string judul;
    int harga;
    Buku* next;
};

class SLLC {
private:
    Buku* head;

public:
    SLLC() {
        head = nullptr;
    }

    void tambahBuku(int nomor, string judul, int harga) {
        Buku* bukuBaru = new Buku();
        bukuBaru->nomor = nomor;
        bukuBaru->judul = judul;
        bukuBaru->harga = harga;
        bukuBaru->next = nullptr;

        if (head == nullptr) {
            head = bukuBaru;
        } else {
            Buku* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = bukuBaru;
        }
    }

    void cetakBuku() {
        if (head == nullptr) {
            cout << "Tidak ada buku dalam daftar." << endl;
            return;
        }
        Buku* temp = head;
        while (temp != nullptr) {
            cout << "Data Buku" << endl << endl;
            cout << "Nomor Buku: " << temp->nomor << endl;
            cout << "Judul Buku: " << temp->judul << endl; 
            cout << "Harga Buku: " << formatRupiah(temp->harga) << endl << endl;
            temp = temp->next;
        }
    }

    void editHarga(int nomor, int hargaBaru) {
        Buku* temp = head;
        while (temp != nullptr) {
            if (temp->nomor == nomor) {
                temp->harga = hargaBaru;
                cout << "\nHarga untuk buku dengan nomor " << nomor << " telah diubah menjadi " << formatRupiah(hargaBaru) << "." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Buku dengan nomor " << nomor << " tidak ditemukan." << endl;
    }

    string formatRupiah(int harga) {
        stringstream ss;
        ss.imbue(locale("")); // locale setting for thousand separator
        ss << fixed << "Rp" << harga;
        return ss.str();
    }

    void menu() {
        while (true) {
            cout << "\033[2J\033[1;1H";  // Membersihkan layar
            cout << "Pilih menu\n" << endl;
            cout << "1. Tambah Buku\n";
            cout << "2. Cetak Buku\n";
            cout << "3. Edit Harga\n";
            cout << "4. Keluar\n" << endl;
            cout << "Masukkan pilihan Anda: ";
            char pilihan;
            cin >> pilihan;
            cin.ignore();  // Membersihkan buffer input

            if (pilihan == '1') {
                cout << "\033[2J\033[1;1H";
                int nomor, harga;
                string judul;
                cout << "Silahkan Masukkan Data Buku" << endl << endl;
                cout << "Masukkan nomor buku: ";
                cin >> nomor;
                cin.ignore();  // Membersihkan buffer input
                cout << "Masukkan judul buku: ";
                getline(cin, judul);
                cout << "Masukkan harga buku: ";
                cin >> harga;
                tambahBuku(nomor, judul, harga);
            } else if (pilihan == '2') {
                cout << "\033[2J\033[1;1H";
                cetakBuku();
                cout << endl;
                cout << "Tekan Enter untuk kembali ke menu...";
                cin.ignore();
                cin.get();  // Menunggu pengguna menekan Enter
            } else if (pilihan == '3') {
                cout << "\033[2J\033[1;1H";
                cout << "Silahkan Masukkan Harga Baru Yang Anda Inginkan" << endl << endl;
                int nomor, hargaBaru;
                cout << "Masukkan nomor buku yang ingin diedit: ";
                cin >> nomor;
                cout << "Masukkan harga baru: ";
                cin >> hargaBaru;
                editHarga(nomor, hargaBaru);
                cout << "Tekan Enter untuk kembali ke menu...";
                cin.ignore();
                cin.get();  // Menunggu pengguna menekan Enter
            } else if (pilihan == '4') {
                cout << "Keluar dari program." << endl;
                break;
            } else {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                cout << "Tekan Enter untuk kembali ke menu...";
                cin.ignore();
                cin.get();  // Menunggu pengguna menekan Enter
            }
        }
    }
};

int main() {
    SLLC sllc;
    sllc.menu();
    return 0;
}