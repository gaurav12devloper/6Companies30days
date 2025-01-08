/*
994. Rotting Oranges
https://leetcode.com/problems/rotting-oranges/description/
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh=0;
        int timer=0;
        // store rotten orange co-ordinate in queue and count fresh orange
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) q.push(make_pair(i,j));
            }
        }
        while(!q.empty() && fresh!=0){
            int size=q.size();
            while(size){
                int dx=q.front().first;
                int dy=q.front().second;
                q.pop();
                 // four adjacent positions at which the oranged placed will get rotten.
                vector<int>dir={1,0,-1,0,1};
                for(int i=0;i<dir.size()-1;i++){
                    int newdx=dx+dir[i]; // make sure newdx and dx variable must different
                    int newdy=dy+dir[i+1];
                    if(newdx>=0 && newdx<grid.size() && newdy>=0 && newdy<grid[0].size() && grid[newdx][newdy]==1){
                        fresh--;
                        grid[newdx][newdy]=2; // now make the fresh orange rotten
                        q.push(make_pair(newdx,newdy));
                    }
                }
                size--;
            }
            timer++;
        }
        return fresh == 0 ? timer : -1;
    }
};
