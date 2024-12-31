#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size), prefix(size), suffix(size);
        prefix[0] = 1;
        for (int i = 1 ; i< size; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        copy(prefix.begin(), prefix.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

        suffix[size - 1] = 1;
        for (int i = nums.size() - 2 ; i >= 0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

         copy(suffix.begin(), suffix.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

        for (int i = 0 ; i < nums.size() ; i++){
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};

int main(){
    Solution* a = new Solution();
    vector<int> d = {1,2,3,4};
    vector<int> b = a->productExceptSelf(d);
    for(auto &c : b){
        cout<<c<<" ";
    }
}