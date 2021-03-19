#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;


class file {
  ifstream inFile;
  string line[21];
  string pic;
  struct check {
    int line;
    int col;
  };

  public:
    file();
  ~file();
  void loop(); //pêtla wczytuj¹ca z pliku
  //USER CODE 1: pozosta³e metody programu
  void checkPic();
};

file::file() {
  inFile.open("dane_obrazki.txt");
  if (!inFile.good()) {
    cerr << "Blad - pliku nie da sie otworzyc!\n";
    exit(1);
  }
}

file::~file() {
  inFile.close();
}

//USER CODE 2: pozosta³e metody - implementacja

void file::loop() {
  string data; //lub np. int jeœli czytamy liczby
  while (!inFile.eof()) //string po stringu (do spacji/nowej linii) wczyta ca³y plik
  {
    inFile >> data;
    //USER CODE 3: obs³uga danych wczytanych z pliku za pomoc¹ metod powy¿ej
    cout << data << " ";
  }
}

void file::checkPic() {
  typedef struct check chec(pic dPic) {
    int wierszParzysty, kolumnaParzysta;

    struct check res;

    res.line = dlugosc + 1;
    res.col = dlugosc + 1;

    for (int i = 0; i < RZM; i++) {
      wierszParzysty = kolumnaParzysta = 0;

      for (int j = 0; j < RZM; j++) {
        wierszParzysty = wierszParzysty + dPic[i][j];
        kolumnaParzysta = kolumnaParzysta + dPic[j][i];
      }

      if ((wierszParzysty % 2) != dPic[i][dlugosc])
        res.line = i + 1;

      if ((kolumnaParzysta % 2) != dPic[dlugosc][i])
        res.col = i + 1;
    }

    return res;
  }
}
int main() {
  file f;
  f.loop();
  f.checkPic();
  return 0;
}
