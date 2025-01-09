/*
36. Valid Sudoku
https://leetcode.com/problems/valid-sudoku/
*/
class Solution {
public:
    bool issafe(int row,int col,vector<vector<char>>& board){
        char val=board[row][col];
        // check in row
        for(int i=0;i<9;i++){
            if(i!=row && board[i][col]==val) return false;

            // check in col
            if(i!=col && board[row][i]==val) return false;

             // check in 3*3
             if((3*(row/3)+i/3)==row && (3*(col/3)+i%3)==col) continue;
             if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!issafe(i,j,board)) return false;
                }
            }
        }
        return true;
    }
};