#include<iostream>
#include<vector>
#include<memory>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size();
        int left = 0,right = 0, longestOnes = 0, k = 1;
        while (right < size){
        	if(nums[right] == 0){
        		k--;
        	}
        	right++;
        	while( k < 0){
        		if(nums[left] == 0){
        			k++;
        		}
        		left++;
        	}
        	longestOnes = max(longestOnes, right-left);
        }
        return longestOnes - 1;
    }
};

int main(){
	vector<int> nums = {0,1,1,1,0,1,1,0,1};
	unique_ptr<Solution> sln = make_unique<Solution>();
	cout<<sln->longestSubarray(nums);
}