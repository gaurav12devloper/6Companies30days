/*
1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
*/
class Solution {
public:
    vector<pair<int,int>>adj[101];
    vector<pair<int,int>>ans;
    
    void dijkstra(int source, int n,int distanceThreshold){
        vector<int>result(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        result[source]=0;
        pq.push({source,0});
        while(!pq.empty()){
            int node=pq.top().first;
            int d=pq.top().second;
            pq.pop();
            for(auto neighbor:adj[node]){
                int adjnode=neighbor.first;
                int adjDis=neighbor.second;
                if(result[adjnode]>d+adjDis){
                    result[adjnode]=d+adjDis;
                    pq.push({adjnode,d+adjDis});
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(i!=source && result[i]<=distanceThreshold){
                count++;
            }
        }
        ans.push_back({count,source});
    }

    bool static cmp(pair<int,int>a, pair<int,int>b){
        if(a.first==b.first){
            return a.second>b.second; // Higher index city preferred
        }
        return a.first<b.first; // Fewer reachable cities preferred
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // create adjcency list
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        for(int i=0;i<n;i++){
            dijkstra(i,n,distanceThreshold);
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans[0].second;
    }
};