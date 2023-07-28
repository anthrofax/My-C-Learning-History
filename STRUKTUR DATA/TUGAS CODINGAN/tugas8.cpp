#include <iostream>
#define maks 4 // Menentukan maksimum muatan queue

using namespace std;

struct Queue // Deklarasi Queue untuk menampung simpul pada graph agar nantinya bisa ditelusuri sesuai dengan yang diinginkan
{
    int rear, front, data[maks];
} verticesQueue;

int n;

bool isFull() // Untuk mengecek apakah Queue yang menampung representasi simpul pada graph sudah penuh atau belum
{
    return verticesQueue.rear == maks;
}

bool isEmpty() // Untuk mengecek apakah Queue yang menampung representasi simpul pada graph masih kosong
{
    return verticesQueue.rear == 0;
}

void enqueue(int insertedVertice) // Untuk menambah elemen baru ke Queue yang menampung representasi simpul pada graph
{
    if (isFull())
    {
        cout << "Antrian Penuh!";
    }
    else
    {
        verticesQueue.data[verticesQueue.rear] = insertedVertice;
        verticesQueue.rear++;
    }
}

int dequeue() // Untuk mengambil sekaligus menghapus simpul pada graph di Queue
{
    int temporaryStored;

    if (isEmpty())
    {
        cout << "Antrian masih kosong!";
    }
    else
    {
        temporaryStored = verticesQueue.data[verticesQueue.front];
        for (int i = verticesQueue.front; i < verticesQueue.rear; i++)
        {
            verticesQueue.data[i] = verticesQueue.data[i + 1];
        }
        verticesQueue.rear--;
    }
    return temporaryStored;
}

void cetakgraph(int G[][5], int n) // Untuk mencetak graph (array 2 dimensi) yang dimasukkan sebagai parameter ke function cetakGraph tersebut
{
    cout << "Cost List : " << endl;
    int i, j;
    int simpul1 = 1, simpul2 = 1;

    cout << endl;
    for (i = 0; i < n; i++)
    {
        cout << "\t";
        for (j = 0; j < n; j++)
        {
            cout << G[i + 1][j + 1] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void BFS(int G[][5], int startVertice, int amoutOfVertices) // Untuk melakukan penelusuran graph berdasarkan aturan Breadth First Search
{
    int i = startVertice, j = 1;
    int temp, tempdata, finalTempData = 0;
    bool cekSelesai;
    int visitedArray[5] = {0};

    cout << i << "--->";
    visitedArray[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        tempdata = 999;
        for (j = 1; j <= amoutOfVertices; j++)
        {
            if (G[i][j] != 0 && visitedArray[j] == 0)
            {
                if (G[i][j] < tempdata)
                {
                    tempdata = G[i][j];
                    temp = j;
                }
            }
        }

        for (int k = 1; k <= amoutOfVertices; k++)
        {
            if (visitedArray[k] == 1)
            {
                cekSelesai = true;
            }
            else
            {
                cekSelesai = false;
                break;
            }
        }

        if (!cekSelesai)
        {
            finalTempData += tempdata;
            visitedArray[temp] = 1;
            cout << temp << "--->";
            enqueue(temp);
        }
    }
    cout << startVertice << endl;
    cout << "Minimum Cost : " << finalTempData + G[temp][startVertice] << endl;
}

int main()
{
    int G[5][5] = {{0, 0, 0, 0, 0},
                   {0, 0, 4, 1, 3},
                   {0, 4, 0, 2, 1},
                   {0, 1, 2, 0, 5},
                   {0, 3, 1, 5, 0}};
    cetakgraph(G, 4);
    cout << "Jalur Terpendek : " << endl;
    BFS(G, 4, 4);

    return 0;
}