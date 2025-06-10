#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0 ; i < nums.size(); i++){
            map[nums[i]] = i ;
        }
         for(const auto& it : map){
            cout<<it.first<<" "<<it.second;
         }
        vector<int> result;
        for(const auto& it : map){
            int key = target - it.first;
            if(map.count(key)){
                result.push_back(it.second);
                result.push_back(map[key]);
                break;
            }
        }
        return result;
    }
};

int main(){
    Solution *a = new Solution();
    vector <int> c {3,3};
    a->twoSum(c,6);
}