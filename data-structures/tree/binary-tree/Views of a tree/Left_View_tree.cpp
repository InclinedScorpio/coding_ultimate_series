//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
void findLeftView(Node *root, int level, vector<int> &result)
{
    if (root == NULL)
        return;

    if (level == result.size())
    {
        result.push_back(root->key);
    }
    findLeftView(root->left, level + 1, result);
    findLeftView(root->right, level + 1, result);
}

vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> result;
    int level = 0;
    findLeftView(root, 0, result);
    return result;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    vector<int> res;
    res = leftView(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}