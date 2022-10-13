
TreeNode* createNode(int val)
{
    TreeNode *t=new TreeNode();
    t->val=val;
    return t;
}
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> dubl;
        TreeNode * Node=createNode(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            TreeNode * node1=Node;
            while(node1!=NULL)
            {
                if(node1->val==nums[i])
                {
                    dubl.push_back(nums[i]);
                    break;
                }
                else if(node1->val < nums[i])
                {
                    if(node1->right == NULL)
                    {
                        TreeNode *t=createNode(nums[i]);
                        node1->right=t;
                        break;
                    }
                    else
                    {
                        node1=node1->right;
                    }
                }
                else
                {
                    if(node1->left == NULL)
                    {
                        TreeNode *t=createNode(nums[i]);
                        node1->left=t;
                        break;
                    }
                    else
                    {
                        node1=node1->left;
                    }
                }
            }
            
        }
        return dubl;
    }
};