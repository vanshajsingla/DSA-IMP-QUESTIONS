// link: https://leetcode.com/problems/contains-duplicate-ii
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //O(n^2) Giving TLE 
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         if(nums[i]==nums[j]&&abs(i-j)<=k)
        //             return true;
        //     }
        // }
        // return false;
        int n=nums.size();
    unordered_map<int,int> mp;                       //key = element, value = index
    
    for(int i=0;i<n;i++){
        int curr=nums[i];
		
        if(mp.find(curr)!=mp.end()){                 //if curr_element is present in map
            if(abs(i-mp[curr]) <= k) return true;    //then check abs(i-mp[curr]) <= k, return true;
            //mp[curr]=i;                              //else update the index of curr_element;
        }
        mp[curr]=i;                                  //else, push element and it's index into map
    }
    return false;
        
        
    }
};
