#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> dic;
        dic['I'] = 1;
        dic['V'] = 5;
        dic['X'] = 10;
        dic['L'] = 50;
        dic['C'] = 100;
        dic['D'] = 500;
        dic['M'] = 1000;
        int length = s.length(); // 1
        int number = 0;
        for (int  i = length - 1; i >=0 ; i--){
            if(length > 1 && dic[s[i]] * 5 == dic[s[i+1]] || dic[s[i]] * 10 == dic[s[i+1]]){
                number -= dic[s[i]];
            }
            else{
                number += dic[s[i]];
            }
        }
        return number;
    }
};


int main(){
    Solution* slt = new Solution();
    int result = slt->romanToInt("IV");
    cout<<result;
}