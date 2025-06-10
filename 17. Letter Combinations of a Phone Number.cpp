#include<iostream>
#include<vector>
#include<memory>
#include<unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char,string> mp = {
            {'2' ,"abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5',"jkl"},
            {'6', "mno"},
            {'7',"pqrs"},
            {'8', "tuv"},
            {'9',"wxyz"}
        };  
        vector<string> combinations;
        function<void(int, string)> backtrack = [&](int i, string currentStr){
            if(currentStr.length() == digits.length()){
                combinations.push_back(currentStr);
                return;
            }
            for(char c : mp[digits[i]]){
                backtrack(i+1, currentStr + c);
            }
        };
        backtrack(0,"");
        return combinations;
    } 
};

int main(){
	string input = "23";
    std::unique_ptr<Solution> sln = std::make_unique<Solution>();
    vector<string> result = sln->letterCombinations(input);
    for(auto &a : result){
        cout<<a<<", ";
    }
}