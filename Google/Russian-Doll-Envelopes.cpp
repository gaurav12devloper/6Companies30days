/*
354. Russian Doll Envelopes
https://leetcode.com/problems/russian-doll-envelopes/
*/
class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        
        // if width equal then sort height in descending order
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        //sort width in ascending order
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(ans.back()<envelopes[i][1]) ans.push_back(envelopes[i][1]);
            else{
                int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin(); 
                ans[index]=envelopes[i][1];
                //*index=envelopes[i][1];
            }
        }
        return ans.size();
    }
};

// lower_bound basically find the position in ans where envelopes[i][1] can replace an element.

/*
if feeling doubbt why i have store only second elemnt of envelopes then remember i have sort envelops decending order of hight when width is same
due this when width is same then greater height already in our ans vector and every time ehen lower hiehgt came then we replace greater height with those lower height
*/