/*
3154. Find Number of Ways to Reach the K-th Stair
https://leetcode.com/problems/find-number-of-ways-to-reach-the-k-th-stair/description/
*/

class Solution {
public:
    vector<long long>power;
    unordered_map<string,int>mp;
    int k1;
    int solve(int pos,int back,int jump){
        if(pos>k1+1) return 0;   // agar pos+1 se jada ho gaya to wo back kar bhi achieve nahi kar sakta

        int ans=0;
        string key=to_string(pos)+"-"+ to_string(back)+"-"+ to_string(jump);
        if(mp.find(key)!=mp.end()) return mp[key];
        if(pos==k1) ans++;
        if(back==1){  // that means back is allowed
            ans+=solve(pos-1,0,jump);
        }
        ans+=solve(pos+power[jump],1,jump+1);
        return mp[key]=ans;
    }
    int waysToReachStair(int k) {
        k1=k;
        power.resize(32);
        for(int i=0;i<31;i++){
            power[i]=pow(2,i);
        }
        return solve(1,1,0);
    }
};