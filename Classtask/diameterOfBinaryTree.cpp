class Solution {
public:
    int dia=INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return dia;
    }
    int height(TreeNode* node)
    {
        if(node==NULL)
        {
            return 0;
        }
        else
        {
            int left=height(node->left);
            int right=height(node->right);
            dia=max(dia,left+right);
            return 1+max(left,right);
        }
    }
};