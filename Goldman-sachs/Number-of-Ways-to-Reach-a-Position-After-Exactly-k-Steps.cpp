/*
2400. Number of Ways to Reach a Position After Exactly k Steps
https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/
*/
class Solution {
public:
    int M = 1e9+7;
    int f(int s, int e, int k, int i, vector<vector<int>> &dp){
        if(i==0) {
            if(s==e) {
                return 1;
            }
            else return 0;
        }
        if(abs(e-s)>i) return 0;
        if(dp[s+1000][i] != -1) {
            return dp[s+1000][i]%M;
        }
        int left = f(s-1, e, k, i-1, dp)%M;
        int right = f(s+1, e, k, i-1, dp)%M;
        
        return dp[s+1000][i] = (left + right)%M;
    }
    int numberOfWays(int s, int e, int k) {
        vector<vector<int>> dp(3000, vector<int>(k+1, -1));
        return f(s, e, k, k, dp);
    }
};