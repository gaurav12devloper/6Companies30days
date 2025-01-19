/*
1095. Find in Mountain Array
https://leetcode.com/problems/find-in-mountain-array/
*/

class Solution {
public:
    int find_peak(MountainArray &mountainArr){
        int left=0;
        int right=mountainArr.length()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                left=mid+1;
            }
            else right=mid-1;
        }
        return left;
    }
    int b_search(int start,int end,int target,MountainArray &mountainArr){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)==target) return mid;
            if(mountainArr.get(mid)<target){
                start=mid+1;
            }
            else end=mid-1;
        }
        return -1;
    }

    int rb_search(int start,int end,int target,MountainArray &mountainArr){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mountainArr.get(mid)==target) return mid;
            if(mountainArr.get(mid)>target){
                start=mid+1;
            }
            else end=mid-1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak=find_peak(mountainArr);

        // 0 to prak element
        int ans=b_search(0,peak,target,mountainArr); 
        if(ans!=-1) return ans;
        
        // peak+1 to end
        int end=mountainArr.length()-1;
        ans=rb_search(peak+1,end,target,mountainArr);
        if(ans!=-1) return ans;

        return -1;
    }
};