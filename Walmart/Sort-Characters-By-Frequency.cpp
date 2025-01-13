/*
451. Sort Characters By Frequency
https://leetcode.com/problems/sort-characters-by-frequency/description/
*/
class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq; // max priority queue
        for(auto it: s){
            mp[it]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            auto t=pq.top();
            ans+=string(t.first,t.second);  // string(5,a);
            pq.pop();
        }
        return ans;
    }
};

/*
class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int>mp;
       string ans;
       for(int i=0;i<s.length();i++){
           mp[s[i]]++; // counting freq of each character
       }
       this queue will stores the elements in descending order i.e the largest element is at the top
      priority_queue<pair<int,char>>p; 
       for(auto it:mp){
           p.push({it.second,it.first});
       }
       while(!p.empty()){
           int n=p.top().first;
           while(n--){
               ans+=p.top().second;
           }
           p.pop();
       }
       return ans;
    }
}; */
