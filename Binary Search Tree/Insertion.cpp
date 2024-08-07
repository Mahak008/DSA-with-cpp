// Leetcode - 701

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }

    TreeNode* curr = root;
    while (curr) {
        if (curr->val < val) {
            if (curr->right) {
                curr = curr->right;
            } else {
                curr->right = new TreeNode(val);
                break;
            }
        } else {
            if (curr->left) {
                curr = curr->left;
            } else {
                curr->left = new TreeNode(val);
                break;
            }
        }
    }

    return root;
}

// Input: root = [4,2,7,1,3], val = 5
// Output: [4,2,7,1,3,5]
