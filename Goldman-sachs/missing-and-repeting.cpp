/*
https://www.proelevate.in/dsa-practice/6-companies-30-days
Missing And Repeating
*/
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int r=0;
        int m=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=arr[arr[i]-1]){  // here i am just checking if arr[i]=3 then at i=2 must not equal to 3
                swap(arr[i],arr[arr[i]-1]); // swap the number make it correct position ex: if no is 3 then swap 3 to index 2, similarly swap index 4 to 3 and so on.
                i--;
            }
            else {
                if(arr[i]!=(i+1)) r=arr[i];  
            }
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=(i+1)) m=i+1;
        }
        return {r,m};
    }
};