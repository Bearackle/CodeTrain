#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        int s_length = s.size();
        for(int i = 0 ; i < s_length ;i++){
            mp[s[i]]++;
        }
        int t_length = t.size();
        for(int i = 0 ; i < t_length ; i++){
            if(mp.count(mp[t[i]]) > 0 && mp[t[i]] > 0){
                --mp[t[i]];
            } else {
                return false;
            }
        }
        if(t_length != s_length)
            return false;
        return true;
    }
};

int main(){
    Solution * a = new Solution();
    cout<<a->isAnagram("aacc",  "ccac");
}