// Nama : Afridho Ikhsan
// NPM : 2210631170002
// Kelas : 2A Informatika

#include <iostream>
using namespace std;
#define maks 20

struct node // Mendeklarasikan struct node untuk menampung data & pointer ke left child & right child dari masing-masing node pada tree
{
    int data;
    struct node *left;
    struct node *right;
};

struct Queue // Mendeklarasikan Queue yang nanti akan digunakan untuk membangun & penelusuran tree berdasarkan level
{
    int rear, front;
    struct node *alamatNode[maks];
} nodeQueue;

bool isFull(Queue *selectedQueue) // Untuk mengecek apakah Queue yang menampung alamat dari node tree sudah penuh
{
    return selectedQueue->rear == maks;
}

bool isEmpty(Queue *selectedQueue) // Untuk mengecek apakah Queue yang menampung alamat dari node tree masih kosong
{
    return selectedQueue->rear == 0;
}

void enqueue(Queue *selectedQueue, struct node *enqueuedPointer) // Untuk memasukkan alamat dari node tree ke dalam queue
{
    if (isFull(selectedQueue))
    {
        std::cout << "Antrian sudah penuh!" << endl;
    }
    else
    {
        selectedQueue->alamatNode[selectedQueue->rear] = enqueuedPointer;
        selectedQueue->rear++;
    }
}

struct node *dequeue(Queue *selectedQueue) // Untuk mengambil alamat dari node tree yang paling depan pada queue
{
    struct node *temp = selectedQueue->alamatNode[selectedQueue->front];
    for (int i = selectedQueue->front; i < selectedQueue->rear; i++)
    {
        selectedQueue->alamatNode[i] = selectedQueue->alamatNode[i + 1];
    }
    selectedQueue->rear--;
    return temp;
}

int cekBatasKedalaman(struct node **selectedTree) // Untuk melakukan penelusuran jalur yang paling pendek dari akar ke leaf, sehingga dapat diketahui batas dalamnya
{
    node *temp;

    enqueue(&nodeQueue, *selectedTree);
    int batasKedalaman = 1;
    while (!isEmpty(&nodeQueue))
    {
        temp = dequeue(&nodeQueue);
        if (temp->left == NULL || temp->right == NULL)
        {
            return batasKedalaman;
        }
        else
        {
            batasKedalaman++;
            if (temp->left != NULL)
            {
                enqueue(&nodeQueue, temp->left);
            }
            else if (temp->right != NULL)
            {
                enqueue(&nodeQueue, temp->right);
            }
        }
    }
    return batasKedalaman;
}

void membangunTree() // Untuk membangun tree berdasarkan konsep binary tree
{
    node *p, *t, *root;
    p = new node();
    root = new node();

    int x;
    cout << "Inputkan value untuk root : ";
    cin >> x;
    root->data = x;
    root->left = root->right = NULL;
    enqueue(&nodeQueue, root);

    while (!isEmpty(&nodeQueue))
    {
        int y, z;
        p = dequeue(&nodeQueue);
        cout << "Inputkan nilai dari left child dari " << p->data << " : ";
        cin >> y;
        if (y != -1)
        {
            t = new node();
            t->data = y;
            t->left = t->right = 0;
            p->left = t;
            enqueue(&nodeQueue, t);
        }

        cout << "Inputkan nilai dari right child dari " << p->data << " : ";
        cin >> z;
        if (z != -1)
        {
            t = new node();
            t->data = z;
            t->left = t->right = 0;
            p->right = t;
            enqueue(&nodeQueue, t);
        }
    }
    int testdata = cekBatasKedalaman(&root);
    cout << "Batas kedalaman : " << testdata << endl;
}

int main()
{
    membangunTree();
}