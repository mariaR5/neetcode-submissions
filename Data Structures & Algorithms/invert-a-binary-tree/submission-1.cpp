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
    TreeNode* addNode(TreeNode* root, TreeNode* leftNode, TreeNode* rightNode) {
        if (root == NULL) return NULL;

        root->left = leftNode;
        root->right = rightNode;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        TreeNode* rightRoot = invertTree(root->right);
        TreeNode* leftRoot = invertTree(root->left);
        TreeNode* newRoot = addNode(root, rightRoot, leftRoot);
        return newRoot;
    }
};
