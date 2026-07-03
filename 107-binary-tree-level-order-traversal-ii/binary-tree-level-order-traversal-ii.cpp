
 /*/**
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(level);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
}; 

//Rule yaad rakhna:

//Recursion ⇒ Helper almost always useful.
//Simple BFS ⇒ Helper optional, usually direct function is preferred.
/*class Solution {
public:
//level order traversal 
void levelOrder(TreeNode* root, vector<vector<int>>& ans){
    
    if(root==nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
         int size=q.size();
vector<int>level;
for(int i=0;i<size;i++){
    TreeNode* node=q.front();
    q.pop();
    level.push_back(node->val);
    if(node->left != NULL){
        q.push(node->left);
    }
    if(node->right != NULL){
        q.push(node->right);
    }
}
ans.push_back(level);
    }

}

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>>ans;
      levelOrder(root,ans);
      reverse(ans.begin(), ans.end());
      return ans;
    }
};*/
