#include<iostream>
#include<vector>
#include<map>
using namespace std;
// T.C: O(N^2),S.C: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
       for(int i=0;i<nums.size();i++)
       {
           for(int j=i+1;j<nums.size();j++)
           {
               if(nums[i]+nums[j]==target)
                    {
                        ans.push_back(i);
                        ans.push_back(j);
                    }
           }
       } 
       return ans;
    }
};

// T.C: O(N),S.C: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        // map to store element,index
        unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++)
       {
          int rem=target-nums[i];
             if(mp.find(rem)!=mp.end())
           {
               ans.push_back(mp[rem]);
               ans.push_back(i);
           }
           mp[nums[i]]=i;
       }
       return ans;
    }
};