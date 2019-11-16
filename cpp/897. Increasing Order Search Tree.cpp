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
    
    void visit(TreeNode* node, TreeNode*& result) {
        if (node == nullptr) {
            return;
        }
        visit(node -> right, result);
        node -> right = result;
        result = node;
        // put node to result
        visit(node -> left, result);
        node -> left = nullptr;
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode * result = nullptr;
        visit(root, result);
        return result;
    }
};
