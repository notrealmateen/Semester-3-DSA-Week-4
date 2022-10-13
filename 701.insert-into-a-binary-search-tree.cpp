/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    TreeNode *createNode(int val)
    {
        TreeNode *t = new TreeNode();
        t->val = val;
        return t;
    }
    TreeNode *insertIntoBST(TreeNode *root, int num)
    {
        TreeNode *node1 = root;
        if(root==NULL)
        {
            root = createNode(num);
            return root;
        }
        while (node1 != NULL)
        {
            if (node1->val <= num)
            {
                if (node1->right == NULL)
                {
                    TreeNode *t = createNode(num);
                    node1->right = t;
                    break;
                }
                else
                {
                    node1 = node1->right;
                }
            }
            else
            {
                if (node1->left == NULL)
                {
                    TreeNode *t = createNode(num);
                    node1->left = t;
                    break;
                }
                else
                {
                    node1 = node1->left;
                }
            }
        }
        return root;
    }
    
};
// @lc code=end
