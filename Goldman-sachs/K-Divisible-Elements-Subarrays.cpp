/*
K Divisible Elements Subarrays
https://leetcode.com/problems/k-divisible-elements-subarrays/
*/
class Trie {
public:
    int val;
    unordered_map <int,Trie*> next;
};
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans = 0;
        Trie* root = new Trie();
        for(int i = 0; i<nums.size(); i++){
            Trie* temp = root;
            int count = 0;
            for(int j = i; j<nums.size(); j++){
                if(nums[j]%p==0) count++;
                if(count>k) break;
                
                if(!temp->next[nums[j]]){
                    temp->next[nums[j]] = new Trie();
                    ans++;
                }
                temp = temp->next[nums[j]];
            }
        }
        return ans;
    }
};