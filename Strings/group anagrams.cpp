// link: https://leetcode.com/problems/group-anagrams
// approach 1: using sorting T.C=O(m*nlogn)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
/////////////////////////////////////////////////////////////////////////
// approach 2: using 26 size array T.C=O(nk)
class Solution {
public:
string generate(string word)
{
    int arr[26]={0};
    for(char ch:word)
    {
        arr[ch-'a']++;
    }
    string newWord="";
    for(int i=0;i<26;i++)
    {
        int freq=arr[i];
        if(freq>0)
        {
            newWord+=string(freq,i+'a');
        }
    }
    return newWord;
}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
        int n=strs.size();
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++)
        {
            string temp=generate(strs[i]);
            mp[temp].push_back(strs[i]); 
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
