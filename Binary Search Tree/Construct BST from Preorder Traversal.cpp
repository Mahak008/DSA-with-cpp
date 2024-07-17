// Leetcode - 1008

TreeNode* build(vector<int>& preorder, int& i, int bound) {
    if (i == preorder.size() || preorder[i] > bound) {
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[i++]);

    root->left = build(preorder, i, root->val);
    root->right = build(preorder, i, bound);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return build(preorder, i, INT_MAX);
}

// Input: preorder = [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]
