/*
2002. Maximum Product of the Length of Two Palindromic Subsequences
https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/
*/
class Solution {
public:
    int ans=0;
    bool ispalindrome(string s){
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
    void solve(string s, string s1,string s2,int index){
        if(ispalindrome(s1) && ispalindrome(s2)){
            int size=s1.size()*s2.size();
            ans=max(ans,size);
        }
        for(int i=index;i<s.size();i++){
            s1.push_back(s[i]);
            solve(s,s1,s2,i+1);
            s1.pop_back();
            
            s2.push_back(s[i]);
            solve(s,s1,s2,i+1);
            s2.pop_back();
        }
        //solve(s,s1+s[index],index+1); // include
        //solve(s,temp,index+1);      // exclude
    }
    int maxProduct(string s) {
        string s1="";
        string s2="";
        solve(s,s1,s2,0);
        return ans;
    }
};