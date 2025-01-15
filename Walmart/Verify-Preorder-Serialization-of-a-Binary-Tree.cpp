/*
331. Verify Preorder Serialization of a Binary Tree
https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
*/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        int count=1;
        bool prev=true;
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]==','){
                prev=true;
                continue;
            }
            if(prev==true){  // since number can be more then 1 digit that we need to make sure that all digit betwwen comma consider as single digit
                if(preorder[i]!='#') count+=1;
                else count--;
                //cout<<count;
                prev=false;
            }
            if(count<=0 && i<preorder.size()-1) return false; // if zero or less then zero appear before traversal of all node then return false
        }
        if(count==0) return true;
        return false;
    }
};

/*
"   9,3,4,#,#,1,#,#,2,#,6,#,#"
 1  2 3 4 3 2 3 2 1 2 1 2 1 0 valid  
*/
/*
when i am at 9 will produce two more data out of which we consume 1 that why we incrment only 1.
when # appear then that mean 2 data will not produce and since # is consume so reduce one, overall reduce 1.
*/