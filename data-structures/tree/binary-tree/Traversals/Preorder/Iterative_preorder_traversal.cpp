//https://www.techiedelight.com/preorder-tree-traversal-iterative-recursive/
//Preorder Traversal -> Root-left-right
//Time & Space Complexity - O(n)
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to print Nodes in a binary tree in Level order
vector<int> preorderTraversal(Node *root)
{
    stack<Node *> st;

    vector<int> preorder;
    if (root == NULL)
        return preorder;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if (root->right != NULL)
        {
            st.push(root->right);
        }
        if (root->left != NULL)
            st.push(root->left);
    }
    return preorder;
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
    v = preorderTraversal(root);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}