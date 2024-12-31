#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> suffix(nums.size());
    suffix[nums.size()-1]  = 1;
    for(int i = nums.size() - 2 ; i >= 0; i--){
        suffix[i] = suffix[i+1] * nums[i+1]; 
    }
    for(int i = 0 ; i < nums.size() ; i++){
        nums[i] = nums[i] * suffix[i];
    }
    for(auto &ele : suffix){
        cout<<ele<<" ";
    }
    cout<<endl;
     for(auto &ele : nums){
        cout<<ele<<" ";
    }
}