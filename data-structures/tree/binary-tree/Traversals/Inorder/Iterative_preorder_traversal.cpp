//https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
//Inorder TRaversal -> Left-Root-Right
//For iterative implementation we need an explicit stack.
//This program has O(N) complexity as the 'N' is the total no. of nodes in Tree
//The space complexity is O(N) as the space required is proportional to the height of tree
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to print Nodes in a binary tree in Level order
vector<int> inorderTraversal(Node *root)
{
    stack<Node *> st;
    Node *node = root;
    vector<int> inorder;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
                break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
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

    vector<int> v;
    v = inorderTraversal(root);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}