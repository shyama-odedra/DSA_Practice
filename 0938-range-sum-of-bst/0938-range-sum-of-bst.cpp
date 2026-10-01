class Solution {
public:
    int res = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return res;
        
        if(root->val >= low and root->val <= high) {
            res += root->val;
            rangeSumBST(root->left, low, high);
            rangeSumBST(root->right, low, high);
        } else if(root->val < low) {
            rangeSumBST(root->right, low, high);
        } else if(root->val > high) {
            rangeSumBST(root->left, low, high);
        }
        return res;
    }
};