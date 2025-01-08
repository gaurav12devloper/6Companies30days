/*
168. Excel Sheet Column Title
https://leetcode.com/problems/excel-sheet-column-title/description/
*/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber>0){
            columnNumber--;
            int rem=columnNumber%26;
            char val=rem+'A';
            ans=val+ans;
            columnNumber=columnNumber/26;
        }
        return ans;
    }
};