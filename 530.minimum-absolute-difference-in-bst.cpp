/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        stack<TreeNode *> stack;
        TreeNode *curr = root;
        vector<int> vtr;
        while (!stack.empty() || curr != NULL)
        {
            if (curr != NULL)
            {
                stack.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = stack.top();
                stack.pop();
                cout << curr->val << " ";
                vtr.push_back(curr->val);
                curr = curr->right;
            }
        }
        int size=vtr.size();
        int numf=10000;
        vector<int> vt;
        if(size==1)
        {
            return vtr[0];
        }
        for(int i=0;i<size-1;i++)
        {
            if(vtr[i+1]-vtr[i]<numf)
            {
                cout<<"hi"<<endl;
                numf=vtr[i+1]-vtr[i];
            }
        }
        return numf;
    }
};
// @lc code=end
