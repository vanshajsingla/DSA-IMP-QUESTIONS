// link: https://leetcode.com/problems/maximum-subarray
// Intution: we have 2 options either to include curr element or not in subarray. If by including element we get higher sum take it otherwise don't take it.
// If sum becomes negative at any pt. then make sum=0 as we don't want -ve sum
//  This will also work correctly in case we have all -ve elements in the array as in that case only single(largest element) will be our ans which will be stored in maxi. 
class Solution {
public:
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
