/*
Random Flip Matrix
https://leetcode.com/problems/random-flip-matrix/description/
*/
class Solution {
public:
    int totalRow,totalCol;
    int row,col;
    Solution(int m, int n) {
        totalRow=m;
        totalCol=n;
        row=0;
        col=0;
    }
    
    vector<int> flip() {
        col++;
        if (col==totalCol)
        {
            col=0;
            row++;
        }
        if (row==totalRow)
        {
            row=0;
            col=0;
        }
        return {row,col};
    }
    
    void reset() {
        
    }
};