/*
1568. Minimum Number of Days to Disconnect Island
https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
*/
class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j, vector<vector<int>>&visited){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1 && !visited[i][j]){
            visited[i][j]=1;
            dfs(grid,i,j+1,visited);
            dfs(grid,i,j-1,visited);
            dfs(grid,i-1,j,visited);
            dfs(grid,i+1,j,visited);
        }
    }

    int numberofIsland(vector<vector<int>>& grid){
        int island=0;
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    dfs(grid,i,j,visited);
                    island++;
                }
            }
        }
        return island;
    }

    int minDays(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));
        int island=0;
        island=numberofIsland(grid);
        if(island==0 || island>1){   // when graph contain 0 island or disconnected island already presend
            return 0;
        }
        else{
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    if(grid[i][j]==1){
                        grid[i][j]=0;   // Temporarily remove the land
                        island=numberofIsland(grid);
                        if(island>1 || island==0) return 1;  // island==0 we need to check beacuse when grid contain single 1, case 98
                        grid[i][j]=1;  // Restore the land
                    }
                }
            }
        }
        return 2;
    }
};

// we can make this unconnected by filpin 1 to zero either 0,1,2 time, 
// maximum two time required to make this unconneted 
/*
if graph not contain 1 then 0 island return 0.
if graph contain 1 i.e graph is connected then we need to make it unconnected graph for
that, traverse the grid if found 1 then make it 0 and check whether island become disconnected, if not then make it again 1,
and go for other 1, make them 0 similary we do for all 1 until found graph disconnected,
if we didn't found disconnected graph by flipping single 1 then we nkow that it will definitly become disconnected when 
we flip two 1 to zero.
*/