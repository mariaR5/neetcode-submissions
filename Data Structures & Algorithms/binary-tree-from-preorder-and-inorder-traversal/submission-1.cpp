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
    unordered_map<int, int> mpp;

    TreeNode* buildSubTree(
        vector<int>& preorder, 
        vector<int>& inorder, 
        int preRoot,
        int inStart, int inEnd
        ) {
        if (preRoot > preorder.size() || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preRoot]);

        int i = mpp[root->val];

        int leftSize = i - inStart;

        root->left = buildSubTree(preorder, inorder, preRoot + 1, inStart, i - 1);
        root->right = buildSubTree(preorder, inorder, preRoot + leftSize + 1, i + 1, inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) 
            mpp[inorder[i]] = i;

        return buildSubTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};
