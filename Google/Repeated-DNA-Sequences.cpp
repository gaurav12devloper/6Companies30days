/*
187. Repeated DNA Sequences
https://leetcode.com/problems/repeated-dna-sequences/description/
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string,int>mp;
        if(s.size()<=10) return ans;
        for(int i=0;i<s.size()-9;i++){
            string curr=s.substr(i,10);
            mp[curr]++;
        }
        for(auto it:mp){
            if(it.second>1) ans.push_back(it.first);
        }
        return ans;
    }
};
