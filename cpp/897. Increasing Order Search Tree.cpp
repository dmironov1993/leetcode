//First solution
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



//Second solution
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
public:
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        TreeNode* result = nullptr;
        while (true) {
            if (current == nullptr) {
                if (parent == nullptr) {
                    return result;
                } else {
                    assert(parent != nullptr);
                    current = parent;
                    parent = parent -> right;
                    current -> right = nullptr;
                }
            } else {
                assert(current != nullptr);
                if (current -> right != nullptr) {
                    TreeNode *tmp = current -> right;
                    current -> right = parent;
                    parent = current;
                    current = tmp;
                } else {
                    assert(current-> right == nullptr);
                    current -> right = result;
                    result = current;
                    current = current -> left;
                    result -> left = nullptr;
                }
            }
        }
    }
};
