/*
2572. Count the Number of Square-Free Subsets
https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/
*/

#define mod int(1e9+7)
int prime_number[] = {2,3,5,7,11,13,17,19,23,29};
int dp[1001][1025];
class Solution {
public:
    int h(vector<int> &a, int in, int mask) {
        if(in == a.size()) {
            return 0;
        }
        if(dp[in][mask] != -1) {
            return dp[in][mask];
        }
        // no take - use the mask without updation
        int do_not_take = h(a, in+1, mask) % mod;
        // take
        int take = 1, new_mask = mask;
        for(int i=0 ; i<10 ; ++i) {
            if(a[in] % prime_number[i] == 0) {
                if(mask & (1<<i)) {
                    take = 0;
                    break;
                }
                new_mask |= (1<<i);
            }
        }
        if(take == 1) {
            take = (1ll + h(a, in+1, new_mask)) % mod;
        }
        
        return dp[in][mask] = (do_not_take + take) % mod;
    }
    int squareFreeSubsets(vector<int>& a) {
        memset(dp, -1, sizeof(dp));
        vector<int> t;
        for(auto i: a) {
            bool use_this_number = 1;
            for(int j=0 ; j<10 ; ++j) {
                if(i % (prime_number[j] * prime_number[j]) == 0) {
                    use_this_number = 0;
                    break;
                }
            }
            if(use_this_number) {
                t.push_back(i);
            }
        }
        return h(t, 0, 0);
    }
};
