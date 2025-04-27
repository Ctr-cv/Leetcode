class Solution {
    public static int MAXN = 3000001;
    // The trie himself
    public static int[][] trie = new int [MAXN][2];
    // Tracks space for our trie
    public static int cnt;
    // Start from which particular bit to reduce constant time
    public static int left;
    public static int findMaximumXOR(int[] nums){
        build(nums);
        int ans = 0;
        for (int num : nums){
            ans = Math.max(ans, getXor(num));
        }
        clear();
        return ans;
    }

    public static void build(int[] nums){
        cnt = 1;
        int max = Integer.MIN_VALUE;
        for (int i=0; i < nums.length; i++) max = Math.max(max, nums[i]);
        left = 31 - Integer.numberOfLeadingZeros(max);
        for (int num : nums) insert(num);
    }

    public static void insert(int num){
        int cur = 1;
        for (int i = left, path; i >= 0; i--){
            // Gets the ith bit of num
            path = (num >> i) & 1;
            if (trie[cur][path] == 0) trie[cur][path] = ++cnt;
            cur = trie[cur][path];
        }
    }

    public static int getXor(int num){
        int ans = 0;
        int cur = 1;
        for (int i = left; i >= 0; i--){
            // num[i], 0 or 1
            int path = (num >> i) & 1;
            // reverse num[i]
            int want = path ^ 1;
            // If this branch doesn't exist, change it back
            // Now want is the branch that we will take.
            if (trie[cur][want] == 0) want ^= 1;
            cur = trie[cur][want];
            // Add the bit to ans using OR
            ans |= (path ^ want) << i;
        }
        return ans;
    }

    public static void clear(){
        for (int i = 1; i <= cnt; i++){
            Arrays.fill(trie[i], 0);
        }
    }
}