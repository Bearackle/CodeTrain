#include<iostream>
#include<vector>
#include<memory>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
    	int size = nums.size();
    	int left = 0;
    	int right = 0;
    	int maxOnes = 0;
        while(right < size){
        	if(nums[right] == 0){
        		k--;
        	}
        	right++;
        	while(k < 0){
        		if(nums[left] == 0)
        			k++;
        		left++;
        	}
        	maxOnes = std::max(maxOnes, right -left);
        }
        return maxOnes;
    }
};

int main(){
	std::vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
	int k = 2;
	std::unique_ptr<Solution> sln = std::make_unique<Solution>();
	std::cout<<sln->longestOnes(nums,k);
}