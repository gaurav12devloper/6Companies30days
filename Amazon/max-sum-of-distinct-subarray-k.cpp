/*
2461. Maximum Sum of Distinct Subarrays With Length K
https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
*/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        int left=0;
        long long maxi=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(mp.count(nums[i])){
                sum-=nums[left];
                mp.erase(nums[left]);
                left++;
            }
            mp[nums[i]]=1;
            if((i-left+1)==k){
                 maxi=max(maxi,sum);
                 sum-=nums[left];
                 mp.erase(nums[left]);
                 left++;
            }
        }
        return maxi;
    }
};