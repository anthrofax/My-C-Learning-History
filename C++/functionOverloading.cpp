#include <iostream>
using namespace std;

// Overloading = menimpa

// Dengan overloading (penimpaan function), akan memungkinkan kita untuk membuat 1 fungsi yang cocok dengan beberapa kondisi argument yang akan kita masukkan, karena c++ akan otomatis memilih function mana yang paling cocok untuk digunakan, walaupun nama function nya sama.

// *Misal

// Basic Function
int menghitungLuasKotak(int panjang, int lebar) {
    return panjang * lebar;
}

double menghitungLuasKotak(double panjang, double lebar) {
    return panjang * lebar;
}

int menghitungLuasKotak(int sisi) {
    return sisi * sisi;
}

double menghitungLuasKotak(double sisi) {
    return sisi * sisi;
}

int main() {
    // Pemanggilan function di bawah tetap bisa bekerja dengan normal walaupun argumen yang dimasukkan berbeda-beda, baik itu dari jumlah argument nya maupun tipe data dari argument yang kita masukkan (bisa berjalan di berbagai kondisi yang kita siapkan)

    // Menghitung luas dengan 2 argument bertipe integer
    cout<<menghitungLuasKotak(2,3)<<endl;
    // Menghitung luas dengan 2 argument bertipe double (inputan yang dimasukkan bilangan riil).
    cout<<menghitungLuasKotak(2.5, 4.5)<<endl;
    // Menghitung luas kotak yang hanya memiliki 1 argument
    cout<<menghitungLuasKotak(2)<<endl;
    // Menghitung luas kotak yang hanya memiliki 1 argument (inputannya berupa bilangan riil).
    cout<<menghitungLuasKotak(5.5)<<endl;

    return 0;
}