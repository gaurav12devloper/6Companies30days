/*
1600. Throne Inheritance
https://leetcode.com/problems/throne-inheritance/description/
*/
class ThroneInheritance {
    unordered_map<string,vector<string>>kingdom;
    unordered_set<string>dead;
    string root;
public:
    ThroneInheritance(string kingName) {
        root=kingName;
    }
    
    void birth(string parentName, string childName) {
        kingdom[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }

    void dfs(vector<string>& ans,string root){
        if(dead.find(root)==dead.end()) ans.push_back(root);
        for(auto child:kingdom[root]){
            dfs(ans,child);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        dfs(ans,root);
        return ans;
    }
};
