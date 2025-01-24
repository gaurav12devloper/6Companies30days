/*
https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/
Count Words Obtained After Adding a Letter
*/

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string>st;
        int ans=0;
        for(auto word:startWords){
            sort(word.begin(),word.end());
            st.insert(word);
        }
        for(auto word:targetWords){
            sort(word.begin(),word.end());
            for(int i=0;i<word.size();i++){ // we will remove i character
                string t=word.substr(0,i)+word.substr(i+1);
                if(st.find(t)!=st.end()){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};