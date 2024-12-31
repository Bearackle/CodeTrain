class Solution {
public:;
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int lim = nums.size();
        for(int i = 1;i<lim;i++)
        {
            if (nums[k] != nums[i])
            {
                    ++k;
                    nums[k] = nums[i];
            }    
        }
        return k+1;
    }
};