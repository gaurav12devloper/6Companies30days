/*
462. Minimum Moves to Equal Array Elements II
https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int middle=nums[nums.size()/2];
        int step=0;
        for(int i=0;i<nums.size();i++){
            step+=abs(nums[i]-middle);
        }
        return step;
    }
};