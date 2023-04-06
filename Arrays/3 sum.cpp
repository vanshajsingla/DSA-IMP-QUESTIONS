// link: https://leetcode.com/problems/3sum
class Solution {
public:
    void Twosum(vector<int>& nums,vector<vector<int>>&ans,int target,int i,int j)
    {
        while(i<j)
        {
            if(nums[i]+nums[j]==target)
            {
                // removing duplicates by ignoring nums[i]/nums[j] if equal to nums[i-1]/nums[j-1] taken
                while(i<j&& nums[i]== nums[i+1])
                    i++;
                while(i<j&& nums[j]== nums[j-1])
                    j--;
                ans.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
            else if(nums[i]+nums[j]<target)
                i++;
            else
                j--;
        }

    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        // n1+n2+n3=0 => n2+n3=-n1 => target=-n1
        for(int i=0;i<n-2;i++)
        {
            // removing duplicates by ignoring n1 if previously taken
            if(i>0&&nums[i]==nums[i-1])
                continue;
            int target=-nums[i];
            Twosum(nums,ans,target,i+1,n-1);
        }
        return ans;
    }
};
