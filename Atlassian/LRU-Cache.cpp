/*
146. LRU Cache
https://leetcode.com/problems/lru-cache/
*/
class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator>mp;
     list<pair<int,int>> l;
    int size;
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            l.splice(l.begin(),l,mp[key]);
            return mp[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
            {
                l.splice(l.begin(),l,mp[key]);
                mp[key]->second=value;
                return;
            }
            if(l.size()==size)
            {
                auto d_key=l.back().first;
                l.pop_back();
                mp.erase(d_key);
            }
            l.push_front({key,value});
            mp[key]=l.begin();
    }
};