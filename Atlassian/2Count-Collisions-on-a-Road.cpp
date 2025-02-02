/*
2211. Count Collisions on a Road
https://leetcode.com/problems/count-collisions-on-a-road/description/
*/
class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.length();
        int fromRight=0;
        int cnt=0;
        
        int i=0;
        while(i<n && directions[i]=='L')
            i++;
        while(i<n)
        {
            if(directions[i]=='R')
                fromRight++;
            else
            {
                if(directions[i]=='S')
                    cnt+=fromRight;
                else
                    cnt+=fromRight+1;
                
                fromRight=0;
            }
            
            i++;
        }
        return cnt;
        
    }
};