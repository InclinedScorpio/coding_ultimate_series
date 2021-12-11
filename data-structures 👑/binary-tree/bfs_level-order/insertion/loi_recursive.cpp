#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
        Node* left;
        Node* right;
        int data;

        Node(int data, Node* left, Node* right) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

/**
 * LOGIC: 2i+1, 2i+2 are the left and right child 
 * 
 */
int globalIndex=0;
Node* createTree(int arr[], int index, int arrSize) {
    if(index>=arrSize || arr[index]==-1){ 
        return NULL;
    }
    Node* node = new Node(arr[index], NULL, NULL);
    node->left = createTree(arr, 2*index+1, arrSize);
    node->right = createTree(arr, 2*index+2, arrSize);
    return node;
}

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
    int levelOrder[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1};
    int sizeOfArr = sizeof(levelOrder)/sizeof(levelOrder[0]);
    Node* root = createTree(levelOrder, 0, sizeOfArr);
    bfsTraversalWithNIter(root);
}