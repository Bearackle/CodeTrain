#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int s;
         while (n > 9){
            int i = n;
            s = 0;
            while ( i > 0){
                    int j  = i % 10;
                    s += j*j;
                    i /= 10;
            }
            n = s;
        }
        return n == 1;   
    }
};

int main(){
    Solution * a = new Solution();
    cout<<a->isHappy(19);
}