/*
1401. Circle and Rectangle Overlapping
https://leetcode.com/problems/circle-and-rectangle-overlapping/description/
*/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX=max(x1,min(x2,xCenter));
        int closestY=max(y1,min(y2,yCenter));
        int dx=xCenter-closestX;
        int dy=yCenter-closestY;
        return dx*dx+dy*dy<=radius*radius;
    }
};

/*
basically i have find first nearest value of x and y. 
min(x2,xCenter), consider ex1,(0,3) since Xcenter is nearest so definatly circle will on left and side
now find max(0,x1)=(0,1)=1 so we get nearest x is 1.
similarly we find y.
now find out the distance and if distance is less then or equal to radius then true
*/