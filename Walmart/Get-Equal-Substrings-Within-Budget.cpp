/*
1208. Get Equal Substrings Within Budget
https://leetcode.com/problems/get-equal-substrings-within-budget/description/
*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0;
        for(int r=0,l=0;r<s.size();r++){
            int cost=abs(s[r]-t[r]);
            maxCost-=cost;
            if(maxCost>=0){   // it check how long subarray satisfy our requirement
                ans=max(ans,r-l+1);
            }
           //If maxCost becomes negative, shrink the window from the left until maxCost is non-negative again
            while(maxCost<0 && l<=r){
                int leftdiff=abs(s[l]-t[l]);
                maxCost+=leftdiff;  // Increase maxCost by this cost as we are removing it from the window
                l++;
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
       int ans = 0, curr = 0, left = 0, n = s.size();
        for(int right = 0; right < n; right++) {
            maxCost-= abs(s[right]-t[right]);
            while(maxCost<0) {
                maxCost += abs(s[left]-t[left]);
                left++;
            }
            ans = max(ans, right-left+1);
        }

        return ans;
    }
};
*/