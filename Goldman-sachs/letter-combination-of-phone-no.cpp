/*
17. Letter Combinations of a Phone Number
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>result={""};
        if(digits.length()==0) return {};
        vector<string>phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> temp;
        for(auto it:digits){
           for(auto cm:result){
               for(auto ch:phone[it-'0']){
                   temp.push_back(cm+ch);
               }
           }
           result.swap(temp);
           temp.clear();
        }
        return result;
    }
};