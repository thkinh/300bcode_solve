#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    };


void Init(TreeNode* x)
{
    x->val = 0;
    x->left = NULL;
    x->right = NULL;
}

TreeNode* CreateNode(TreeNode* &root, int x)
{
        TreeNode* p = new TreeNode;
        p->val = x;
        p->left = NULL;
        p->right = NULL;
        root = p;
}

void AddNode(TreeNode* &root, int x)
{
    if (root == NULL)
    {
        CreateNode(root,x);
    }
    else
    {
        if (x < root->val)
        {
            cout <<"adding to the left\n";
            AddNode(root->left,x);
            cout <<"adding successfully\n";
        }
        else if (x > root->val)
        {
            cout <<"adding to the right\n";
            AddNode(root->right,x);
            cout <<"adding successfully\n";
        }
    }
    
}

void Print(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    Print(root->left);
    cout << root->val <<" ";
    Print(root->right);
}

class Solution
{
public:
    TreeNode *invertTree(TreeNode* &root)
    {
        if (root == NULL)
            return NULL;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }    
}; 

int main()
{
    TreeNode* root ;
    Init(root);
    CreateNode(root,4); 
    AddNode(root,2);
    AddNode(root,7);
    Print(root);

    Solution ret;
    TreeNode* p = new TreeNode;
    p = ret.invertTree(root);
    Print(p);

    return 0;
}