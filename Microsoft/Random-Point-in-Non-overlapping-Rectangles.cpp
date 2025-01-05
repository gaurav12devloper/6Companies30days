/*
Random Point in Non-overlapping Rectangles
https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/
*/
class Solution {
public:

    vector<int>tPoints;
    vector<vector<int>>rect;
    Solution(vector<vector<int>>& rects) {
        rect=rects;
        int total=0;
        for(int i=0;i<rects.size();i++){
            int x1=rects[i][0];
            int y1=rects[i][1];
            int x2=rects[i][2];
            int y2=rects[i][3];
            total+=(x2-x1+1)*(y2-y1+1); // total interior point
            tPoints.push_back(total);
        }
    }
    
    vector<int> pick() {
        int point=rand()%tPoints.back();
        int index=upper_bound(tPoints.begin(),tPoints.end(),point)-tPoints.begin();
        auto r=rect[index];
        int randomX=rand()%(r[2]-r[0]+1)+r[0];
        int randomY=rand()%(r[3]-r[1]+1)+r[1];
        return {randomX,randomY};
    }
};
