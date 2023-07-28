#include <iostream>
using namespace std;

// Nama : Afridho Ikhsan
// Kelas : 2A Informatika
// NPM : 2210631170002

void push(int stack[], int &top, int item)
{
    top++;
    stack[top] = item;
}

int pop(int stack[], int &top)
{
    int item = stack[top];
    top--;
    return item;
}

void hanoiFunction(int jumlahData, int awal[], int &awal_top, int akhir[], int &akhir_top, int bantu[], int &bantu_top, char menaraAwal, char menaraTujuan, char menaraPerantara)
{
    if (jumlahData == 1)
    {
        int item = pop(awal, awal_top);
        push(akhir, akhir_top, item);
        ≈ cout << "Pindahkan batu " << item << " Dari Menara " << menaraAwal << " Ke menara " << menaraTujuan << endl;
    }
    else
    {
        hanoiFunction(jumlahData - 1, awal, awal_top, bantu, bantu_top, akhir, akhir_top, menaraAwal, menaraPerantara, menaraTujuan);
        hanoiFunction(1, awal, awal_top, akhir, akhir_top, bantu, bantu_top, menaraAwal, menaraTujuan, menaraPerantara);
        hanoiFunction(jumlahData - 1, bantu, bantu_top, akhir, akhir_top, awal, awal_top, menaraPerantara, menaraTujuan, menaraAwal);
    }
}
int main()
{
    int awal[3] = {30, 20, 10}, awal_top = 2;
    int akhir[3] = {0}, akhir_top = -1;
    int bantu[3] = {0}, bantu_top = -1;

    hanoiFunction(3, awal, awal_top, akhir, akhir_top, bantu, bantu_top, 'A', 'C', 'B');

    return 0;
}
