/*
324. Wiggle Sort II
https://leetcode.com/problems/wiggle-sort-ii/description/
*/

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        vector<int> snums(nums);
        sort(snums.begin(), snums.end());
        int n = nums.size();
        for (int i = 0, j = (n - 1) / 2, k = n - 1; i < n; i++)
        {
            nums[i] = snums[i % 2 == 0 ? j-- : k--];
        }
    }
};
/*
we can not put j=0 beacause if we start taking minimum element from starting then problem occur
like  [1,3,2,2,3,1]=>[1,3,1,3,2,2]  when middle element is same
*/