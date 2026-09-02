class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp[i][j] will store the edit distance of word1[0..i-1] and word2[0..j-1]
        int[][] dp = new int[m + 1][n + 1];
        
        // Initialize base cases for empty strings
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    // Characters match, inherit the diagonal cost
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Mismatch: find minimum of insert, delete, or replace
                    int insertOp = dp[i][j - 1];
                    int deleteOp = dp[i - 1][j];
                    int replaceOp = dp[i - 1][j - 1];
                    
                    dp[i][j] = 1 + Math.min(replaceOp, Math.min(insertOp, deleteOp));
                }
            }
        }
        
        return dp[m][n];
    }
}
