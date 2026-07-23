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
    void traverse(TreeNode* root, int curMax, int& count) {
        if (root == NULL) return;

        if (root->val >= curMax) {
            curMax = root->val;
            count++;
        }

        traverse(root->left, curMax, count);
        traverse(root->right, curMax, count);
    }
    
    int goodNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int count = 0;
        int curMax = root->val;
        traverse(root, curMax, count);
        return count;
    }
};
