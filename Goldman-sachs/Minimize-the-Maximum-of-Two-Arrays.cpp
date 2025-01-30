/*
Minimize the Maximum of Two Arrays
https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/
*/

typedef long long ll;
class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ll lcm=(ll)divisor1/__gcd(divisor1,divisor2)*divisor2; 
        auto f=[&](ll mid){
            ll ng_c=mid/lcm,ng_a=mid/divisor1,ng_b=mid/divisor2;
            ll can_c=mid-ng_a-ng_b+ng_c,can_a=mid-ng_a-can_c,can_b=mid-ng_b-can_c;
            if(can_a<uniqueCnt1){
                ll diff=uniqueCnt1-can_a;
                if(can_c<diff)return false;
                can_c-=diff;
            }
            return (can_b+can_c>=uniqueCnt2);
        };
        ll l=0,r=1e10+5;
        while(r-l>1){
            ll mid=(l+r)/2;
            if(f(mid))r=mid;
            else l=mid;
        }
        return r;
    }
};