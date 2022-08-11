#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> levelorder(TreeNode*root)
{
    vector<int>res;
    if(root==NULL)
    return res;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        int sum = 0;
        while(size--)
        {
            TreeNode*curr = q.front();
            q.pop();
            sum+=curr->val;
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
        }
        res.push_back(sum);
    }
    return res;
}
