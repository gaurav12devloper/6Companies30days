/*
https://leetcode.com/problems/high-access-employees/description/
2933. High-Access Employees
*/

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>>mp;
        vector<string>ans;
        int minute;
        for(auto& time:access_times){
            string x=time[1];
            minute=x[0]-'0';
            minute=minute*10+x[1]-'0';
            minute*=60;
            minute+=(x[2]-'0')*10 + x[3]-'0';
            mp[time[0]].push_back(minute);
        }
        for(auto t:mp){
            sort(t.second.begin(),t.second.end());
            for(int i=0;i<int(t.second.size()-2);i++){
                if((t.second[i+2]-t.second[i])<60){
                    ans.push_back(t.first);
                    break;
                }
            }
        }
        return ans;
    }
};