/*
299. Bulls and Cows
https://leetcode.com/problems/bulls-and-cows/description/
*/
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp1,mp2;
        for(auto it:guess) mp1[it]++;
        for(auto it:secret) mp2[it]++;
        int bull=0;
        int cow=0;
        // substrct so that mp1 can only count of those value which are not present in guess
        for(auto it:mp1){
            mp1[it.first]-=mp2[it.first];
        }
        for(int i=0;i<secret.size();i++){
            if(guess[i]==secret[i]){
                bull++;
            }
        }
        int count=0;
        for(auto it:mp1){
            if(it.second>0) count+=it.second; // counnt will contain all diffrent value is not present in guess
        }
        cow=secret.size()-count-bull;  // here bull is substract so that (same index match element get remove and only present element but diffrent location remain)
        string ans=to_string(bull)+"A"+to_string(cow)+"B";
        return ans;
    }
};