// this is not a effective solution, it took 5ms to complete

bool is(TreeNode* l, TreeNode* r);
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return is(root->left,root->right);
    }
};
 bool is(TreeNode* l, TreeNode* r)
   {
       if(l == NULL && r== NULL) return true;
       else if(l == NULL || r == NULL) return false;
       else if(l->val != r->val) return false;
       return is(l->left, r->right) && is(l->right, r->left);
   }