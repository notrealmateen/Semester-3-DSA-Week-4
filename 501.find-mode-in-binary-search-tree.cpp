/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
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
        int size=vtr.size();
        int countf=1;
        int numf;
        int prev=vtr[0];
        int count=1;
        vector<int> vt;
        if(size==1)
        {
            vt.push_back(vtr[0]);
            return vt;
        }
        vt.push_back(prev);
        for(int i=1;i<size;i++)
        {
            if(vtr[i]==prev)
            {
                count++;
                if(count==countf)
                {
                    vt.push_back(vtr[i]);
                }
                else if(count>countf)
                {
                    vt.clear();
                    vt.push_back(vtr[i]);
                    countf=count;
                }
            }
            else
            {
                count=1;
                if(count==countf)
                {
                    vt.push_back(vtr[i]);
                }
                prev=vtr[i];
            }
        }
        return vt;
    }
};
// @lc code=end

