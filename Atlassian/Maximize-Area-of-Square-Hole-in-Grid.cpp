/*
2943. Maximize Area of Square Hole in Grid
https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/
*/
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int h=1,v=1;
        int count=1;
        for(int i=0;i<hBars.size()-1;i++){
            if((hBars[i]+1)==hBars[i+1]) count++;
            else count=1;
            h=max(h,count);
        }

        count=1;
        for(int i=0;i<vBars.size()-1;i++){
            if((vBars[i]+1)==vBars[i+1]) count++;
            else count=1;
            v=max(v,count);
        }
        int ans=min(v,h)+1;
        return ans*ans;
    }
};