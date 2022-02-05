//https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/
#include <iostream>
using namespace std;

// A binary tree node has data, pointer to
// left child and a pointer to right child
typedef struct treenode
{
    int val;
    struct treenode *left;
    struct treenode *right;
} node;

// Helper function to print Inorder traversal
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << " " << root->val;
    inorder(root->right);
}

//InvertTree traverses recusrsively through all the nodes and swaps the left and right node links of the parent node
//Since each node is visited only once, So time complexity is O(n) and
//space complexity will be O(h) here 'h' is the height of tree
void swap(node *curr)
{
    if (!curr)
        return;
    swap(curr->left);
    swap(curr->right);
    node *temp;
    temp = curr->left;
    curr->left = curr->right;
    curr->right = temp;
}

node *invertTree(node *root)
{
    swap(root);
    return root;
}
node *Insert(node *root, int data)
{
    if (root == NULL)
    {
        root = new node();
        root->val = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->val)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}
// Driver code
int main()
{

    int n;
    cin >> n;
    int k;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        root = Insert(root, k);
    }

    // Print inorder traversal of the input tree
    cout << "Inorder of original tree: ";
    inorder(root);
    node *mirror = NULL;
    mirror = invertTree(root);

    // Print inorder traversal of the mirror tree
    cout << "\nInorder of mirror tree: ";
    inorder(mirror);

    return 0;
}
