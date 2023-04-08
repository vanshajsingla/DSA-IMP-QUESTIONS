// link: https://leetcode.com/problems/maximum-product-subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Approach 1:O(n2) (TLE) (find all subarrays & find max. product)
        // int n=nums.size(),prod=1,maxi=INT_MIN;
        // for(int i=0;i<n;i++)
        // {
        //     prod=1;
        //     for(int j=i;j<n;j++)
        //     {
        //         prod=prod*nums[j];
        //         maxi=max(maxi,prod);
        //     }
        // } 
        // return maxi;

        // Approach 2:O(n)
        // Intution: 
        // maintain max,min product while traversing
        // we have 2 choices either include curr element to curr product subarray or start new subarray from curr element
        // if element is -ve swap min & max prod. bcoz
        //  -ve no. will make our prod. min if curr prod. is +ve 
        // Also if curr prod. is -ve then -ve * -ve will make positve
        // Note: here we can't initialize our ans with either INT_MIN or INT_MAX bcoz we need to take max as well as min
        // So, initialize with nums[0]
        int n=nums.size(), ans=nums[0],maxi=ans,mini=ans;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
            {
                swap(mini,maxi);
            }
            maxi=max(nums[i],maxi*nums[i]);
            mini=min(nums[i],mini*nums[i]);
            ans=max(ans,maxi);
        }
        return ans;
    }
};
