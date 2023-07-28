#include <iostream>
#define maks 20
using namespace std;

struct Queue
{
    int rear, front, data[maks];
} QueueTest;

bool isFull()
{
    return QueueTest.rear == maks;
}

bool isEmpty()
{
    return QueueTest.rear == 0;
}

void viewQueue()
{
    if (isEmpty())
    {
        cout << "Antrian Kosong" << endl;
    }
    else
    {
        cout << "Antrian : ";
        for (int i = QueueTest.front; i < QueueTest.rear; i++)
        {
            cout << QueueTest.data[i] << ((i + 1 == QueueTest.rear) ? "" : ", ");
        }
        cout << endl;
    }
}

void enqueue()
{
    if (isFull())
    {
        cout << "Antrian Penuh!";
    }
    else
    {
        cout << "Inputkan data queue : ";
        cin >> QueueTest.data[QueueTest.rear];
        QueueTest.rear++;
        cout << "Data ditambahkan\n";
        viewQueue();
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Antrian masih kosong!";
    }
    else
    {
        cout << "Data yang dikeluarkan : | " << QueueTest.data[QueueTest.front] << " |" << endl;
        for (int i = QueueTest.front; i < QueueTest.rear; i++)
        {
            QueueTest.data[i] = QueueTest.data[i + 1];
        }
        QueueTest.rear--;
        viewQueue();
    }
}

int main()
{
    int pil;

    do
    {

        cout
            << "Menu Utama\n1. Enqueue\n2. Dequeue\n3. Keluar" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            cout << "Enqueue" << endl;
            enqueue();
            break;
        case 2:
            cout << "Dequeue" << endl;
            dequeue();
            break;
        case 3:
            cout << "Terima Kasih" << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia!" << endl;
            break;
        }

    } while (pil != 3);
}
