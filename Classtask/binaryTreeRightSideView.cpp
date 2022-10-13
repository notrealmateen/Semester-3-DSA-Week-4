
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vtr;
        if(root==NULL)  return vtr;
        
        queue<TreeNode *> qu;
        
        vtr.push_back(root->val);
        
        while(!qu.empty())
        {
            TreeNode * node=NULL;
            int n=qu.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* top=qu.front();
                qu.pop();
                if(top==NULL)
                {
                    continue;
                }
                if(i%2==0)
                {
                    node=top;
                }
                qu.push(top->right);            
                qu.push(top->left);
            }
            if(node!=NULL)
            {
                vtr.push_back(node->val);
            }
        }
        return vtr;
    }
};
main()
{
    Solution a;
    a.rightSideView([1,2,3,null,5,null,4]);
}