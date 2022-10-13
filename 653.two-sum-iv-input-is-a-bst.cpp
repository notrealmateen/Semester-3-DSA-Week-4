/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    bool findTarget(TreeNode *root, int k)
    {
        stack<TreeNode *> stack;
        TreeNode *curr = root;
        vector<int> vtr;
        // if(root==NULL) return false;
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
        int size = vtr.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (i == j)
                    continue;

                if (vtr[i] + vtr[j] == k)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
