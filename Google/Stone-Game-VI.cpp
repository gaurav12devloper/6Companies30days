/*
1686. Stone Game VI
https://leetcode.com/problems/stone-game-vi/description/
*/
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vector<vector<int>>combine;
        for(int i=0;i<n;i++){
            int a=aliceValues[i];
            int b=bobValues[i];
            combine.push_back({-a-b,a,b}); // combine value so that sort and get maximum at front, alice value, bob value
        }
        sort(combine.begin(),combine.end());
        int a=0;
        int b=0;
        for(int i=0;i<n;i++){
            if(i%2==0) a+=combine[i][1]; // alice will get thier point which kept at index 1
            else b+=combine[i][2];
        }
        if(a==b) return 0;
        else if(a>b) return 1;
        
        return -1;
    }
};

/*
understand question properly then you can solve easily
if alice take ith value then bob cannot take ith value and never in past
*/