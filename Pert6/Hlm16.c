#include <stdio.h>
#include <string.h> 

typedef struct {
  char elemen[30];
  int jml_kata; 
} Kata;

Kata kata;
Kata *p_kata = &kata;

int main() {
  char kalimat[30];
  p_kata->jml_kata = 0;
  char *p = p_kata->elemen;

  printf("Masukkan kata: ");
  fgets(kalimat, sizeof(kalimat), stdin); 
 
  kalimat[strcspn(kalimat, "\n")] = '\0';

 
  strlen(kalimat);

  printf("Kalimat: %s\n", kalimat);

  
  int i;
  for (i = 0; kalimat[i] != '\0' && kalimat[i] != ' '; i++);
  p_kata->jml_kata = (kalimat[i] == ' ') + 1; 

  
  p = p_kata->elemen;
  for (i = 0; kalimat[i] != '\0'; i++) {
    if (kalimat[i] != ' ') {
      *p = kalimat[i];
      p++;
    }
  }

  
  int palindrom = 1;
  for (i = 0; i < p_kata->jml_kata / 2; i++) {
    if (*p != *(p + p_kata->jml_kata - 1 - i)) {
      palindrom = 0;
      break;
    }
    p++;
  }

  if (palindrom) {
    printf("Kata tersebut palindrom.\n");
  } else {
    printf("Kata tersebut bukan palindrom.\n");
  }

  return 0;
}