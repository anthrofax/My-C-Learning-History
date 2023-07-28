#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

Node *awal, *akhir, *bantu;

void pushMid(Node *leftNode, Node *rightNode, string value)
{
    Node *newNode = new Node();
    newNode->data = value;
    leftNode->next = newNode;
    newNode->next = rightNode;
};

void tampilNode()
{
    bantu = awal;
    while (bantu != NULL)
    {
        if (bantu->next == NULL)
            cout << bantu->data << "->NULL";
        else
            cout << bantu->data << "->";
        bantu = bantu->next;
    }
    cout << endl;
}

int main()
{
    Node *afridho = new Node();
    Node *ikhsan = new Node();
    Node *masputra = new Node();
    awal = afridho;
    akhir = masputra;

    afridho->data = "nama depan";
    ikhsan->data = "nama tengah";
    masputra->data = "nama belakang";

    afridho->next = ikhsan;
    ikhsan->next = masputra;
    masputra->next = NULL;

    pushMid(afridho, afridho->next, "nama baru");
    tampilNode();
    pushMid(masputra, NULL, "new name");
    tampilNode();
}