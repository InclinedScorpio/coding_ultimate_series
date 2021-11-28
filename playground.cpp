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

Node* createTree(int arr[], int sizeOfArr) {
    // create root and push in queue
    Node* root = new Node(arr[0], NULL, NULL);
    queue<Node*> queue;
    queue.push(root);

    int index=0;
    while(index<sizeOfArr) {
        
        Node* curr = queue.front();
       
        if(!queue.empty()) {
            queue.pop();
        }//had to do as queue.pop() in case any iter q is empty

        if(!curr) {
            index++;
            continue;
        } 

        // create left & right and link to current node
        if( ((2*index+1) < sizeOfArr) ) {
            if(arr[2*index+1]!=-1) {
                Node* left = new Node(arr[2*index+1], NULL, NULL);
                curr->left = left;
                queue.push(left);
            }
        }
        if( ((2*index+1) < sizeOfArr) && arr[2*index+1]==-1) {
            queue.push(NULL);
        }

        if( ((2*index+2) < sizeOfArr) && arr[2*index+2]!=-1 ) {
            Node* right = new Node(arr[2*index+2], NULL, NULL);
            curr->right = right;
            queue.push(right);
        }
        if( ((2*index+2) < sizeOfArr) && arr[2*index+2]==-1) {
            queue.push(NULL);
        }
        index++;
    }
    return root;
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
    Node* root = createTree(levelOrder, sizeOfArr);

    bfsTraversalWithNIter(root);
}