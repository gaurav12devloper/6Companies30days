/*
Phone directory
https://www.geeksforgeeks.org/problems/phone-directory4628/1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        sort(contact, contact + n);
        vector<vector<string>> ans;
        vector<string> temp;
        string search;
        for (int i = 0; i < s.size(); i++)
        {
            search += s[i];
            for (int j = 0; j < n; j++)
            {
                if (contact[j].size() >= search.size())
                {
                    string curr = contact[j].substr(0, search.size());
                    if (curr == search)
                        temp.push_back(contact[j]);
                }
            }
            if (temp.size() == 0)
            {
                temp.push_back("0");
            }
            auto it = unique(temp.begin(), temp.end());
            temp.erase(it, temp.end());
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < ans.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends