#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *createNode(int val)
{
    TreeNode *t = new TreeNode();
    t->val = val;
    return t;
}
void insert(TreeNode *Node, int num)
{
    TreeNode *node1 = Node;
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
}
bool search(TreeNode *node, int num)
{
    TreeNode *node1 = node;
    while (node1 != NULL)
    {
        if (node1->val == num)
        {
            return true;
        }
        else if (node1->val < num)
        {
            if (node1->right == NULL)
            {
                return false;
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
                return false;
            }
            else
            {
                node1 = node1->left;
            }
        }
    }
    return false;
}
void displayall(TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *curr = root;
    while (!s.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = s.top();
            s.pop();
            cout << curr->val << " ";
            curr = curr->right;
        }
    }
}
bool delete1(TreeNode* node, int num) //delete does not work
{
    if (search(node, num))
    {
        TreeNode *node1 = node;
        TreeNode *prev=NULL;
        while (node1 != NULL)
        {
            if (node1->val == num)
            {
                TreeNode *left=NULL;
                if(node1->left==NULL && node1->right==NULL)
                {
                    if(num>prev->val)
                    {
                        prev->right=NULL;
                    }
                    else 
                    {
                        prev->left=NULL;
                    }
                    return true;
                }
                if(node->left==NULL)
                {
                    if(num>prev->val)
                    {
                        prev->right=node->right;
                    }
                    else 
                    {
                        prev->left=node->right;
                    }
                    return true;
                }
                else if(node->right==NULL)
                {
                    if(num>prev->val)
                    {
                        prev->right=node->left;
                    }
                    else 
                    {
                        prev->left=node->left;
                        cout<<"jo"<<endl;
                    }
                    return true;
                }
                /*
                if(node1->val > prev->val)
                {
                    prev->right=node1->right;
                    left=node1->left;
                    node1=prev->right;
                }
                else
                {
                    prev->left=node1->right;
                    left=node1->left;
                    node1=prev->left;
                }
                
                while(node1!=NULL)
                {
                    if(node1->left==NULL)
                    {
                        node1->left=left;
                        break;
                    }
                    else
                    {
                        node1=node1->left;
                    }
                }
                return true;
                */

            }
            else if (node1->val < num)
            {
                if (node1->right == NULL)
                {
                    return false;
                }
                else
                {
                    prev=node1;
                    node1 = node1->right;
                }
            }
            else
            {
                if (node1->left == NULL)
                {
                    return false;
                }
                else
                {
                    prev=node1;
                    node1 = node1->left;
                }
            }
        }
    }
    return false;
}
main()
{
    TreeNode *node = createNode(6);
    insert(node, 5);
    insert(node, 7);
    insert(node, 1);
    insert(node, 8);
    insert(node, 9);
    insert(node, 2);
    displayall(node);
    cout << endl;

    // cout<<search(node,2);

    cout<<delete1(node,9)<<endl;
    displayall(node);
}