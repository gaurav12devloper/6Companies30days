/*
2223. Sum of Scores of Built Strings
https://leetcode.com/problems/sum-of-scores-of-built-strings/
*/
class Solution {
public:
    vector<long long> find_lps(string& s){
        vector<long long>lps(s.size(),0);
        int i=1;
        int len=0;  // length of longest prefix equal to suffix
        while(i<s.size()){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    cout<<i<<" "<<len;
                    len=lps[len-1]; // len=len-1  // if not equal to then substract len by1 and again check but in this case don't increment i value
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
   }
    long long sumScores(string s) {
        int n=s.size();
        vector<long long> lps = find_lps(s);
        vector<long long> dp(n,0);
        long long ans=0;
        for(int i=0;i<n;i++){
            dp[i] = lps[i]==0?1:dp[lps[i]-1]+1;
            ans+=dp[i];
        }
        return ans;
    }
};
