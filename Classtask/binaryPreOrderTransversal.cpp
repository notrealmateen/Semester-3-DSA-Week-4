class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        vector<int> vtr;
        if(root==NULL) return vtr;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* current=stk.top();
            stk.pop();
            vtr.push_back(current->val);
            if(current->right!=NULL)
            {
                stk.push(current->right);
            }
            if(current->left!=NULL)
            {
                stk.push(current->left);
            }
            
        }
        return vtr;
    }
};