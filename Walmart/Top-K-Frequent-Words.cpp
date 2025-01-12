/*
692. Top K Frequent Words
https://leetcode.com/problems/top-k-frequent-words/description/
*/
class Solution {
public:
    struct cmp{
        bool operator()(pair<int,string>&a,pair<int,string>&b){
            if(a.first == b.first)
                return a.second > b.second; // > pe true hai isliye bada element top pe hoga but ye max priority queue hai siliye smaller top pe rahegea // Smaller lexicographical order comes first
            else
                return a.first < b.first;  // Larger frequency comes first
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        unordered_map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }
        for(auto it:mp){  // sort by frequence use priority queue
            pq.push({it.second,it.first});
        }
        vector<string>ans;
        vector<string>samefreq;
        for(int i=0;i<k;i++){
            string t=pq.top().second;
            ans.push_back(t);
            pq.pop();
        }
        return ans;
    }
};


/*

class Solution {
	public:
		vector<string> topKFrequent(vector<string>& words, int k) {
			unordered_map <string, int> umap;
			for (string s: words) umap[s]++;
			priority_queue <pair<int, string>> pq;
			for (auto it: umap) {
				// minus sign used to build min heap 
				pq.push({-it.second, it.first});
				if(pq.size() > k) pq.pop();
			}
			vector <string> res;
			while (k--) {
				res.push_back(pq.top().second);
				pq.pop();
			}
			reverse (res.begin(), res.end());
			return res;
		}
	};
*/