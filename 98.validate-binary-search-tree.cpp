/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> stack;
        TreeNode *curr = root;
        vector<int> vtr;
        if(root==NULL) return false;
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
        for(int i=0;i<size-1;i++)
        {
            if(vtr[i]>=vtr[i+1])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
