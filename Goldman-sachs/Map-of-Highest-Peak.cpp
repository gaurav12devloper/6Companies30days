/*
1765. Map of Highest Peak
https://leetcode.com/problems/map-of-highest-peak/
*/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>>q;
        int row=isWater.size();
        int col=isWater[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    isWater[i][j]=0;
                }
                else isWater[i][j]=-1;
            }
        }
        vector<int>dir={1,0,-1,0,1}; // right,bottom,left,top
        while(!q.empty()){
            auto position=q.front();
            q.pop();
            int i=position.first;
            int j=position.second;
            
            for(int d=0;d<4;d++){
                int i_=i+dir[d];
                int j_=j+dir[d+1];
                if(i_>=0 && i_<row && j_>=0 && j_<col && isWater[i_][j_]==-1){
                    isWater[i_][j_]=1+isWater[i][j];
                    q.push({i_,j_}); // it get visited but next time we need neibour of it
                }
            }
        }
        return isWater;
    }
};

// similar to rotten orange