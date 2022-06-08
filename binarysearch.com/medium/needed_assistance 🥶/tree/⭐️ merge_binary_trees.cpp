// https://binarysearch.com/problems/Merging-Binary-Trees

/**
 * LOGIC: As we are required to take constant space
 * - We need to understand that we can take any of the tree and update required things there
 * - Let's say we take 0th tree
 * - For 0th left if data is present and 1's not present then we will keep it as it is
 * - If 0th left is null and 1st has data on left
 * - We will rewire 1st left to 0th left
 * 
 * - That's how using a single tree we can update required things
 * 
 */ 
Tree* solve(Tree* node0, Tree* node1) {
    if(!node0) return node1;
    else if(!node1) return node0;
    else {
        node0->val +=node1->val;
        node0->left = solve(node0->left, node1->left);
        node0->right = solve(node0->right, node1->right);
        return node0;
    }
}