#include <iostream>
using namespace std;

int stack[100], top = 0;

void push(int sisaBagi)
{
    stack[top] = sisaBagi;
    top++;
}

int pop()
{
    top--;
    return stack[top];
}

void prosesDesimalKeHeksa(int desimal)
{
    if (desimal == 0)
    {
        push(desimal);
        return;
    }
    else if (desimal < 0)
    {
        desimal *= -1;
    }

    while (desimal > 0)
    {
        int sisaBagi = desimal % 16;
        push(sisaBagi);
        cout << "\n\t" << desimal << "\t / 16 = ";
        desimal /= 16;
        cout << desimal << " sisa " << sisaBagi << endl;
    }
    cout << "\n\t---------------------------" << endl
         << endl;
}

void hasilDesimalKeHeksa(int desimal)
{
    char hurufHeksa;

    if (desimal < 0)
    {
        cout << "-";
    }

    while (top != 0)
    {
        int sisaBagi = pop();

        if (sisaBagi >= 0 && sisaBagi <= 9)
        {
            cout << sisaBagi;
        }
        else
        {
            hurufHeksa = 'A' + (sisaBagi - 10);
            cout << hurufHeksa;
        }
    }
    cout << endl;
}

int main()
{
    int desimal;

    cout << "Masukkan bilangan desimal: ";
    cin >> desimal;

    cout << "\n\t===========================" << endl;
    prosesDesimalKeHeksa(desimal);
    cout << "\tBilangan Desimal      : " << desimal << endl
         << "\tBilangan Heksadesimal : ";
    hasilDesimalKeHeksa(desimal);
    cout << "\n\t===========================" << endl;

    return 0;
}