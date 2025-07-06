#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int findTilt(TreeNode* root) {
        dfs(root);
        int sum = 0;
        for(int i = 0; i < rs.size(); i++){
            sum+= rs[i];
        }
        return sum;
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left_child = dfs(root->left);
        int right_child = dfs(root->right);
        int tilt = abs(left_child - right_child);
        rs.push_back(tilt);
        return root->val;
    }
private:
    vector<int> rs;
};

int main(){
	TreeNode* root = new TreeNode();
	root
}