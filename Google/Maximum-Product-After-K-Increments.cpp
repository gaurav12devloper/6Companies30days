/*
2233. Maximum Product After K Increments
https://leetcode.com/problems/maximum-product-after-k-increments/description/
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k--){
            int top=pq.top();
            pq.pop();
            pq.push(top+1);
        }
        long long int ans=1;
        long long int mod=1e9+7;
        while(!pq.empty()){
            ans=(ans*pq.top())%mod;
            pq.pop();
        }
        return ans;
    }
};
/*
For making product maximum we need to increment lowest element of nums.
*/