/*
Run Length Encoding
https://www.geeksforgeeks.org/problems/run-length-encoding/1
*/

class Solution {
  public:
    string encode(string s) {
        int n = s.size();
        string ans = "";
        for(int i =0;i< s.size();i++)
        {
            int count = 1;
            while(i+1 < n and s[i] == s[i+1])
            {
                count++;
                i++;
            }
            ans += s[i];
            ans += to_string(count);
        }
        return ans;
    }
};