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

    void inorderleaf(TreeNode* root, vector<int> &v)
    {
        if(root == NULL) return;
        
        inorderleaf(root->left, v);

        if(root->left == NULL && root->right == NULL)
            v.push_back(root->val);

        inorderleaf(root->right, v);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> v1;
        vector<int> v2;

        inorderleaf(root1, v1);
        inorderleaf(root2, v2);

        return v1 == v2;
    }
};
