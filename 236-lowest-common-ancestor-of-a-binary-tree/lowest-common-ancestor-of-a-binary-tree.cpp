/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: //brute force
    bool getPath(TreeNode* root, vector<TreeNode*>& path, TreeNode* node) {
        if (root == nullptr)  return false;
        path.push_back(root);
        if (root == node)  return true;

        if (getPath(root->left, path, node) || //o(n),o(n)
        getPath(root->right, path, node))
        return true;
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        getPath(root, path1, p); //o(n)
        getPath(root, path2, q); //o(n)
        int i = 0;
        while (i < path1.size() && i < path2.size()) {
            if (path1[i] != path2[i])
             break;
            i++;
        }
        return path1[i - 1];
    }
};