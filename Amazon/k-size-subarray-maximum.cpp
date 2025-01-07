/*
K Sized Subarray Maximum
https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
*/
class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<arr.size();i++){
            if(!pq.empty() && arr[pq.top().second]<arr[i]) pq.pop();
            pq.push({arr[i],i});
            
            // make sure largest value present at top and it must within range
            while(i-pq.top().second>=k) pq.pop();
            
            // at the begining array, it will not belong to range of k.
            if(i>=k-1) ans.push_back(pq.top().first);
        }
        return ans;
    }
};

// we can do this question with dequeue also.
//https://leetcode.com/problems/sliding-window-maximum/