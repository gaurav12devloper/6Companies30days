/*
188. Best Time to Buy and Sell Stock IV
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
*/

class Solution {
public:
    int solve(vector<int>& prices,int index,int buy,int limit,vector<vector<vector<int>>>&dp){
        if(limit==0 || index==prices.size()) return 0;
        if(dp[index][buy][limit]!=-1) return dp[index][buy][limit];
        int profit=0;
        if(buy){
            int b=-prices[index]+solve(prices,index+1,0,limit,dp);
            int not_buy=solve(prices,index+1,1,limit,dp);
            profit=max(b,not_buy);
        }
        else{
            int sell=prices[index]+solve(prices,index+1,1,limit-1,dp);
            int not_sell=solve(prices,index+1,0,limit,dp);
            profit=max(sell,not_sell);
        }
        return dp[index][buy][limit]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,k,dp);
    }
};

/*
there are four case possible
(1)buy (2) not buy i.e skip (3) sell (4) skip the sell
important point:
int b=-prices[index]+solve(prices,index+1,0,limit);
-prices[index], we know that when we but and sell then we substracy buy amount, and solve fucntion return sell amount
*/