 //link: https://leetcode.com/problems/4sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      sort(nums.begin(),nums.end());
        set<vector<int>> s;
      vector<vector<int>> ans;
        int n=nums.size();
        for(int l=0;l<n-3;l++)
        {

            for(int k=l+1;k<n-2;k++)
            {
                int i=k+1,j=n-1;
                while(i<j)
                    {
                        long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                        if(sum==target)
                        {
                            // while(i<j&& nums[i]== nums[i+1])
                            //     i++;
                            // while(i<j&& nums[j]== nums[j-1])
                            //     j--;
                                s.insert({nums[l],nums[k],nums[i],nums[j]});
                           i++;
                           j--;
                        }
                        else if(sum<target)
                            i++;
                        else 
                            j--;
                    }
            }
        }
        for(auto it:s)
        {
            ans.push_back(it);
        }  
        return ans;
    }
};
