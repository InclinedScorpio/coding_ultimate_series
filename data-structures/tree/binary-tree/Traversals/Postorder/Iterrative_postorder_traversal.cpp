//https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/
//PostOrder Traversal -> left-right-root
//Time Complexity- O(2N)
//Space Complexity - O(N)
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
vector<int> postorder(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
    Node *temp = NULL;
    vector<int> postOrder;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else
                curr = temp;
        }
    }
    return postOrder;
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
    v = postorder(root);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}