/*
661. Image Smoother
https://leetcode.com/problems/image-smoother/description/
*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row=img.size();
        int col=img[0].size();
        vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
        vector<vector<int>>result(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int count=1;
                int sum=img[i][j];
                for(int k=0;k<dirs.size();k++){
                    int x=i+dirs[k][0];
                    int y=j+dirs[k][1];
                    if(x<row && x>=0 && y<col && y>=0){
                        sum+=img[x][y];
                        count++;
                    }
                }
                result[i][j]=sum/count;
            }
        }
        return result;
    }
};