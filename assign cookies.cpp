#include<iostream>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       int count =  0;
       int i = 0, j = 0;
       sort(g.begin(), g.end());
       sort(s.begin(), s.end());
       int s_g = g.size(), s_s = s.size();
       while(i < s_g && j < s_s){
          if(s[j] >= g[i]){
            count++;
            i++;
          }
        j++;
       }
       return count;  
    }
};

int main(){
	
}