//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
//Vertical Order Traversal
// We cannot use recursive traversal for this problem.
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
vector<int> topView(Node *root)
{
    //Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mp;
    queue<pair<Node *, int> > q; //to store a pair of Node and the vertical line
    q.push({root, 0});           //push the first root and the first line
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first; //get the topmost node in the queue
        int line = it.second;  //get the line of that node
        if (mp.find(line) == mp.end())
            mp[line] = node->key; //check whether the line exists in the map

        if (node->left != NULL)
            q.push({node->left, line - 1}); //enter the node in the queue with line-1

        if (node->right != NULL)
            q.push({node->right, line + 1}); //enter the node in the queue with line+1
    }
    for (auto it : mp)
    {
        ans.push_back(it.second); //enter the nodes in the result vector
    }
    return ans;
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
    res = topView(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}