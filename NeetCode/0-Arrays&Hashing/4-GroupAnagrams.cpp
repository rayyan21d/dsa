

#include <bits/stdc++.h>
using namespace std;

class MySolution
{
public:
    vector<int> returnFrequencyTable(string s)
    {
        vector<int> arr(26, 0);
        for (char c : s)
        {
            arr[c - 'a']++;
        }

        return arr;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        map<vector<int>, vector<string>> mpp;

        for (int i = 0; i < strs.size(); i++)
        {
            mpp[returnFrequencyTable(strs[i])].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

class SolutionNeetCode
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> res;
        for (const auto &s : strs)
        {
            vector<int> count(26, 0);
            for (char c : s)
            {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i)
            {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto &pair : res)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};