#include<iostream>
#include<vector>
#include<map>

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['IV'] = 4;
        mp['VI'] = 6;
        mp['V'] = 5;
        mp['IX'] = 9;
        mp['X'] = 10;
        mp['XI'] = 11;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        vector<int> vec;
        for (const auto& pair : mp) {
            int number = num / pair.second;
            int modulo = num % pair.second;
            std::fill_n(std::back_inserter(vec), number, pair.second);
            num = modulo;
        }
        string b;
        for(auto &a : vec){
            b.append(mp.find(a));
        }
        return b;
    }
};

int main(){
    Solution *a = new Solution();
    std::cout<<a->intToRoman(99);
}

