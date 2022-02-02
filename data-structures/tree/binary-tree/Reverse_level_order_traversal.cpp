//https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node *> Q;
    Q.push(root);
    vector<int> v;
    while (!Q.empty())
    {
        Node *current = Q.front();
        Q.pop();
        v.push_back(current->data);
        if (current->right != NULL)
            Q.push(current->right);
        if (current->left != NULL)
            Q.push(current->left);
    }
    reverse(v.begin(), v.end());
    return v;
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
    vector<int> v;
    v = reverseLevelOrder(root);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}