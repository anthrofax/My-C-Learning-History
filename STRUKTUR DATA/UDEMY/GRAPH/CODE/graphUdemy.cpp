#define Queue_h
#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"
#include <iostream>
#define maks 20

using namespace std;

struct Queue
{
    int rear, front, data[maks];
} verticesQueue;

int n;

bool isFull()
{
    return verticesQueue.rear == maks;
}

bool isEmpty()
{
    return verticesQueue.rear == 0;
}

void viewQueue()
{
    if (isEmpty())
    {
        cout << "Antrian Kosong" << endl;
    }
    else
    {
        cout << "Antrian : ";
        for (int i = verticesQueue.front; i < verticesQueue.rear; i++)
        {
            cout << verticesQueue.data[i] << ((i + 1 == verticesQueue.rear) ? "" : ", ");
        }
        cout << endl;
    }
}

void enqueue(int insertedVertice)
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

int dequeue()
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

void BFS(int G[][7], int startVertice, int amoutOfVertices)
{
    int i = startVertice, j;

    int visitedArray[7] = {0};

    cout << i << " ";
    visitedArray[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        for (j = 1; j < amoutOfVertices; j++)
        {
            if (G[i][j] == 1 && visitedArray[j] == 0)
            {
                cout << j << " ";
                visitedArray[j] = 1;
                enqueue(j);
            }
        }
    }
    cout << endl;
}

void DFS(int G[][7], int startVertice, int amountOfVertices)
{
    static int visitedVertice[7] = {0};
    int j;

    if (visitedVertice[startVertice] == 0)
    {
        cout << startVertice << " ";
        visitedVertice[startVertice] = 1;

        for (j = 1; j < amountOfVertices; j++)
        {
            if (G[startVertice][j] == 1 && visitedVertice[j] == 0)
            {
                DFS(G, j, amountOfVertices);
            }
        }
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    BFS(G, 5, 7);
    DFS(G, 4, 7);

    return 0;
}