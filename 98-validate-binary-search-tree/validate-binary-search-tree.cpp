/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // We use a helper function to keep track of the allowed range of values.
        // We use LONG_MIN and LONG_MAX to safely handle tree nodes that might contain INT_MIN or INT_MAX.
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        // An empty tree (or reaching the end of a branch) is technically a valid BST
        if (node == nullptr) {
            return true;
        }

        // If the current node's value is outside the allowed range, it's not a valid BST
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        // Recursively check the left and right subtrees:
        // 1. For the left subtree, all values must be less than the current node's value (maxVal becomes node->val)
        // 2. For the right subtree, all values must be greater than the current node's value (minVal becomes node->val)
        return validate(node->left, minVal, node->val) && 
               validate(node->right, node->val, maxVal);
    }
};