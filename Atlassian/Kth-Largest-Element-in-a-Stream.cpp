/*
https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
703. Kth Largest Element in a Stream
*/

class KthLargest {
public:
    priority_queue<int,vector<int>, greater<>>pq;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        for(auto it:nums){
            pq.push(it);
        }
        kth=k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>kth) pq.pop();
        return pq.top();
    }
};