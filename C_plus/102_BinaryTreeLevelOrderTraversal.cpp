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
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > ret;
        if (!root)
            return ret;
        queue<TreeNode *> q;
        q.push(root);
        int number_of_node_level;
        while (!q.empty())
        {
            number_of_node_level = q.size();
            vector<int> temp;
            while (number_of_node_level)
            {
                TreeNode *t = q.front();
                q.pop();
                temp.push_back(t->val);

                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                number_of_node_level--;
            }
            ret.push_back(temp);
        }
        return ret;
    }
};