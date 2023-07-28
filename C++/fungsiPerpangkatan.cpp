#include <iostream>

using namespace std;

int perhitunganPangkat(int a,int b) {
int hasilPangkat = 0;
for(int i = 1; i <= b; i++){
hasilPangkat = a * a;
}
return hasilPangkat;
}


int main() {
    cout<<perhitunganPangkat(5,2)<<endl;
}