class Solution {
public:
    map<vector<int>,int>mp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        if(mp.find(needs)!=mp.end()){
            return mp[needs];
        }
        int ans=0;
        for(int i=0;i<needs.size();i++){
            ans+=needs[i]*price[i]; 
        }
        int n=special.size();
        for(int i=0;i<n;i++){
            bool valid=true;
            for(int j=0;j<price.size();j++){
                if(needs[j]<special[i][j]){
                    valid=false;
                    break;
                }
            }
            // if special offer is valid
            if(valid){
                for(int j=0;j<needs.size();j++){
                    needs[j]-=special[i][j];
                }
                int ans2=special[i].back();
                ans=min(ans,ans2+shoppingOffers(price,special,needs)); // since we can apply multiple offer that why calling here again
                
                // now let do backtracking beacuase may be not including prev case price get minimum
                for(int j=0;j<needs.size();j++){
                    needs[j]+=special[i][j];   // add the need again which you have remove before
                }
            }
        }
        return mp[needs]=ans;
    }
};