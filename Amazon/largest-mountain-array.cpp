/*
845. Longest Mountain in Array
https://leetcode.com/problems/longest-mountain-in-array/description/
*/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<=2) return 0;
        vector<int>start(arr.size());
        vector<int>end(arr.size());
        int count=1;
        start[0]=1;
        // find the incresing element from prev to curr
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]<arr[i]){
                count++;
                start[i]=count;
            }
            else {
                start[i]=0;
                count=1;
            }
        }
        end[arr.size()-1]=1;
        count=1;
        // find the incresing elment from end to current
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                count++;
                end[i]=count;
            }
            else {
                end[i]=0;
                count=1;
            }
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(start[i]>1 && end[i]>1){
                ans=max(ans,start[i]+end[i]-1); // -1 because middle elment count twice
            }
        }
        return ans;
    }
};