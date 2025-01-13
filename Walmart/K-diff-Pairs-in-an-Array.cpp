/*
https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
532. K-diff Pairs in an Array
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[i]-nums[j])==k){
                    ans.insert({nums[i],nums[j]});
                }
            }
        }
        return ans.size();
    }
};