class Solution {
public:
    int countPathsFromNode(TreeNode* node, long long targetSum) {
        if (!node) return 0;
        
        int count = 0;
        if (node->val == targetSum) {
            count++;
        }
        
        count += countPathsFromNode(node->left, targetSum - node->val);
        count += countPathsFromNode(node->right, targetSum - node->val);
        
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        
        return countPathsFromNode(root, targetSum) 
             + pathSum(root->left, targetSum) 
             + pathSum(root->right, targetSum);
    }
};