#include <iostream>
using namespace std;

struct Stack
{
    unsigned capacity;
    int top;
    int *array;
};

Stack *createStack(unsigned capacity)
{
    Stack *stack = new Stack;
    stack->capacity = capacity;
    stack->top = 0; // nilai awal top adalah 0
    stack->array = new int[capacity];
    return stack;
}

int isFull(Stack *stack)
{
    return stack->top == stack->capacity;
}

int isEmpty(Stack *stack)
{
    return stack->top == 0;
}

void push(Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[stack->top] = item;
    stack->top++;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    stack->top--;
    return stack->array[stack->top];
}

int main()
{
    Stack *stack = createStack(10);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    cout << pop(stack) << endl;
    cout << pop(stack) << endl;
    cout << pop(stack) << endl;
    return 0;
}
