#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> sp;
        for(int i = 0; i < m; i++){
            for(int j; j <n ; j++){
                sp.push_back(matrix[i][j]);
            }
            swap(i, j);
        }

    }
    return sp;
};

int main(){
    Solution* a = new Solution();
    vector<vector<int>> vec = a->spiralOrder({{1,2,3},{4,5,6},{7,8,9}});
    for(auto & it : vec){
        for(auto &ic : it){
            cout<<ic<<" ";
        }
    }
}