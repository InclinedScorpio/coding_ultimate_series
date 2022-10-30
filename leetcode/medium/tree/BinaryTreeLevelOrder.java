// Question: https://leetcode.com/problems/binary-tree-level-order-traversal/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BinaryTreeLevelOrder {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> levelOrder = new ArrayList<>();
        levelOrder(root, levelOrder);
        return levelOrder;
    }
    
    private void levelOrder(TreeNode root, List<List<Integer>> levelOrder) {
        
        if(root == null) return;
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        queue.add(null);
        
        List<Integer> currentLevelNodes = new ArrayList<>();
        
        while(!queue.isEmpty()) {
            TreeNode current = queue.poll();
            
            if(current == null) {
                levelOrder.add(currentLevelNodes);
                if(queue.isEmpty()) {
                    return;
                }
                queue.add(null);
                currentLevelNodes = new ArrayList<>();
                continue;
            }
            
            currentLevelNodes.add(current.val);
            
            if(current.left != null) queue.add(current.left);
            if(current.right != null) queue.add(current.right);
            
        }
    }
}
