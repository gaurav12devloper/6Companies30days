/*
825. Friends Of Appropriate Ages
https://leetcode.com/problems/friends-of-appropriate-ages/description/
*/
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int>mp;
        for(int i=0;i<ages.size();i++){
            mp[ages[i]]++;
        }

        int ans=0;
        for(auto x:mp){
            int x1=x.first;
            for(auto y: mp){
                int y1=y.first;
                if(!(y1 <= 0.5 * x1 + 7 || y1 > x1 || (y1 > 100 && x1 < 100))){
                    ans+=x.second*y.second;  // number of friend reueest send
                    if(x1==y1) ans-=x.second;  // substracting because it ccan not send friend request to themself
                }
            }
        }
        return ans;
    }
};
