#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *front;
    Node *rear;
};

// Inisialisasi queue
void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

// Cek apakah queue kosong
bool isEmpty(Queue *q)
{
    return (q->front == NULL && q->rear == NULL);
}

// Enqueue data
void enqueue(Queue *q, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue data
void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue kosong" << endl;
    }
    else
    {
        Node *temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        cout << "Mengeluarkan data: " << temp->data << endl;
        delete (temp);
    }
}

// Tampilkan isi queue
void display(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue kosong" << endl;
    }
    else
    {
        Node *temp = q->front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    Queue q;
    initQueue(&q);

    // Menu
    int pilih, data;
    do
    {
        cout << "-------------------------" << endl;
        cout << " Menu Pilihan" << endl;
        cout << " [1] Enqueue" << endl;
        cout << " [2] Dequeue" << endl;
        cout << " [3] Tampilkan" << endl;
        cout << " [4] Keluar" << endl;
        cout << "-------------------------" << endl;
        cout << " Masukkan pilihan : " << endl;
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            enqueue(&q, data);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            cout << "Keluar" << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
        }

    } while (pilih != 4);
    return 0;
}