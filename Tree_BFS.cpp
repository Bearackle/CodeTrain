#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node*left;
    Node*right;
    Node() : data(0) , left(nullptr),right(nullptr){};
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
Node* insert(Node* root, int x)
        {
            if (!root) return new Node(x);
            else 
            {
                Node*current;
                if(root->data > x)
                {
                    current = insert(root->left,x);
                    root->left = current;
                }
                else if(root->data < x)
                    {
                        current = insert(root->right,x);
                        root->right = current;
                    }
              return root;
            }
        }
void BFS(Node* root)
    {
        if (root==NULL) return;
            queue <Node*> s;
            s.push(root);
        while(!s.empty())
            {   
            Node* current = s.front();
            cout<<current->data<<" ";
            if(current->left)
                s.push(current->left);
            if(current->right)
                s.push(current->right);
            s.pop();
            }
    }

int main()
{
     Node* X;
     X = NULL;
     int a[] = {5,7,-2,0,-5,1,6,-3};
    for(int i = 0;i<8;i++)
    {
        X = insert(X,a[i]);
    }
    BFS(X);
}  

// this is full code of BFS traversal algorithms
