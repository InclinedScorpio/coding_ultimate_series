//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
int height(Node *root, int &diameter)
{
    if (root == NULL)
        return 0;
    int l = height(root->left, diameter);
    int r = height(root->right, diameter);
    diameter = max(diameter, 1 + l + r);

    return 1 + max(l, r);
}
int diameter(Node *root)
{
    // Your code here
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

// Function to Insert Node in a Binary Search Tree
Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

// Wrapper over print2DUtil()

int main()
{
    int n;
    cin >> n;
    int k;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        root = Insert(root, k);
    }
    // Print Nodes in Level Order.

    int Dia = diameter(root);
    cout << Dia;

    return 0;
}