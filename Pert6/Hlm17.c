#include <stdio.h>
#include <string.h> 

typedef struct {
    int tgl;
    int bln;
    int th;
} Tanggal;

typedef struct {
    char noID[5];
    char nama[30];
    char jenis_kelamin;
    Tanggal tgl_lahir;
} KTP;

typedef struct {
    KTP ktp[100]; 
    int jml;
} Data_KTP;

Data_KTP data_ktp;
Data_KTP *p = &data_ktp;

void tambahData() {
    if (p->jml >= 100) {
        printf("Data KTP penuh!\n");
        return;
    }

    printf("Masukkan data KTP baru:\n");
    printf("No. ID: ");
    scanf("%s", p->ktp[p->jml].noID);

    printf("Nama: ");
    scanf("%s", p->ktp[p->jml].nama);

    printf("Jenis Kelamin (L/P): ");
    scanf(" %c", &p->ktp[p->jml].jenis_kelamin);

    printf("Tanggal Lahir (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &p->ktp[p->jml].tgl_lahir.tgl, &p->ktp[p->jml].tgl_lahir.bln, &p->ktp[p->jml].tgl_lahir.th);

    p->jml++;
}

void cariDataTahun(int tahun) {
    int ditemukan = 0;

    for (int i = 0; i < p->jml; i++) {
        if (p->ktp[i].tgl_lahir.th == tahun) {
            printf("Data KTP ke-%d:\n", i + 1);
            printf("No. ID: %s\n", p->ktp[i].noID);
            printf("Nama: %s\n", p->ktp[i].nama);
            printf("Jenis Kelamin: %c\n", p->ktp[i].jenis_kelamin);
            printf("Tanggal Lahir: %d/%d/%d\n", p->ktp[i].tgl_lahir.tgl, p->ktp[i].tgl_lahir.bln, p->ktp[i].tgl_lahir.th);
            printf("\n");
            ditemukan = 1;
        }
    }

    if (!ditemukan) {
        printf("Tidak ada data KTP dengan tahun lahir %d.\n", tahun);
    }
}

void tampilkanDataJenisKelamin(char jenis_kelamin) {
    int ditemukan = 0;

    for (int i = 0; i < p->jml; i++) {
        if (p->ktp[i].jenis_kelamin == jenis_kelamin) {
            printf("Data KTP ke-%d:\n", i + 1);
            printf("No. ID: %s\n", p->ktp[i].noID);
            printf("Nama: %s\n", p->ktp[i].nama);
            printf("Jenis Kelamin: %c\n", p->ktp[i].jenis_kelamin);
            printf("Tanggal Lahir: %d/%d/%d\n", p->ktp[i].tgl_lahir.tgl, p->ktp[i].tgl_lahir.bln, p->ktp[i].tgl_lahir.th);
            printf("\n");
            ditemukan = 1;
        }
    }

    if (!ditemukan) {
        printf("Tidak ada data KTP dengan jenis kelamin %c.\n", jenis_kelamin);
    }
}

void editData() {
    char no_ktp[5];
    printf("Masukkan No. ID KTP yang ingin diedit: ");
    scanf("%s", no_ktp);

    int i;
    for (i = 0; i < p->jml; i++) {
        if (strcmp(p->ktp[i].noID, no_ktp) == 0) {
            printf("Masukkan data KTP baru untuk No. ID %s:\n", no_ktp);
            printf("Nama: ");
            scanf("%s", p->ktp[i].nama);

            printf("Jenis Kelamin (L/P): ");
            scanf(" %c", &p->ktp[i].jenis_kelamin);

            printf("Tanggal Lahir (DD/MM/YYYY): ");
            scanf("%d/%d/%d", &p->ktp[i].tgl_lahir.tgl, &p->ktp[i].tgl_lahir.bln, &p->ktp[i].tgl_lahir.th);

            printf("Data KTP berhasil diubah.\n");
            return;
        }
    }

    printf("Data KTP dengan No. ID %s tidak ditemukan.\n", no_ktp);
}

int main() {
    data_ktp.jml = 0;

    int pilihan;
    int tahun;
    char jenis_kelamin;

    do {
        printf("Menu:\n");
        printf("1. Tambah Data KTP\n");
        printf("2. Cari Data KTP Berdasarkan Tahun Lahir\n");
        printf("3. Tampilkan Data KTP Berdasarkan Jenis Kelamin\n");
        printf("4. Edit Data KTP\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                printf("Masukkan tahun lahir yang dicari: ");
                scanf("%d", &tahun);
                cariDataTahun(tahun);
                break;
            case 3:
                printf("Masukkan jenis kelamin (L/P): ");
                scanf(" %c", &jenis_kelamin);
                tampilkanDataJenisKelamin(jenis_kelamin);
                break;
            case 4:
                editData();
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (pilihan != 5);

    return 0;
}