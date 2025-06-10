class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int lim = nums.size();
    int k = lim;
        for (int i = 0;i < k;i++)
        {
            if (nums[i] == val)
            {
                  do {    
                         --k;
                         if(k<=i) return k;
                   }  while (nums[k] == val);
                swap(nums[i], nums[k]);
            }
        }
        return k;
    }
};