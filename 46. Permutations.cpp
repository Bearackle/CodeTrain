#include<iostream>
#include<vector>
#include<memory>
#include<unordered_map>
#include<functional>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()){
            return {{}};
        }
        vector<int> temp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(temp);
        vector<vector<int>> res;
        for(const auto &p : perms){
            for(int i = 0 ; i <= p.size(); i++){
                vector<int> pcopy = p;
                pcopy.insert(pcopy.begin() + i, nums[0]);
                res.push_back(pcopy);
            }
        }
        return res;
    }
};

int main(){
	vector<int> nums = {1,2,3};
    std::unique_ptr<Solution> sln = std::make_unique<Solution>();
    vector<vector<int>> result = sln->permute(nums);
    for(auto &a : result){
        cout<<"[";
        for(auto &b : a){
            cout<<b<<" ";
        }
        cout<<"]";
    }
}
// thực hiện đệ quy