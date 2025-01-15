/*
https://leetcode.com/problems/battleships-in-a-board/description/
419. Battleships in a Board
*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X'){
                    if(i==0 && j==0) ans++;
                    else if(j==0 && board[i-1][j]!='X') ans++;
                    else if(i==0 && board[i][j-1]!='X') ans++; 
                    else if(i>0 && j>0 && board[i-1][j]!='X' && board[i][j-1]!='X') ans++;
                }
            }
        }
        return ans;
    }
};

// you can do this with DFS also