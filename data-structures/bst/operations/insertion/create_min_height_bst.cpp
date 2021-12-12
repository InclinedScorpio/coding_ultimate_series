#include <iostream>
#include <map>
#include <queue>

using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data, Node* left=NULL, Node* right=NULL) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

/**
 * COMPLEXITY: O(N) - we are traversing the sorted array
 * QUESTION: Create a minimum height BST from a 'sorted array'
 * LOGIC: As we need minimum, we need to always pick the middle index
 * > because that's how index will be equally divided among left, right
 * > and height will be minimum
 * 
 * 1. On each call, create node...
 * 2. left must point to left remaining side middle element
 * 3. right must point to right remaining side middle element
 * 
 * INPUT: [1, 2, 3, 4, 5, 6, 7]
 * OUTPUT:
 *                             4
 *                        2         6
 *                     1     3    5    7
 */ 
Node* createMinHeightBST(int arr[], int min, int max, Node* node=NULL) {
    if(min>max){
        return NULL;
    }
    int midIndex = (min+max)/2;

    // create node
    node = new Node(arr[midIndex]);
    node->left = createMinHeightBST(arr, min, midIndex-1, node);
    node->right = createMinHeightBST(arr, midIndex+1, max, node);
    return node;
}

/**
 * BFS Traversal used for printing the result
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
    Node* root = NULL;
    int arr[] =  {1, 2, 3, 4, 5, 6, 7};
    int sizeofArr = sizeof(arr)/sizeof(arr[0]);
    root = createMinHeightBST(arr, 0, sizeofArr-1);
    bfsTraversalWithNIter(root);
}
