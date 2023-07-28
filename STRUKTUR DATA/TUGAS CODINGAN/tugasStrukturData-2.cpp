#include <iostream>
using namespace std;

// Nama ; Afridho Ikhsan
// NPM : 2210631170002

int main()
{
    int arrTest[4][4] = {{92, 42, 64, 85}, {23, 63, 34, 12}, {78, 12, 67, 83}, {53, 99, 19, 12}}; // Inisialisasi variable array 2 dimensi bernama "arrTest" dengan 4 baris & 4 kolom
    int i, j, m, n;                                                                               // Deklarasi 4 variable yang akan digunakan untuk perulangan nanti

    cout << "Nilai awal dari Array 2 Dimensi \"arrTest\" : " << endl;
    for (i = 0; i < 4; i++) // Perulangan pertama untuk menampilkan bentuk awal dari "arrTest"
    {
        for (j = 0; j < 4; j++)
        {
            cout << arrTest[i][j] << "\t"; // Menampilkan masing-masing elemen dari "arrTest" sesuai dengan urutan baris & kolomnya
        }
        cout << endl;
    }

    cout << endl
         << "Bentuk dari \"arrTest\" jika diputar 90 derajat : " << endl;

    for (m = 0; m < 4; m++) // Perulangan kedua untuk menampilkan "arrTest" jika diputar 90 derajat
    {
        for (n = 3; n >= 0; n--)
        {
            cout << arrTest[n][m] << "\t";
        }
        cout << endl;
        n = 3;
    }
}
