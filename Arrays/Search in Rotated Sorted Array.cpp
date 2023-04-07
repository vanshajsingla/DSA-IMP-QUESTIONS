// link:https://leetcode.com/problems/search-in-rotated-sorted-array
// approach 1:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //// if mid<nums[0] => mid is in 1st sorted half
        //// if mid>nums[0]=> mid is in 2nd sorted half
      int n = nums.size();
      int left = 0;
      int right = n-1;
     
      while(left <= right){
           int mid= left + (right - left) / 2;
        if(nums[mid] == target)
         return mid;
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
      return -1;
    }
};
// approach 2:
class Solution {
public:

    int findPivot(vector<int>& nums) // i.e. find min element in rotated sorted array using binary search
    {
        int n=nums.size();
        int l=0,r=n-1;
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
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pvtIndex=findPivot(nums);
        int idx=binarySearch(0,pvtIndex-1,nums,target);
        if(idx!=-1)
            return idx;
        idx=binarySearch(pvtIndex,n-1,nums,target);
        return idx;
    }
};


