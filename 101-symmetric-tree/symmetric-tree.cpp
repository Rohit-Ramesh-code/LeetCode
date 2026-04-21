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
    bool isSymmetric(TreeNode* root) {
        // An empty tree is inherently symmetric
        if (root == nullptr) {
            return true;
        }
        
        // Check if the left and right subtrees are mirrors of each other
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* leftNode, TreeNode* rightNode) {
        // 1. If both nodes are null, we reached the ends symmetrically
        if (leftNode == nullptr && rightNode == nullptr) {
            return true;
        }
        
        // 2. If only one node is null, the tree is lopsided
        if (leftNode == nullptr || rightNode == nullptr) {
            return false;
        }
        
        // 3. If the values at these mirrored positions don't match, it's not symmetric
        if (leftNode->val != rightNode->val) {
            return false;
        }
        
        // 4. Recursively check the children. 
        // A mirror means the OUTER children must match, and the INNER children must match.
        return isMirror(leftNode->left, rightNode->right) && 
               isMirror(leftNode->right, rightNode->left);
    }
};