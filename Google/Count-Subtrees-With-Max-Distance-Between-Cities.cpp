/*
1617. Count Subtrees With Max Distance Between Cities
https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/description/
*/

class Solution {
public:
    int solve(int state,vector<vector<int>>&dist,int n){
        int city=0,edge=0, maxDist=0;
        for(int i=0;i<n;i++){
            if(((state>>i)&1)==0) continue;  // skip the city if i is not in our subset 
            city++;
            for(int j=i+1;j<n;j++){
                if(((state>>j)&1)==0) continue;
                edge+=dist[i][j]==1;            // if adj then only incrment edge   
                maxDist=max(maxDist,dist[i][j]);
            }
        }
        if(city-1==edge) return maxDist;  // why this beacause subset {1,4} is not valid in this 0 edge but two city
        return 0;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>dist(n,vector<int>(n,n)); // value n is taken beacause distance never be greater then or eual to n

        // creating adjacency matrix
        for(auto e:edges){
            dist[e[0]-1][e[1]-1]=1;
            dist[e[1]-1][e[0]-1]=1; // beacuse bidirection edges
        }

        // find the minimum distance between all pair
        // floyd warshall 
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        // now count the how many substree exist whose max distance id d
        vector<int>ans(n-1,0);
        for(int state=0;state<(1<<n);state++){  // number of subset possible is 2^n-1, 
            int d=solve(state,dist,n);
            if(d>0) ans[d-1]++;
        }
        return ans;
    }
};

/* in solve function we count city and edge so that i can avoid invalid subset
 otherwise {1,2,3}, {1,2,4}, {2,3,4} and {1,2,3,4} similar to this {1,4} also have max two distance 2 it get also inclueded
 */