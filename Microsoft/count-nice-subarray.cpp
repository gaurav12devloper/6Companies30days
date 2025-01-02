class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd=0,ans=0;
        int left=0,right=0;
        int count=0;
        while(right<nums.size()){
            if(nums[right]&1){
                odd++;
                count=0;
            }
            while(odd==k){
                count++;
                odd-=nums[left++]&1;
            }
            ans+=count;
            right++;
        }
        return ans;
    }
};

/* // convert this problem into binary subarray sum equal to k
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp[sum-k]){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};
*/
