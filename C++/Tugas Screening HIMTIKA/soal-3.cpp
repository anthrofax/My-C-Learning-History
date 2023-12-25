#include <iostream>
using namespace std;

bool apakahBilanganPrima(int bil)
{

    if (bil == 1)
        return false;

    for (int i = 1; i <= bil; i++)
    {
        if (i != 1 && i != bil)
        {
            if (bil % i == 0)
                return false;
        }
    }

    return true;
}

int main()
{
    int bil;

    cout << "Masukkan sebuah bilangan: ";
    cin >> bil;

    cout << "Bilangan yang anda masukkan " << ((apakahBilanganPrima(bil)) ? "adalah prima" : "bukan bilangan prima") << endl;
}