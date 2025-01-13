/*
368. Largest Divisible Subset
https://leetcode.com/problems/largest-divisible-subset/description/
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>t(n,1);
        vector<int>prev_index(n,-1);  //through this we access all element which contribute in our ansswer
        int last_index=0; // last index which satisfy divisiblity rule
        int maxL=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(t[i]<t[j]+1){
                        prev_index[i]=j;
                        t[i]=t[j]+1;
                    }
                }
                if(t[i]>maxL){
                    maxL=t[i];
                    last_index=i;
                }
            }
        }
        vector<int>result;
        while(last_index!=-1){
            result.push_back(nums[last_index]);
            last_index=prev_index[last_index];
        }

        // Reverse the result to get the correct order
        reverse(result.begin(),result.end());
        return result;
    }
};