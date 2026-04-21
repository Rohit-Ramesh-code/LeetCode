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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 1. If both nodes are null, we reached the ends identically
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // 2. If only one node is null, the trees have different shapes
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // 3. If the values at the current nodes don't match, they aren't the same
        if (p->val != q->val) {
            return false;
        }
        
        // 4. Recursively check the left children against each other, 
        // AND the right children against each other.
        return isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
};