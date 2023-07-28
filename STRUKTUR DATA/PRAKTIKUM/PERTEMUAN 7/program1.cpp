#include <iostream>
using namespace std;

struct edoNode
{
    int data;
    struct edoNode *left;
    struct edoNode *right;
};

struct edoNode *newNode(int data)
{
    struct edoNode *lol = new struct edoNode;
    lol->data = data;
    lol->left = NULL;
    lol->right = NULL;
    return (lol);
}

void printPostorder(struct edoNode *node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void printInorder(struct edoNode *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(struct edoNode *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main()
{
    struct edoNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "\nPreorder traversal of binarty tree is: \n";
    printPreorder(root);
    cout << "\nInorder traversal of binary tree is: \n";
    printInorder(root);
    cout << "\nPostorder traversal of binary tree is: \n";
    printPostorder(root);

    getchar();
    return 0;
}