#include <iostream>

using namespace std;
#define MAX 999

int graph[MAX][MAX];
int n;
char simpul1 = 'A';
char simpul2 = 'A';

void addedge(int n)
{
    int i, j;
    cout << "Beri Nilai 1 jika edge di kedua simpul yang terhubung dan 0 untuk tidak" << endl
         << endl;

    for (i = 0; i < n; i++)
    {
        cout << "Simpul " << simpul1++ << " Terhubung dengan" << endl;
        for (j = 0; j < n; j++)
        {
            cout << "Simpul " << simpul2++ << " = ";
            cin >> graph[i][j];
        }
        simpul2 = 'A';
        cout << endl;
    }
}

void cetakgraph(int n)
{
    cout << "Cetak Adjacentcy Matriks" << endl;
    int i, j;
    cout << " ";
    simpul1 = 'A';
    simpul2 = 'A';

    for (i = 0; i < n; i++)
    {
        cout << simpul1++ << " ";
    }

    cout << endl;
    for (i = 0; i < n; i++)
    {
        cout << simpul2++ << " ";
        for (j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void searchPath(char x, char y)
{
    char source = x - 65;
    char destination = y - 65;
    int visited[MAX] = {0};
    int dist[MAX];
    int parent[MAX];
    for (int i = 0; i < n; i++)
    {
        dist[i] = MAX;
        parent[i] = -1;
    }

    dist[source] = 0;
    visited[source] = 1;
    parent[source] = -1;

    int queue[MAX];
    int front = 0;
    int rear = 0;
    int z = 0;
    queue[rear++] = source;
    while (front != rear)
    {
        int u = queue[front++];
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && !visited[v])
            {
                visited[v] = 1;

                dist[v] = dist[u] + 1;
                parent[v] = u;
                queue[rear++] = v;
            }
        }
    }

    if (!visited[destination])
    {
        cout << "Tidak ada jalur dari " << x << " ke " << y << endl;
    }
    else
    {
        cout << "Jarak terpendek dari " << x << " ke " << y << " adalah " << dist[destination] << endl;

        cout << "Jalur terpendek adalah: ";
        int u = destination;
        while (u != -1)
        {
            simpul1 = 'A';
            simpul1 += u;
            cout << simpul1 << " ";
            u = parent[u];
        }
        cout << endl;
    }
}

void deleteEdge(char x, char y)
{
    int i = x - 65;
    int j = y - 65;
    graph[i][j] = 0;
    graph[j][i] = 0;
    cout << "Garis antara Simpul " << x << " dan " << y << " Berhasil terhapus!\n";
}

void deleteVertex(char z)
{
    int v = z - 65;

    if (v > n)
    {
        cout << "Simpul tidak ada." << endl;
        return;
    }

    for (int i = v; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[j][i] = graph[j][i + 1];
        }
    }

    for (int i = v; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = graph[i + 1][j];
        }
    }

    n--;
    cout << "Simpul " << z << " Berhasil terhapus." << endl;
}

int main()
{
first:
    system("clear");
    char name = 'A', x, y;
    int source, destination, j, i;
    int pil;

    cout << "=================================" << endl;
    cout << "=========-Adjency Matiks-=========" << endl;
    cout << "=================================" << endl;
    cout << "1. Tambah simpul dan sisi" << endl;
    cout << "2. Cetak Graph" << endl;
    cout << "3. Cari Jalur" << endl;
    cout << "4. Hapus Simpul" << endl;
    cout << "5. Hapus Sisi" << endl;
    cout << "\nMasukkan Pilihan : ";
    cin >> pil;

    if (pil == 1)
    {
        system("clear");
        cout << "Masukkan jumlah n : ";
        cin >> n;
        addedge(n);
        cout << "\nsimpul berhasil dibuat, tekan apa saja untuk lanjut";
        cin.ignore(); // tambahkan cin.ignore() untuk membersihkan newline dari input
        cin.get();    // tambahkan cin.get() untuk menunggu pengguna menekan tombol sebelum melanjutkan
        goto first;
    }
    else if (pil == 2)
    {
        system("clear");
        cetakgraph(n);
        cin.ignore(); // tambahkan cin.ignore() untuk membersihkan newline dari input
        cin.get();    // tambahkan cin.get() untuk menunggu pengguna menekan tombol sebelum melanjutkan
        goto first;
    }
    else if (pil == 3)
    {
        system("clear");
        cout << "Mencari Jalur Terpendek \n";
        cout << "Masukkan node asal = ";
        cin >> x;
        cout << "Masukkan node tujuan = ";
        cin >> y;
        searchPath(x, y);
        cin.ignore(); // tambahkan cin.ignore() untuk membersihkan newline dari input
        cin.get();    // tambahkan cin.get() untuk menunggu pengguna menekan tombol sebelum melanjutkan
        goto first;
    }
    else if (pil == 4)
    {
        system("clear");
        cetakgraph(n);
        cout << "\nMenghapus Simpul = ";
        cin >> x;
        deleteVertex(x);
        cin.ignore(); // tambahkan cin.ignore() untuk membersihkan newline dari input
        cin.get();    // tambahkan cin.get() untuk menunggu pengguna menekan tombol sebelum melanjutkan
        goto first;
    }
    else if (pil == 5)
    {
        system("clear");
        cetakgraph(n);
        cout << "\nMenghapus garis antara simpul ";
        cin >> x;
        cout << "Dengan simpul ";
        cin >> y;
        deleteEdge(x, y);
        cin.ignore(); // tambahkan cin.ignore() untuk membersihkan newline dari input
        cin.get();    // tambahkan cin.get() untuk menunggu pengguna menekan tombol sebelum melanjutkan
        goto first;
    }
    else
        cout << "input yang anda masukkan salah";
    return 0;
}