/*
2343. Query Kth Smallest Trimmed Number
https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/
*/
    class Solution {
    public:
        int solve(vector<string>& nums,int k,int digit){
            vector<string>temp;
            priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>>pq;
            for(int i=0;i<nums.size();i++){
                string temp=nums[i].substr(nums[i].size()-digit); // will get the size of (digit size string from last)
                pq.push({temp,i});
            }
            while(k>1){
                pq.pop();
                k--;
            }
            return pq.top().second;   // return the k smallest value index
        }
        vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
            vector<int>ans;
            for(int i=0;i<queries.size();i++){
                int k=queries[i][0];
                int digit=queries[i][1];
                int index=solve(nums,k,digit);
                ans.push_back(index);
            }
            return ans;
        }
    };

    /*
    queries[i] = [ki, trimi] trimi digit ka last se chhod ke baki ka digit remove kar dena sare nums me se, then k smallest wala return kar dena

    */