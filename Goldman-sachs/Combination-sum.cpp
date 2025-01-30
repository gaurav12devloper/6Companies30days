/*
216. Combination Sum III
https://leetcode.com/problems/combination-sum-iii/description/
*/

class Solution {
public:
    vector<vector<int>>ans;
    void solve(int k,vector<int>&input,vector<int>&temp,int target,int idx){
        if(idx>9) return;
        if(temp.size()==k && target==0){
            ans.push_back(temp);
            return;
        } 
        	solve(k,input,temp,target,idx+1);
            temp.push_back(input[idx]);
            solve(k,input,temp,target-input[idx],idx+1);
            temp.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>input;
        for(int i=1;i<=9;i++) input.push_back(i);
        vector<int>temp;
        solve(k,input,temp,n,0);
        return ans;
    }
};