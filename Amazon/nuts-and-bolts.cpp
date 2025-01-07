/*
https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
Nuts and Bolts Problem
*/
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[nuts[i]]=1;
        }
        int i=0;
        for(auto it:mp){
            nuts[i]=it.first;
            bolts[i]=it.first;
            i++;
        }
    }
};
/*
order: { !,#,$,%,&,*,?,@,^ }
above order is according to the ascii value.
since i am using map, it will automatically sort the keys.
*/
/*
time complexity: O(n)
space complexity: O(n)
*/
// another ways to do that which take constant space
/*
 int freq[256]={}; // now constant space
        for(int i=0;i<n;i++){
            freq[nuts[i]]=1;
        }
        int j=0;
        for(int i=0;i<256;i++){
            if(freq[i]>0){
                nuts[j]=(char)i;
                bolts[j]=(char)i;
                j++;
            }
        }
*/