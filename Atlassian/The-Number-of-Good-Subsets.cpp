/*
1994. The Number of Good Subsets
https://leetcode.com/problems/the-number-of-good-subsets/
*/

class Solution {
public:
    int dp[40][2500];
    long mod = 1000000007;
    long recurse(int curr, int mask, vector<int>& elig, map<int,int>& numsPrimeMask, vector<int>& v, map<int,int>& freq){
        if(curr>=elig.size()){
            long totalCnt = 1;
            for(auto el:v){
                // cout<<el<<" ";
                totalCnt = (totalCnt%mod * freq[el]%mod)%mod;
            }
            // cout<<totalCnt<<endl;
            return totalCnt;
        }
        long ans = recurse(curr+1, mask, elig, numsPrimeMask, v, freq);

        if((numsPrimeMask[elig[curr]]&mask) == 0){
            v.push_back(elig[curr]);
            ans = (ans%mod + recurse(curr+1, mask^numsPrimeMask[elig[curr]], elig, numsPrimeMask, v, freq)%mod)%mod;
            v.pop_back();
        }

        cout<<ans<<endl;

        return ans;
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        int sz = primes.size();

        map<int,int> primeIndex;
        for(int i=0;i<sz;i++){
            primeIndex[primes[i]] = i;
        }
        map<int,int> numsPrimeMask;

        int ones = 0;

        set<int> elig;
        map<int,int> freq;
        for(auto el:nums){
            if(el==1){
                ones++;
                continue;
            }
            bool take = true;
            int primeMask = 0;
            int curr = el;
            for(int j=2;j*j<=el;j++){
                int cnt = 0;
                while(curr%j == 0){
                    curr = curr/j;
                    cnt++;
                }
                if(cnt>0 && cnt!=1){
                    take = false;
                }
                else if(cnt==1){
                    primeMask = primeMask ^ (1<<primeIndex[j]);
                }
            }
            if(curr!=1){
                primeMask = primeMask ^ (1<<primeIndex[curr]);
            }
            if(take){
                elig.insert(el);
                freq[el]++;
                numsPrimeMask[el] = primeMask;
            }
        }

        vector<int> v;

        vector<int> unq(elig.begin(), elig.end());

        memset(dp,-1,sizeof(dp));

        long ans =  recurse(0, 0, unq, numsPrimeMask, v, freq);
        ans = (ans - 1 + mod)%mod; //for empty subset

        // cout<<ans<<endl;

        long ones_ans = 1;
        for(int i=1;i<=ones;i++){
            ones_ans = (ones_ans%mod * 2%mod)%mod;
        }

        //Handle ones
        ans = (ans%mod + ((ones_ans-1+mod)%mod * ans%mod)%mod)%mod;

        return ans;
    }
};