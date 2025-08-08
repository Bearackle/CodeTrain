class NumArray {
public:
    NumArray(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] = nums[i-1] + nums[i]; 
        }
        prefixSum = nums;
    }
    int sumRange(int left, int right) {
        
        return prefixSum[right] - (left > 0 ? prefixSum[left-1] : 0);   
    }
private:
    vector<int> prefixSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */