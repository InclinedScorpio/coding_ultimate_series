// https://leetcode.com/problems/first-missing-positive/

class Solution {
    public int firstMissingPositive(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int i: nums) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        
        for(int i = 1; i <= (Math.pow(2, 31) - 1); i++) {
            if(!map.containsKey(i)) return i;
        }
        return 1;
    }
}
