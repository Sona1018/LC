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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = 0;
        // queue store {node, index}
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            // no of nodes at current level
            int size = q.size();

            long long mini = q.front().second;  // 1st index of current level (used for normalization)
            long long first, last;
            for (int i = 0; i < size; i++) {
                long long cur_id = q.front().second - mini; // normalize index to avoid overflow
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) // store 1st index of this level
                first = cur_id;
        
                if (i == size - 1) // store last index of this level
                last = cur_id;
        
                if (node->left) { // push left child with its index
                q.push({node->left, cur_id * 2 + 1});
                }
              
                if (node->right) {   // push right child with its index
                q.push({node->right, cur_id * 2 + 2});
                }
            }
            ans = max(ans, (int)(last - first + 1)); // width = last index - first index + 1
        }
        return ans;
    }
};