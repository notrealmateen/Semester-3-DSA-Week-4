class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        vector<int> vtr;
        stack<int> stk2;
        if(root==NULL) return vtr;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* current=stk.top();
            stk.pop();
            stk2.push(current->val);
            if(current->left!=NULL)
            {
                stk.push(current->left);
            }
            if(current->right!=NULL)
            {
                stk.push(current->right);
            }
        }
        while(!stk2.empty())
        {
            vtr.push_back(stk2.top());
            stk2.pop();
        }
        return vtr;
    }
};