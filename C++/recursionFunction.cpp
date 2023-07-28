#include <iostream>
using namespace std;

int fungsiFaktorial(int a);
int fungsiFibonacci(int a);
int bilanganAwal = 1;

int main() {
    int inputanUser;
    cout<<"Masukkan angka yang ingin difaktorialkan dan difibonaccikan: ";
    cin>>inputanUser;
    cout<<"Hasil Faktorial dari angka "<<inputanUser<<" adalah "<<fungsiFaktorial(inputanUser)<<endl;
    cout<<"Proses Fibonacci : "<<fungsiFibonacci(inputanUser)<<endl;
    return 0;
}

int fungsiFaktorial(int a) {
    int hasilFaktorial = a;
    if(a <= 1) {
        return 1;
    } else {
        return hasilFaktorial * fungsiFaktorial((a - 1));
    }
}

// Fibonacci dengan menggunakan recursion
int fungsiFibonacci(int n) {
    // 0, 1, 1, 2, 3, 5, 8, 13
     if(n == 0 || n == 1) {
        return n;
     } else {
        return fibonacci(n-1) + fibonacci(n - 2);
     }
}

// Fibonacci dengan menggunakna iterasi
// int fungsiFibonacci(int a) {
// //   0, 1, 1, 2, 3, 5, 8, 13, 21
//     int bilanganSebelumnya = 0, bilanganSekarang = 1, nextTerm = 0;

//     for(int i = 1; i <= a; i++) {
//       if(i == 1) {
//         cout<<nextTerm<<", ";
//       } else if(i == 2) {
//         cout<<(nextTerm + 1)<<", ";
//     } else{
//          nextTerm = bilanganSekarang + bilanganSebelumnya;
//         // 1 + 0 = 1
//         // 1 + 1 = 2
//         // 2 + 1 = 3
//         bilanganSebelumnya = bilanganSekarang;
//         // 0 -> 1
//         // 1 -> 1
//         // 1 -> 2
//         bilanganSekarang = nextTerm;
//         // 1 -> 1
//         // 1 -> 2
//         // 2 -> 3
//         if(i == a) {
//         cout<<nextTerm<<endl;
//         } else {
//         cout<<nextTerm<<", ";
//         }
//       }
//     }

//     cout<<"Angka fibonacci yang ke-"<<a<<" adalah : ";
//     return nextTerm;
// }