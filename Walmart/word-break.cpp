/*
https://leetcode.com/problems/word-break/
139. Word Break
*/
class Solution {
public:
    unordered_set<string>dic;
    int n;
    int dp[301];
    bool solve(string &s,int idx){
        if(idx>=n) return true;
        //if(dic.find(s.substr(idx,n-idx))!=dic.end()) return true;
        if(dp[idx]!=-1) return dp[idx];
        for(int l=1;l<=n;l++){
            string temp=s.substr(idx,l);
            if(dic.find(temp)!=dic.end() && solve(s,idx+l)){
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }   
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        for(auto it:wordDict) dic.insert(it);
        return solve(s,0);
    }
};

/*
s = "applepenapple", wordDict = ["apple","pen","app"]

                applepenapple
                /    \
            app       lepenapple  since this word is not found.
            / \   \
        apple  pen  apple
*/

