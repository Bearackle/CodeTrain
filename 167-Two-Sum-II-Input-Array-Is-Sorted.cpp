class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0 ; i < nums.size(); i++){
            map[nums[i]] = i ;
        }
        vector<int> result;
        for(int i = 0 ; i < nums.size(); i++){
            int key = target - nums[i];
            if(map.count(key) && map[key] != i){
                result.push_back(i+1);
                result.push_back(map[key] + 1);
                break;
            }
        }
        return result;
    }
};