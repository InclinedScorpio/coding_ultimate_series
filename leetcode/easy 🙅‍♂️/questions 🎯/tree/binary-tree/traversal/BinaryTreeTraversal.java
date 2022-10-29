// Question: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
class BinaryTreeTraversal {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> order = new ArrayList<>();
        levelOrderBottom(root, order);
        return order;
    }
    
    private void levelOrderBottom(TreeNode root, List<List<Integer>> order) {
        
        if(root == null) return;
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        queue.offer(null);
        
        List<Integer> currentLevelNodes = new ArrayList();
        
        while(!queue.isEmpty()) {
            TreeNode current = queue.poll();
            
            if(current == null) {
                
                order.add(0, currentLevelNodes);
                
                if(queue.isEmpty()) {
                    return;
                }
                
                queue.add(null);
                currentLevelNodes = new ArrayList<>();
                continue;
            }
        currentLevelNodes.add(current.val);
        
        if(current.left != null) queue.offer(current.left);
        if(current.right != null) queue.offer(current.right);
        
        }
    }
}
