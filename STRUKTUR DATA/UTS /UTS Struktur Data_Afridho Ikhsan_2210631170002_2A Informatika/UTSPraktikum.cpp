#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
};

Node *head, *last, *bantu;
int BitDigit = 0;

void push()
{
    int value;
    Node *NewNode = new Node();
    cout << "Inputkan nilai bit ke-" << BitDigit + 1 << " ";
    cin >> value;
    NewNode->data = value;

    if (head == NULL || last == NULL)
    {
        if (head == NULL && last == NULL)
        {
            head = NewNode;
            head->next = last;
            head->prev = NULL;
        }
        else if (last == NULL)
        {
            last = NewNode;
            head->next = last;
            last->next = NULL;
            last->prev = head;
        }
    }
    else
    {
        last->next = NewNode;
        NewNode->next = NULL;
        NewNode->prev = last;
        last = NewNode;
    }

    BitDigit++;
}

int KonversiBinerKeDesimal()
{
    int NilaiDesimal = 0, i = 0;

    if (last == NULL)

        NilaiDesimal += head->data * (pow(2, i++));

    bantu = last;
    while (bantu != NULL)
    {
        NilaiDesimal += bantu->data * (pow(2, i++));
        bantu = bantu->prev;
    }

    return NilaiDesimal;
}

void tampilNode()
{
    bantu = head;
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
    int jumlahDigitBit;

    cout << "Berapa digit yang ingin anda inputkan ";
    cin >> jumlahDigitBit;

    while (jumlahDigitBit > 0)
    {
        push();
        jumlahDigitBit--;
    };

    tampilNode();
    cout << "Nilai Desimal : " << KonversiBinerKeDesimal() << endl;
}
