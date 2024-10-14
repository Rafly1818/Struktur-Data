#include <stdio.h>
#include <string.h>

char getKeypadChar(char c) {
    // Konversi huruf kecil menjadi huruf besar jika perlu
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }

    switch (c) {
        case 'A': case 'B': case 'C':
            return '2';
        case 'D': case 'E': case 'F':
            return '3';
        case 'G': case 'H': case 'I':
            return '4';
        case 'J': case 'K': case 'L':
            return '5';
        case 'M': case 'N': case 'O':
            return '6';
        case 'P': case 'Q': case 'R': case 'S':
            return '7';
        case 'T': case 'U': case 'V':
            return '8';
        case 'W': case 'X': case 'Y': case 'Z':
            return '9';
        case ' ':
            return '#';  // Mengganti spasi dengan #
        default:
            return c;  // Mengembalikan karakter asli jika bukan huruf
    }
}

void convertToKeypad(const char* input, char* output) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        output[i] = getKeypadChar(input[i]);
    }
    output[i] = '\0';  // Menambahkan null terminator di akhir string
}

int main() {
    char kalimat[100];
    char hasil[100];

    printf("Masukkan sebuah kalimat : ");
    fgets(kalimat, sizeof(kalimat), stdin);

    // Menghapus newline yang ditambahkan oleh fgets
    kalimat[strcspn(kalimat, "\n")] = '\0';

    convertToKeypad(kalimat, hasil);
    
    printf("%s\n", hasil);

    return 0;
}