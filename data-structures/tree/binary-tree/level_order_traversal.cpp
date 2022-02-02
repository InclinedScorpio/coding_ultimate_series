//https://practice.geeksforgeeks.org/problems/level-order-traversal/1
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to print Nodes in a binary tree in Level order
void LevelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);
    //while there is at least one discovered node
    while (!Q.empty())
    {
        Node *current = Q.front();
        Q.pop(); // removing the element at front
        cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
    }
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
void print2DUtil(Node *root)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels

    // Process right child first
    print2DUtil(root->right);

    // Print current node after space
    // count
    cout << endl;

    cout << root->data << "\n";

    // Process left child
    print2DUtil(root->left);
}

// Wrapper over print2DUtil()
void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root);
}
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
    print2D(root);
    LevelOrder(root);
    return 0;
}