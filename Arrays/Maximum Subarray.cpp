//link : https://leetcode.com/problems/maximum-subarray
class Solution {
public:
// APPROACH 1: O(n3)
int maxSubArray(vector<int>& nums) {
int maxi=INT_MIN,sum=0,n=nums.size();
for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
    {
         sum=0;
        for(int k=i;k<=j;k++)
        {
            sum+=nums[k];
        }
         maxi=max(sum,maxi);
    }
}
return maxi;
}

// APPROACH 2: O(n2)
int maxSubArray(vector<int>& nums) {
int maxi=INT_MIN,sum=0,n=nums.size();
for(int i=0;i<n;i++)
{
    sum=0;
    for(int j=i;j<n;j++)
    {
            sum+=nums[j];
         maxi=max(sum,maxi);
    }
}
return maxi;
}

// APPROACH 3: Kadane's algo O(n)
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
           sum+=nums[i];
           maxi=max(sum,maxi);
           if(sum<0)
           sum=0;
        }
        return maxi;
    }
};
