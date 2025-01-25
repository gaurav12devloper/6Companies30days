/*
1969. Minimum Non-Zero Product of the Array Elements
https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/description/
*/

class Solution {
public:
    long long mod=1e9+7;
    long long myPow(unsigned long long base,unsigned long long exp){
       if(exp==0) return 1;
       long long result=myPow(base,exp/2);
       result=(result*result)%mod;
       if(exp%2==1) result=((base%mod)*result)%mod;

       return result;
    }
    int minNonZeroProduct(int p) {
        unsigned long long  x=(1LL<<p)-1; // maximum 2^3=8-1=7=> 111
        unsigned long long ans=myPow(x-1,x/2);
        ans%=mod;
        ans=((x%mod)*ans)%mod;    
        return ans;
    }
};

