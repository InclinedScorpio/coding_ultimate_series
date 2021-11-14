#include <iostream>

using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

    Node(int data,Node* left,Node* right) {
        // this->data = data;
        // this->left=left;
        // this->right=right;
    }
};

Node* createTree() {

}

int main() {
    int treeData[] = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    for (int a : treeData) {
        cout<<a<<endl;
        cout<<treeData.length;
    }
//    Node* alpha = createTree();
}