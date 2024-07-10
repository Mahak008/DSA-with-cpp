vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {

            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }

            level.push_back(node->val);
        }

        ans.push_back(level[0]);
    }

    return ans;
}

// Input:
//    1
//  /  \
// 3    2
// Output: 1 3