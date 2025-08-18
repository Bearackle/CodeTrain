// 3 colors

#include<iostream>

using namespace std;

class Solution{
public:
    void sortColors(vector<int>& nums){
        int n = nums.size();
        int low = 0,mid = 0, high = n - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                mid++;
                low++;
            } else if(nums[mid] == 2){
                int temp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;
                high--;
            } else if (nums[mid] == 1){
                mid++;
            }
        }
    }
};

int main(){ 
    vector<int> vect = {1,0,2};
    Solution* sln = new Solution();
    sln->sortColors(vect);
    for(auto& v : vect){
        cout<<v<<" ";
    }
}