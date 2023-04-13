// link: https://leetcode.com/problems/product-of-array-except-self
// Approach 1: (using div operation)
// sc : O(1),T.C:O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),flag=0,prod=1,c=0;
        vector<int>ans;
         for(int i=0;i<n;i++)
         {
              if(nums[i]!=0)
              {
                  prod*=nums[i];
              }
              else
              {
                  flag=1;
                  c++;
              }
         }
            
          for(int i=0;i<n;i++)
          {
              if(c==n||c>1)
              {
                   ans.push_back(0);
              }
             else if(flag==1&&nums[i]!=0)
              {
                  ans.push_back(0);
              }
              else if(flag==1&&nums[i]==0)
              {
                  ans.push_back(prod);
              }
              else
              {
                  ans.push_back(prod/nums[i]);
              }
          }  
          return ans;
    }
};
//////////////////////////////////////////////////
 // Approach 2:(using left & right array)
        // sc : O(n),T.C:O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),prod=1;
        vector<int>left(n),right(n),ans(n);
        for(int i=0;i<n;i++)
        {
          prod*=nums[i-1];
           left[i]=prod;
        }
        prod=1;
        for(int i=n-1;i>=0;i--)
        {
           prod*=nums[i-1];
           right[i]=prod;
        }
        ans[0]=right[1];
        ans[n-1]=left[n-2];
          for(int i=1;i<n-1;i++)
        {
           ans[i]=left[i-1]*right[i+1];
        }
        return ans;
    }
};

//////////////////////////////////////////////////
   // Approach 3:(using single output array)
        // sc : O(1),T.C:O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),prod=1;
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
          prod*=nums[i];
           ans[i]=prod;
        }
        prod=1;
        for(int i=n-1;i>0;i--)
        {
          ans[i]=ans[i-1]*prod;
           prod*=nums[i];
        }
        ans[0]=prod;
        return ans;
    }
};
