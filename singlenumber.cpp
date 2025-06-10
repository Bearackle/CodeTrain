#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution
{
	public:
		 int singleNumber(vector<int>& nums) {
			int num = 0;
			for(auto &x : nums)
			{
				num = num^x;
			}
			return num;
    }
};

int main()
{
	Solution *c = new Solution;
	vector<int> b {1,3,4,5,1,3,4};
	cout<<c->singleNumber(b);
}