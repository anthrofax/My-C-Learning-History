#include <iostream>
using namespace std;

// Prototype merupakan cara agar kita bisa melakukan deklarasi suatu fungsi lebih awal dan menulis program nya di bawah (belakangan)

// Prototype ini akan berguna saat kita ingin bekerja dengan multifile
int hitungLuas(int a, int b);


void tampilkanHasilLuas(int hasilLuas);

int main() {
    int panjang, lebar, LuasPersegiPanjang;

    cin>>panjang;
    cin>>lebar;
    LuasPersegiPanjang = hitungLuas(panjang, lebar);
    cout<<"Luas dari persegi panjang adalah : ";
    tampilkanHasilLuas(LuasPersegiPanjang);
}

int hitungLuas(int a, int b) {
return a * b;
}

void tampilkanHasilLuas(int hasilLuas) {
    cout<<hasilLuas<<endl;
}