/*
3006. Find Beautiful Indices in the Given Array I
https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/
*/
class Solution {
public:
    vector<int>all_ocurrence(string s,string req){
        size_t index=s.find(req);
        vector<int>ans;
        while(index!=string::npos){
            ans.push_back(static_cast<int>(index));
            index=s.find(req,index+1);
        }
        return ans;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>a_index=all_ocurrence(s,a);
        vector<int>b_index=all_ocurrence(s,b);
        vector<int>ans;
        int i=0,j=0;
        while(i<a_index.size() && j<b_index.size()){
            if(abs(a_index[i]- b_index[j])<=k) ans.push_back(a_index[i++]);
            else if(b_index[j]-a_index[i]>k) i++;
            else j++;
        }
        return ans;
    }
};