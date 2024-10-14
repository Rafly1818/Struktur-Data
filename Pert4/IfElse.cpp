#include <iostream>
#include <string>

using namespace std;

void countCharacters(string sentence) {
  int consonants = 0, vowels = 0, numerics = 0;

  for (char ch : sentence) {
    if (isalpha(ch)) {
      if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u') {
        vowels++;
      } else {
        consonants++;
      }
    } else if (isdigit(ch)) {
      numerics++;
    }
  }

  cout << "Konsonan: " << consonants << endl;
  cout << "Vokal: " << vowels << endl;
  cout << "Numerik: " << numerics << endl;
}

int main() {
cout << "Latihan 4 Struktur data" << endl << endl;
  string sentence;
  cout << "Masukkan kalimat: ";
  getline(cin, sentence); 

  countCharacters(sentence);

  return 0;
}