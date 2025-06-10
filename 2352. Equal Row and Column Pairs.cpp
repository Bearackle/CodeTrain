#include<iostream>
#include<vector>
#include<memory>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
    	
    }
};

int main(){
	std::vector<vector<int>> nums = {{3,2,1},{1,7,6},{2,7,7}};
	std::unique_ptr<Solution> sln = std::make_unique<Solution>();
	std::cout<<sln->longestOnes(nums,k);
}