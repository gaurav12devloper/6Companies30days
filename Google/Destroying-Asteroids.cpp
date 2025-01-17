/*
2126. Destroying Asteroids
https://leetcode.com/problems/destroying-asteroids/
*/
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long int ans=mass;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<=ans){
                ans+=asteroids[i];
            }
            else return false;
        }
        return true;
    }
};