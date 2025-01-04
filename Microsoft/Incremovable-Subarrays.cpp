/*
2970. Count the Number of Incremovable Subarrays I
https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/
*/
class Solution {
public:
    bool check(vector<int>& nums,int start, int end){
        int prev=0;
        for(int i=0;i<nums.size();i++){
            if(i>=start && i<=end) continue;
            if(nums[i]<=prev) return false;
            prev=nums[i];
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(check(nums,i,j)) ans++;  // remove[i,j] and cehcking incresing opr not
            }
        }
        return ans;
    }
};
