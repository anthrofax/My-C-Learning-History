#include <iostream>

using namespace std;

void menampilkanHasil(float inputan) {
    cout << inputan << endl;
}
int main() {
    int panjang, lebar, luasPersegiPanjang, kelilingPersegiPanjang;

    cout << "Panjang : ";
    cin>>panjang;
    cout << "Lebar : ";
    cin>>lebar;
    luasPersegiPanjang = panjang * lebar;
    kelilingPersegiPanjang = 2 * (panjang + lebar);
    cout << "Menggunakan void"<<endl;
    cout << "Luas nya adalah : ";
    menampilkanHasil(luasPersegiPanjang);
    cout << "Menggunakan void"<<endl;
    cout << "Keliling nya adalah : ";
    menampilkanHasil(kelilingPersegiPanjang);

}