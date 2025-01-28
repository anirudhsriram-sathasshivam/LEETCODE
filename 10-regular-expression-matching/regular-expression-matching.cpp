class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;  // Empty string matches empty pattern

        // Initialize the first row (s is empty, only '*' can match zero occurrences)
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] == '*' && j >= 2) {
                dp[0][j] = dp[0][j-2];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == '*' && j >= 2) {
                    // Zero occurrences of the preceding character
                    dp[i][j] = dp[i][j-2];
                    // One or more occurrences if the preceding character matches
                    if (p[j-2] == '.' || p[j-2] == s[i-1]) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                } else {
                    // Direct match or '.' which matches any character
                    if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
        }

        return dp[m][n];
    }
};