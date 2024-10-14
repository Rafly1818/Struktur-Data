#include <stdio.h>

int searchCharacter(char word[], char target, int *count) {
  int found = 0;
  for (int i = 0; word[i] != '\0'; i++) {
    if (word[i] == target) {
      found = 1;
      (*count)++;
    }
  }
  return found;
}

int main() {
  char word[100]; // Alokasikan ruang untuk input pengguna
  char target;

  printf("Masukkan kata: ");
  fgets(word, sizeof(word), stdin); // Dapatkan input kata dari pengguna

  printf("Masukkan karakter yang ingin dicari: ");
  scanf("%c", &target); // Dapatkan input karakter target dari pengguna

  int count = 0;
  int found = searchCharacter(word, target, &count);

  if (found) {
    printf("Huruf '%c' ditemukan %d kali dalam kata '%s'\n", target, count, word);
  } else {
    printf("Huruf '%c' tidak ditemukan dalam kata '%s'\n", target, word);
  }

  return 0;
}