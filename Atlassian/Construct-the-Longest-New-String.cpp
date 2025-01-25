/*
2745. Construct the Longest New String
https://leetcode.com/problems/construct-the-longest-new-string/description/
*/

class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans=min(x,y)*4+z*2;       // multiply 4 beaucse 2 for x and 2 for y
        if(x != y) ans +=2;
        return ans;
    }
};