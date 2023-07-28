// Nama : Afridho Ikhsan
// Kelas : 2A Informatika
// NPM : 2210631170002

#include <iostream>  //Untuk mengikutsertakan library iostream, agar nantinya dapat mengakses input/output (I/O) standar dari sistem operasi. seperti untuk membaca input dari user dan menampilkan output ke layar atau perangkat lainnya, seperti file atau jaringan.
using namespace std; // Untuk memberitahu compiler bahwa kode yang ditulis bersumber dari namespace standar C++
#define maks 20      // Untuk menentukan nilai maksimum karakter pada Queue

struct Queue // Mendeklarasikan struct Queue
{
    int rear, front;
    char karakter[maks];
} reversedQueue;

bool isFull(Queue *selectedQueue) // Untuk mengecek suatu queue sudah penuh atau belum
{
    return selectedQueue->rear == maks;
}

bool isEmpty(Queue *selectedQueue)
{
    return selectedQueue->rear == 0;
}

void enqueue(Queue *selectedQueue, char inputChar) // Untuk memasukkan suatu char pada Queue (Sesuai dengan konsep queue/antrian)
{
    if (isFull(selectedQueue))
    {
        cout << "Antrian sudah penuh!" << endl;
    }
    else
    {
        selectedQueue->karakter[selectedQueue->rear] = inputChar;
        selectedQueue->rear++;
    }
}

void dequeue(Queue *selectedQueue) // Untuk menghapus char pada Queue (Sesuai dengan konsep queue/antrian)
{
    for (int i = selectedQueue->front; i < selectedQueue->rear; i++)
    {
        selectedQueue->karakter[i] = selectedQueue->karakter[i + 1];
    }
    selectedQueue->rear--;
}

bool cekPalindrome(string checkedText) // Untuk mengecek suatu text yang user inputkan bersifat palindrome atau tidak
{
    string reversedString = "";

    for (int i = checkedText.length() - 1; i >= 0; i--)
    {
        enqueue(&reversedQueue, checkedText[i]);
    }

    for (int y = reversedQueue.front; y < reversedQueue.rear; y++)
    {
        reversedString += reversedQueue.karakter[y];
    }

    return reversedString == checkedText;
}

int main()
{
    int pil;
    string inputText;
    cout << "Inputkan string yang ingin dicek sifat palindromenya : ";
    getline(cin, inputText);

    if (cekPalindrome(inputText))
        cout << "Queue adalah palindrome" << endl;
    else
        cout << "Queue tidak bersifat palindrome" << endl;

    while (!isEmpty(&reversedQueue))
    {
        dequeue(&reversedQueue);
    }

    do
    {

        cout << "Masih ada string yang ingin dicek sifat palindrome nya? \n"
             << "1. Ya\n"
             << "2. Tidak" << endl;
        cin >> pil;

        switch (pil)
        {
        case 1:
            cout << "Inputkan string yang ingin dicek sifat palindromenya : ";
            cin.ignore();
            getline(cin, inputText);
            if (cekPalindrome(inputText))
                cout << "Queue adalah palindrome" << endl;
            else
                cout << "Queue tidak bersifat palindrome" << endl;

            while (!isEmpty(&reversedQueue))
            {
                dequeue(&reversedQueue);
            }
            break;
        case 2:
            cout << "Terimakasih :)" << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia!" << endl;
            break;
        }
    } while (pil != 2);
}