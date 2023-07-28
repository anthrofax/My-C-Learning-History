#include <iostream>

using namespace std;

int main()
{
    // 1.
    // int x = 9;
    // int *y;
    // y = &x;

    // cout << "Nilai Variable X : " << x << endl;
    // cout << "Alamat Variable X : " << &x << endl;
    // cout << "Isi dari Variable Y : " << y << endl;
    // cout << "Nilai yang tersimpan di dalam Variable Y : " << *y << endl;

    // 2.
    // int x, y;
    // int *px;

    // x = 77;
    // y = x;
    // px = &x;

    // cout << "Nilai x : " << x << endl;
    // cout << "Nilai y : " << y << endl;
    // cout << "Alamat x : " << &x << endl;
    // cout << "Alamat y : " << &y << endl;
    // cout << "Alamat x yang disimpan pada px : " << px << endl;
    // cout << "Nilai px : " << *px << endl;

    // 3.
    // int x;
    // int *px;
    // int **ppx;

    // x = 170;
    // px = &x;
    // ppx = &px;

    // cout << "Nilai x : " << x << endl;
    // cout << "Nilai px : " << px << endl;
    // cout << "Nilai ppx : " << ppx << endl;

    // 4.
    // int x[5];
    // int *px;
    // px = x; // px = &x[0]

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "Masukkan Nilai " << i + 1 << " : ";
    //     cin >> x[i];
    // }
    // cout << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "Nilai x[" << i << "] : " << *px << endl;
    //     cout << "Alamat x[" << i << "] : " << px << endl;
    //     px++;
    // }

    // 5.
    // int x[10] = {12, 35, 20, 23, 54, 49, 81, 92, 119, 29};
    // int i;
    // int min = 1000;   // asumsi paling minimum
    // int maks = -1000; // asumsi paling maksimum

    // for (i = 0; i < 10; i++)
    // {
    //     if (x[i] > maks)
    //     {
    //         maks = x[i];
    //     }
    //     if (x[i] < min)
    //     {
    //         min = x[i];
    //     }
    // }

    // cout << "Nilai maksimum : " << maks << endl;
    // cout << "Nilai minimum : " << min << endl;

    // 6.
    int x[10] = {12, 35, 20, 23, 54, 49, 81, 92, 119, 29};
    int i, dicari;
    bool ketemu = false;

    cout << "Bilangan yang ingin dicari : ";
    cin >> dicari;

    for (i = 0; i < 10; i++)
    {
        if (x[i] == dicari)
        {
            ketemu = true;
            cout << "Bilangan ditemukan di elemen : " << i << endl;
        }
    }

    if (ketemu)
    {
        cout << "Bilangan ditemukan!" << endl;
    }
    else
    {
        cout << "Bilangan tersebut tidak ditemukan!" << endl;
    }
    return 0;
}