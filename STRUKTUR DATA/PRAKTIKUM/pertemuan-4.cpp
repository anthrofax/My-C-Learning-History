#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int main()
{
    // Buat simpul pertama dan isinya
    Node *head = new Node();
    head->data = 1;
    head->next = NULL;

    // BUat simpul kedua dan isinya
    Node *second = new Node();
    second->data = 2;
    second->next = NULL;

    // Sambungkan simpul kedua ke simpul pertama
    head->next = second;

    // Buat simpul ketiga dan isinya
    Node *third = new Node();
    third->data = 3;
    third->next = NULL;

    // Sambungkan simpul kedua ke simpul ketiga
    second->next = third;

    // Cetak isi setiap simpul pada linked list
    Node *node = head;
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}

// #include <iostream>

// using namespace std;

// struct dataktp
// {
//     char nama[50];
//     char alamat[50];
//     char golonganDarah[2];
//     dataktp *next, *prev;
// };

// dataktp *awal = NULL, *akhir = NULL, *bantu, *baru;

// void inputDatadepan()
// {
//     baru = new dataktp;
//     baru->next = NULL;
//     baru->prev = NULL;
//     cout << "Nama\t\t: ";
//     cin >> baru->nama;
//     cout << "Alamat\t\t: ";
//     cin >> baru->alamat;
//     cout << "Golongan darah";
//     cin >> baru->golonganDarah;

//     if (awal == NULL)
//     {
//         awal = akhir = baru;
//     }
//     else
//     {
//         baru->next = awal;
//         awal->prev = baru;
//         awal = baru;
//     }
//     system("cls");
// }

// void inputDatabelakang()
// {
//     baru = new dataktp;
//     baru->next = NULL;
//     baru->prev = NULL;
//     cout << "Nama\t\t: ";
//     cin >> baru->nama;
//     cout << "Alamat\t\t: ";
//     cin >> baru->alamat;
//     cout << "Golongan darah : ";
//     cin >> baru->golonganDarah;
//     if (awal == NULL)
//     {
//         awal = akhir = baru;
//     }
//     else
//     {
//         akhir->next = baru;
//         baru->prev = akhir;
//         akhir = baru;
//     }
//     system("cls");
// }

// void outputData()
// {
//     bantu = awal;
//     while (bantu != NULL)
//     {
//         cout << "Nama\t\t: " << bantu->nama << endl;
//         cout << "Alamat\t\t: " << bantu->alamat << endl;
//         cout << "Golongan darah\t\t: " << bantu->golonganDarah << endl;
//         bantu = bantu->next;
//     }
// }

// int main()
// {
//     int pilihan;
//     do
//     {
//         cout << "-----------------DOUBLE LINKED LIST-----------------\n";
//         cout << "Pilihan menu : \n";
//         cout << "1. Input data di depan\n";
//         cout << "2. Input data di belakang\n";
//         cout << "3. Output data\n";
//         cout << "4. EXIT\n";
//         cout << "Pilihan : ";
//         cin >> pilihan;
//         switch (pilihan)
//         {
//         case 1:
//             inputDatadepan();
//             break;
//         case 2:
//             inputDatabelakang();
//             break;
//         case 3:
//             if (baru == NULL)
//             {
//                 cout << "Data masih kosong! \n";
//             }
//             else
//             {
//                 outputData();
//             }
//             break;
//         default:
//             cout << "------------EXIT----------------";
//             break;
//         }

//     } while (pilihan <= 3);
//     getchar();
// }

// #include <iostream>
// using namespace std;

// struct node
// {
//     int number;
//     node *next, *prev;
// };

// node *awal, *akhir, *cur, *baru, *del, *skrg;

// void middle()
// {
//     baru = new node();
//     baru->number = 3;
//     baru->next = awal->next;
//     awal->next = baru;
//     if (baru->next != NULL)
//     {
//         baru->next->prev = baru;
//     }
// }

// void deleteFirst()
// {
//     del = awal;
//     awal = awal->next;
//     awal->prev = NULL;
//     delete del;
// }

// void deleteAkhir()
// {
//     del = akhir;
//     skrg = awal;
//     while (skrg->next != akhir)
//     {
//         skrg = skrg->next;
//     }
//     akhir = skrg;
//     akhir->next = NULL;
//     delete del;
// }

// void deleteTengah()
// {
//     del = baru;
//     skrg = awal;
//     while (skrg->next != baru)
//     {
//         skrg = skrg->next;
//     }
//     baru = skrg;
//     baru->next = akhir;
//     baru->prev = awal;
//     delete del;
// }

// void print()
// {
//     cur = awal;
//     while (cur != NULL)
//     {
//         cout << "Datanya adalah " << cur->number << endl;
//         cur = cur->next;
//     }
//     cout << endl;
// }

// int main()
// {
//     awal = new node();
//     akhir = new node();

//     awal->number = 1;
//     awal->next = akhir;
//     awal->prev = NULL;

//     akhir->number = 2;
//     akhir->next = NULL;
//     akhir->prev = awal;

//     print();

//     middle();
//     print();

//     deleteTengah();
//     print();

//     deleteFirst();
//     print();

//     deleteAkhir();
//     print();
// }