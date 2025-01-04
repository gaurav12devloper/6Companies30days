/*
2976. Minimum Cost to Convert String I
https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/
*/
class Solution {
public:
    vector<pair<int,int>>adj[26]; //array of vector size 26
    vector<vector<int>>dp; // we can not declare intialize dp here
    int dijstra(int src,int des){
        if(dp[src][des]!=-1) return dp[src][des];
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>distance(26,INT_MAX);
        pq.push({src,0});
        while(!pq.empty()){
            int node=pq.top().first;
            int d=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int neibor=it.first;
                int nDis=it.second;
                if(distance[neibor]>nDis+d){
                    distance[neibor]=nDis+d;
                    pq.push({neibor,nDis+d}); // add this node in priority queue with updated distance
                }
            }
        }
        return dp[src][des]=distance[des]==INT_MAX?-1:distance[des];
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        dp.resize(26,vector<int>(26,-1));
        long long ans=0;
        // create the adj list
        for(int i=0;i<original.size();i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                int c=dijstra(source[i]-'a',target[i]-'a');
                if(c<0) return -1;
                else ans+=c;
            }
        }
        return ans;
    }
};
/*
approach: adjcency list nikal lo and minimum distance nikalne ke liye dijstra alogrithm use kar lo jab source and taget match na ho tab.
*/
// by using dijstra algorithm i have find out all min distance from source to other node