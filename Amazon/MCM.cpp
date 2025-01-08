/*
https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1
Brackets in Matrix Chain Multiplication
*/
class Solution {
  public:
    vector<vector<int>>bp,dp;   //bp breaking point
    int MCM(vector<int> &arr,int left,int right){
        if(left>=right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        
        int min_val=INT_MAX;
        
        for(int i=left;i<right;i++){
            int temp=MCM(arr,left,i)+MCM(arr,i+1,right)+arr[left-1]*arr[i]*arr[right];
            if(temp<min_val){
                min_val=temp;
                bp[left][right]=i;
            }
        }
        return dp[left][right]=min_val;
    }   
    void construct_string(int i, int j, string &ans) {
        if (i==j){
            ans.push_back('A' + i - 1);
            return;
        }
        ans.push_back('(');
        construct_string(i, bp[i][j], ans);
        construct_string(bp[i][j] + 1, j, ans);
        ans.push_back(')');
    }
    
    string matrixChainOrder(vector<int> &arr) {
        int n=arr.size();
        string ans;
        dp.resize(n, vector<int>(n, -1));
        bp.resize(n, vector<int>(n, -1));
        MCM(arr,1,n-1);
        construct_string(1,n-1,ans);
        return ans;
    }
};

