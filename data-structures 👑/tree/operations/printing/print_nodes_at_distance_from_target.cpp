#include <iostream>

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

void find_node_at_level_k(Node* node, int k, int level=0) {
	if(node==NULL) {
		return;
	}
	if(level==k) {
		cout<<node->data<<" ";
	}
	find_node_at_level_k(node->left, k, level+1);
	find_node_at_level_k(node->right, k, level+1);
}


/***
 * TREE:
 *                               1
 *                        2              3
 *                  4         5*            6
 *                        7        8
 *                              9    10
 * 
 * 
 * COMPLEXITY: O(N^2)
 * LOGIC: Question has 2 parts
 * 1. Below the level of target node, run simple (print_node_at_k_level)
 * 2. For other nodes above target - this is the main logic
 * > 1. Return at what level is target present
 * > 2. Now, keep checking if present in left or right side of current node
 * > 3. If on left, then print kth level from right side
 * > 4. If on right, then print kth level from left side
 * > 5. If not present on both sides, return -1(means not present on this path)
 * 
 * • So basically if return value is more than -1 that means node comes "In path btw root and Target "
 * • ... and we needs to cover the nodes which maybe at a distance along the way
 * 
 * NOTE: All nodes have to be covered as we won't know which ones are "In path btw root and Target "
 */ 
int print_nodes_at_distance_k(Node* node, Node* target, int k) {
	if(node==NULL) {
		return -1;
	}
	if(node==target) {
		find_node_at_level_k(node, k);
		return k-1;
	}

	int leftTree = print_nodes_at_distance_k(node->left, target, k);
	if(leftTree==0) { //the current node is at the k distance and so parent nodes don't need to worry, as they will never be printed(-1)
		cout<<node->data<<" ";
		return -1;
	}
	if(leftTree>-1) {
		// print node on right side
		find_node_at_level_k(node->right, leftTree-1);
		return leftTree-1;
	}

	int rightTree = print_nodes_at_distance_k(node->right, target, k);
	if(rightTree==0) { //the current node is at the k distance and so parent nodes don't need to worry, as they will never be printed(-1)
		cout<<node->data<<" ";
		return -1;
	}
	if(rightTree>-1) { 
		// print node on left side
		find_node_at_level_k(node->left, rightTree-1);
		return rightTree-1;
	}

	// if target is nor left, nor right(both gives -1)
	return -1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->left->right->right->left = new Node(9);
    root->left->right->right->right = new Node(10);

    print_nodes_at_distance_k(root,root->left->right, 2);
}
