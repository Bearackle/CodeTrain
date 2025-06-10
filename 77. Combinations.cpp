#include<iostream>
#include<vector>
#include<memory>
#include<unordered_map>
#include<functional>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> temp_combination;
        function<void(int,vector<int>)> backtrack = [&](int i, vector<int> temp_combination){
            if(temp_combination.size() == k){
                combinations.push_back(temp_combination);
                return;
            }
            for(int c = i; c <= n; c++){
                temp_combination.push_back(c);
                backtrack(c + 1,temp_combination);
                temp_combination.pop_back();
            }
        };
        backtrack(1,temp_combination);
        return combinations;
    }
};

int main(){
	int n = 4, k = 2;
    std::unique_ptr<Solution> sln = std::make_unique<Solution>();
    vector<vector<int>> result = sln->combine(n,k);
    for(auto &a : result){
        for(auto &b : a){
            cout<<b<<" ";
        }
    }
}