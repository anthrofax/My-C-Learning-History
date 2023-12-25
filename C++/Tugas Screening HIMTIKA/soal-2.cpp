#include <iostream>
using namespace std;

int MenghitungLuasPersegiPanjang(int panjang, int lebar) {
  return panjang * lebar;
}

int main() {
    int panjang, lebar, luas;

    cout << "Masukkan nilai untuk panjang dari persegi panjang: ";
    cin>>panjang;
    cout  << "Masukkan nilai untuk lebar dari persegi panjang: ";
    cin>>lebar;

    luas = MenghitungLuasPersegiPanjang(panjang, lebar);

    cout << "Luas dari persegi panjang tersebut adalah " << luas <<endl;
}