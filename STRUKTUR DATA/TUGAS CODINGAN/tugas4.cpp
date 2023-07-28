#include <iostream>
using namespace std;

// Nama : Afridho Ikhsan
// Kelas : 2A - Informatika
// NPM : 2210631170002

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void inputData(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    Node *node = head;
    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = new_node;
}

void reverseList()
{
    Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void outputLinkedList()
{
    Node *node = head;
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    int n, data;
    Node *head = NULL;

    cout << "Masukkan 5 angka: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> data;
        inputData(data);
    }

    cout << "\nLinked List Asli: ";
    outputLinkedList();

    reverseList();

    cout << "Link List Setelah Direverse: ";
    outputLinkedList();

    return 0;
}