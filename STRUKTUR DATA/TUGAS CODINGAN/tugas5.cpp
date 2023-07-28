// Buatlah program pemecahan masalah Menara Hanoi yang memindahkan lempengan dari menara A ke menara C dengan perantara menara B dengan jumlah data 3 (10,20,30). Buat program tersebut dengan menerapkan konsep struktur data stack(boleh dengan stack array atau stack linked list), tapi tidak boleh menggunakan library stack.

// Contoh Output Program:
// 1. Pindahkan batu 10 dari A ke C
// 2. Pindahkan batu 20 dari A ke B
// 3. Pindahkan batu 10 dari C ke B
// 4. Pindahkan batu 30 dari A ke C
// 5. Pindahkan batu 10 dari B ke A
// 6. Pindahkan batu 20 dari B ke C
// 7. Pindahkan batu 10 dari A ke C

#include <iostream>
using namespace std;

// Struktur data stack
struct Stack
{
    int top;
    unsigned int capacity;
    int *array;
};

// Fungsi untuk membuat stack baru
struct Stack *createStack(unsigned int capacity)
{
    struct Stack *stack = new Stack;
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new int[capacity];
    return stack;
}

// Fungsi untuk memeriksa apakah stack kosong
bool isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

// Fungsi untuk memeriksa apakah stack penuh
bool isFull(struct Stack *stack)
{
    return (stack->top == stack->capacity - 1);
}

// Fungsi untuk menambahkan elemen ke stack
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Fungsi untuk menghapus elemen dari stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

// Fungsi untuk memindahkan lempengan dari menara awal ke menara tujuan
void moveDisk(char fromTower, char toTower, int disk)
{
    cout << "Pindahkan batu " << disk << " dari menara " << fromTower << " ke menara " << toTower << endl;
}

// Fungsi rekursif untuk pemindahan lempengan dari menara awal ke menara tujuan
void towerOfHanoi(int numDisks, struct Stack *source, struct Stack *destination, struct Stack *auxiliary)
{
    if (numDisks == 1)
    {
        int disk = pop(source);
        push(destination, disk);
        moveDisk('A', 'C', disk);
        return;
    }
    towerOfHanoi(numDisks - 1, source, auxiliary, destination);
    int disk = pop(source);
    push(destination, disk);
    moveDisk('A', 'C', disk);
    towerOfHanoi(numDisks - 1, auxiliary, destination, source);
}

int main()
{
    int numDisks = 3;
    struct Stack *source = createStack(numDisks);
    struct Stack *destination = createStack(numDisks);
    struct Stack *auxiliary = createStack(numDisks);
    push(source, 30);
    push(source, 20);
    push(source, 10);
    towerOfHanoi(numDisks, source, destination, auxiliary);
    return 0;
}
