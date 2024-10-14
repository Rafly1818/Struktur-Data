#include <stdio.h>
#include <string.h>

void balikKalimat(char *kalimat, int panjang) {
  char temp;
  for (int i = 0; i < panjang / 2; i++) {
    temp = kalimat[i];
    kalimat[i] = kalimat[panjang - i - 1];
    kalimat[panjang - i - 1] = temp;
  }
}

int main() {
  char kalimat[100];

  printf("Masukkan kalimat: ");
  fgets(kalimat, sizeof(kalimat), stdin);

  // Menghilangkan newline character
  kalimat[strlen(kalimat) - 1] = '\0';

  int panjang = strlen(kalimat);

  printf("Kalimat asli: %s\n", kalimat);

  balikKalimat(kalimat, panjang);

  printf("Kalimat terbalik: %s\n", kalimat);

  

  return 0;
}