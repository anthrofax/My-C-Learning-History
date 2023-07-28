#include <iostream>
using namespace std;

struct node
{
    int number;
    node *next;
};

node *awal, *akhir, *middle, *baru, *skrg, *del, *cur;

void inputDiDepan()
{
    baru = new node();
    cout << "Masukkan Angka Baru: ";
    cin >> baru->number;
    baru->next = awal;
    awal = baru;
}

void inputDiBelakang()
{
    baru = new node();
    cout << "Masukkan Angka Baru: ";
    cin >> baru->number;
    baru->next = NULL;
    akhir->next = baru;
    akhir = baru;
}

void inputDiTengah()
{
    baru = new node();
    cout << "Masukkan Angka Baru: ";
    cin >> baru->number;
    baru->next = akhir;
    middle->next = baru;
    middle = baru;
}

void printSingleLinkedList()
{
    skrg = awal;
    while (skrg != NULL)
    {
        cout << "Datanya adalah " << skrg->number << endl;

        skrg = skrg->next;
    }
}

void deleteAwal()
{
    del = awal;
    awal = awal->next;
    delete del;
}

void deleteAkhir()
{
    del = akhir;
    cur = awal;
    while (cur->next != akhir)
    {
        cur = cur->next;
    }
    akhir = cur;
    akhir->next = NULL;
    delete del;
}

void deleteTengah()
{
    del = middle;
    cur = awal;
    while (cur->next != middle)
    {
        cur = cur->next;
    }
    middle = cur;
    middle->next = akhir;
    delete del;
}

int main()
{
    awal = new node();
    middle = new node();
    akhir = new node();

    awal->number = 1;
    middle->number = 2;
    akhir->number = 3;

    awal->next = middle;
    middle->next = akhir;
    akhir->next = NULL;

    printSingleLinkedList();

    cout << endl;

    inputDiDepan();
    printSingleLinkedList();

    cout << endl;

    inputDiTengah();
    printSingleLinkedList();

    cout << endl;

    inputDiBelakang();
    printSingleLinkedList();

    cout << endl;

    deleteAwal();
    printSingleLinkedList();

    cout << endl;

    deleteAkhir();
    printSingleLinkedList();

    cout << endl;

    deleteTengah();
    printSingleLinkedList();
}