#include <iostream>
using namespace std;

string determineNumber(int bil) {
    if (bil == 0) return "0";
    else if(bil > 0) return "positif";
    else  return "negatif";
}

int main() {
    int bil;

    cout << "Masukkan sebuah bilangan: ";
    cin>>bil;

    cout << "Bilangan yang anda masukkan adalah " << determineNumber(bil) <<endl;
}