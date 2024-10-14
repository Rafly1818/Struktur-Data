#include <stdio.h>
#include <string.h>
void balikKata(char *kata) {
  char *awal = kata;
  char *akhir = kata + strlen(kata) - 1;

  while (awal < akhir) {
    char temp = *awal;
    *awal = *akhir;
    *akhir = temp;

    awal++;
    akhir--;
  }
}

int main() {
  char kata[100];

  printf("Masukkan kata/kalimat: ");
  scanf("%s", kata);

  balikKata(kata);

  printf("Kata/kalimat yang dibalik: %s\n", kata);

  return 0;
}