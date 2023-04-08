// link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii
// APPROACH 1: 
class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int n = nums.size();
      int left = 0;
      int right = n-1;
     while(left<right&&nums[left]==nums[left+1])
        left++;
         while(left<right&&nums[right]==nums[right-1])
        right--;
      while(left <= right){
           int mid= left + (right - left) / 2;
        if(nums[mid] == target)
         return true;
        if(nums[mid] >= nums[left]) {
          if(target >= nums[left] && target <= nums[mid])
            {
                right = mid - 1;
            }
           else left = mid + 1;
        } 
        else {
          if(target >= nums[mid] && target <= nums[right]) 
            left = mid + 1;
          else right = mid - 1;
        }
      }
      return false;
    }
};

// APPROACH 2: Find pivot and apply BS in both sorted halves
class Solution {
public:
    int findPivot(vector<int>& nums) // i.e. find min element in rotated sorted array using binary search
    {
        int n=nums.size();
        int l=0,r=n-1;
        // skip duplicate elements
        while(l<r&&nums[l]==nums[l+1])
        {
            l++;
        }   
        while(l<r&&nums[r]==nums[r-1])
        {
            r--;
        }
        while(l<r) // not l<=r otherwise u will get stuck in infinite loop
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
                r=mid;// not mid-1 bcoz mid can be our ans as nums[mid]<nums[r] 
        }
        return r;
    }
    int binarySearch(int l,int r,vector<int>& nums, int target)
    {
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
    bool search(vector<int>& nums, int target) {
                int n=nums.size();
        int pvtIndex=findPivot(nums);
        int idx=binarySearch(0,pvtIndex-1,nums,target);
        if(idx!=-1)
            return true;
        idx=binarySearch(pvtIndex,n-1,nums,target);
       if(idx!=-1)
            return true;
            return false;
    }
};
