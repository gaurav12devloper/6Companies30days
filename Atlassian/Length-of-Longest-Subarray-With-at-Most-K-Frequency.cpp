/*
2958. Length of Longest Subarray With at Most K Frequency
https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
*/
class Solution {
public:
    int ans=0;
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int l=0,r=0;r<nums.size();r++){
            mp[nums[r]]++;
            while(mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};