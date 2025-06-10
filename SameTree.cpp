void NLR (TreeNode*p, TreeNode*q,bool &a);
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool a = 1;
        NLR(p,q,a);
         return a;
    }
};

 void NLR (TreeNode*p, TreeNode*q,bool &a)
  {
      if(p == NULL && q == NULL) return;
      else if(p != NULL && q != NULL)
      {
          if(p->val != q->val) a = 0;
      }
      else {
           a = 0;
           return; 
          }
     NLR(p->left,q->left,a);
     NLR(p->right, q->right,a);  
  }


  //another path

  class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q == NULL) return true;
       else if (p==NULL || q == NULL) return false;
       else if (p->val != q->val) return false; 
       return isSameTree(p->right, q->right) && isSameTree(p->left,q->left);
    }
  };
