#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data) {
        this->data = data;
    }
};

int globalIndex=-1;

Node* createTree(int *arr) {
    globalIndex++;
    if(arr[globalIndex]<0) {
        return NULL;
    }
    Node* node = new Node(arr[globalIndex]);
    node->left = createTree(arr);
    node->right = createTree(arr);
    return node;
}

void preOrderTraversal(Node* node) {
    if(!node) {
        return;
    }
    cout<<node->data<<" ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

/**
 * 
 * Can be done using recursion as well but iteration is simpler
 *              1
 *          2      3 NULL
 *       4    5  -    6 NULL
 *     -   -7   -    -   -
 * 
 * Logic: After 1 keep null, now whenever you get Null, push Null
 */
void bfsTraversalWithNIter(Node* root) {
    queue<Node*> queueIter;
    queueIter.push(root);
    queueIter.push(NULL);

    while(!queueIter.empty()) {
        Node* temp = queueIter.front();
        if(temp && temp->left) {
            queueIter.push(temp->left);
        }
        if(temp && temp->right) {
            queueIter.push(temp->right);
        }

        if(temp==NULL) {
            cout<<endl;
            if(queueIter.size()==1){
                break;
            }
            queueIter.push(NULL);
        }else {
            cout<<temp->data<<" ";
        }
            queueIter.pop();
    }
}

int main() {
    int treeData[] = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    Node* root = createTree(treeData);
    bfsTraversalWithNIter(root);
}