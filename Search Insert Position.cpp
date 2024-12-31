 int BiSearch(vector<int> nums, int l, int r, int target);
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()- 1;
         return  BiSearch(nums,l,r,target);
    }
};
    int BiSearch(vector<int> nums, int l, int r, int target)
    {
        int  p = (l+r)/2;
        if (r>=l) 
         {
           if (target == nums[p]) return p;
         if(target < nums[p])
           return BiSearch(nums,l,p-1,target);
         if(target > nums[p])
           return BiSearch(nums,p+1,r,target);
         }
         return l;
    }