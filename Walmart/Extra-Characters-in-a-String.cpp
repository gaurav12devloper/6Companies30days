/*
2707. Extra Characters in a String
https://leetcode.com/problems/extra-characters-in-a-string/description/
*/
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>st(dictionary.begin(),dictionary.end());
        vector<int>dp(s.size()+1,0);
        int n=s.size();
        for(int i=s.size()-1;i>=0;i--){
            dp[i]=1+dp[i+1];
            for(int j=i;j<n;j++){
                string curr=s.substr(i,j-i+1);  // take substring from current i to j
                if(st.find(curr)!=st.end()){
                    dp[i]=min(dp[i],dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};

/*
        l  e e t s c o d  e
dp      1  4 3 2 1 0 3 2  1  0    at c zero becaouse dp[i]=4, dp[j+1]=0 where is end wala zero.

    at first 1 beacause dp[0]=min(dp[0],dp[4])=>(4,1)=1
*/