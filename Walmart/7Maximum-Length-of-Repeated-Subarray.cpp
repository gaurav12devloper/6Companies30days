/*
718. Maximum Length of Repeated Subarray
https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1<n2){
            swap(nums1,nums2);
            swap(n1,n2);
        }
        vector<int>dp(n1+1), prev(n1+1);
        int ans=0;
        for(int i=1;i<=nums1.size();i++){
            for(int j=1;j<=nums2.size();j++){
                if(nums1[i-1]==nums2[j-1]) dp[j]=prev[j-1]+1;
                else dp[j]=0;

                ans=max(ans,dp[j]);
            }
            prev=dp;  // make current dp as prev
        }
        return ans;
    }
};