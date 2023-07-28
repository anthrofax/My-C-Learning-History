// #include <iostream>
// using namespace std;

// int maks = 5, top = 0;
// string buku[5];

// void PushBuku(string data)
// {
//     if (top >= maks)
//     {
//         cout << "Data Full" << endl;
//     }
//     else
//     {
//         buku[top] = data;
//         top++;
//     }
// }

// void DisplayBuku()
// {
//     cout << "Data Stack Buku " << endl;
//     cout << "=================" << endl;
//     for (int i = maks - 1; i >= 0; i--)
//     {
//         if (buku[i] != "")
//         {
//             cout << "Stack ke -" << i << " = " << buku[i] << endl;
//         }
//     }
// }

// bool isFull()
// {
//     if (top == maks)
//     {
//         cout << "Stack sudah penuh" << endl;
//         return true;
//     }
//     else
//         cout << "stack masih kosong" << (maks - top) << " Data";
//     return false;
// }

// bool isEmpty()
// {
//     if (top == 0)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void PopBuku()
// {
//     if (isEmpty())
//     {
//         cout << "Data Kosong" << endl;
//     }
//     else
//     {
//         buku[top - 1] = "";
//         top--;
//     }
// }

// void PeekBuku(int posisi)
// {
//     if (isEmpty())
//     {
//         cout << "Data kosong" << endl;
//     }
//     else
//     {
//         int index = top - 1;
//         for (int i = 0; i < posisi; i++)
//         {
//             index--;
//         }
//         cout << index << endl;
//     }
// }

// int main()
// {
//     PushBuku("Sherlock");
//     PushBuku("Hujan");
//     DisplayBuku();
//     cout << endl;

//     PushBuku("Negeri 5 Menara");
//     PushBuku("Senja");
//     PushBuku("Sejarah Dunia");
//     DisplayBuku();
//     cout << endl;

//     PushBuku("Kata");
//     DisplayBuku();

//     isFull();
//     PopBuku();
//     DisplayBuku();
//     PeekBuku(2);

//     return 0;
// }

// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *next;
// };

// struct Stack
// {
//     Node *top;
//     Stack()
//     {
//         top = NULL;
//     }

//     void push(int value)
//     {
//         Node *newNode = new Node;
//         newNode->data = value;
//         newNode->next = top;
//         top = newNode;
//         cout << "Nilai " << value << " sudah diinput ke dalam stack. \n";
//         system("cls");
//     }

//     void pop()
//     {
//         if (top == NULL)
//         {
//             cout << "Stack kosong. \n";
//             return;
//         }
//         Node *temp = top;
//         int poppedValue = temp->data;
//         top = top->next;
//         delete temp;
//         cout << "Nilai " << poppedValue << " sudah dihapus dari stack/ \n";
//         system("cls");
//     }

//     void display()
//     {
//         if (top == NULL)
//         {
//             cout << "Stack kosong. \n";
//             return;
//         }
//         Node *currentNode = top;
//         cout << "Stack: ";
//         while (currentNode != NULL)
//         {
//             cout << currentNode->data << "->";
//             currentNode = currentNode->next;
//         }
//         cout << "NULL" << endl;
//     }
// };

// int main()
// {
//     Stack s;
//     int pilih, nilai;
//     while (true)
//     {
//         cout << "Menu:\n";
//         cout << "1. Push\n";
//         cout << "2. Pop\n";
//         cout << "3. Tampilkan stack\n";
//         cout << "4. Keluar\n";
//         cout << "Pilihan: ";
//         cin >> pilih;
//         switch (pilih)
//         {
//         case 1:
//             cout << "Masukkan nilai yang ingin di-push ";
//             cin >> nilai;
//             s.push(nilai);
//             break;
//         case 2:
//             s.pop();
//             break;
//         case 3:
//             s.display();
//             break;
//         case 4:
//             return 0;
//         default:
//             cout << "Pilihan tidak valid.\n";
//             break;
//         }
//     }
// }
