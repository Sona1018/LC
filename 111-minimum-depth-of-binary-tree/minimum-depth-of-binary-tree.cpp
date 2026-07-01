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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr)
        //giving count of current node + the other 1 thats why using 1+
        return 1 + minDepth(root->right);
        if (root->right == nullptr) return 1 + minDepth(root->left);
       
    else
     return 1 + min(minDepth(root->left), minDepth(root->right));
    }
}; //tc:o(n),sc:o(h)