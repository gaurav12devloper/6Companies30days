/*
1823. Find the Winner of the Circular Game
https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
*/

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>nums(n);
        for(int i=0;i<n;i++) nums[i]=i+1;
        int i=0;
        while(nums.size()>1){
            i=(i+k-1)%nums.size();
            nums.erase(nums.begin()+i);
        }
        return nums[0];
    }
};
// i have substraced 1 because the index starts from 0.